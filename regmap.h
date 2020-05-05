/*
 * regmap.h
 *
 *  Created on: 14 Feb 2020
 *      Author: DELL
 */

#ifndef REGMAP_H_
#define REGMAP_H_
#define REG volatile unsigned long int *

/*
#ifdef AHB
#define     PORTA_AHB       0x40058000
#define     PORTB_AHB       0x40059000
#define     PORTC_AHB       0x4005A000
#define     PORTD_AHB       0x4005B000
#define     PORTE_AHB       0x4005C000
#define     PORTF_AHB       0x4005D000
#ifndef
#define     PORTA_APB       0x40004000
#define     PORTB_APB       0x40005000
#define     PORTC_APB       0x40006000
#define     PORTD_APB       0x40007000
#define     PORTE_APB       0x40024000
#define     PORTF_APB       0x40025000
#endif

*/
#define     PORTA_AHB       0x40058000
#define     PORTA_APB       0x40004000

#define     PORTB_APB       0x40005000
#define     PORTB_AHB       0x40059000

#define     PORTC_APB       0x40006000
#define     PORTC_AHB       0x4005A000

#define     PORTD_APB       0x40007000
#define     PORTD_AHB       0x4005B000

#define     PORTE_APB       0x40024000
#define     PORTE_AHB       0x4005C000

#define     PORTF_APB       0x40025000
#define     PORTF_AHB       0x4005D000





#define     GPIODATA        0x3FC//
#define     GPIODIR         0x400//
#define     GPIOAFSEL       0x420//
#define     GPIODR2R        0x500
#define     GPIODR4R        0x504
#define     GPIODR8R        0x508//
#define     GPIOODR         0x50C
#define     GPIOPUR         0x510
#define     GPIOPDR         0x514
#define     GPIOSLR         0x518
#define     GPIODEN         0x51C//

/*
#define GPIOF_OFFSET(offset)       (*((volatile unsigned long int*)(GPIOF_BASE+offset)))

#define GPIOF_BASE  0x4005D000
#define GPIODATA                GPIOF_OFFSET(0x3FC)
#define GPIODIR                 GPIOF_OFFSET(0x400)
#define GPIOAFSEL               GPIOF_OFFSET(0x420)
#define GPIODR2R                GPIOF_OFFSET(0x500)
#define GPIODR4R                GPIOF_OFFSET(0x504)
#define GPIODR8R                GPIOF_OFFSET(0x508)
#define GPIODEN                 GPIOF_OFFSET(0x06C)
#define GPIOODR                 GPIOF_OFFSET(0x50C)
#define GPIOPUR                 GPIOF_OFFSET(0x510)
#define GPIOPDR                 GPIOF_OFFSET(0x514)
#define GPIOSLR                 GPIOF_OFFSET(0x518)


*/
/*
 *

volatile unsigned long int * GPIO_F_DIR = 0x4005D400;//
volatile unsigned long int *GPIO_F_RCGCGPIO = 0x400FE608;//
volatile unsigned long int *GPIO_F_DEN = 0x4005D51C;//
volatile unsigned long int *GPIO_F_DATA = 0x4005D3FC;//
volatile unsigned long int *GPIOAFSEL_F = 0x4005D420;//
volatile unsigned long int *GPIODR8R_F =0x4005D508;//
volatile unsigned long int * GPIOHBCTL = 0x400FE06C;//
volatile unsigned long int *RCC = 0x400FE060;//
*/

#define SYSCTRL_BASE  0x400FE000
#define SYSCTRL_OFFSET(offset)       (*((volatile unsigned long int*)(SYSCTRL_BASE+offset)))
#define RCC                      SYSCTRL_OFFSET(0x060)
#define RCGCGPIO                 SYSCTRL_OFFSET(0x608)
#define GPIOHBCTL                SYSCTRL_OFFSET(0x06C)

/*
volatile unsigned long int *GPIOHBCTL_f = 0x400FE06C;//
volatile unsigned long int *RCC_f = 0x400FE060;//
volatile unsigned long int *RCGCGPIO_f = 0x400FE608;//
*/
#endif /* REGMAP_H_ */
