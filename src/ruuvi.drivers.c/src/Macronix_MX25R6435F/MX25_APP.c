/*
 * COPYRIGHT (c) 2010-2016 MACRONIX INTERNATIONAL CO., LTD
 * SPI Flash Low Level Driver (LLD) Sample Code
 *
 * Application program of SPI flash
 * This sample code provides a reference, not recommand for directing using.
 *
 * $Id: MX25_APP.c,v 1.4 2012/01/03 08:00:06 modelqa Exp $
 */

#include    <stdlib.h>
#include    "MX25_CMD.h"

#define  TRANS_LENGTH  16
#define  RANDOM_SEED   106
#define  FLASH_TARGET_ADDR  0x00000000

#define  Error_inc(x)  x = x + 1;

/* function prototype */
uint8  FlashID_Test( void );
uint8  FlashReadWrite_Test( void );

/*
 * Main Program
 */
void main()
{
    Initial_Spi();
    FlashID_Test();        // Simple test : flash ID
    FlashReadWrite_Test(); // Simple test : flash read / write
}

/*
 * Simple flash ID test
 */
uint8 FlashID_Test( void )
{
    uint32  flash_id = 0;
    uint16  error_cnt = 0;
    uint16  rems_id;
    uint8   electric_id = 0;
    FlashStatus  flash_state = {0};
    ReturnMsg  msg;

    /* Read flash device id */
    msg =  CMD_RDID( &flash_id );
    if( msg != (ReturnMsg)FlashOperationSuccess )
        return FALSE;

    msg = CMD_RES( &electric_id );
    if( msg != (ReturnMsg)FlashOperationSuccess )
        return FALSE;

    /* Decide rems_id order. 0: { manufacturer id, device id }
                             1: { device id,  manufacturer id } */
    flash_state.ArrangeOpt = 0;

    msg = CMD_REMS( &rems_id, &flash_state );
    if( msg != (ReturnMsg)FlashOperationSuccess )
        return FALSE;

    /* Compare to expected value */
    if( flash_id != FlashID )
        Error_inc( error_cnt );

    if( electric_id != ElectronicID )
        Error_inc( error_cnt );

    if( flash_state.ArrangeOpt )
    {
        if( rems_id != RESID1 )
           Error_inc( error_cnt );
    }else
    {
        if( rems_id != RESID0 )
           Error_inc( error_cnt );
    }

    if( error_cnt != 0 )
        return FALSE;
    else
        return TRUE;
}
/*
 * Simple flash read/write test
 */
uint8 FlashReadWrite_Test( void )
{
    ReturnMsg  message= 0;
    FlashStatus  flash_state = {0};

    uint32  flash_addr;
    uint32  trans_len = 0;
    uint16  i=0, error_cnt = 0;
    uint16  seed = 0;
    uint8   st_reg = 0;
    uint8   memory_addr[TRANS_LENGTH] = {0};
    uint8   memory_addr_cmp[TRANS_LENGTH] = {0};

    /* Assign initial condition */
    flash_addr = FLASH_TARGET_ADDR;
    trans_len = TRANS_LENGTH;
    seed = RANDOM_SEED;

    /* Prepare data to transfer */
    srand( seed );
    for( i=0; i< trans_len; i=i+1 ){
        memory_addr[i] = rand()%256;   // generate random byte data
    }

    /* Erase 4K sector of flash memory
       Note: It needs to erase dirty sector before program */
    CMD_SE( flash_addr );

    /* Program data to flash memory */
    CMD_PP( flash_addr, memory_addr, trans_len );

    /* Read flash memory data to memory buffer */
    CMD_READ( flash_addr, memory_addr_cmp, trans_len );

    /* Compare original data and flash data */
    for( i=0; i < (trans_len); i=i+1 )
    {
        if( memory_addr[i] != memory_addr_cmp[i] )
            Error_inc( error_cnt );
    }

    /* Erase 4K sector of flash memory */
    CMD_SE( flash_addr );

    if( error_cnt != 0 )
        return FALSE;
    else
        return TRUE;

}


