#ifndef __UART_H // Checks wether the UART header file has been defined 
#define __UART_H // Declares the UART header file and the following lines of code to be executed during the pre-process in the compilation

#include "stm32f4xx.h" // Include source code for STM-Hardware and neccessary references
#include <stdio.h> // Include the Standard I/O for C

void USART2_Init(void); // Calls and references the declaration of UART function
void test_setup(void); // Calls and references the test function from UART.c
#endif // End of the header file
