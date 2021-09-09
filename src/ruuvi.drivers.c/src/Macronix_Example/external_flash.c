///**
// ******************************************************************************
// * @file      ext_flash.c
// *            This source file provides external flash memory related functionalities.
// *
// * @author    Glide Embedded Technology <www.glidemtech.com>
// * @date       7, August, 2019
// ******************************************************************************
// */
//
///* Includes ------------------------------------------------------------------*/
///* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdint.h>
//
#include "external_flash.h"
#include <hal/nrf_gpio.h>
#include <hal/nrf_spi.h>
#include "nrf_drv_spi.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "nrf_delay.h"





uint8_t print = 1;


#define SPI_INSTANCE  0 /**< SPI instance index. */
static const nrf_drv_spi_t spi = NRF_DRV_SPI_INSTANCE(SPI_INSTANCE);

#define WAIT_FOR_PERIPH() do { \
        while (!m_finished) {} \
        m_finished = false;    \
    } while (0)

static volatile bool m_finished = false;


static uint8_t m_buffer_tx[256];
static uint8_t m_buffer_rx[256];

//static uint8_t m_data_send[256];
static uint8_t m_data_receive[256];

#define TEST_STRING  "Z" //"Nordic"
static uint8_t       m_tx_buf[] = TEST_STRING;           /**< TX buffer. */
static uint8_t       m_rx_buf[sizeof(TEST_STRING) + 1];    /**< RX buffer. */
static const uint8_t m_length = sizeof(m_tx_buf); 

static uint8_t m_buffer_tx[256];
static uint8_t m_buffer_rx[256];
//int16_t pcm_data_buffer[MEM_SIZE_15KB] = {0};
static uint16_t pcm_data_buffer[MEM_SIZE_15KB];
//static uint8_t m_data_send[256];
static uint8_t m_data_receive[256];

static uint8_t m_data_send[225] = {[0 ... 224] = 0xcd};
uint8_t StatusReg;
uint8_t ConfigReg;
uint8_t SecurityReg;

/**
 * @brief SPI user event handler.
 * @param event
 */
void spi_event_handler(nrf_drv_spi_evt_t const * p_event,
                       void *                    p_context)
{
    m_finished = true;
    uint16_t i ;
    //printf("\n\rTransfer completed.");
    if (m_buffer_rx[0] != 0)
    {
//        printf(" Received:");
        for(i=0;i<8;i++)
        {
//          printf("m_buffer_rx[%d] = %x ",i,m_buffer_rx[i]);
        }
        NRF_LOG_HEXDUMP_INFO(m_buffer_rx, strlen((const char *)m_buffer_rx));
    }
   // nrf_gpio_pin_set(SPI_SS_PIN);
}
void cs_low(void)
{
//  nrf_gpio_pin_set(SPI_SS_PIN);
  nrf_gpio_pin_clear(SPI_SS_PIN);
}


void cs_high(void)
{
//  nrf_gpio_pin_clear(SPI_SS_PIN);
   nrf_gpio_pin_set(SPI_SS_PIN);
}



/*
 * Reset setting Command
 */

/*
 * Function:       CMD_RSTEN
 * Arguments:      None.
 * Description:    Enable RST command
 * Return Message: FlashOperationSuccess
 */
ReturnMsg cmd_rsten( void )
{
    // Chip select go low to start a flash command
    cs_low();

    // Write RSTEN command
   
    uint8_t instruction = FLASH_CMD_RSTEN;
    m_buffer_tx[0] = instruction;
    
   nrf_drv_spi_transfer(&spi,(uint8_t const *)m_buffer_tx,1,m_buffer_rx,1);

    // Chip select go high to end a flash command
    cs_high();

    return FlashOperationSuccess;
}

/*
 * Function:       CMD_RST
 * Arguments:      fsptr, pointer of flash status structure
 * Description:    The RST instruction is used as a system (software) reset that
 *                 puts the device in normal operating Ready mode.
 * Return Message: FlashOperationSuccess
 */
ReturnMsg cmd_rst( void )
{
    // Chip select go low to start a flash command
    cs_low();

    // Write RST command = 0x99
    
    uint8_t instruction = FLASH_CMD_RST;
    m_buffer_tx[0] = instruction;
    
   nrf_drv_spi_transfer(&spi,(uint8_t const *)m_buffer_tx,1,m_buffer_rx,1);

    // Chip select go high to end a flash command
    cs_high();

 
    return FlashOperationSuccess;
}



/*
 * Function:       CMD_WRSR
 * Arguments:      UpdateValue, 8/16 bit status register value to updata
 * Description:    The WRSR instruction is for changing the values of
 *                 Status Register Bits (and configuration register)
 * Return Message: FlashIsBusy, FlashTimeOut, FlashOperationSuccess
 */

ReturnMsg cmd_wrsr( uint8_t UpdateValue )

{
    // Check flash is busy or not
    if( IsFlashBusy() )    return FlashIsBusy;

    // Setting Write Enable Latch bit
    uint8_t err_code;
   err_code = cmd_wren();

    // Chip select go low to start a flash command
//    cs_low();

    // Send command and update value

    uint8_t instruction[9] = {0};
    instruction[0] = FLASH_CMD_WRSR;
    nrf_drv_spi_transfer(&spi,(uint8_t const *)instruction,1,m_buffer_rx,3); 
    nrf_delay_ms(2);
    printf("UPDATE VALUE  = %d",UpdateValue);
    instruction[1]=UpdateValue;
//    memcpy(instruction[1],UpdateValue,8);
    nrf_drv_spi_transfer(&spi,(uint8_t const *)instruction[1],2,m_buffer_rx,4); 

//#ifdef SUPPORT_WRSR_CR
//    SendByte( UpdateValue >> 8, SIO );    // write configuration register
//#endif

    // Chip select go high to end a flash command
    cs_high();


    if( WaitFlashReady( WriteStatusRegCycleTime ) )
        return FlashOperationSuccess;
    else
        return FlashTimeOut;

}


//
//ReturnMsg cmd_wrsr( uint8_t UpdateValue )
//
//{
//    // Check flash is busy or not
//    if( IsFlashBusy() )    return FlashIsBusy;
//
//    // Setting Write Enable Latch bit
//    uint8_t err_code;
//    uint8_t read_value;
//        nrf_gpio_pin_clear(SPI_WP_PIN);
//   err_code = cmd_wren();
//
//    // Chip select go low to start a flash command
////    cs_low();
//
//    // Send command and update value
//   err_code =  cmd_rdsr(read_value);
//   printf("rdsr valu = %d \n",read_value);
//   if((read_value & 2)== 1)
//  {
//     uint8_t instruction[9] = {0};
//    instruction[0] = FLASH_CMD_WRSR;
//    nrf_drv_spi_transfer(&spi,(uint8_t const *)instruction,1,m_buffer_rx,3); 
//    nrf_delay_ms(2);
//    printf("UPDATE VALUE  = %d",UpdateValue);
//    instruction[1]=UpdateValue;
////    memcpy(instruction[1],UpdateValue,8);
//    nrf_drv_spi_transfer(&spi,(uint8_t const *)instruction[1],2,m_buffer_rx,4); 
//
//    err_code =  cmd_rdsr(read_value);
//   printf("rdsr valu = %d \n",read_value);
//   if((read_value ^ 1)==1)
//   {
//      printf("wep is zero \n");
//    
//   }
//
//  }
//
//
////    uint8_t instruction[9] = {0};
////    instruction[0] = FLASH_CMD_WRSR;
////    nrf_drv_spi_transfer(&spi,(uint8_t const *)instruction,1,m_buffer_rx,3); 
////    nrf_delay_ms(2);
////    printf("UPDATE VALUE  = %d",UpdateValue);
////    instruction[1]=UpdateValue;
//////    memcpy(instruction[1],UpdateValue,8);
////    nrf_drv_spi_transfer(&spi,(uint8_t const *)instruction[1],2,m_buffer_rx,4); 
//
////#ifdef SUPPORT_WRSR_CR
////    SendByte( UpdateValue >> 8, SIO );    // write configuration register
////#endif
//
//    // Chip select go high to end a flash command
//    cs_high();
//
//
//    if( WaitFlashReady( WriteStatusRegCycleTime ) )
//        return FlashOperationSuccess;
//    else
//        return FlashTimeOut;
//
//}


/*
 * Function:       CMD_RDSCUR
 * Arguments:      SecurityReg, 8 bit buffer to store security register value
 * Description:    The RDSCUR instruction is for reading the value of
 *                 Security Register bits.
 * Return Message: FlashOperationSuccess
 */
ReturnMsg cmd_rdscur( uint8_t *SecurityReg )
{
    uint8_t  gDataBuffer;

    // Chip select go low to start a flash command
    cs_low();

    //Send command
    
    uint8_t instruction = FLASH_CMD_RDSCUR;
    nrf_drv_spi_transfer(&spi,(uint8_t const *)instruction,1,gDataBuffer,3); 

    // Chip select go high to end a flash command
    cs_high();

    *SecurityReg = gDataBuffer;

    return FlashOperationSuccess;

}

/*
 * Function:       CMD_WRSCUR
 * Arguments:      None.
 * Description:    The WRSCUR instruction is for changing the values of
 *                 Security Register Bits.
 * Return Message: FlashIsBusy, FlashOperationSuccess, FlashWriteRegFailed,
 *                 FlashTimeOut
 */
ReturnMsg cmd_wrscur( void )
{
    uint8_t  gDataBuffer;

    // Check flash is busy or not
    if( IsFlashBusy() )    return FlashIsBusy;

    // Setting Write Enable Latch bit
    cmd_wren();

    // Chip select go low to start a flash command
    cs_low();

    // Write WRSCUR command
    uint8_t instruction = FLASH_CMD_WRSCUR;
    nrf_drv_spi_transfer(&spi,(uint8_t const *)instruction,1,gDataBuffer,3); 

    // Chip select go high to end a flash command
    cs_high();

    if( WaitFlashReady( WriteSecuRegCycleTime ) ){

        cmd_rdscur( &gDataBuffer );

        // Check security register LDSO bit
        if( (gDataBuffer & FLASH_LDSO_MASK) == FLASH_LDSO_MASK )
                return FlashOperationSuccess;
        else
                return FlashWriteRegFailed;
    }
    else
        return FlashTimeOut;

}


/*
 * Function:       CMD_RDID
 * Arguments:      Identification, 32 bit buffer to store id
 * Description:    The RDID instruction is to read the manufacturer ID
 *                 of 1-byte and followed by Device ID of 2-byte.
 * Return Message: FlashOperationSuccess
 */
ReturnMsg cmd_rdid( uint32_t *Identification )
{
    uint32_t temp;
    uint8_t  gDataBuffer[3];

    // Chip select go low to start a flash command
    cs_low();

    // Send command
//    SendByte( FLASH_CMD_RDID, SIO );
    uint8_t instruction = FLASH_CMD_RDID;
    nrf_drv_spi_transfer(&spi,(uint8_t const *)instruction,1,gDataBuffer,3); 

   
   

    // Chip select go high to end a command
    cs_high();

    // Store identification
    temp =  gDataBuffer[0];
    temp =  (temp << 8) | gDataBuffer[1];
    *Identification =  (temp << 8) | gDataBuffer[2];
    printf("rdid = %x  %x",gDataBuffer [0],gDataBuffer [1]);

    return FlashOperationSuccess;
}

/*
 * Function:       CMD_RES
 * Arguments:      ElectricIdentification, 8 bit buffer to store electric id
 * Description:    The RES instruction is to read the Device
 *                 electric identification of 1-byte.
 * Return Message: FlashOperationSuccess
 */
ReturnMsg cmd_res( uint8_t *ElectricIdentification )
{

    printf("cmd_res \n");
    // Chip select go low to start a flash command
    cs_low();

    // Send flash command and insert dummy cycle
     uint8_t instruction[4];
    instruction[0]= FLASH_CMD_RES;
    instruction[1]= 0;
    instruction[2]=0;
    instruction[3]=0;
    nrf_drv_spi_transfer(&spi,(uint8_t const *)instruction,4,m_buffer_rx,5); 
    // Get electric identification
    *ElectricIdentification = m_buffer_rx[4];
    printf(" eid = %x\n",m_buffer_rx[4]);
    // Chip select go high to end a flash command
  cs_high();

    return FlashOperationSuccess;
}

/*
 * Function:       CMD_REMS
 * Arguments:      REMS_Identification, 16 bit buffer to store id
 *                 fsptr, pointer of flash status structure
 * Description:    The REMS instruction is to read the Device
 *                 manufacturer ID and electric ID of 1-byte.
 * Return Message: FlashOperationSuccess
 */
ReturnMsg cmd_rems( uint16_t *REMS_Identification, FlashStatus *fsptr )
{
    uint8_t  gDataBuffer[2];

    // Chip select go low to start a flash command
    cs_low();

    // Send flash command and insert dummy cycle ( if need )
    // ArrangeOpt = 0x00 will output the manufacturer's ID first
    //            = 0x01 will output electric ID first
//    SendByte( FLASH_CMD_REMS, SIO );
//    InsertDummyCycle( 16 );
//    SendByte( fsptr->ArrangeOpt, SIO );
    uint8_t instruction[4];
    instruction[0]= FLASH_CMD_REMS;
    instruction[1]= 0;
    instruction[2]=0;
     instruction[3]=0x00;
    nrf_drv_spi_transfer(&spi,(uint8_t const *)instruction,4,m_buffer_rx,6); 
    // Get ID
    gDataBuffer[0] = m_buffer_rx[2];//GetByte( SIO );
    gDataBuffer[1] = m_buffer_rx[3];//GetByte( SIO );

    // Store identification informaion
    *REMS_Identification = (gDataBuffer[0] << 8) | gDataBuffer[1];

    // Chip select go high to end a flash command
    cs_high();

    return FlashOperationSuccess;
}

void cmd_read( uint32_t flash_address, uint16_t *target_address, uint32_t byte_length )
{
    uint32_t index;
    
    // Check flash address
    if( flash_address > FlashSize ) 
      return FlashAddressInvalid;
//    cmd_wrdis();
//    nrf_delay_ms(100);

    // Chip select go low to start a flash command
    cs_low();
// nrf_delay_ms(50);
    // Write READ command and address
    memset(m_buffer_tx,0x00,sizeof(m_buffer_tx));
    uint8_t instruction;
    instruction = FLASH_CMD_READ;
    m_buffer_tx[0]= instruction;
    m_buffer_tx[1] = flash_address >> 16;
    m_buffer_tx[2] = flash_address >> 8;
    m_buffer_tx[3] = flash_address;
//    nrf_drv_spi_transfer(&spi,(uint8_t const *)m_buffer_tx,FLASH_CMD_READ_LENGHT,m_data_receive,FLASH_CMD_READ_LENGHT+16); 
    nrf_drv_spi_transfer(&spi,(uint8_t const *)m_buffer_tx,FLASH_CMD_READ_LENGHT,m_data_receive,FLASH_CMD_READ_LENGHT+byte_length); 
//    for( index=0; index < 4; index++ )
//    {
//      printf("m_buffer_tx[%d] = %.02x \n",index,m_buffer_tx[index]);
//      nrf_delay_ms(10);
//    }
   
//    for( index=0; index < 20; index++ )
//    {
//      printf("m_data_receive[%d] = %.02x \n",index,m_data_receive[index]);
//      nrf_delay_ms(10);
//    }

    // Chip select go high to end a flash command
   nrf_delay_ms(50);
   cs_high();

    return true;
}


void read_data_ext_flash(void)
{
    uint8_t i;
    static uint32_t flash_address = FLASH_TARGET_ADDR;
    static counter=0;
    for(i=0;i<16;i++)
//    for(i=0;i<2;i++)
    {
//      for(j=0;j<256;j=j+2)
      {
        cmd_read(flash_address,pcm_data_buffer,225);
         uint16_t index;
         nrf_delay_ms(5);
      //  for( index=0; index < 102400; index++ )
         for( index=0; index < 225; index++ )
          {
              // Read data one byte at a time
        
              printf("\r\n%2.2X%2.2X",pcm_data_buffer[index],pcm_data_buffer[index+1]);
              index = index+1;
       
          }
//        nrf_delay_ms(10);

      }
      flash_address = flash_address + 0x000100;
//      counter ++;
    }


//   uint32_t flash_address = FLASH_TARGET_ADDR;
////  cmd_read(flash_address,pcm_data_buffer,102400);
//  cmd_read(flash_address,pcm_data_buffer,3584); //256*16  3584 bytes


//  for( index=0; index < 102400; index++ )
//   for( index=0; index < MEM_SIZE_15KB; index++ )
//    {
//        // Read data one byte at a time
//        
//        printf("\r\n%2.2X%2.2X",pcm_data_buffer[index],pcm_data_buffer[index+1]);
//        index = index+1;
//       
//    }
//
//    for( index=0; index < MEM_SIZE_15KB; index++ )
////    {
////        // Read data one byte at a time
////        
//        printf("\r\n%2.2X%",pcm_data_buffer[index]);
//        index = index+1;
//       
//    }


}




/*
 * Function:       Wait_Flash_WarmUp
 * Arguments:      None.
 * Description:    Wait some time until flash read / write enable.
 * Return Message: None.
 */
void wait_flash_warm_up()
{
    uint32_t time_cnt = FlashFullAccessTime;
    while( time_cnt > 0 )
    {
        time_cnt--;
    }
}
uint8_t flash_ID_test( uint8_t id )
{

  uint8_t instruction[8] = {0};

  uint8_t id_read = id;
  switch (id_read)  
  {
            case 1:
                
                instruction[0] = FLASH_CMD_RES ;
                instruction[1]= 0x00;
                instruction[2] = 0x00;
                instruction[3]= 0x00;
                cs_low();
                nrf_drv_spi_transfer(&spi,(uint8_t const *)instruction,4,m_buffer_rx,5); 
                nrf_delay_ms(1);
                printf("\rValue is 1:");
                 printf("%02x \n",m_buffer_rx[4]);
                cs_high();
                break;
            case 2:
                
                instruction[0] = FLASH_CMD_REMS ;
                instruction[1]= 0x01;
                instruction[2] = 0x02;
                instruction[3]= 0x00;
                printf("\rValue is 2:");
                memset(m_buffer_rx,0x00,sizeof(m_buffer_rx));
                nrf_drv_spi_transfer(&spi,(uint8_t const *)instruction,4,m_buffer_rx,6); 
                nrf_delay_ms(2);
                printf("%02x,%02x,%02x,%02x,%02x,%02x\n",m_buffer_rx[0],m_buffer_rx[1],m_buffer_rx[2],m_buffer_rx[3],m_buffer_rx[4],m_buffer_rx[5]);
//                printf("%d,%d,%d,%d,%d,%d\n",m_buffer_rx[0],m_buffer_rx[1],m_buffer_rx[2],m_buffer_rx[3],m_buffer_rx[4],m_buffer_rx[5]);
                break;
            case 3:               
                m_buffer_tx[0] = FLASH_CMD_RDID;
                cs_low();
                nrf_drv_spi_transfer(&spi,(uint8_t const *)m_buffer_tx,1,m_buffer_rx,4); 
                nrf_delay_ms(2);
                printf("\rValue is 3:");
                printf("%02x,%02x,%02x\n",m_buffer_rx[1],m_buffer_rx[2],m_buffer_rx[3]);
//                  printf("%d,%d,%d \n",m_buffer_rx[1],m_buffer_rx[2],m_buffer_rx[3]);
                cs_high();
                break;
            default:
                printf("Out of range");
                break;

  }

   return true;
}


ReturnMsg cmd_rdsr( uint8_t *StatusReg )
{
    uint8_t  gDataBuffer;

    // Chip select go low to start a flash command
    cs_low();

    // Send command

    nrf_drv_spi_transfer(&spi,FLASH_CMD_RDSR,1,gDataBuffer,1); 
    // Chip select go high to end a flash command
    cs_high();

    *StatusReg = gDataBuffer;
//     printf("cmd_rdsr =  %d \n",gDataBuffer);

    return FlashOperationSuccess;
}

ReturnMsg cmd_rdcr( uint8_t *StatusReg )
{
    uint8_t  gDataBuffer;

    // Chip select go low to start a flash command
     cs_low();

    // Send command
//    SendByte( FLASH_CMD_RDSR, SIO );
//    gDataBuffer = GetByte( SIO );
    nrf_drv_spi_transfer(&spi,FLASH_CMD_RDCR,1,gDataBuffer,1); 
    // Chip select go high to end a flash command
    cs_high();

    *StatusReg = gDataBuffer;
//    printf("status register = %x \n",StatusReg);

    return FlashOperationSuccess;
}


bool IsFlashBusy( void )
{
    uint8_t  gDataBuffer;

    cmd_rdsr( &gDataBuffer );
    
    if( (gDataBuffer & FLASH_WIP_MASK)  == FLASH_WIP_MASK )
        return true;
    else
        return false;
}

bool WaitFlashReady( uint32_t ExpectTime )
{

    uint32_t temp = 0;
    while( IsFlashBusy() )
    {
        if( temp > ExpectTime )
        {
            return false;
        }
        temp = temp + 1;
    }
       return true;
}

ReturnMsg cmd_wren( void )
{
//    // Chip select go low to start a flash command
//    cs_low();
    memset(m_buffer_tx,0x00,sizeof(m_buffer_tx));
    // Write Enable command = 0x06, Setting Write Enable Latch Bit
    uint8_t instruction = FLASH_CMD_WREN;
    m_buffer_tx[0] = instruction;
    
   nrf_drv_spi_transfer(&spi,(uint8_t const *)m_buffer_tx,1,m_buffer_rx,0);
    // Chip select go high to end a flash command
//    cs_high();

    return FlashOperationSuccess;
}



ReturnMsg cmd_wrdis( void )
{
    // Chip select go low to start a flash command
    cs_low();

    // Write Enable command = 0x06, Setting Write Enable Latch Bit
    uint8_t instruction = FLASH_CMD_WRDI;
    m_buffer_tx[0] = instruction;
    
   nrf_drv_spi_transfer(&spi,(uint8_t const *)m_buffer_tx,1,m_buffer_rx,1);
    // Chip select go high to end a flash command
    cs_high();

    return FlashOperationSuccess;
}

ReturnMsg cmd_pp( uint32_t flash_address, uint16_t *source_address, uint32_t byte_length )
{
//    printf("cmd_pp \n");
    uint32_t index;
    // Check flash address
    if( flash_address > FLASH_SIZE ) return FlashAddressInvalid;
    //
    //    // Check flash is busy or not
//    if( IsFlashBusy() )    return FlashIsBusy;

   
    nrf_delay_ms(10);
    

    // Chip select go low to start a flash command
    cs_low();

   // Setting Write Enable Latch bit
    cmd_wren();
    nrf_delay_ms(3);

    // Write Page Program command
    uint8_t len = 4;
    m_buffer_tx[0]=FLASH_CMD_PP;
//    memcpy(m_buffer_tx,instruction,4);
    //    nrf_drv_spi_transfer(&spi,instruction,len,m_buffer_rx,len+1); 
    memcpy(m_buffer_tx[4],flash_address >> 16,1);

    m_buffer_tx[1] = flash_address >> 16;
    m_buffer_tx[2] = flash_address >> 8;
    m_buffer_tx[3] = flash_address;

    for( index=4; index < byte_length; index++ )
    {
       m_buffer_tx[index] = (uint8_t) source_address[index];//0xaa;
    }
     printf("\r data transmitted:  ");
           for( index=0; index < 30; index++ )
          {
            printf(" %.02x ",m_buffer_tx[index]);
            nrf_delay_ms(10);
          }
          printf("\n");

//    nrf_drv_spi_transfer(&spi,(uint8_t const *)m_buffer_tx,20,m_data_receive,0);
        nrf_drv_spi_transfer(&spi,(uint8_t const *)m_buffer_tx,251,m_data_receive,0);
    // Chip select go high to end a flash command
    nrf_delay_ms(50);
    cs_high();
    nrf_delay_ms(20);

    if( WaitFlashReady( PageProgramCycleTime ) )
        return FlashOperationSuccess;
    else
      return FlashTimeOut;
}

uint8_t cmd_se( uint32_t flash_address )
{
    // Check flash address
    if( flash_address > FLASH_SIZE ) return FlashAddressInvalid;

    // Check flash is busy or not
    if( IsFlashBusy() )    return FlashIsBusy;

       // Chip select go low to start a flash command
    cs_low();

    // Setting Write Enable Latch bit
    cmd_wren();
   
    nrf_delay_ms(3);

 
//    nrf_delay_ms(100);
    //Write Sector Erase command = 0x20;

    m_buffer_tx[0] = FLASH_CMD_SE;
    m_buffer_tx[1] = flash_address >> 16;
    m_buffer_tx[2] = flash_address >> 8;
    m_buffer_tx[3] = flash_address;

//    printf(" \r sectore esrase command : %0.2x,%0.2x,%0.2x,%0.2x\n ",m_buffer_tx[0],m_buffer_tx[1],m_buffer_tx[2],m_buffer_tx[3]);

    nrf_drv_spi_transfer(&spi,(uint8_t const *)m_buffer_tx,4,m_buffer_rx,0); 
    // Chip select go high to end a flash command

    nrf_delay_ms(50);
    cs_high();
    nrf_delay_ms(240);
    printf("sector esrsed \n");

//    if( WaitFlashReady( SectorEraseCycleTime ) )
//    if( WaitFlashReady( 240000000 ))

//        cmd_rdsr(StatusReg);
             
      return FlashOperationSuccess;
   
//    else
//        return FlashTimeOut;
}

uint8_t cmd_block_erase( uint32_t flash_address )
{
    // Check flash address
    if( flash_address > FLASH_SIZE ) return FlashAddressInvalid;

    // Check flash is busy or not
//    if( IsFlashBusy() )    return FlashIsBusy;


    // Chip select go low to start a flash command
    cs_low();

    
        // Setting Write Enable Latch bit
    cmd_wren();

    nrf_delay_ms(3);

    //Write Sector Erase command = 0x20;
    uint8_t instruction;
    instruction= FLASH_CMD_BE;
//    instruction[1]= 0;
//    instruction[2] =0;
//    instruction[3]=0;
    m_buffer_tx[0] = instruction;
//    memcpy(m_buffer_tx,instruction,4);
    m_buffer_tx[1] = flash_address >> 16;
    m_buffer_tx[2] = flash_address >> 8;
    m_buffer_tx[3] = flash_address;

//    SendByte( FLASH_CMD_SE, SIO );
//    SendFlashAddr( flash_address, SIO, addr_4byte_mode );
    nrf_drv_spi_transfer(&spi,(uint8_t const *)m_buffer_tx,4,m_buffer_rx,0); 
    // Chip select go high to end a flash command
    nrf_delay_ms(100);
    cs_high();
     nrf_delay_ms(4000);
    printf("block earsed \n");

//    if( WaitFlashReady( SectorEraseCycleTime ) )
        return FlashOperationSuccess;
//    else
//        return FlashTimeOut;
}

/*
 * Function:       CMD_CE
 * Arguments:      None.
 * Description:    The CE instruction is for erasing the data
 *                 of the whole chip to be "1".
 * Return Message: FlashIsBusy, FlashOperationSuccess, FlashTimeOut
 */
ReturnMsg cmd_ce( void )
{
    // Check flash is busy or not
//    if( IsFlashBusy() )    return FlashIsBusy;
        // Chip select go low to start a flash command
    cs_low();

    // Setting Write Enable Latch bit
    cmd_wren();

    nrf_delay_ms(3);
//    nrf_delay_ms(100);
    //Write Chip Erase command = 0x60;
     m_buffer_tx[0] = 0xC7;//FLASH_CMD_CE;
     nrf_drv_spi_transfer(&spi,(uint8_t const *)m_buffer_tx,1,m_buffer_rx,0);

    // Chip select go high to end a flash command
    nrf_delay_ms(100);
    cs_high();

    
//    cmd_rdsr(StatusReg);
//    printf("StatusReg= %d \n",StatusReg);

    //if( WaitFlashReady( 60000 ) )
      nrf_delay_ms(60000);
      printf("chip esrsed \n");

        return FlashOperationSuccess;
//    else
//        return FlashTimeOut;
//return FlashOperationSuccess;
}



ReturnMsg full_sector_erase(void)
{
  uint8_t i=0;
   uint32_t flash_address = FLASH_TARGET_ADDR;
  for(i=0;i<5;i++)
  {
    cmd_se(flash_address);
    nrf_delay_ms(240);
    flash_address = flash_address + FLASH_SECTORSIZE;
  }
}

/*
 * Simple flash read/write test
 */
uint8_t flash_read_write_test( void )
{
    uint8_t  message= 0;
    FlashStatus  flash_state = {0};

    uint32_t  flash_addr;
    uint32_t  trans_len = 0;
    uint16_t  i=0, error_cnt = 0;
    uint16_t  seed = 0;
    uint8_t   st_reg = 0;

    /* Assign initial condition */
    flash_addr = FLASH_TARGET_ADDR;
    trans_len = TRANS_LENGTH;
    seed = RANDOM_SEED;

    /* Erase 4K sector of flash memory
       Note: It needs to erase dirty sector before program */
    uint8_t err_code;
//    err_code = cmd_se( flash_addr ); //cmd_ce();//cmd_block_erase(flash_addr);//cmd_se( flash_addr );
//    printf("error code = %d \n",err_code);
//     nrf_delay_ms(300);
//
//
//    cmd_read( flash_addr, m_data_receive, TRANS_LENGTH );
//     nrf_delay_ms(300);
//
//                printf("\r data after chip erase:  ");
//           for( i=4; i < 20; i++ )
//          {
//            printf(" %.02x ",m_data_receive[i]);
//            nrf_delay_ms(10);
//          }
//          printf("\n");
//    

    /* Program data to flash memory */
//    cmd_pp( flash_addr, m_data_send,256  ); //TRANS_LENGTH
//    nrf_delay_ms(500);

    /* Read flash memory data to memory buffer */
//    cmd_read( flash_addr, m_data_receive, 256 ); //TRANS_LENGTH
//     nrf_delay_ms(300);

    /* Compare original data and flash data */
    
//    for( i=4; i < (trans_len); i=i+1 )
//    {
//        if( m_data_send[i] != m_data_receive[i] )
//        {
//            printf("wrong data \n");
//            Error_inc( error_cnt );
//        }
//        else
//         {
           printf("\r data received:  ");
           for( i=4; i < 256; i++ )
          {
            printf(" %.02x ",m_data_receive[i]);
            nrf_delay_ms(10);
          }
          printf("\n");

//         }
//    }
    
    /* Erase 4K sector of flash memory */
//    cmd_se( flash_addr ); //cmd_ce();//cmd_block_erase(flash_addr); //
//    nrf_delay_ms(240); //240    60000


    if( error_cnt != 0 )
        return false;
    else
        return true;

}
uint8_t ext_flash_init(void)
{

    uint8_t retval = false;

    /* Configure SPI pins */
    nrf_drv_spi_config_t spi_config = NRF_DRV_SPI_DEFAULT_CONFIG;
    spi_config.ss_pin   = SPI_SS_PIN;
    spi_config.miso_pin = SPI_MISO_PIN;
    spi_config.mosi_pin = SPI_MOSI_PIN;
    spi_config.sck_pin  = SPI_SCK_PIN;
    spi_config.mode     = NRF_DRV_SPI_MODE_0;
    spi_config.frequency= NRF_DRV_SPI_FREQ_125K;
    APP_ERROR_CHECK(nrf_drv_spi_init(&spi, &spi_config, spi_event_handler, NULL));

    nrf_gpio_pin_set(SPI_WP_PIN);
//     nrf_gpio_pin_clear(SPI_WP_PIN);

    uint8_t err_code;
    cmd_rsten();
    cmd_rst();
    err_code = cmd_wrdis();

    /* Set CS pin to High*/

//    cs_high();

    wait_flash_warm_up();
    nrf_delay_ms(100);
    flash_ID_test(3);

    /* read and verify manufacturer and device id from external flash to ensure external flash is working */
    if(flash_ID_test(3) == true)
    {
//        flash_read_write_test();
//        return true;
    }
//    cmd_wren();
//    cmd_wrsr(2);
//    cmd_rdsr(StatusReg);
//    cmd_rdcr(ConfigReg);
//nrf_delay_ms(500);
////cmd_ce();
////    cmd_se(0x000000);
////    nrf_delay_ms(500);
//printf("finish \n");
//    cmd_read( 0x000000, m_data_receive, TRANS_LENGTH );
//    uint8_t i;
//     printf("\r data after chip erase at 0x000000:  ");
//           for( i=4; i < 20; i++ )
//          {
//            printf(" %.02x ",m_data_receive[i]);
//            nrf_delay_ms(10);
//          }
//          printf("\n");
     
//     cmd_se(0x008000);
//     cmd_read( 0x008000, m_data_receive, TRANS_LENGTH );
//
//
//     printf("\r data after chip erase at 0x008000:  ");
//           for( i=4; i < 20; i++ )
//          {
//            printf(" %.02x ",m_data_receive[i]);
//            nrf_delay_ms(10);
//          }
//          printf("\n");


    return retval;
}


