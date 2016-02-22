/*
 * File: pushb.h
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Computer Systems Engineering
 *
 */
#ifndef PUSHB_H_
#define PUSHB_H_

typedef enum
{
	pushb_state_off = 1,
	pushb_state_on = 0
} pushb_state;


void pushb_init();
void pushb_portc_debounce(int);

#endif
