#include "PAA5100JE.h"
#include "spi.h"
#include "app_ios_and_regs.h"

#define F_CPU 32000000
#include <util/delay.h>

Motion th;
bool optical_tracking_initialize_flow0(void)
{
	/* Power up and reset */
	optical_tracking_write_register_flow0(POWER_UP_RESET_REG_ADD, 0x5A);
	_delay_us(10);
	
	/* Check if the right IC is present */
	uint8_t productID = optical_tracking_read_register_flow0(PRODUCT_ID_REG_ADD);
	uint8_t invProductID = optical_tracking_read_register_flow0(INVERSE_PRODUCT_ID_REG_ADD);
	
	if (productID != 0x49 && invProductID != 0xB8)
		return false;
	
	/* Read the data registers */
	optical_tracking_read_register_flow0(MOTION_REG_ADD);
	optical_tracking_read_register_flow0(DELTA_X_L_REG_ADD);
	optical_tracking_read_register_flow0(DELTA_X_H_REG_ADD);
	optical_tracking_read_register_flow0(DELTA_Y_L_REG_ADD);
	optical_tracking_read_register_flow0(DELTA_Y_H_REG_ADD);
	
	_delay_us(1);
	
	performanceOptimizationRoutine_flow0();		
	
	return true;
}

bool optical_tracking_initialize_flow1(void)
{
	/* Power up and reset */
	optical_tracking_write_register_flow1(POWER_UP_RESET_REG_ADD, 0x5A);
	_delay_us(10);
	
	/* Check if the right IC is present */
	uint8_t productID = optical_tracking_read_register_flow1(PRODUCT_ID_REG_ADD);
	uint8_t invProductID = optical_tracking_read_register_flow1(INVERSE_PRODUCT_ID_REG_ADD);
	
	if (productID != 0x49 && invProductID != 0xB8)
	return false;
	
	/* Read the data registers */
	optical_tracking_read_register_flow1(MOTION_REG_ADD);
	optical_tracking_read_register_flow1(DELTA_X_L_REG_ADD);
	optical_tracking_read_register_flow1(DELTA_X_H_REG_ADD);
	optical_tracking_read_register_flow1(DELTA_Y_L_REG_ADD);
	optical_tracking_read_register_flow1(DELTA_Y_H_REG_ADD);
	
	_delay_us(1);
	
	performanceOptimizationRoutine_flow1();
	
	return true;
}


// Performance optimization registers (proprietary to PixArt)
uint8_t writeRegAdrOptSend_1[5] = {0x7F, 0x55, 0x50, 0x7F, 0x43};
uint8_t writeValueOptSend_1[5] = {0x00, 0x01, 0x07, 0x0E, 0x10};
uint8_t writeRegAdrOptSend_2[5] = {0x7F, 0x51, 0x50, 0x55, 0x7F};
uint8_t writeValueOptSend_2[5] = {0x00, 0x7B, 0x00, 0x00, 0x0E};
uint8_t writeRegAdrOptSend_3[67] = {0x7F, 0x61, 0x7F, 0x40, 0x7F, 0x41, 0x43, 0x45, 0x5F, 0x7B, 0x5E, 0x5B, 0x6D, 0x45, 0x70, 0x71, 0x7F, 0x44, 0x40, 0x4E, 0x7F, 0x66, 0x65, 0x6A, 0x61, 0x62, 0x7F, 0x4F, 0x5F, 0x48, 0x49, 0x57, 0x60, 0x61, 0x62, 0x63, 0x7F, 0x45, 0x7F, 0x4D, 0x55, 0x74, 0x75, 0x4A, 0x4B, 0x44, 0x45, 0x64, 0x65, 0x7F, 0x65, 0x66, 0x63, 0x6F, 0x7F, 0x48, 0x7F, 0x41, 0x43, 0x4B, 0x45, 0x44, 0x4C, 0x7F, 0x5B, 0x7F, 0x40};
uint8_t writeValueOptSend_3[67] = {0x00, 0xAD, 0x03, 0x00, 0x05, 0xB3, 0xF1, 0x14, 0x34, 0x08, 0x34, 0x11, 0x11, 0x17, 0xE5, 0xE5, 0x06, 0x1B, 0xBF, 0x3F, 0x08, 0x44, 0x20, 0x3A, 0x05, 0x05, 0x09, 0xAF, 0x40, 0x80, 0x80, 0x77, 0x78, 0x78, 0x08, 0x50, 0x0A, 0x60, 0x00, 0x11, 0x80, 0x21, 0x1F, 0x78, 0x78, 0x08, 0x50, 0xFF, 0x1F, 0x14, 0x67, 0x08, 0x70, 0x1C, 0x15, 0x48, 0x07, 0x0D, 0x14, 0x0E, 0x0F, 0x42, 0x80, 0x10, 0x02, 0x07, 0x41};
uint8_t writeRegAdrOptSend_4[16] = {0x7F, 0x32, 0x7F, 0x40, 0x7F, 0x68, 0x69, 0x7F, 0x48, 0x6F, 0x7F, 0x5B, 0x4E, 0x5A, 0x40, 0x73};
uint8_t writeValueOptSend_4[16] = {0x00, 0x00, 0x07, 0x40, 0x06, 0xF0, 0x00, 0x0D, 0xC0, 0xD5, 0x00, 0xA0, 0xA8, 0x90, 0x80, 0x1F};

// Frame synchronization procedure (proprietary to PixArt)
uint8_t writeFrameSyncAdr_1[8] = {0x7F, 0x40, 0x7F, 0x62, 0x63, 0x68, 0x69, 0x7F};
uint8_t writeFrameSyncVal_1[8] = {0x07, 0x41, 0x06, 0x10, 0x00, 0x10, 0x00, 0x00};
		 
void performanceOptimizationRoutine_flow0(void)
{	
	if (1) // Use extra calibration?
	{
		 uint8_t tempRetVal = 0;
		 int C1 = 0, C2 = 0;
		 for (int i = 0; i < 5; i++)
		 {
			 optical_tracking_write_register_flow0(writeRegAdrOptSend_1[i], writeValueOptSend_1[i]);
		 }
		 tempRetVal = optical_tracking_read_register_flow0(0x67);
		 tempRetVal = tempRetVal & 0x80u;
		 if (tempRetVal == 0x80u)
		 optical_tracking_write_register_flow0(0x48, 0x04);
		 else
		 optical_tracking_write_register_flow0(0x48, 0x02);
		 for (int i = 0; i < 5; i++)
		 {
			 optical_tracking_write_register_flow0(writeRegAdrOptSend_2[i], writeValueOptSend_2[i]);
		 }
		 if (optical_tracking_read_register_flow0(0x73) == 0x00)
		 {
			 C1 = (int)optical_tracking_read_register_flow0(0x70);
			 if (C1 <= 28)
			 C1 += 14;
			 else
			 C1 += 11;
			 if (C1 > 63)
			 C1 = 63;
			 C2 = (int)optical_tracking_read_register_flow0(0x71);
			 C2 = (C2 * 45) / 100;
			 optical_tracking_write_register_flow0(0x7F, 0x00);
			 optical_tracking_write_register_flow0(0x61, 0xAD);
			 optical_tracking_write_register_flow0(0x51, 0x70);
			 optical_tracking_write_register_flow0(0x7F, 0x0E);

			 optical_tracking_write_register_flow0(0x70, (uint8_t)C1);
			 optical_tracking_write_register_flow0(0x71, (uint8_t)C2);
		 }
	}
	 
    for (int i = 0; i < 67; i++)
    {
        optical_tracking_write_register_flow0(writeRegAdrOptSend_3[i], writeValueOptSend_3[i]);
    }
    _delay_us(10);
    
	 for (int i = 0; i < 16; i++)
    {
        optical_tracking_write_register_flow0(writeRegAdrOptSend_4[i], writeValueOptSend_4[i]);
    }
    _delay_us(10);
    optical_tracking_write_register_flow0(0x73, 0x00);
}

void performanceOptimizationRoutine_flow1(void)
{
	if (1) // Use extra calibration?
	{
		 uint8_t tempRetVal = 0;
		 int C1 = 0, C2 = 0;
		 for (int i = 0; i < 5; i++)
		 {
			 optical_tracking_write_register_flow1(writeRegAdrOptSend_1[i], writeValueOptSend_1[i]);
		 }
		 tempRetVal = optical_tracking_read_register_flow1(0x67);
		 tempRetVal = tempRetVal & 0x80u;
		 if (tempRetVal == 0x80u)
		 optical_tracking_write_register_flow1(0x48, 0x04);
		 else
		 optical_tracking_write_register_flow1(0x48, 0x02);
		 for (int i = 0; i < 5; i++)
		 {
			 optical_tracking_write_register_flow1(writeRegAdrOptSend_2[i], writeValueOptSend_2[i]);
		 }
		 if (optical_tracking_read_register_flow1(0x73) == 0x00)
		 {
			 C1 = (int)optical_tracking_read_register_flow1(0x70);
			 if (C1 <= 28)
			 C1 += 14;
			 else
			 C1 += 11;
			 if (C1 > 63)
			 C1 = 63;
			 C2 = (int)optical_tracking_read_register_flow1(0x71);
			 C2 = (C2 * 45) / 100;
			 optical_tracking_write_register_flow1(0x7F, 0x00);
			 optical_tracking_write_register_flow1(0x61, 0xAD);
			 optical_tracking_write_register_flow1(0x51, 0x70);
			 optical_tracking_write_register_flow1(0x7F, 0x0E);

			 optical_tracking_write_register_flow1(0x70, (uint8_t)C1);
			 optical_tracking_write_register_flow1(0x71, (uint8_t)C2);
		 }
	}
	 
    for (int i = 0; i < 67; i++)
    {
        optical_tracking_write_register_flow1(writeRegAdrOptSend_3[i], writeValueOptSend_3[i]);
    }
    _delay_us(10);
    
	 for (int i = 0; i < 16; i++)
    {
        optical_tracking_write_register_flow1(writeRegAdrOptSend_4[i], writeValueOptSend_4[i]);
    }
    _delay_us(10);
    optical_tracking_write_register_flow1(0x73, 0x00);
}

void optical_tracking_read_motion(Motion motion_flow0[], Motion motion_flow1[])
{
	spi_start_flow0();
	spi_start_flow1();
	_delay_us(1);
	spi_tx_byte_flow0(MOTION_BURST_REG_ADD);
	spi_tx_byte_flow1(MOTION_BURST_REG_ADD);
	_delay_us(5);
	for (uint8_t i = 0; i<7; i++)
	{
		*(((uint8_t*)(motion_flow0))+i) = spi_rx_byte_flow0();
		*(((uint8_t*)(motion_flow1))+i) = spi_rx_byte_flow1();
	}
	_delay_us(1);
	spi_stop_flow0();
	spi_stop_flow1();
}

void optical_tracking_read_motion_optimized(Motion motion_flow0[], Motion motion_flow1[])
{
	clr_FLOW0_CS;
	clr_FLOW1_CS;
	_delay_us(2);
	
	SPIC_DATA = MOTION_BURST_REG_ADD;
	SPID_DATA = MOTION_BURST_REG_ADD;
	loop_until_bit_is_set(SPIC_STATUS, SPI_IF_bp);
	loop_until_bit_is_set(SPID_STATUS, SPI_IF_bp);
	
	_delay_us(5);
	
	for (uint8_t i = 0; i<7; i++)
	{
		SPIC_DATA = 0;
		SPID_DATA = 0;
		
		loop_until_bit_is_set(SPIC_STATUS, SPI_IF_bp);
		*(((uint8_t*)(motion_flow0))+i) = SPIC_DATA;
		
		loop_until_bit_is_set(SPID_STATUS, SPI_IF_bp);
		*(((uint8_t*)(motion_flow1))+i) = SPID_DATA;
	}
	
	_delay_us(1);
	
	set_FLOW0_CS;
	set_FLOW1_CS;
}

uint8_t optical_tracking_read_register_flow0(uint8_t address)
{
	address &= ~0x80;

	spi_start_flow0();
	_delay_us(1);
	spi_tx_byte_flow0(address);
	_delay_us(5);
	uint8_t byte = spi_rx_byte_flow0();
	_delay_us(1);
	spi_stop_flow0();
	
	return byte;
}

uint8_t optical_tracking_read_register_flow1(uint8_t address)
{
	address &= ~0x80;

	spi_start_flow1();
	_delay_us(1);
	spi_tx_byte_flow1(address);
	_delay_us(5);
	uint8_t byte = spi_rx_byte_flow1();
	_delay_us(1);
	spi_stop_flow1();
	
	return byte;
}

void optical_tracking_write_register_flow0(uint8_t address, uint8_t byte)
{
	address |= 0x80;

	spi_start_flow0();
	_delay_us(1);
	spi_tx_byte_flow0(address);
	_delay_us(1);
	spi_tx_byte_flow0(byte);
	_delay_us(5);
	spi_stop_flow0();
	
}

void optical_tracking_write_register_flow1(uint8_t address, uint8_t byte)
{
	address |= 0x80;

	spi_start_flow1();
	_delay_us(1);
	spi_tx_byte_flow1(address);
	_delay_us(1);
	spi_tx_byte_flow1(byte);
	_delay_us(5);
	spi_stop_flow1();
	
}