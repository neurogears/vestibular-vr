#ifndef _SPI_H_
#define _SPI_H_
#include "cpu.h"

void spi_start(void);
uint8_t spi_rx_byte(void);
void spi_tx_byte(uint8_t byte);
void spi_stop (void);

#endif /* _SPI_H_ */