#ifndef SPI_INT_H
#define SPI_INT_H

void SPI_voidInitialization(void);
u8 SPI_Slave_Recieve(void);
u8 SPI_Master_Recieve(void);
void SPI_Transmit(u8 data);

#endif
