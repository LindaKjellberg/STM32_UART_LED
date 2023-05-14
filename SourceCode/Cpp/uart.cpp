#include "UART.h" // Gets the header file containing the UART function during the compilation pre-process

void USART2_Init(void) { // Declaration of the function to initialize the USART protocol and its contained components

// 1. Enable the clock access for the uart2 driver:
RCC->APB1ENR |= 0x20000; //Activate UART2 by setting bit 17 in APB1ENR to 1.

// 2. Enable the clock access for portA:
RCC->AHB1ENR |= 0x01; //Activate GPIOA by setting bit 0 in AHB1ENR to 1.

// 3. Enable pins related to selected port for alternative function:
GPIOA->MODER &= ~0x00F0; // Clears bits 4-7 in order to prepare pins PA2 and PA3
  //& and ~ forces an inversion which leads to all the bits that are being denoted by hexadecimal value 1, is replaced in real value by 0

GPIOA->MODER |= 0x00A0; // Set pins 5 and 7 to 1 in order to activate alternative functionality on pins PA2 och PA3

// 4. Choose type of alternative function for the selected pins:
GPIOA->AFR[0] &= ~0xFF00; // Clears bits 8-15 in order to prepare pins PA2 och PA3
GPIOA->AFR[0] |= 0x7700; // Set bits 8-11 and 12-15 to the format 0111

/* The construction of the devices communication is completed */

/* Begin to configure the UART protocol */

USART2->BRR = 0x0683; // Set standard baud rate using hexadecimal 0x0683 (9600bps)
USART2->CR1 = 0x000C; // Set tx och rx to work in 8-bit data mode. (8-bits of data, 1 stop bit, no parity)
USART2->CR2 = 0x000; // Sets CR2 to 0 (default)
USART2->CR3 = 0x000; // Sets CR3 to 0 (default)
USART2->CR1 |= 0x2000; // Resets bit 13 (the UART activation) to 1

}
// UART Write function
int USART2_write(int ch){ // Declare UART Write function (which transferes data to the terminal)

  while(!(USART2->SR & 0x0080)){} // Set up rules which controls that the status of the transfere is empty and able to receive the next character (byte)
  USART2->DR = (ch & 0xFF); // Sets transfer of bytes to the data register

  return ch; // Character to be returned

}
// UART Read function
int USART2_read(void){ // Declare UART Read function (which receives data from the device)

  while(!(USART2->SR & 0x0020)){} // Set up rules which controls if there is any more data to receive
  return USART2->DR; // Reads the data
}