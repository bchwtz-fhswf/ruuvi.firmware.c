#include "spi_flash.h"
#include "nrf_drv_gpiote.h"

#include "ruuvi_interface_log.h"
#include "ruuvi_driver_sensor.h"
#include "ruuvi_interface_gpio.h"
#include "ruuvi_interface_spi.h"

#if RI_LOG_ENABLED
#include <stdio.h>
#include <stdarg.h>
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
            LOGDf("Config: %i\r\n", (int)status_register);
            break;

        case 3:
            test_mx_read(0x1000);
            break;

        case 4:
            printf("Running write enable\r\n");
            mx_write_enable();
            break;
        
        case 5:
            printf("Running sector erase at address 0x1000\r\n");
            mx_sector_erase(0x1000);
            break;

        case 6:
            mx_read_status_register(&status_register);
            LOGDf("Status: %i\r\n", (int)status_register);

            // If the WIP bit is set, don't advance to the next state
            if(status_register & REG_SR_BIT_WIP) flash_state--;
            break;

        case 7:
            test_mx_read(0x1000);
            break;

        case 8:
            LOGDf("Running write enable\r\n");
            mx_write_enable();
            break;

        case 9:
            address = 0x1000;
            for(int i = 0; i < READ_WRITE_LENGTH; i++) data_buf[i] = i;
            mx_program(address, data_buf, READ_WRITE_LENGTH);
            LOGDf("Programming data at address %.8X\r\n", address);
            break;

        case 10:
            mx_read_status_register(&status_register);
            LOGDf("Status: %i\r\n", (int)status_register);

            // If the WIP bit is set, don't advance to the next state
            if(status_register & REG_SR_BIT_WIP) flash_state--;
            break;

        case 11:
            test_mx_read(0x1000);
            flash_state=0;
            break;
    }
}

rd_status_t mx_init(void)
{
    return RD_SUCCESS;
}


rd_status_t mx_read_rems(uint8_t * manufacturer_id, uint8_t * device_id)
{
    rd_status_t err_code = RD_SUCCESS;
    
    uint8_t spi_tx_cmd[] = {CMD_REMS, 0x00, 0x00, CMD_REMS_ADDRESS_DEFAULT, 0x00, 0x00};
    uint8_t spi_rx_response[6];

    ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, MX_PIN_CS);

    err_code |= ri_gpio_write (chipSelect, RI_GPIO_LOW);
    err_code |= ri_spi_xfer_blocking(spi_tx_cmd, sizeof(spi_tx_cmd), spi_rx_response, sizeof(spi_rx_response));
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_HIGH);

    *manufacturer_id = spi_rx_response[4];
    *device_id = spi_rx_response[5];

    LOGD("mx_read_rems: ");
    ri_log_hex(RI_LOG_LEVEL_DEBUG, spi_rx_response, sizeof(spi_rx_response));
    LOGD("\r\n");

    RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    return err_code;
}

rd_status_t mx_read_status_register(uint8_t *status)
{
    uint8_t spi_tx_cmd[2] = {CMD_RDSR, 0};
    static uint8_t spi_rx_rsp[2];

    ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, MX_PIN_CS);

    rd_status_t err_code = RD_SUCCESS;
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_LOW);
    err_code |= ri_spi_xfer_blocking(spi_tx_cmd, sizeof(spi_tx_cmd), spi_rx_rsp, sizeof(spi_rx_rsp));
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_HIGH);

    *status = spi_rx_rsp[1];

    LOGD("mx_read_status_register: ");
    ri_log_hex(RI_LOG_LEVEL_DEBUG, spi_rx_rsp, sizeof(spi_rx_rsp));
    LOGD("\r\n");

    RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    return err_code;
}


rd_status_t mx_read_config_register(uint8_t *config)
{
    uint8_t spi_tx_cmd[2] = {CMD_RDCR, 0};
    static uint8_t spi_rx_rsp[2];

    ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, MX_PIN_CS);

    rd_status_t err_code = RD_SUCCESS;
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_LOW);
    err_code |= ri_spi_xfer_blocking(spi_tx_cmd, sizeof(spi_tx_cmd), spi_rx_rsp, sizeof(spi_rx_rsp));
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_HIGH);

    *config = spi_rx_rsp[1];

    LOGD("mx_read_config_register: ");
    ri_log_hex(RI_LOG_LEVEL_DEBUG, spi_rx_rsp, sizeof(spi_rx_rsp));
    LOGD("\r\n");

    RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    return err_code;
}


rd_status_t mx_read(uint32_t address, uint8_t * data_ptr, uint32_t data_length)
{
    uint8_t spi_tx_cmd[] = {CMD_READ, (address >> 16) & 0xFF, (address >> 8) & 0xFF, (address >> 0) & 0xFF};
    
    rd_status_t err_code = RD_SUCCESS;

    ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, MX_PIN_CS);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_LOW);

    err_code |= ri_spi_xfer_blocking(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
    while(data_length > 255)
    {
        err_code |= ri_spi_xfer_blocking(0, 0, data_ptr, 255);
        data_ptr += 255;
        data_length -= 255;
    }
    err_code |= ri_spi_xfer_blocking(0, 0, data_ptr, data_length);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_HIGH);

    RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    return err_code;
}


rd_status_t mx_write_enable(void)
{
    static uint8_t spi_tx_cmd[] = {CMD_WREN};

    rd_status_t err_code = RD_SUCCESS;

    ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, MX_PIN_CS);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_LOW);
    err_code |= ri_spi_xfer_blocking(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_HIGH);

    RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    return err_code;
}

rd_status_t mx_program(uint32_t address, uint8_t * data_ptr, uint32_t data_length)
{
    uint8_t spi_tx_cmd[] = {CMD_PROGRAM, (address >> 16) & 0xFF, (address >> 8) & 0xFF, (address >> 0) & 0xFF};
    
    rd_status_t err_code = RD_SUCCESS;

    ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, MX_PIN_CS);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_LOW);

    err_code |= ri_spi_xfer_blocking(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
    while(data_length > 255)
    {
        err_code |= ri_spi_xfer_blocking(data_ptr, 255, 0, 0);
        data_ptr += 255;
        data_length -= 255;
    }
    err_code |= ri_spi_xfer_blocking(data_ptr, data_length, 0, 0);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_HIGH);

    RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    return err_code;
}


rd_status_t mx_sector_erase(uint32_t address)
{
    uint8_t spi_tx_cmd[] = {CMD_SECTOR_ERASE, (address >> 16) & 0xFF, (address >> 8) & 0xFF, (address >> 0) & 0xFF};

    rd_status_t err_code = RD_SUCCESS;

    ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, MX_PIN_CS);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_LOW);
    err_code |= ri_spi_xfer_blocking(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_HIGH);

    RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    return err_code;
}


rd_status_t mx_chip_erase(void)
{
    static uint8_t spi_tx_cmd[] = {CMD_CHIP_ERASE};

    rd_status_t err_code = RD_SUCCESS;

    ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, MX_PIN_CS);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_LOW);
    err_code |= ri_spi_xfer_blocking(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
    err_code |= ri_gpio_write (chipSelect, RI_GPIO_HIGH);

    RD_ERROR_CHECK (err_code, ~RD_ERROR_FATAL);

    return err_code;
}

