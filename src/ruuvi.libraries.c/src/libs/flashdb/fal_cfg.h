/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-05-17     armink       the first version
 */

#ifndef _FAL_CFG_H_
#define _FAL_CFG_H_

#include "fal_ruuvi_flash_port.h"

#define FAL_PART_HAS_TABLE_CFG
#define RUUVI_FLASH_DEV_NAME             "ruuviflash0"

/* ===================== Flash device Configuration ========================= */
extern const struct fal_flash_dev ruuvi_flash0;

/* flash device table */
#define FAL_FLASH_DEV_TABLE                                          \
{                                                                    \
    &ruuvi_flash0,                                                   \
}
/* ====================== Partition Configuration ========================== */
#ifdef FAL_PART_HAS_TABLE_CFG
/* partition table */
/* Array of { FAL_PART_MAGIC_WORD, "Name", device, start, length, 0 } */
#define FAL_PART_TABLE                                                           \
{                                                                                \
    {FAL_PART_MAGIC_WORD, "fdb_kvdb1",  RUUVI_FLASH_DEV_NAME,                      0,                        2*FDB_RUUVI_BLOCK_SIZE, 0},  \
    {FAL_PART_MAGIC_WORD, "fdb_tsdb1",  RUUVI_FLASH_DEV_NAME, 2*FDB_RUUVI_BLOCK_SIZE, (FDB_RUUVI_BLOCK_COUNT-2)*FDB_RUUVI_BLOCK_SIZE, 0},  \
}
#endif /* FAL_PART_HAS_TABLE_CFG */

#endif /* _FAL_CFG_H_ */
