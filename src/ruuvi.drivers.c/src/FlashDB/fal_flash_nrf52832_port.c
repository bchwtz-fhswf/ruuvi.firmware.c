/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-01-26     armink       the first version
 */

#include <fal.h>
#include <sfud.h>
#include <ruuvi_task_flash.h>

#ifdef FAL_USING_SFUD_PORT
#ifdef RT_USING_SFUD
#include <spi_flash_sfud.h>
#endif

#ifndef FAL_USING_NOR_FLASH_DEV_NAME
#define FAL_USING_NOR_FLASH_DEV_NAME             "nrf52832_flash"
#endif

static int init(void);
static int read(long offset, uint8_t *buf, size_t size);
static int write(long offset, const uint8_t *buf, size_t size);
static int erase(long offset, size_t size);

static sfud_flash_t sfud_dev = NULL;
struct fal_flash_dev internal_flash =
{
    .name       = FAL_USING_NOR_FLASH_DEV_NAME,
    .addr       = 0,
    .len        = RT_FLASH_RINGBUFFER_MAXSIZE*4073,
    .blk_size   = 4073,
    .ops        = {read, write, erase},
    .write_gran = 1
};

/* static int init(void)
{

#ifdef RT_USING_SFUD
    sfud_dev = rt_sfud_flash_find_by_dev_name(FAL_USING_NOR_FLASH_DEV_NAME);
#else
    extern sfud_flash sfud_internal_flash;
    sfud_dev = &sfud_internal_flash;
#endif

    if (NULL == sfud_dev)
    {
        return -1;
    }

    internal_flash.blk_size = sfud_dev->chip.erase_gran;
    internal_flash.len = sfud_dev->chip.capacity;

    return 0;
}*/

static int read(long offset, uint8_t *buf, size_t size)
{

}

static int write(long offset, const uint8_t *buf, size_t size)
{
rd_status_t rt_flash_store (const uint16_t file_id, const uint16_t record_id,
                            const void * const message, size);
}

static int erase(long offset, size_t size)
{

}
#endif /* FAL_USING_SFUD_PORT */

