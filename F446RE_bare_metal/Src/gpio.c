/*
 * gpio.c
 *
 *  Created on: Jul 15, 2025
 *      Author: prate
 */


#include "gpio.h"

#define GPIOAEN     (1U << 0) // = 0b00000001
#define GPIOBEN     (1U << 1) // = 0b00000010
#define GPIOCEN     (1U << 2)

#define GPIOA8      (1U << 8)
#define GPIOB5      (1U << 5)
#define GPIOC13     (1U << 13)
#define GPIOA5		(1U << 5)

#define RED_LED     GPIOA8
#define BLUE_LED    GPIOB5
#define USER_BUTTON GPIOC13
#define USER_LED	GPIOA5


void gpio_init(void){
	//Enable clock access to GPIO ports A, B and C

	//Enable clock to GPIOA
	RCC_AHB1ENR |= GPIOAEN;

	//Enable clock to GPIOB
	RCC_AHB1ENR |= GPIOBEN;

	//Enable clock to GPIOC
	RCC_AHB1ENR |= GPIOCEN;

	//Set pin modes

	//Red led, GPIOA8. output
	GPIOA_MODER |= (1U << 16);
	GPIOA_MODER &= ~(1U << 17);

	//GPIOB5, blue led output
	GPIOB_MODER |= (1U << 10);
	GPIOB_MODER &= ~(1U << 11);

	//input button, GPIOC13
	GPIOC_MODER &= ~(3U << 26);

	//Set GPIOA5 on board led to output
	GPIOA_MODER |= (1U << 10);
	GPIOA_MODER &= ~(1U << 11);

	//Set PA9 and PA10 to alternative mode
	GPIOA_MODER |= (1U << 19);
	GPIOA_MODER &= ~(1U << 18);
	GPIOA_MODER |= (1U << 21);
	GPIOA_MODER &= ~(1U << 20);

	//Set alternative functions for USART AF7 for PA9 and PA10
	GPIOA_AFRH &= ~(0xF << 4);   // clear PA9 AF
	GPIOA_AFRH |=  (7U << 4);    // set AF7 for PA9

	GPIOA_AFRH &= ~(0xF << 8);   // clear PA10 AF
	GPIOA_AFRH |=  (7U << 8);    // set AF7 for PA10

	//Set GPIOA1 to analog for ADC
	GPIOA_MODER |= (3U << 2);

}

void red_led_on(void){

	GPIOA_ODR |= RED_LED;
}

void red_led_off(void){

	GPIOA_ODR &= ~(RED_LED);
}

void blue_led_on(void){

	GPIOB_ODR |= BLUE_LED;
}

void blue_led_off(void){

	GPIOB_ODR &= ~(BLUE_LED);

}

void led_toggle(void){

	GPIOA_ODR ^= USER_LED;
	led_delay();
}

void program_state_set(int *program_state){

	//when button is pressed -> PC13 goes low
	if(!(GPIOC_IDR & USER_BUTTON)){

		if(*program_state == OFF){

			*program_state = ON;
			led_delay();

		}else if(*program_state == ON){

			*program_state = OFF;
			led_delay();

		}
	}

}

void program_state_display(int *program_state){

	if(*program_state == OFF){
		red_led_on();
		blue_led_off();

	}else if(*program_state == ON){
		red_led_off();
		blue_led_on();

	}
}

void led_delay(void){

	for(int i = 0; i < 150000; i++);
}
