#include "spi_flash.h"
#include "nrf_drv_gpiote.h"

#include "ruuvi_interface_log.h"
#include "ruuvi_driver_sensor.h"
#include "ruuvi_interface_gpio.h"
#include "ruuvi_interface_spi.h"
#include "nrf_drv_spi.h"
#include <stddef.h>


#if RI_LOG_ENABLED
#include <stdio.h>
#include <stdarg.h>

//Neue SPI Instanz
static const nrf_drv_spi_t spi_macronix = NRF_DRV_SPI_INSTANCE (
                                     SPI_INSTANCE_MACRONIX);  /**< SPI instance. */

static bool  m_spi_init_done = false;

static inline void LOG (const char * const msg)
{
    ri_log (RI_LOG_LEVEL_INFO, msg);
}

static inline void LOGD (const char * const msg)
{
    ri_log (RI_LOG_LEVEL_DEBUG, msg);
}

static inline void LOGDf (const char * const msg, ...)
{
    char fmsg[RD_LOG_BUFFER_SIZE];
    va_list args;
    *fmsg = 0;
    va_start(args, msg);
    vsnprintf(fmsg, RD_LOG_BUFFER_SIZE, msg, args);
    va_end(args);
    ri_log (RI_LOG_LEVEL_DEBUG, fmsg);
}
#else
#define LOG(...) 
#define LOGD(...)
#define LOGDf(...)
#define snprintf(...)
#endif


static uint32_t flash_state = 0;

#define READ_WRITE_LENGTH 256
static void test_mx_read(uint32_t address)
{
    static uint8_t data_buf[READ_WRITE_LENGTH];
    mx_read(address, data_buf, READ_WRITE_LENGTH);
    LOGDf("Reading address %.8x: ", address);
    for(int i = 0; i < READ_WRITE_LENGTH; i++) LOGDf("%.2X-" ,(int)data_buf[i]);
    LOGDf("\r\n");
}

void access_flash(void)
{
    rd_status_t status = mx_init();
    uint8_t man_id, dev_id, status_register, config_register;
    uint8_t data_buf[READ_WRITE_LENGTH];
    uint32_t address;

    LOGDf("Flash test Case %d\r\n", flash_state);

    switch(flash_state++)
    {
        case 0:
            mx_read_rems(&man_id, &dev_id);
            LOGDf("Reading REMS. Man id: %.2x, Dev id: %.2x\r\n", (int)man_id, (int)dev_id);
            break;

        case 1:
            mx_read_status_register(&status_register);
            LOGDf("Status: %i\r\n", (int)status_register);
            break;

        case 2:
            mx_read_config_register(&config_register);
            LOGDf("Config: %i\r\n", (int)config_register);
            break;

        case 3:
            test_mx_read(0x9000);
            break;

        case 4:
            printf("Running write enable\r\n");
            mx_write_enable();
            break;
        
        case 5:
            printf("Running sector erase at address 0x9000\r\n");
            mx_sector_erase(0x9000);
            break;

        case 6:
            mx_read_status_register(&status_register);
            LOGDf("Status: %i\r\n", (int)status_register);

            // If the WIP bit is set, don't advance to the next state
            if(status_register & (1 << REG_SR_BIT_WIP) ) flash_state--;
            break;

        case 7:
            test_mx_read(0x9000);
            break;

        case 8:
            LOGDf("Running write enable\r\n");
            mx_write_enable();
            break;

        case 9:
            address = 0x9000;
            for(int i = 0; i < READ_WRITE_LENGTH; i++) data_buf[i] = 1;
            mx_program(address, data_buf, READ_WRITE_LENGTH);
            LOGDf("Programming data at address %.8X\r\n", address);
            break;

        case 10:
            mx_read_status_register(&status_register);
            LOGDf("Status: %i\r\n", (int)status_register);

            // If the WIP bit is set, don't advance to the next state
            if(status_register & (1 << REG_SR_BIT_WIP) ) flash_state--;
            break;

        case 11:
            test_mx_read(0x9000);
            flash_state=0;
            break;
    }
}

rd_status_t mx_init(void)
{
/* Verwendet von Ruuvi Spi initialisierung - aber mit fester SPI instanz, also nicht nutzbar
    ri_gpio_id_t ss_pins[SPI_SS_NUMBER_MACRONIX] = SPI_SS_LIST_MACRONIX;
    ri_spi_init_config_t spi_config_macronix =
    {
        .mosi = MISO_SPI_MACRONIX,
        .miso = MOSI_SPI_MACRONIX,
        .sclk = SCK_SPI_MACRONIX,
        .ss_pins = ss_pins,
        .ss_pins_number = sizeof (ss_pins) / sizeof (ri_gpio_id_t),
        // Assume mode 0 always. - Gilt das auch für uns??
        .mode = RI_SPI_MODE_0,
        .frequency = SPI_FREQ_MACRONIX //Welche ist da für uns interessant?
    };
    */

    //Return error if SPI is already init
    if (m_spi_init_done) { return NRF_ERROR_INVALID_STATE; }

    rd_status_t status = RD_SUCCESS;
    nrf_drv_spi_mode_t mode = RI_SPI_MODE_0; //Könnte man auf NRV DRV SPI MODE Übersetzen anstatt das Ruuvi Makro zu benutzen?
    nrf_drv_spi_frequency_t frequency = NRF_DRV_SPI_FREQ_1M;
    //status |= ruuvi_to_nrf_spi_mode (config->mode, &mode);
    //status |= ruuvi_to_nrf_spi_freq (config->frequency, &frequency);
    RD_ERROR_CHECK (status, RD_SUCCESS);
    nrf_drv_spi_config_t spi_config_macronix = NRF_DRV_SPI_DEFAULT_CONFIG;
    spi_config_macronix.ss_pin       = NRF_DRV_SPI_PIN_NOT_USED;
    spi_config_macronix.miso_pin     = MISO_SPI_MACRONIX;
    spi_config_macronix.mosi_pin     = MOSI_SPI_MACRONIX;
    spi_config_macronix.sck_pin      = SCK_SPI_MACRONIX;
    spi_config_macronix.irq_priority = SPI_DEFAULT_CONFIG_IRQ_PRIORITY;
    spi_config_macronix.orc          = 0xFF;
    spi_config_macronix.frequency    = NRF_DRV_SPI_FREQ_125K;
    spi_config_macronix.mode         = mode; //Könnte man auch direkt den Wert rein schreiben?
    spi_config_macronix.bit_order    = NRF_DRV_SPI_BIT_ORDER_MSB_FIRST;
    // Use blocking mode by using NULL as event handler
    ret_code_t err_code = NRF_SUCCESS;
    err_code = nrf_drv_spi_init (&spi_macronix, &spi_config_macronix, NULL, NULL);

    ri_gpio_id_t ss_pins[SPI_SS_NUMBER_MACRONIX] = SPI_SS_LIST_MACRONIX;
    //for (size_t ii = 0; ii < config->ss_pins_number; ii++)   Wenn mehr Slaves genutzt werden vielleicht sinnvoll?
    //{
    ri_gpio_configure (SS_SPI_MACRONIX,
                           RI_GPIO_MODE_OUTPUT_STANDARD);
    ri_gpio_write (SS_SPI_MACRONIX, RI_GPIO_HIGH);
    //}

    m_spi_init_done = true;
    return (status | ruuvi_nrf5_sdk15_to_ruuvi_error (err_code));
}

/*
rd_status_t mx_read_rems(uint8_t * manufacturer_id, uint8_t * device_id)
{
    rd_status_t err_code = RD_SUCCESS;
    
    uint8_t spi_tx_cmd[] = {CMD_REMS, 0x00, 0x00, CMD_REMS_ADDRESS_DEFAULT, 0x00, 0x00};
    uint8_t spi_rx_response[6];

    ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, SS_SPI_MACRONIX);

    err_code |= ri_gpio_write (chipSelect, RI_GPIO_LOW);
    err_code |= ri_spi_xfer_blocking_macronix(spi_tx_cmd, sizeof(spi_tx_cmd), spi_rx_response, sizeof(spi_rx_response));
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_HIGH);

    *manufacturer_id = spi_rx_response[4];
    *device_id = spi_rx_response[5];

    LOGD("mx_read_rems: ");
    ri_log_hex(RI_LOG_LEVEL_DEBUG, spi_rx_response, sizeof(spi_rx_response));
    LOGD("\r\n");

    //RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    return err_code;
}*/

rd_status_t mx_read_rems(uint8_t * manufacturer_id, uint8_t * device_id)
{
    rd_status_t err_code = RD_SUCCESS;

    uint8_t spi_tx_cmd[] = {CMD_REMS, 0x00, 0x00, CMD_REMS_ADDRESS_DEFAULT};
    uint8_t spi_rx_response[2];

    ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, SS_SPI_MACRONIX);

    err_code |= ri_gpio_write (chipSelect, RI_GPIO_LOW);
    //Kann nicht genutzt werden weil es fest die ruuvi spi Funktion nutzt
    err_code |= ri_spi_xfer_blocking_macronix(spi_tx_cmd, sizeof(spi_tx_cmd), 0,0);
    err_code |= ri_spi_xfer_blocking_macronix(0,0, spi_rx_response, sizeof(spi_rx_response));
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_HIGH);

    *manufacturer_id = spi_rx_response[0];
    *device_id = spi_rx_response[1];

    LOGD("mx_read_rems: ");
    ri_log_hex(RI_LOG_LEVEL_DEBUG, spi_rx_response, sizeof(spi_rx_response));
    LOGD("\r\n");

    //RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    return err_code;
}

rd_status_t mx_read_status_register(uint8_t *status)
{
    uint8_t spi_tx_cmd[2] = {CMD_RDSR, 0};
    static uint8_t spi_rx_rsp[2];

    ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, SS_SPI_MACRONIX);

    rd_status_t err_code = RD_SUCCESS;
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_LOW);
    err_code |= ri_spi_xfer_blocking_macronix(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
    err_code |= ri_spi_xfer_blocking_macronix(0, 0, spi_rx_rsp, sizeof(spi_rx_rsp));
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_HIGH);

    *status = spi_rx_rsp[1];

    LOGD("mx_read_status_register: ");
    ri_log_hex(RI_LOG_LEVEL_DEBUG, spi_rx_rsp, sizeof(spi_rx_rsp));
    LOGD("\r\n");

    //RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    return err_code;
}


rd_status_t mx_read_config_register(uint8_t *config)
{
    uint8_t spi_tx_cmd[2] = {CMD_RDCR, 0};
    static uint8_t spi_rx_rsp[2];

    ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, SS_SPI_MACRONIX);

    rd_status_t err_code = RD_SUCCESS;
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_LOW);
    err_code |= ri_spi_xfer_blocking_macronix(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
    err_code |= ri_spi_xfer_blocking_macronix(0, 0, spi_rx_rsp, sizeof(spi_rx_rsp));
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_HIGH);

    *config = spi_rx_rsp[1];

    LOGD("mx_read_config_register: ");
    ri_log_hex(RI_LOG_LEVEL_DEBUG, spi_rx_rsp, sizeof(spi_rx_rsp));
    LOGD("\r\n");

    //RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    return err_code;
}


rd_status_t mx_read(uint32_t address, uint8_t * data_ptr, uint32_t data_length)
{
    uint8_t spi_tx_cmd[] = {CMD_READ, (address >> 16) & 0xFF, (address >> 8) & 0xFF, (address >> 0) & 0xFF};
    
    rd_status_t err_code = RD_SUCCESS;

    ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, SS_SPI_MACRONIX);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_LOW);

    err_code |= ri_spi_xfer_blocking_macronix(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
    while(data_length > 255)
    {
        err_code |= ri_spi_xfer_blocking_macronix(0, 0, data_ptr, 255);
        data_ptr += 255;
        data_length -= 255;
    }
    err_code |= ri_spi_xfer_blocking_macronix(0, 0, data_ptr, data_length);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_HIGH);

    //RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    return err_code;
}


rd_status_t mx_write_enable(void)
{
    static uint8_t spi_tx_cmd[] = {CMD_WREN};

    rd_status_t err_code = RD_SUCCESS;

    ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, SS_SPI_MACRONIX);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_LOW);
    err_code |= ri_spi_xfer_blocking_macronix(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_HIGH);

    //RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    return err_code;
}

rd_status_t mx_program(uint32_t address, uint8_t * data_ptr, uint32_t data_length)
{
    uint8_t spi_tx_cmd[] = {CMD_PROGRAM, (address >> 16) & 0xFF, (address >> 8) & 0xFF, (address >> 0) & 0xFF};
    
    rd_status_t err_code = RD_SUCCESS;

    ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, SS_SPI_MACRONIX);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_LOW);

    err_code |= ri_spi_xfer_blocking_macronix(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
    while(data_length > 255)
    {
        err_code |= ri_spi_xfer_blocking_macronix(data_ptr, 255, 0, 0);
        data_ptr += 255;
        data_length -= 255;
    }
    err_code |= ri_spi_xfer_blocking_macronix(data_ptr, data_length, 0, 0);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_HIGH);

    //RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    return err_code;
}


rd_status_t mx_sector_erase(uint32_t address)
{
    uint8_t spi_tx_cmd[] = {CMD_SECTOR_ERASE, (address >> 16) & 0xFF, (address >> 8) & 0xFF, (address >> 0) & 0xFF};

    rd_status_t err_code = RD_SUCCESS;

    ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, SS_SPI_MACRONIX);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_LOW);
    err_code |= ri_spi_xfer_blocking_macronix(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_HIGH);

    //RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    return err_code;
}


rd_status_t mx_chip_erase(void)
{
    static uint8_t spi_tx_cmd[] = {CMD_CHIP_ERASE};

    rd_status_t err_code = RD_SUCCESS;

    ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, SS_SPI_MACRONIX);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_LOW);
    err_code |= ri_spi_xfer_blocking_macronix(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_HIGH);

    //RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    return err_code;
}


rd_status_t ri_spi_xfer_blocking_macronix (const uint8_t * tx,
                                  const size_t tx_len, uint8_t * rx, const size_t rx_len)
{
    //Return error if not init or if given null pointer
    if (!m_spi_init_done)            { return RD_ERROR_INVALID_STATE; }

    if ( (NULL == tx && 0 != tx_len) || (NULL == rx && 0 != rx_len)) { return RD_ERROR_NULL; }

    ret_code_t err_code = NRF_SUCCESS;
    err_code |= nrf_drv_spi_transfer (&spi_macronix, tx, tx_len, rx, rx_len);
    return ruuvi_nrf5_sdk15_to_ruuvi_error (err_code);
}
