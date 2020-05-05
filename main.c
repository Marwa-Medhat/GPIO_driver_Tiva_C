

/**
 * main.c
 */
#include "regmap.h"
#include "std_types.h"
#include "gpio.h"


int main(void)
{

     GPIOClockSet(PORTF_AHB);//tmam mf
     GPIOBusSet(PORTF,AHB);//tmm mf
     GPIODirModeSet(PORTF_AHB, 0xff, MODE_OUT);//tmm mf
     GPIOPadSet(PORTF_AHB,0xff, Drive_8mA, PAD_NPU_NPD);//tmm mf
     GPIOWrite(PORTF_AHB,0xff,0x04);//tmm

   /*
         GPIOClockSet(PORTF_AHB);//tmam mf
         GPIOBusSet(PORTF,AHB);//tmm mf
         GPIODirModeSet(PORTF_AHB,ALL_PIN_MASK , MODE_OUT);//tmm mf
         GPIOPadSet(PORTF_AHB,ALL_PIN_MASK, Drive_8mA, PAD_NPU_NPD);//tmm mf
         GPIOWrite(PORTF_AHB,ALL_PIN_MASK,GPIO_PIN_0);//tmm

*/

	return 0;
}
