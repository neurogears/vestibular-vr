#include "PAA5100JE.h"
#include "spi.h"

#define F_CPU 32000000
#include <util/delay.h>

Motion th;
bool optical_tracking_initialize(void)
{
	/* Power up and reset */
	optical_tracking_write_register(POWER_UP_RESET_REG_ADD, 0x5A);
	_delay_us(10);
	
	/* Check if the right IC is present */
	uint8_t productID = optical_tracking_read_register(PRODUCT_ID_REG_ADD);
	uint8_t invProductID = optical_tracking_read_register(INVERSE_PRODUCT_ID_REG_ADD);
	
	if (productID != 0x49 && invProductID != 0xB8)
		return false;
	
	/* Read the data registers */
	optical_tracking_read_register(MOTION_REG_ADD);
	optical_tracking_read_register(DELTA_X_L_REG_ADD);
	optical_tracking_read_register(DELTA_X_H_REG_ADD);
	optical_tracking_read_register(DELTA_Y_L_REG_ADD);
	optical_tracking_read_register(DELTA_Y_H_REG_ADD);
	
	_delay_us(1);
	
	performanceOptimizationRoutine();		
	
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
		 
void performanceOptimizationRoutine(void)
{
    /*uint8_t tempRetVal = 0;
    int C1 = 0, C2 = 0;
    for (int i = 0; i < 5; i++)
    {
        optical_tracking_write_register(writeRegAdrOptSend_1[i], writeValueOptSend_1[i]);
    }
    tempRetVal = optical_tracking_read_register(0x67);
    tempRetVal = tempRetVal & 0x80u;
    if (tempRetVal == 0x80u)
        optical_tracking_write_register(0x48, 0x04);
    else
        optical_tracking_write_register(0x48, 0x02);
    for (int i = 0; i < 5; i++)
    {
        optical_tracking_write_register(writeRegAdrOptSend_2[i], writeValueOptSend_2[i]);
    }
    if (optical_tracking_read_register(0x73) == 0x00)
    {
        C1 = (int)optical_tracking_read_register(0x70);
        if (C1 <= 28)
            C1 += 14;
        else
            C1 += 11;
        if (C1 > 63)
            C1 = 63;
        C2 = (int)optical_tracking_read_register(0x71);
        C2 = (C2 * 45) / 100;
        optical_tracking_write_register(0x7F, 0x00);
        optical_tracking_write_register(0x61, 0xAD);
        optical_tracking_write_register(0x51, 0x70);
        optical_tracking_write_register(0x7F, 0x0E);

        optical_tracking_write_register(0x70, (uint8_t)C1);
        optical_tracking_write_register(0x71, (uint8_t)C2);
    }
	 */
    for (int i = 0; i < 67; i++)
    {
        optical_tracking_write_register(writeRegAdrOptSend_3[i], writeValueOptSend_3[i]);
    }
    _delay_us(10);
    
	 for (int i = 0; i < 16; i++)
    {
        optical_tracking_write_register(writeRegAdrOptSend_4[i], writeValueOptSend_4[i]);
    }
    _delay_us(10);
    optical_tracking_write_register(0x73, 0x00);
}

void optical_tracking_read_motion(Motion motion[])
{
	/* Data received when using burst:
		uint8_t ?
		uint8_t ?
		int16_t deltaA
		int16_t deltaB
		uint8_t Squal - The number of valid features detected by the sensor in the current frame
	*/	
	
	spi_start();
	_delay_us(1);
	spi_tx_byte(MOTION_BURST_REG_ADD);
	_delay_us(5);	
	for (uint8_t i = 0; i<7; i++)
		*(((uint8_t*)(motion))+i) = spi_rx_byte();
	_delay_us(1);
	spi_stop();
}

uint8_t optical_tracking_read_register(uint8_t address)
{
	address &= ~0x80;
	
	spi_start();
	_delay_us(1);
	spi_tx_byte(address);
	_delay_us(5);
	uint8_t byte = spi_rx_byte();
	_delay_us(1);
	spi_stop();
	
	return byte;
}

void optical_tracking_write_register(uint8_t address, uint8_t byte)
{
	address |= 0x80;
	
	spi_start();
	_delay_us(1);
	spi_tx_byte(address);
	_delay_us(1);
	spi_tx_byte(byte);
	_delay_us(5);
	spi_stop();
}