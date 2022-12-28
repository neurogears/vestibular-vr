#ifndef _SPI_H_
#define _SPI_H_
#include "cpu.h"

void spi_initialize_flow0(void);
void spi_initialize_flow1(void);

void spi_start_flow0(void);
void spi_start_flow1(void);

uint8_t spi_rx_byte_flow0(void);
uint8_t spi_rx_byte_flow1(void);

void spi_tx_byte_flow0(uint8_t byte);
void spi_tx_byte_flow1(uint8_t byte);

void spi_stop_flow0(void);
void spi_stop_flow1(void);

#endif /* _SPI_H_ */