/**
 * @file fal_ram_port.c
 * @author Thomas Hoof <thomas.hoof@gmx.de>
 * @date 2021-08-10
 * @copyright Ruuvi Innovations Ltd, License BSD-3-Clause.
 */

#include <string.h>
#include "fal.h"

#define RAM_BLOCK_COUNT (8)
#define RAM_BLOCK_SIZE (1024)
static uint8_t ram[RAM_BLOCK_COUNT * RAM_BLOCK_SIZE];

static int fal_ram_init(void)
{
    return 1;
}

static int fal_ram_read(long offset, uint8_t *buf, size_t size)
{
    memcpy(buf, ram+offset, size);
    return size;
}

static int fal_ram_write(long offset, const uint8_t *buf, size_t size) 
{
    memcpy(ram+offset, buf, size);
    return size;
}

static int fal_ram_erase(long offset, size_t size)
{    
    uint8_t content[RAM_BLOCK_SIZE];
    memset(content, 0xff, RAM_BLOCK_SIZE);

    return fal_ram_write(offset, content, size);
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
