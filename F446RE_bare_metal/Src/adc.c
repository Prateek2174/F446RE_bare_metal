/*
 * adc.c
 *
 *  Created on: Jul 15, 2025
 *      Author: prate
 */

#include "adc.h"
#include "usart.h"

//Enable bits
#define SR_EOC         (1U << 1)
#define CR2_SWSTART    (1U << 30)
#define CR2_ADON	   (1U << 0)
#define CR2_CONT	   (1U << 1)
#define SQR3_SQ1	   (0x01) //Channel 1
#define APB2ENR_ADC1EN (1U << 8)

void adc_init(void){

	//Enable clock access to ADC module
	RCC_APB2ENR |= APB2ENR_ADC1EN;

	//Set GPIOA1 in gpio.c mode to analog

	//Set data resolution to 10-bit (minimum 13 ADCCLK cycles)
	ADC_CR1 |= (1U << 24);
	ADC_CR1 &= ~(1U << 25);

	//Select channel
	ADC_SQR3 |= SQR3_SQ1;

	//Enable ADC module
	ADC_CR2 |= CR2_ADON;
}

void adc_conversion(void){
	//Set continuous conversion
	ADC_CR2 |= CR2_CONT;

	//Start ADC module
	ADC_CR2 |= CR2_SWSTART;
}

int adc_read(void){

	while(!(ADC_SR & SR_EOC)); //loop til EOC bit = 1 -> conversion complete

	return ADC_DR;
}

void adc_sample_signal(char *buffer, int *program_state){
	char byte_one;
	int uart_byte;

	if(*program_state == ON){

		char *pointer = buffer;

		for(int x = 0; x < 64; x++){

			uart_byte = adc_read();
			byte_one = (uart_byte & 0xFF);

			*buffer++ = byte_one;
		}
		//Sampling complete
		adc_transmit_signal(pointer);
	}

}

void adc_transmit_signal(char * buffer){

	for(int i = 0; i < 64; i++){

		usart1_write(*buffer++);
	}
}
