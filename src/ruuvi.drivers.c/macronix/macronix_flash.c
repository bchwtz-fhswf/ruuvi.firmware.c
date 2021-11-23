#include "macronix_flash.h"
#include "nrf_drv_gpiote.h"

#include "nrf_drv_spi.h"
#include "ruuvi_driver_sensor.h"
#include "ruuvi_interface_gpio.h"
#include "ruuvi_interface_log.h"
#include "ruuvi_interface_spi.h"
#include "ruuvi_nrf5_sdk15_error.h"
#include <stddef.h>

static bool m_spi_init_done = false;
//New SPI Instance "2" as 0 and 1 are occupied by ruuvi internal SPI
static const nrf_drv_spi_t spi_macronix = NRF_DRV_SPI_INSTANCE(
    SPI_INSTANCE_MACRONIX); /**< SPI instance. */


#if RI_LOG_ENABLED
#include <stdarg.h>
#include <stdio.h>


static inline void LOG(const char *const msg) {
  ri_log(RI_LOG_LEVEL_INFO, msg);
}

static inline void LOGD(const char *const msg) {
  ri_log(RI_LOG_LEVEL_DEBUG, msg);
}

static inline void LOGDf(const char *const msg, ...) {
  char fmsg[RD_LOG_BUFFER_SIZE];
  va_list args;
  *fmsg = 0;
  va_start(args, msg);
  vsnprintf(fmsg, RD_LOG_BUFFER_SIZE, msg, args);
  va_end(args);
  ri_log(RI_LOG_LEVEL_DEBUG, fmsg);
}
#else
#define LOG(...)
#define LOGD(...)
#define LOGDf(...)
#define snprintf(...)
#endif

#define READ_WRITE_LENGTH 256

static void test_mx_read(uint32_t address) {
  static uint8_t data_buf[READ_WRITE_LENGTH];
  mx_read(address, data_buf, READ_WRITE_LENGTH);
  LOGDf("Reading address %.8x: ", address);
  for (int i = 0; i < READ_WRITE_LENGTH; i++)
    LOGDf("%.2X-", (int)data_buf[i]);
  LOGDf("\r\n");
}

rd_status_t mx_init(void) {
  //Return error if SPI is already init
  if (m_spi_init_done) {
    return NRF_ERROR_INVALID_STATE;
  }
  nrf_drv_spi_config_t spi_config_macronix = NRF_DRV_SPI_DEFAULT_CONFIG;
  spi_config_macronix.ss_pin = NRF_DRV_SPI_PIN_NOT_USED;
  spi_config_macronix.miso_pin = MISO_SPI_MACRONIX;
  spi_config_macronix.mosi_pin = MOSI_SPI_MACRONIX;
  spi_config_macronix.sck_pin = SCK_SPI_MACRONIX;
  spi_config_macronix.irq_priority = SPI_DEFAULT_CONFIG_IRQ_PRIORITY;
  spi_config_macronix.orc = 0xFF;
  spi_config_macronix.frequency = NRF_DRV_SPI_FREQ_8M;
  spi_config_macronix.mode = NRF_DRV_SPI_MODE_0;
  spi_config_macronix.bit_order = NRF_DRV_SPI_BIT_ORDER_MSB_FIRST;

  // Use blocking mode by using NULL as event handler
  ret_code_t err_code = NRF_SUCCESS;
  err_code = nrf_drv_spi_init(&spi_macronix, &spi_config_macronix, NULL, NULL);

  //Initialize all SS Pins from SPI_SS_LIST_MACRONIX as output pins and set them high
  ri_gpio_id_t ss_pins[SPI_SS_NUMBER_MACRONIX] = SPI_SS_LIST_MACRONIX;
  for (size_t ii = 0; ii < SPI_SS_NUMBER_MACRONIX; ii++) {
    ri_gpio_configure(ss_pins[ii],
        RI_GPIO_MODE_OUTPUT_STANDARD);
    ri_gpio_write(ss_pins[ii], RI_GPIO_HIGH);
  }
  m_spi_init_done = true;
  return (err_code);
}

rd_status_t mx_read_rems(uint8_t *manufacturer_id, uint8_t *device_id) {
  rd_status_t err_code = RD_SUCCESS;

  uint8_t spi_tx_cmd[] = {CMD_REMS, 0x00, 0x00, CMD_REMS_ADDRESS_DEFAULT};
  uint8_t spi_rx_response[2];

  ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, SS_SPI_MACRONIX);

  err_code |= ri_gpio_write(chipSelect, RI_GPIO_LOW);
  err_code |= ri_spi_xfer_blocking_macronix(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
  err_code |= ri_spi_xfer_blocking_macronix(0, 0, spi_rx_response, sizeof(spi_rx_response));
  err_code |= ri_gpio_write(chipSelect, RI_GPIO_HIGH);

  *manufacturer_id = spi_rx_response[0];
  *device_id = spi_rx_response[1];

  //LOGD("mx_read_rems: ");
  //ri_log_hex(RI_LOG_LEVEL_DEBUG, spi_rx_response, sizeof(spi_rx_response));
  //LOGD("\r\n");

  return err_code;
}

rd_status_t mx_read_status_register(uint8_t *status) {
  uint8_t spi_tx_cmd[2] = {CMD_RDSR, 0};
  static uint8_t spi_rx_rsp[2];

  ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, SS_SPI_MACRONIX);

  rd_status_t err_code = RD_SUCCESS;
  err_code |= ri_gpio_write(chipSelect, RI_GPIO_LOW);
  err_code |= ri_spi_xfer_blocking_macronix(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
  err_code |= ri_spi_xfer_blocking_macronix(0, 0, spi_rx_rsp, sizeof(spi_rx_rsp));
  err_code |= ri_gpio_write(chipSelect, RI_GPIO_HIGH);

  *status = spi_rx_rsp[1];

  //LOGD("mx_read_status_register: ");
  //ri_log_hex(RI_LOG_LEVEL_DEBUG, spi_rx_rsp, sizeof(spi_rx_rsp));
  //LOGD("\r\n");

  return err_code;
}

rd_status_t mx_read_config_register(uint8_t *config) {
  uint8_t spi_tx_cmd[2] = {CMD_RDCR, 0};
  static uint8_t spi_rx_rsp[2];

  ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, SS_SPI_MACRONIX);

  rd_status_t err_code = RD_SUCCESS;
  err_code |= ri_gpio_write(chipSelect, RI_GPIO_LOW);
  err_code |= ri_spi_xfer_blocking_macronix(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
  err_code |= ri_spi_xfer_blocking_macronix(0, 0, spi_rx_rsp, sizeof(spi_rx_rsp));
  err_code |= ri_gpio_write(chipSelect, RI_GPIO_HIGH);

  *config = spi_rx_rsp[1];

  //LOGD("mx_read_config_register: ");
  //ri_log_hex(RI_LOG_LEVEL_DEBUG, spi_rx_rsp, sizeof(spi_rx_rsp));
  //LOGD("\r\n");

  return err_code;
}

rd_status_t mx_read(uint32_t address, uint8_t *data_ptr, uint32_t data_length) {
  uint8_t spi_tx_cmd[] = {CMD_READ, (address >> 16) & 0xFF, (address >> 8) & 0xFF, (address >> 0) & 0xFF};

  rd_status_t err_code = RD_SUCCESS;

  ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, SS_SPI_MACRONIX);
  err_code |= ri_gpio_write(chipSelect, RI_GPIO_LOW);

  err_code |= ri_spi_xfer_blocking_macronix(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
  while (data_length > 255) {
    err_code |= ri_spi_xfer_blocking_macronix(0, 0, data_ptr, 255);
    data_ptr += 255;
    data_length -= 255;
  }
  err_code |= ri_spi_xfer_blocking_macronix(0, 0, data_ptr, data_length);
  err_code |= ri_gpio_write(chipSelect, RI_GPIO_HIGH);

  return err_code;
}



rd_status_t mx_write_enable(void) {
  static uint8_t spi_tx_cmd[] = {CMD_WREN};

  rd_status_t err_code = RD_SUCCESS;

  ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, SS_SPI_MACRONIX);
  err_code |= ri_gpio_write(chipSelect, RI_GPIO_LOW);
  err_code |= ri_spi_xfer_blocking_macronix(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
  err_code |= ri_gpio_write(chipSelect, RI_GPIO_HIGH);

  return err_code;
}


rd_status_t mx_program(uint32_t address, const uint8_t *data_ptr, uint32_t data_length) {

  rd_status_t err_code = RD_SUCCESS;

  ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, SS_SPI_MACRONIX);
  err_code |= ri_gpio_write(chipSelect, RI_GPIO_LOW);
  uint8_t spi_tx_cmd[] = {CMD_PROGRAM, (address >> 16) & 0xFF, (address >> 8) & 0xFF, (address >> 0) & 0xFF};

  err_code |= ri_spi_xfer_blocking_macronix(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
  err_code |= ri_spi_xfer_blocking_macronix(data_ptr, data_length, 0, 0);
  err_code |= ri_gpio_write(chipSelect, RI_GPIO_HIGH);
  return err_code;
}

rd_status_t mx_sector_erase(uint32_t address) {
  uint8_t spi_tx_cmd[] = {CMD_SECTOR_ERASE, (address >> 16) & 0xFF, (address >> 8) & 0xFF, (address >> 0) & 0xFF};

  rd_status_t err_code = RD_SUCCESS;

  ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, SS_SPI_MACRONIX);
  err_code |= ri_gpio_write(chipSelect, RI_GPIO_LOW);
  err_code |= ri_spi_xfer_blocking_macronix(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
  err_code |= ri_gpio_write(chipSelect, RI_GPIO_HIGH);

  return err_code;
}

rd_status_t mx_chip_erase(void) {
  static uint8_t spi_tx_cmd[] = {CMD_CHIP_ERASE};
  rd_status_t err_code = RD_SUCCESS;

  ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, SS_SPI_MACRONIX);
  err_code |= ri_gpio_write(chipSelect, RI_GPIO_LOW);
  err_code |= ri_spi_xfer_blocking_macronix(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
  err_code |= ri_gpio_write(chipSelect, RI_GPIO_HIGH);
  return err_code;
}

rd_status_t ri_spi_xfer_blocking_macronix(const uint8_t *tx,
    const size_t tx_len, uint8_t *rx, const size_t rx_len) {
  //Return error if not init or if given null pointer
  if (!m_spi_init_done) {
    return RD_ERROR_INVALID_STATE;
  }

  if ((NULL == tx && 0 != tx_len) || (NULL == rx && 0 != rx_len)) {
    return RD_ERROR_NULL;
  }

  ret_code_t err_code = NRF_SUCCESS;
  err_code |= nrf_drv_spi_transfer(&spi_macronix, tx, tx_len, rx, rx_len);
  return ruuvi_nrf5_sdk15_to_ruuvi_error(err_code);
}

rd_status_t mx_busy(void) {
  uint8_t status_register;
  mx_read_status_register(&status_register);
  if (status_register & (1 << REG_SR_BIT_WIP)) {
    return RD_ERROR_BUSY;
  } else {
    return RD_SUCCESS;
  }
}

rd_status_t mx_check_write_enable(void) {
  uint8_t status_register;
  mx_read_status_register(&status_register);
  if (status_register & (1 << REG_SR_BIT_WEL)) {
    return RD_SUCCESS;
  } else {
    return RD_ERROR_BUSY;
  }
}


void mx_spi_ready_for_transfer (void){
    while( mx_busy() == RD_ERROR_BUSY){
      ri_yield();
    }

    mx_write_enable();
    while( mx_check_write_enable() == RD_ERROR_BUSY){
      ri_yield();
      LOGD("mx_write resend write_enable\r\n");
      mx_write_enable();
    }

    while( mx_busy() == RD_ERROR_BUSY){
      ri_yield();
    }
}

// TODO read register and only change desired bits
rd_status_t mx_high_performance_switch (bool high_power){
  rd_status_t err_code = RD_SUCCESS;
  uint8_t config;
  err_code |= mx_read_config_register(&config);
  LOGDf("current config: %x\n",config);
  uint8_t command;

  if (high_power==true){
  command = 0x02;
  }
  else{
  command = 0x00;
  }
  uint8_t spi_tx_cmd [] = {CMD_WRSR, 0x00, 0x00, command};
  err_code = RD_SUCCESS;
  mx_spi_ready_for_transfer();
  ri_gpio_id_t chipSelect = RB_PORT_PIN_MAP(0, SS_SPI_MACRONIX);
  err_code |= ri_gpio_write(chipSelect, RI_GPIO_LOW);
  err_code |= ri_spi_xfer_blocking_macronix(spi_tx_cmd, sizeof(spi_tx_cmd), 0, 0);
  err_code |= ri_gpio_write(chipSelect, RI_GPIO_HIGH);
  err_code |= mx_read_config_register(&config);
  LOGDf("current config: %x\n",config);
  return err_code;
}