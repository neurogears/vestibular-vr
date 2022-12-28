#include "spi.h"
#include "app_ios_and_regs.h"

/* Expansion pins used
	   - OUT5     CS
	   - OUT6     CLK
	   - AUX_IN0  MISO
	   - OUT9     MOSI
*/

void spi_start(void)
{	
	/* CS low for 375 ns */
	clr_OUT5; clr_OUT5;
	clr_OUT5; clr_OUT5; clr_OUT5; clr_OUT5; clr_OUT5;
	clr_OUT5; clr_OUT5; clr_OUT5; clr_OUT5; clr_OUT5;	
}

uint8_t spi_rx_byte(void)
{	
	uint8_t byte = 0;
	
	/* MOSI low */
	set_OUT9;
	
	/* Receive byte */	
	/*
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) byte |= 0x80;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) byte |= 0x40;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) byte |= 0x20;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) byte |= 0x10;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) byte |= 0x08;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) byte |= 0x04;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) byte |= 0x02;
	set_OUT6; set_OUT6; clr_OUT6; if (read_AUX_INPUT0) byte |= 0x01;
	*/
	clr_OUT6; clr_OUT6; if (read_AUX_INPUT0) byte |= 0x80; set_OUT6; set_OUT6;
	clr_OUT6; clr_OUT6; if (read_AUX_INPUT0) byte |= 0x40; set_OUT6; set_OUT6;
	clr_OUT6; clr_OUT6; if (read_AUX_INPUT0) byte |= 0x20; set_OUT6; set_OUT6;
	clr_OUT6; clr_OUT6; if (read_AUX_INPUT0) byte |= 0x10; set_OUT6; set_OUT6;
	clr_OUT6; clr_OUT6; if (read_AUX_INPUT0) byte |= 0x08; set_OUT6; set_OUT6;
	clr_OUT6; clr_OUT6; if (read_AUX_INPUT0) byte |= 0x04; set_OUT6; set_OUT6;
	clr_OUT6; clr_OUT6; if (read_AUX_INPUT0) byte |= 0x02; set_OUT6; set_OUT6;
	clr_OUT6; clr_OUT6; if (read_AUX_INPUT0) byte |= 0x01; set_OUT6; set_OUT6;
	
	return byte;
}


void spi_tx_byte(uint8_t byte)
{
	/* Xmit byte */
	clr_OUT6; if (byte & 0x80) set_OUT9; else clr_OUT9; clr_OUT6; set_OUT6; set_OUT6;
	clr_OUT6; if (byte & 0x40) set_OUT9; else clr_OUT9; clr_OUT6; set_OUT6; set_OUT6;
	clr_OUT6; if (byte & 0x20) set_OUT9; else clr_OUT9; clr_OUT6; set_OUT6; set_OUT6;
	clr_OUT6; if (byte & 0x10) set_OUT9; else clr_OUT9; clr_OUT6; set_OUT6; set_OUT6;
	clr_OUT6; if (byte & 0x08) set_OUT9; else clr_OUT9; clr_OUT6; set_OUT6; set_OUT6;
	clr_OUT6; if (byte & 0x04) set_OUT9; else clr_OUT9; clr_OUT6; set_OUT6; set_OUT6;
	clr_OUT6; if (byte & 0x02) set_OUT9; else clr_OUT9; clr_OUT6; set_OUT6; set_OUT6;
	clr_OUT6; if (byte & 0x01) set_OUT9; else clr_OUT9; clr_OUT6; set_OUT6; set_OUT6;
}


void spi_stop (void)
{
	/* CLK low */
	//clr_OUT6;
	
	/* CS high */
	set_OUT5;
}