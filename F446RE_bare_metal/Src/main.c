#include <stdint.h>
#include "gpio.h"
#include "usart.h"
#include "adc.h"

int program_state = OFF;
char buffer[64];
char adc_value;

int main(void)
{
	gpio_init();
	usart1_init();
	adc_init();
	adc_conversion();

    /* Loop forever */
	for(;;){

		//led_toggle();
		program_state_set(&program_state);
		program_state_display(&program_state);
		adc_sample_signal(buffer, &program_state);
		adc_value = *buffer;

	}
}
