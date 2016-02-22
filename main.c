/*
 * File: main.c
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * Computer Systems Engineering
 *
 */


#include "global.h"
#include "gpio.h"
#include "int.h"
#include "led.h"
#include "port.h"
#include "pushb.h"
#include "scanner.h"
#include "sim.h"
#include "systick.h"



static callback_v_t g_portc_callback[32] = { 0 };

void hw_init();
void sw_init();
void push1_pressed();
void push2_pressed();
void portscd_isr();
void systick_callback(uint32_t);

void hw_init() //set all ports to gpio and all registers to output/input
{
	int_mask_all();
	uc_sim_clk();
	uc_port_gpioB();
	uc_port_gpioA();
	uc_port_gpioD();
	uc_port_gpioC();
	uc_gpio_config_B(18);
	uc_gpio_config_A(1);
	uc_gpio_config_B(19);
	uc_gpio_config_A(2);
	uc_gpio_config_C_led(0);
	uc_gpio_config_D(3);
	uc_gpio_config_C_led(4);
	uc_gpio_config_A(12);
	uc_gpio_config_C_led(6);
	uc_gpio_config_A(4);
	pushb_init();
	int_init(int_src_portscd, int_priority_3, int_state_enabled);
	systick_init(systick_period_isr_25_ms, systick_int_enabled, systick_state_enabled, systick_callback);
	int_unmask_all();
}


void sw_init() // button callbacks to the push1 and push2 function
{
	g_portc_callback[7] = push1_pressed;
	g_portc_callback[10] = push2_pressed;
}

void push1_pressed()
{
	scanner_next_state();	
}

void push2_pressed()
{
	scanner_pause();
	
}
void portscd_isr()
{
    // Check PTC7
    if (PORTC_ISFR & 0x00000080) {
        // Debounce before clearing the interrupt request flag. This will eliminate multiple invocations of this
        // ISR due to the switch bouncing up and down.
        pushb_portc_debounce(7);
        PORTC_ISFR |= 0x00000080;
        if (g_portc_callback[7]) g_portc_callback[7]();
    }
    else if (PORTC_ISFR & 0x00000400){
        // Debounce before clearing the interrupt request flag. This will eliminate multiple invocations of this
        // ISR due to the switch bouncing up and down.
        pushb_portc_debounce(10);
        PORTC_ISFR |= 0x00000080;
        if (g_portc_callback[10]) g_portc_callback[10]();
    }
}
void systick_callback(uint32_t p_counter __attribute__((unused))) //systick callback incrementing counter/scanner
{
	g_systick_counter++;
	scanner_countup();
}


int main()
{

	hw_init();
	sw_init();
	for(;;){
	}
    // main() should never return, but C requires that main() return an int, so here it is.
    return 0;
}



