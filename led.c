/*
 * File: led.c
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * Computer Systems Engineering
 *
 */
#include "led.h"
#include "global.h"

void uc_led_on(int n)//turning on individual LEDs
{
	switch(n){
	case 0:
		GPIOB_PDOR |= 1 << 18;
		break;
	case 1:
		GPIOA_PDOR |= 1 << 1;
		break;
	case 2:
		GPIOB_PDOR |= 1 << 19;
		break;
	case 3:
		GPIOA_PDOR |= 1 << 2;
		break;
	case 4:
		GPIOC_PDOR |= 1 << 0;
		break;
	case 5:
		GPIOD_PDOR |= 1 << 3;
		break;
	case 6:
		GPIOC_PDOR |= 1 << 4;
		break;
	case 7:
		GPIOA_PDOR |= 1 << 12;
		break;
	case 8:
		GPIOC_PDOR |= 1 << 6;
		break;
	case 9:
		GPIOA_PDOR |= 1 << 4;
		break;
	}
}

void uc_led_off(int n)//turning off individual LEDs
{
	switch(n){
	case 0:
		GPIOB_PDOR &= ~(1 << 18);
		break;
	case 1:
		GPIOA_PDOR &= ~(1 << 1);
		break;
	case 2:
		GPIOB_PDOR &= ~(1 << 19);
		break;
	case 3:
		GPIOA_PDOR &= ~(1 << 2);
		break;
	case 4:
		GPIOC_PDOR &= ~(1 << 0);
		break;
	case 5:
		GPIOD_PDOR &= ~(1 << 3);
		break;
	case 6:
		GPIOC_PDOR &= ~(1 << 4);
		break;
	case 7:
		GPIOA_PDOR &= ~(1 << 12);
		break;
	case 8:
		GPIOC_PDOR &= ~(1 << 6);
		break;
	case 9:
		GPIOA_PDOR &= ~(1 << 4);
		break;
	}
}

void uc_led_all_off()//turning off all LEDs 
{
	uc_led_off(0);
	uc_led_off(1);
	uc_led_off(2);
	uc_led_off(3);
	uc_led_off(4);
	uc_led_off(5);
	uc_led_off(6);
	uc_led_off(7);
	uc_led_off(8);
	uc_led_off(9);
}

void uc_led_all_on()//turning on all LEDs
{
	uc_led_on(0);
	uc_led_on(1);
	uc_led_on(2);
	uc_led_on(3);
}
