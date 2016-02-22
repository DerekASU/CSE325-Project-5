/*
 * File: gpio.c
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * Computer Systems Engineering
 *
 */
#include "gpio.h"
#include "global.h"
void uc_gpio_config_B(int n) //function to configure the specific gpio ports for output.
{
	PTB_BASE_PTR->PDDR |= 1 << n;
}

void uc_gpio_config_A(int n) //function to configure the specific gpio ports for output.
{
	PTA_BASE_PTR->PDDR |= (1 << n);
}



void uc_gpio_config_D(int n) //function to configure the specific gpio ports for output.
{
	PTD_BASE_PTR->PDDR |= (1 << n);
}

void uc_gpio_config_C_led(int n) //function to configure the specific gpio ports for output.
{
	PTC_BASE_PTR->PDDR |= (1 << n);
}

void uc_gpio_config_C(int n) //function to configure the specific gpio ports for input.
{
	PTC_BASE_PTR->PDDR &= ~(1 << n);
}

