#include "tm4c123gh6pm.h"
#include <stdint.h>

/**
 * main.c
 */
int main(void)
{
    SYSCTL_RCGC2_R |= 0x20;
    GPIO_PORTF_DIR_R |= 0x0E;
    GPIO_PORTF_DEN_R |= 0x0E;

    NVIC_ST_RELOAD_R = 16000000-1; // reload reg. with max value
    NVIC_ST_CTRL_R = 5; // enable it, no interrupt, use system clock

    while(1){
        if(NVIC_ST_CTRL_R & 0x10000)
        {
            GPIO_PORTF_DATA_R ^= 2;
        }
    }
	return 0;
}
