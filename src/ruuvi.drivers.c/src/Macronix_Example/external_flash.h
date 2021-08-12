/**
 ******************************************************************************
 * @file      ext_flash.h
 *            This header file provides external flash memory related APIs.
 *
 * @author    Glide Embedded Technology <www.glidemtech.com>
 * @date      7, August, 2019
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef EXTERNAL_FLASH_H
#define EXTERNAL_FLASH_H
#endif
///* Includes ------------------------------------------------------------------*/
#include <hal/nrf_gpio.h>
#include <stdint.h>
#include <string.h>



/*///System Information Define//////////////////////*/

#define    CLK_PERIOD             20     // unit: ns
#define    Min_Cycle_Per_Inst     12     // use 12T 8051
#define    One_Loop_Inst          8      // instruction count of one loop (estimate)


#define    FlashID          0xc22815
#define    ElectronicID     0x15
#define    RESID0           0xc215
#define    RESID1           0x15c2
#define    FlashSize        0x200000       // 2 MB
#define    CE_period        31250000       // tCE /  ( CLK_PERIOD * Min_Cycle_Per_Inst *One_Loop_Inst)
#define    tW               30000000       // 30ms
#define    tDP              10000          // 10us
#define    tBP              100000         // 100us
#define    tPP              10000000       // 10ms
#define    tSE              240000000      // 240ms
#define    tBE              3500000000     // 3.5s
#define    tBE32            3000000000     // 3s
#define    tPUW             10000000       // 10ms
#define    tWSR             1000000        // 1ms
// Flash information define
#define    WriteStatusRegCycleTime     tW / (CLK_PERIOD * Min_Cycle_Per_Inst * One_Loop_Inst)
#define    PageProgramCycleTime        tPP / (CLK_PERIOD * Min_Cycle_Per_Inst * One_Loop_Inst)
#define    SectorEraseCycleTime        tSE / (CLK_PERIOD * Min_Cycle_Per_Inst * One_Loop_Inst)
#define    BlockEraseCycleTime         tBE / (CLK_PERIOD * Min_Cycle_Per_Inst * One_Loop_Inst)
#define    ChipEraseCycleTime          CE_period
#define    FlashFullAccessTime         tPUW / (CLK_PERIOD * Min_Cycle_Per_Inst * One_Loop_Inst)

#ifdef tBP
#define    ByteProgramCycleTime        tBP / (CLK_PERIOD * Min_Cycle_Per_Inst * One_Loop_Inst)
#endif
#ifdef tWSR
#define    WriteSecuRegCycleTime       tWSR / (CLK_PERIOD * Min_Cycle_Per_Inst * One_Loop_Inst)
#endif
#ifdef tBE32
#define    BlockErase32KCycleTime      tBE32 / (CLK_PERIOD * Min_Cycle_Per_Inst * One_Loop_Inst)
#endif
#ifdef tWREAW
#define    WriteExtRegCycleTime        tWREAW / (CLK_PERIOD * Min_Cycle_Per_Inst * One_Loop_Inst)
#endif
#define    Block_Offset       0x10000     // 64K Block size
#define    Block32K_Offset    0x8000      // 32K Block size
#define    Sector_Offset      0x1000      // 4K Sector size
#define    Page_Offset        0x0100      // 256 Byte Page size
#define    Page32_Offset      0x0020      // 32 Byte Page size (some products have smaller page size)
#define    Block_Num          (FlashSize / Block_Offset)
// Flash control register mask define
// status register
#define    FLASH_WIP_MASK         0x01
#define  TRANS_LENGTH  16
#define  RANDOM_SEED   106
#define  FLASH_TARGET_ADDR      0x000000 // 0x008000 // 
/* Flash memory parameters */
#define FLASH_PAGESIZE          256                     /* 256 Bytes */         /**< External Flash - Page Size */
#define FLASH_SECTORSIZE        (16 * FLASH_PAGESIZE)	/* 16 Pages = 4KB */    /**< External Flash - Sector Size */
#define FLASH_BLOCKSIZE			(16 * FLASH_SECTORSIZE)	/* 16 Sectors = 64KB */ /**< External Flash - Block Size */
#define FLASH_SIZE              (8 * 128 * FLASH_BLOCKSIZE)	/* 128 Blocks = 8MB */  /**< External Flash - Total Memory Size */ 
#define FLASH_BLOCK32K			(32 * 1024)				/* 32KB Block */   
#define FLASH_PAGESIZE_OFFSET          0x000100



/*** MX25 series command hex code definition ***/
//ID comands
#define    FLASH_CMD_RDID      0x9F    //RDID (Read Identification)
#define    FLASH_CMD_RES       0xAB    //RES (Read Electronic ID)
#define    FLASH_CMD_REMS      0x90    //REMS (Read Electronic & Device ID)

//Register comands
#define    FLASH_CMD_WRSR      0x01    //WRSR (Write Status Register)
#define    FLASH_CMD_RDSR      0x05    //RDSR (Read Status Register)
#define    FLASH_CMD_WRSCUR    0x2F    //WRSCUR (Write Security Register)
#define    FLASH_CMD_RDSCUR    0x2B    //RDSCUR (Read Security Register)
#define    FLASH_CMD_RDCR      0x15    //RDCR (Read Configuration Register)

//READ comands
#define    FLASH_CMD_READ        0x03    //READ (1 x I/O)
#define    FLASH_CMD_2READ       0xBB    //2READ (2 x I/O)
#define    FLASH_CMD_4READ       0xEB    //4READ (4 x I/O)
#define    FLASH_CMD_FASTREAD    0x0B    //FAST READ (Fast read data)
#define    FLASH_CMD_DREAD       0x3B    //DREAD (1In/2 Out fast read)
#define    FLASH_CMD_QREAD       0x6B    //QREAD (1In/4 Out fast read)
#define    FLASH_CMD_RDSFDP      0x5A    //RDSFDP (Read SFDP)
#define    FLASH_CMD_READ_LENGHT 4

//Program comands
#define    FLASH_CMD_WREN     0x06    //WREN (Write Enable)
#define    FLASH_CMD_WRDI     0x04    //WRDI (Write Disable)
#define    FLASH_CMD_PP       0x02    //PP (page program)
#define    FLASH_CMD_4PP      0x38    //4PP (Quad page program)

//Erase comands
#define    FLASH_CMD_SE       0x20    //SE (Sector Erase)
#define    FLASH_CMD_BE32K    0x52    //BE32K (Block Erase 32kb)
#define    FLASH_CMD_BE       0xD8    //BE (Block Erase)
#define    FLASH_CMD_CE       0x60    //CE (Chip Erase) hex code: 60 or C7

//Mode setting comands
#define    FLASH_CMD_DP       0xB9    //DP (Deep Power Down)
#define    FLASH_CMD_ENSO     0xB1    //ENSO (Enter Secured OTP)
#define    FLASH_CMD_EXSO     0xC1    //EXSO  (Exit Secured OTP)
#ifdef SBL_CMD_0x77
#define    FLASH_CMD_SBL      0x77    //SBL (Set Burst Length) new: 0x77
#else
#define    FLASH_CMD_SBL      0xC0    //SBL (Set Burst Length) Old: 0xC0
#endif

//Reset comands
#define    FLASH_CMD_RSTEN     0x66    //RSTEN (Reset Enable)
#define    FLASH_CMD_RST       0x99    //RST (Reset Memory)

//Security comands
#ifdef LCR_CMD_0xDD_0xD5
#else
#endif

//Suspend/Resume comands
#define    FLASH_CMD_PGM_ERS_S    0xB0    //PGM/ERS Suspend (Suspends Program/Erase)
#define    FLASH_CMD_PGM_ERS_R    0x30    //PGM/ERS Erase (Resumes Program/Erase)
#define    FLASH_CMD_NOP          0x00    //NOP (No Operation)


#define  Error_inc(x)  x = x + 1;


// Flash control register mask define
// status register
#define    FLASH_WIP_MASK         0x01
#define    FLASH_LDSO_MASK        0x02
#define    FLASH_QE_MASK          0x40
// security register
#define    FLASH_OTPLOCK_MASK     0x03
#define    FLASH_4BYTE_MASK       0x04
#define    FLASH_WPSEL_MASK       0x80
// configuration reigster
#define    FLASH_DC_MASK          0x80
#define    FLASH_DC_2BIT_MASK     0xC0
#define    FLASH_DC_3BIT_MASK     0x07
// other
#define    BLOCK_PROTECT_MASK     0xff
#define    BLOCK_LOCK_MASK        0x01


#define MEM_SIZE_15KB   ( 4 * 1024 ) //15KB Data

 // Return Message
typedef enum {
    FlashOperationSuccess,
    FlashWriteRegFailed,
    FlashTimeOut,
    FlashIsBusy,
    FlashQuadNotEnable,
    FlashAddressInvalid
}ReturnMsg;




// Flash status structure define
struct sFlashStatus{
    /* Mode Register:
     * Bit  Description
     * -------------------------
     *  7   RYBY enable
     *  6   Reserved
     *  5   Reserved
     *  4   Reserved
     *  3   Reserved
     *  2   Reserved
     *  1   Parallel mode enable
     *  0   QPI mode enable
    */
    uint8_t    ModeReg;
    bool    ArrangeOpt;
};
typedef struct sFlashStatus FlashStatus;



extern uint8_t flash_read_write_test( void );
extern uint8_t ext_flash_init(void);
extern uint8_t FlashReadWrite_Test( void );
extern uint8_t flash_ID_test( uint8_t );
extern uint8_t ext_flash_read_id(void);
extern ReturnMsg cmd_rdcr( uint8_t * );
extern ReturnMsg cmd_rdsr( uint8_t * );
extern ReturnMsg cmd_wrdis( void);
extern ReturnMsg cmd_wren( void);
extern ReturnMsg cmd_rsten( void);
extern ReturnMsg cmd_rst( void);
extern ReturnMsg cmd_ce(void);
extern bool WaitFlashReady( uint32_t  );
extern bool IsFlashBusy( void );
extern ReturnMsg full_sector_erase(void);
extern void read_data_ext_flash(void);