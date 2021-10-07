/**
 * @file fal_ram_port.c
 * @author Thomas Hoof <thomas.hoof@gmx.de>
 * @date 2021-08-10
 * @copyright Ruuvi Innovations Ltd, License BSD-3-Clause.
 */

#include <string.h>
#include <stdlib.h>
#include "fal.h"

#define RAM_BLOCK_COUNT (8)
#define RAM_BLOCK_SIZE (1024)
static uint8_t* ram_page[RAM_BLOCK_COUNT];

static int fal_ram_init(void)
{
    memset(ram_page, 0, sizeof(uint8_t*)*RAM_BLOCK_COUNT);
    return 1;
}

static int fal_ram_read(long offset, uint8_t *buf, size_t size)
{
    uint32_t page = offset  >> 10;
    uint16_t page_offset = offset & (RAM_BLOCK_SIZE-1);

    if(ram_page[page]) {
      memcpy(buf, ram_page[page]+page_offset, size);
    } else {
      memset(buf, 0xff, size);
    }
    return size;
}

static int fal_ram_write(long offset, const uint8_t *buf, size_t size) 
{
    uint32_t page = offset  >> 10;
    uint16_t page_offset = offset & (RAM_BLOCK_SIZE-1);

    if(!ram_page[page]) {
      ram_page[page] = malloc(RAM_BLOCK_SIZE);
      if(ram_page[page]) {
        memset(ram_page[page], 0xff, RAM_BLOCK_SIZE);
      } else {
        return 0;
      }
    }
    memcpy(ram_page[page]+page_offset, buf, size);
    return size;
}

static int fal_ram_erase(long offset, size_t size)
{    
    uint32_t page = offset >> 10;

    if(ram_page[page]) {
      memset(ram_page[page], 0xff, RAM_BLOCK_SIZE);
    }

    return size;
}

const struct fal_flash_dev ram0 =
{
    .name       = "ram0",
    .addr       = 0,
    .len        = RAM_BLOCK_COUNT * RAM_BLOCK_SIZE,
    .blk_size   = RAM_BLOCK_SIZE,
    .ops        = {fal_ram_init, fal_ram_read, fal_ram_write, fal_ram_erase},
    .write_gran = 0 // not used
};
