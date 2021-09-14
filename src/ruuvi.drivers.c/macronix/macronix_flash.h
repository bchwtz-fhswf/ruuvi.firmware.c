#ifndef __SPI_FLASH_H
#define __SPI_FLASH_H
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "ruuvi_driver_error.h"

#define CMD_WRSR                    0x01
#define CMD_PROGRAM                 0x02
#define CMD_READ                    0x03
#define CMD_RDSR                    0x05
#define CMD_RDCR                    0x15
#define CMD_WREN                    0x06
#define CMD_REMS                    0x90
#define CMD_REMS_ADDRESS_DEFAULT    0x00
#define CMD_SECTOR_ERASE            0x20
#define CMD_CHIP_ERASE              0x60

#define REG_SR_BIT_WIP              0
#define REG_SR_BIT_WEL              1
#define REG_SR_BIT_BP0              2
#define REG_SR_BIT_BP1              3
#define REG_SR_BIT_BP2              4
#define REG_SR_BIT_BP3              5
#define REG_SR_BIT_QE               6
#define REG_SR_BIT_SRWD             7

// SPI definitions for Macronix Flash
#define SCK_SPI_MACRONIX                  RB_PORT_PIN_MAP(0, 20) // SPI clock GPIO pin number. Original:29, Neu 20
#define MOSI_SPI_MACRONIX                 RB_PORT_PIN_MAP(0, 30) // SPI Master Out Slave In GPIO pin number. Original:25 Neu 30
#define MISO_SPI_MACRONIX                 RB_PORT_PIN_MAP(0, 31) // SPI Master In Slave Out GPIO pin number. Original:28 Neu 31
#define SS_SPI_MACRONIX                   RB_PORT_PIN_MAP(0, 16)  // SPI Slave Select (Macrnoix external flash)
#define SPI_SS_LIST_MACRONIX               {SS_SPI_MACRONIX}
#define SPI_SS_NUMBER_MACRONIX             1
#define SPI_FREQUENCY_1M_MACRONIX          0
#define SPI_FREQUENCY_2M_MACRONIX          1
#define SPI_FREQUENCY_4M_MACRONIX          2
#define SPI_FREQUENCY_8M_MACRONIX          3
#define SPI_FREQ_MACRONIX                  SPI_FREQUENCY_1M_MACRONIX
#define SPI_INSTANCE_MACRONIX              2




void access_flash(void);

rd_status_t mx_init(void);

rd_status_t mx_read_rems(uint8_t * manufacturer_id, uint8_t * device_id);

rd_status_t mx_read_status_register(uint8_t *status);

rd_status_t mx_read_config_register(uint8_t *config);

rd_status_t mx_read(uint32_t address, uint8_t * data_ptr, uint32_t data_length);

rd_status_t mx_write_enable(void);

rd_status_t mx_program(uint32_t address, const uint8_t * data_ptr, uint32_t data_length);

rd_status_t mx_sector_erase(uint32_t address);

rd_status_t mx_chip_erase(void);

rd_status_t ri_spi_xfer_blocking_macronix (const uint8_t * tx,
                                  const size_t tx_len, uint8_t * rx, const size_t rx_len);
                              
rd_status_t mx_busy (void);

rd_status_t mx_check_write_enable(void);

void mx_spi_ready_for_transfer (void);

rd_status_t mx_high_performance_switch (bool high_power);

#endif
