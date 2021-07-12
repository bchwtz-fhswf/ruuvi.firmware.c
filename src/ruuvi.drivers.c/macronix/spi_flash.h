#ifndef __SPI_FLASH_H
#define __SPI_FLASH_H

#include <stdint.h>
#include <stdbool.h>

#include "ruuvi_driver_error.h"

#define MX_PIN_CS           30

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


void access_flash(void);

rd_status_t mx_init(void);

rd_status_t mx_read_rems(uint8_t * manufacturer_id, uint8_t * device_id);

rd_status_t mx_read_status_register(uint8_t *status);

rd_status_t mx_read_config_register(uint8_t *config);

rd_status_t mx_read(uint32_t address, uint8_t * data_ptr, uint32_t data_length);

rd_status_t mx_write_enable(void);

rd_status_t mx_program(uint32_t address, uint8_t * data_ptr, uint32_t data_length);

rd_status_t mx_sector_erase(uint32_t address);

rd_status_t mx_chip_erase(void);

#endif
