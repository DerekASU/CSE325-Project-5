/*
 * File: port.c
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * Computer Systems Engineering
 *
 */

#include "port.h"
#include "global.h"
void uc_port_gpioB()//Configuring registers the port B
{
	PORTB_PCR18 |= PORT_PCR_MUX(0b001);
	PORTB_PCR19 |= PORT_PCR_MUX(0b001);
}

void uc_port_gpioA() //configuring registers in port A
{
	PORTA_PCR1 |= PORT_PCR_MUX(0b001);
	PORTA_PCR2 |= PORT_PCR_MUX(0b001);
	PORTA_PCR4 &= ~(0b111 << 8);
	PORTA_PCR4 |= PORT_PCR_MUX(0b001);
	PORTA_PCR12 |= PORT_PCR_MUX(0b001);
}

void uc_port_gpioD() //configuring registers in port D
{
	PORTD_PCR3 |= PORT_PCR_MUX(0b001);
}

void uc_port_gpioC() //configuring registers in port C
{
	PORTC_PCR0 |= PORT_PCR_MUX(0b001);
	PORTC_PCR4 |= PORT_PCR_MUX(0b001);
	PORTC_PCR6 |= PORT_PCR_MUX(0b001);
	PORTC_PCR7 |= PORT_PCR_MUX(0b001);
	PORTC_PCR10 |= PORT_PCR_MUX(0b001);
}


