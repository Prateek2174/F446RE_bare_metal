/*
 * gpio.h
 *
 *  Created on: Jul 15, 2025
 *      Author: prate
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "base.h"

#define GPIOA_MODER_OFFSET (0x00)
#define GPIOA_MODER        (*(volatile unsigned int *)(GPIOA_PERIPHERAL + GPIOA_MODER_OFFSET))

#define GPIOA_ODR_OFFSET   (0x14)
#define GPIOA_ODR		   (*(volatile unsigned int *)(GPIOA_PERIPHERAL + GPIOA_ODR_OFFSET))

#define GPIOB_MODER_OFFSET (0x00)
#define GPIOB_MODER        (*(volatile unsigned int *)(GPIOB_PERIPHERAL + GPIOB_MODER_OFFSET))

#define GPIOB_ODR_OFFSET   (0x14)
#define GPIOB_ODR		   (*(volatile unsigned int *)(GPIOB_PERIPHERAL + GPIOB_ODR_OFFSET))

#define GPIOC_MODER_OFFSET (0x00)
#define GPIOC_MODER        (*(volatile unsigned int *)(GPIOC_PERIPHERAL + GPIOC_MODER_OFFSET))

#define GPIOC_IDR_OFFSET   (0x10)
#define GPIOC_IDR          (*(volatile unsigned int *)(GPIOC_PERIPHERAL + GPIOC_IDR_OFFSET))

#define RCC_AHB1ENR_OFFSET (0x30)
#define RCC_AHB1ENR        (*(volatile unsigned int *)(RCC_PERIPHERAL + RCC_AHB1ENR_OFFSET))

#define GPIOA_AFRH_OFFSET  (0x24)
#define GPIOA_AFRH	       (*(volatile unsigned int *)(GPIOA_PERIPHERAL + GPIOA_AFRH_OFFSET))

//function prototypes

void gpio_init(void);
void red_led_on(void);
void red_led_off(void);
void blue_led_on(void);
void blue_led_off(void);
void led_toggle(void);
void program_state_set(int *program_state);
void program_state_display(int *program_state);
void led_delay(void);



#endif /* GPIO_H_ */
