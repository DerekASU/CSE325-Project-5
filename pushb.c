/*
 * File: pushb.c
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * Computer Systems Engineering
 *
 */
#include "pushb.h"
#include "global.h"
#include "gpio.h"
#include "port.h"

void pushb_init() //initializing the buttons
{
	uc_gpio_config_C(7);
	uc_gpio_config_C(10);
	PORTC_PCR7 = 0x010A0103;
	PORTC_PCR10 = 0x010A0103;

}

void pushb_portc_debounce(int p_pin) //function to handle the debounce created by buttons
{
    uint32_t signal = 1;
    uint16_t state = 0x0000;
    do {
        state = (state << 1) | signal | 0xE000;
        signal = (~GPIOC_PDIR >> p_pin) & 0x01;
    } while (state != 0xF000);
}

