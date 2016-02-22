/*
 * File: scanner.c
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * Computer Systems Engineering
 *
 */
#include "scanner.h"
#include "systick.h"
#include "global.h"
#include "led.h"

int pause_counter = 0;
int next_counter  = 2;
int delay_counter = 20;
int led_counter = 0;
int g_systick_counter = 0;
int count_up_down = 0;

void scanner_next_state() //function for changing the delay when button1 is pressed
{
	next_counter++;
	next_counter = next_counter%6;
	switch(next_counter){
	case 0:
			delay_counter = 5;
			break;
	case 1:
			delay_counter = 10;
			break;
	case 2:
			delay_counter = 20;
			break;
	case 3:
			delay_counter = 25;
			break;
	case 4:
			delay_counter = 30;
			break;
	case 5:
			delay_counter = 35;
			break;
	}
}

void scanner_pause()//function of pause when button 2 is pressed
{
	pause_counter++;
	pause_counter = pause_counter%2;
	if (pause_counter){
		systick_cfg_state(systick_state_disabled);
	}
	else {
		systick_cfg_state(systick_state_enabled);
	}
}

void scanner_countup(){ //incrementing the scanner
	if  (g_systick_counter > delay_counter){
		g_systick_counter = 0;
		scanner_next();
	}
}

void scanner_next(){ //
	
	if (led_counter == 0){ //start incrementing from 0
		count_up_down = 1;
	}
	else if (led_counter == 9){ //when counter hits 9 decrement
		count_up_down = 0;
	}
	if (count_up_down){ //incrementing the leds
		uc_led_off(led_counter);
		led_counter++;
		uc_led_on(led_counter);
	}
	else { //decrementing the leds
		uc_led_off(led_counter);
		led_counter--;
		uc_led_on(led_counter);
		
	}
}


