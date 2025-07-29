/*
 * adc.h
 *
 *  Created on: Jul 15, 2025
 *      Author: prate
 */

#ifndef ADC_H_
#define ADC_H_

#include "base.h"

#define ADC_SR_OFFSET      (0x00)
#define ADC_SR 		       (*(volatile unsigned int*)(ADC_PERIPHERAL + ADC_SR_OFFSET))

#define ADC_CR1_OFFSET     (0x04)
#define ADC_CR1	           (*(volatile unsigned int*)(ADC_PERIPHERAL + ADC_CR1_OFFSET))

#define ADC_CR2_OFFSET     (0x08)
#define ADC_CR2		       (*(volatile unsigned int*)(ADC_PERIPHERAL + ADC_CR2_OFFSET))

#define ADC_SQR3_OFFSET    (0x34)
#define ADC_SQR3           (*(volatile unsigned int*)(ADC_PERIPHERAL + ADC_SQR3_OFFSET))

#define ADC_DR_OFFSET      (0x4C)
#define ADC_DR             (*(volatile unsigned int*)(ADC_PERIPHERAL + ADC_DR_OFFSET))

#define RCC_APB2ENR_OFFSET (0x44)
#define RCC_APB2ENR        (*(volatile unsigned int*)(RCC_PERIPHERAL + RCC_APB2ENR_OFFSET))

//Function prototypes
void adc_init(void);
void adc_conversion(void);
int adc_read(void);
void adc_sample_signal(char *buffer, int *program_state);
void adc_transmit_signal(char * buff);

#endif /* ADC_H_ */
