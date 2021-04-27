#ifndef DPS310_REG_H
#define DPS310_REG_H

/**
 * @addtogroup DPS310 DPS310 driver
 *
 */
/** @{ */
/**
 * @file dps310_reg.h
 * @author Otso Jousimaa <otso@ojousima.net>
 * @date 2020-11-25
 * @copyright Ruuvi Innovations, License MIT
 *
 */

#define DPS310_PRES_VAL_REG       (0x00U)
#define DPS310_PRES_VAL_LEN       (0x03U)
#define DPS310_FIFO_VAL_REG       (DPS310_PRES_VAL_REG)
#define DPS310_FIFO_VAL_LEN       (DPS310_PRES_VAL_LEN)
#define DPS310_FIFO_VAL_EOF_B0    (0x80U)
#define DPS310_FIFO_VAL_EOF_B1    (0x00U)
#define DPS310_FIFO_VAL_EOF_B2    (0x00U)
#define DPS310_TEMP_VAL_REG       (0x03U)
#define DPS310_TEMP_VAL_LEN       (0x03U)
#define DPS310_PRES_CFG_REG       (0x06U)
#define DPS310_PRES_CFG_WMASK     (0x7FU)
#define DPS310_TEMP_CFG_REG       (0x07U)
#define DPS310_TEMP_CFG_WMASK     (0xFFU)
#define DPS310_MR_SHIFT           (4U)
#define DPS310_MR_MASK            (0x07U << DPS310_MR_SHIFT)
#define DPS310_MR_VAL_1           (0x00U << DPS310_MR_SHIFT)
#define DPS310_MR_VAL_2           (0x01U << DPS310_MR_SHIFT)
#define DPS310_MR_VAL_4           (0x02U << DPS310_MR_SHIFT)
#define DPS310_MR_VAL_8           (0x03U << DPS310_MR_SHIFT)
#define DPS310_MR_VAL_16          (0x04U << DPS310_MR_SHIFT)
#define DPS310_MR_VAL_32          (0x05U << DPS310_MR_SHIFT)
#define DPS310_MR_VAL_64          (0x06U << DPS310_MR_SHIFT)
#define DPS310_MR_VAL_128         (0x07U << DPS310_MR_SHIFT)
#define DPS310_OS_MASK            (0x07U)
#define DPS310_OS_VAL_1           (0x00U)
#define DPS310_OS_VAL_2           (0x01U)
#define DPS310_OS_VAL_4           (0x02U)
#define DPS310_OS_VAL_8           (0x03U)
#define DPS310_OS_VAL_16          (0x04U)
#define DPS310_OS_VAL_32          (0x05U)
#define DPS310_OS_VAL_64          (0x06U)
#define DPS310_OS_VAL_128         (0x07U)
#define DPS310_MEAS_CFG_REG       (0x08U)
#define DPS310_MEAS_CFG_WMASK     (0x07U)
#define DPS310_MEAS_CFG_BOOT_VAL  (0xC0U)
#define DPS310_MODE_STANDBY_VAL   (0x00U)
#define DPS310_MODE_ONE_PRES_VAL  (0x01U)
#define DPS310_MODE_ONE_TEMP_VAL  (0x02U)
#define DPS310_MODE_CONT_PRES_VAL (0x05U)
#define DPS310_MODE_CONT_TEMP_VAL (0x06U)
#define DPS310_MODE_CONT_BOTH_VAL (0x07U)
#define DPS310_MODE_MASK          (0x07U)
#define DPS310_CFG_REG            (0x09U)
#define DPS310_CFG_WMASK          (0xFFU)
#define DPS310_CFG_PRESSH_MASK    (0x04U)
#define DPS310_CFG_TEMPSH_MASK    (0x08U)
#define DPS310_RST_CFG_REG        (0x0CU)
#define DPS310_RST_CFG_WMASK      (0x8FU)
#define DPS310_SOFT_RST_VAL       (0x09U)
#define DPS310_SOFT_RST_MASK      (0x0FU)
#define DPS310_PROD_ID_REG        (0x0DU)
#define DPS310_PROD_ID_BOOT_VAL   (0x10U)
#define DPS310_PROD_ID_REV_MASK   (0xF0U)
#define DPS310_PROD_ID_REV_SHIFT  (4U)
#define DPS310_PROD_ID_MASK       (0x0FU)

#define DPS310_COEF_START_REG     (0x10U)
#define DPS310_COEF_REG_LEN       (0x12U)
#define DPS310_COEF_C0_OFFSET     (0U)
#define DPS310_COEF_C0_LEN_BITS   (12U)
#define DPS310_COEF_C0_SHIFT      (4U)
#define DPS310_COEF_C1_OFFSET     (1U)
#define DPS310_COEF_C1_LEN_BITS   (12U)
#define DPS310_COEF_C00_OFFSET    (3U)
#define DPS310_COEF_C00_LEN_BITS  (20U)
#define DPS310_COEF_C00_SHIFT     (4U)
#define DPS310_COEF_C10_OFFSET    (5U)
#define DPS310_COEF_C10_LEN_BITS  (20U)
#define DPS310_COEF_C01_OFFSET    (8U)
#define DPS310_COEF_C01_LEN_BITS  (16U)
#define DPS310_COEF_C11_OFFSET    (10U)
#define DPS310_COEF_C11_LEN_BITS  (16U)
#define DPS310_COEF_C20_OFFSET    (12U)
#define DPS310_COEF_C20_LEN_BITS  (16U)
#define DPS310_COEF_C21_OFFSET    (14U)
#define DPS310_COEF_C21_LEN_BITS  (16U)
#define DPS310_COEF_C30_OFFSET    (16U)
#define DPS310_COEF_C30_LEN_BITS  (16U)

#define DPS310_COEF_SRC_REG       (0x28U)
#define DPS310_COEF_SRC_MASK      (0x80U)


#define DPS310_RESERVED_START          (0x22U)
#define DPS310_RESERVED_END            (0x27U)

#define DPS310_REGISTER_TABLE_SIZE     (0x29U)

#define DPS310_EFUSE_0_REG             (0x0EU)
#define DPS310_EFUSE_0_VAL             (0xA5U)
#define DPS310_EFUSE_1_REG             (0x0FU)
#define DPS310_EFUSE_1_VAL             (0x96U)
#define DPS310_EFUSE_2_REG             (0x62U)
#define DPS310_EFUSE_2_VAL             (0x02U)

#define DPS310_C0_WEIGHT               (0.5F)
#define DPS310_OS_1_SF                 (524288U)
#define DPS310_OS_2_SF                 (1572864U)
#define DPS310_OS_4_SF                 (3670016U)
#define DPS310_OS_8_SF                 (7864320U)
#define DPS310_OS_16_SF                (253952U)
#define DPS310_OS_32_SF                (516096U)
#define DPS310_OS_64_SF                (1040384U)
#define DPS310_OS_128_SF               (2088960U)
/** @} */

#endif
