#include "spi.h"
#include "app_ios_and_regs.h"

void spi_initialize_flow0(void)
{
	/* Initialize SPI with 2MHz */
	SPIC_CTRL = SPI_MASTER_bm | SPI_ENABLE_bm | SPI_MODE_0_gc /*| SPI_CLK2X_bm*/ | SPI_PRESCALER_DIV16_gc;
}

void spi_initialize_flow1(void)
{
	/* Initialize SPI with 2MHz */
	SPID_CTRL = SPI_MASTER_bm | SPI_ENABLE_bm | SPI_MODE_0_gc /*| SPI_CLK2X_bm*/ | SPI_PRESCALER_DIV16_gc;
}

void spi_start_flow0(void)
{
	/* CS low for 375 ns */
	clr_FLOW0_CS; clr_FLOW0_CS;
	clr_FLOW0_CS; clr_FLOW0_CS; clr_FLOW0_CS; clr_FLOW0_CS; clr_FLOW0_CS;
	clr_FLOW0_CS; clr_FLOW0_CS; clr_FLOW0_CS; clr_FLOW0_CS; clr_FLOW0_CS;
}

void spi_start_flow1(void)
{
	/* CS low for 375 ns */
	clr_FLOW1_CS; clr_FLOW1_CS;
	clr_FLOW1_CS; clr_FLOW1_CS; clr_FLOW1_CS; clr_FLOW1_CS; clr_FLOW1_CS;
	clr_FLOW1_CS; clr_FLOW1_CS; clr_FLOW1_CS; clr_FLOW1_CS; clr_FLOW1_CS;
}

uint8_t spi_rx_byte_flow0(void)
{	
	/* Start clock pulses */
	SPIC_DATA = 0;
	
	/* Wait for byte  */
	loop_until_bit_is_set(SPIC_STATUS, SPI_IF_bp);
	
	/* Return byte */
	return SPIC_DATA;
}

uint8_t spi_rx_byte_flow1(void)
{
	/* Start clock pulses */
	SPID_DATA = 0;
	
	/* Wait for byte  */
	loop_until_bit_is_set(SPID_STATUS, SPI_IF_bp);
	
	/* Return byte */
	return SPID_DATA;
}

void spi_tx_byte_flow0(uint8_t byte)
{
	/* Start sending byte */
	SPIC_DATA = byte;
	
	/* Wait for complete sending  */
	loop_until_bit_is_set(SPIC_STATUS, SPI_IF_bp);
}

void spi_tx_byte_flow1(uint8_t byte)
{
	/* Start sending byte */
	SPID_DATA = byte;
	
	/* Wait for complete sending  */
	loop_until_bit_is_set(SPID_STATUS, SPI_IF_bp);
}

void spi_stop_flow0(void)
{	
	/* CS high */
	set_FLOW0_CS;
}

void spi_stop_flow1(void)
{
	/* CS high */
	set_FLOW1_CS;
}