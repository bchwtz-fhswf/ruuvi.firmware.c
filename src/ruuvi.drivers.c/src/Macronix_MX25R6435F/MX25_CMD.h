/*
 * COPYRIGHT (c) 2010-2016 MACRONIX INTERNATIONAL CO., LTD
 * SPI Flash Low Level Driver (LLD) Sample Code
 *
 * SPI interface command hex code, type definition and function prototype.
 *
 * $Id: MX25_CMD.h,v 1.23 2015/12/15 06:31:21 mxclldb1 Exp $
 */
#ifndef    __MX25_CMD_H__
#define    __MX25_CMD_H__

#include    "MX25_DEF.h"

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
    uint8    ModeReg;
    BOOL     ArrangeOpt;
};

typedef struct sFlashStatus FlashStatus;

/* Basic functions */
void CS_High();
void CS_Low();
void InsertDummyCycle( uint8 dummy_cycle );
void SendByte( uint8 byte_value, uint8 transfer_type );
uint8 GetByte( uint8 transfer_type );

/* Utility functions */
void Wait_Flash_WarmUp();
void Initial_Spi();
BOOL WaitFlashReady( uint32 ExpectTime );
BOOL WaitRYBYReady( uint32 ExpectTime );
BOOL IsFlashBusy( void );
BOOL IsFlashQIO( void );
BOOL IsFlash4Byte( void );
void SendFlashAddr( uint32 flash_address, uint8 io_mode, uint8 addr_mode );
uint8 GetDummyCycle( uint32 default_cycle );

/* Flash commands */
ReturnMsg CMD_RDID( uint32 *Identification );
ReturnMsg CMD_RES( uint8 *ElectricIdentification );
ReturnMsg CMD_REMS( uint16 *REMS_Identification, FlashStatus *fsptr );

ReturnMsg CMD_RDSR( uint8 *StatusReg );
#ifdef SUPPORT_WRSR_CR
   ReturnMsg CMD_WRSR( uint16 UpdateValue );
#else
   ReturnMsg CMD_WRSR( uint8 UpdateValue );
#endif
ReturnMsg CMD_RDSCUR( uint8 *SecurityReg );
ReturnMsg CMD_WRSCUR( void );
ReturnMsg CMD_RDCR( uint8 *ConfigReg );

ReturnMsg CMD_READ( uint32 flash_address, uint8 *target_address, uint32 byte_length  );
ReturnMsg CMD_2READ( uint32 flash_address, uint8 *target_address, uint32 byte_length );
ReturnMsg CMD_4READ( uint32 flash_address, uint8 *target_address, uint32 byte_length );
ReturnMsg CMD_FASTREAD( uint32 flash_address, uint8 *target_address, uint32 byte_length );
ReturnMsg CMD_DREAD( uint32 flash_address, uint8 *target_address, uint32 byte_length );
ReturnMsg CMD_QREAD( uint32 flash_address, uint8 *target_address, uint32 byte_length );
ReturnMsg CMD_RDSFDP( uint32 flash_address, uint8 *target_address, uint32 byte_length );

ReturnMsg CMD_WREN( void );
ReturnMsg CMD_WRDI( void );
ReturnMsg CMD_PP( uint32 flash_address, uint8 *source_address, uint32 byte_length );
ReturnMsg CMD_4PP( uint32 flash_address, uint8 *source_address, uint32 byte_length );

ReturnMsg CMD_SE( uint32 flash_address );
ReturnMsg CMD_BE32K( uint32 flash_address );
ReturnMsg CMD_BE( uint32 flash_address );
ReturnMsg CMD_CE( void );

ReturnMsg CMD_DP( void );
ReturnMsg CMD_ENSO( void );
ReturnMsg CMD_EXSO( void );
ReturnMsg CMD_SBL( uint8 burstconfig );

ReturnMsg CMD_RSTEN( void );
ReturnMsg CMD_RST( FlashStatus *fsptr );

ReturnMsg CMD_PGM_ERS_S( void );
ReturnMsg CMD_PGM_ERS_R( void );
ReturnMsg CMD_NOP( void );
#endif    /* __MX25_CMD_H__ */
