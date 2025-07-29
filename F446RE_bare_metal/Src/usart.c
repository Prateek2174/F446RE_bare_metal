/*
 * usart.c
 *
 *  Created on: Jul 15, 2025
 *      Author: prate
 */

#include <stdint.h>
#include "usart.h"

//Enable bits
#define CR1_UE        (1U << 13)
#define CR1_TE        (1U << 3)
#define CR1_RE        (1U << 2)

#define SR_RXNE	      (1U << 5)
#define SR_TXE        (1U << 7)

#define RCC_USART1_EN (1U << 4)

#define SYSTEM_FREQUENCY 16000000
#define PERIPHERAL_CLOCK SYSTEM_FREQUENCY
#define BAUDRATE         115200

void usart1_init(void){
	//Enable clock access to USART1
	RCC_APB2ENR |= RCC_USART1_EN;
	//Set USART1 Alternate Function in Gpio.c
	//AF7, USART1_TX = PA9, USART1_RX = PA10

	//Configure baudrate
	usart1_set_baudrate(PERIPHERAL_CLOCK, BAUDRATE);

	//Enable TX and RX transfer function in CR1
	USART1_CR1 |= CR1_TE;
	USART1_CR1 |= CR1_RE;

	//Enable USART2 module
	USART1_CR1 |= CR1_UE;
}

char usart1_read(void){

	while(!(USART1_SR & SR_RXNE));

	return USART1_DR;
}

void usart1_write(int ch){

	//Ensure register is not empty first
	while(!(USART1_SR & SR_TXE)); //wait till transmist data register is empty

	USART1_DR = (ch & 0xFF);
}

void usart1_set_baudrate(uint32_t peripheral_clock, uint32_t baudrate){

	USART1_BRR = ((peripheral_clock + (baudrate/2U)) / baudrate);
}
