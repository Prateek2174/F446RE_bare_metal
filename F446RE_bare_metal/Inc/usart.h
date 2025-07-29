/*
 * usart.h
 *
 *  Created on: Jul 15, 2025
 *      Author: prate
 */

#ifndef USART_H_
#define USART_H_

#include "base.h"
#include <stdint.h>

#define USART1_CR1_OFFSET  (0x0C)
#define USART1_CR1         (*(volatile unsigned int*)(USART1_PERIPHERAL + USART1_CR1_OFFSET))

#define USART1_BRR_OFFSET  (0x08)
#define USART1_BRR		   (*(volatile unsigned int*)(USART1_PERIPHERAL + USART1_BRR_OFFSET))

#define USART1_SR_OFFSET   (0x00)
#define USART1_SR		   (*(volatile unsigned int*)(USART1_PERIPHERAL + USART1_SR_OFFSET))

#define USART1_DR_OFFSET   (0x04)
#define USART1_DR          (*(volatile unsigned int*)(USART1_PERIPHERAL + USART1_DR_OFFSET))

#define RCC_APB2ENR_OFFSET (0x44)
#define RCC_APB2ENR        (*(volatile unsigned int*)(RCC_PERIPHERAL + RCC_APB2ENR_OFFSET))

//Function prototypes

void usart1_init(void);
char usart1_read(void);
void usart1_write(int ch);
void usart1_set_baudrate(uint32_t peripheral_clock, uint32_t baudrate);


#endif /* USART_H_ */
