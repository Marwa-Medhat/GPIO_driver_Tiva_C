/*
 * gpio.h
 *
 *  Created on: 17 Feb 2020
 *      Author:DELL
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "regmap.h"
#include "std_types.h"


typedef enum {MODE_IN, MODE_OUT, MODE_AF} gpio_mode_t;
typedef enum {GPIO_PIN_0=0x00000001, GPIO_PIN_1=0x00000010, GPIO_PIN_2=0x00000100,GPIO_PIN_3=0x00001000,GPIO_PIN_4=0x00010000,GPIO_PIN_5=0x00100000,GPIO_PIN_6=0x01000000,GPIO_PIN_7=0x10000000} gpio_pins_t;
typedef enum {ALL_PIN_MASK=0xff,PIN0_MASK=0x00000001, PIN1_MASK=0x00000010,PIN2_MASK=0x00000100,PIN3_MASK=0x00001000,PIN4_MASK=0x00010000,PIN5_MASK=0x00100000,PIN6_MASK=0x01000000,PIN7_MASK=0x10000000,NON_PIN_MASK=0x00} gpio_mask_t;

typedef enum {PORTA, PORTB, PORTC,PORTD,PORTE,PORTF} gpio_port_t;
typedef enum {AHB, APB} gpio_bus_t;
typedef enum {Drive_2mA, Drive_4mA, Drive_8mA, Drive_8mA_Selw} gpio_drive_t;
typedef enum {Pad_PU,Pad_PD,PAD_NPU_NPD,PAD_OD} gpio_pad_t;
/*#define AHB
#ifdef AHB
#define   PORTA      PORTA_AHB
#define   PORTB      PORTB_AHB
#define   PORTC      PORTC_AHB
#define   PORTD      PORTD_AHB
#define   PORTE      PORTE_AHB
#define   PORTF      PORTF_AHB
#else if
#define    PORTA          PORTA_APB
#define    PORTB         PORTB_APB
#define    PORTC        PORTC_APB
#define    PORTD         PORTD_APB
#define    PORTE         PORTE_APB
#define    PORTF         PORTF_APB
#endif
*/
//Functions prototype

void GPIOBusSet(u32  port,gpio_bus_t bus);//tmm mf
gpio_bus_t GPIOBusGet(u32 port);//tmm  MF

//editted clock functions
void GPIOClockSet(u32 port);//tmam mf
void GPIOClockRst(gpio_port_t port);//tmm mf
u8 GPIOClockGet(gpio_port_t port);//tmm mf

void GPIODirModeSet(u32 port, u8 pins, gpio_mode_t Mode);//tmm mf
u8 GPIODirGet(u32 port, u8 pins); //amany
u8 GPIOModeGet(u32 port, u8 pins);//amany

void GPIOPadSet(u32 port, u8 pins, gpio_drive_t str, gpio_pad_t pad);//tmm mf
u8 GPIOPadDriveStrGet(u32 port, u8 pins);//
u8 GPIOPadOpenDrainGet(u32 port,  u8 pins);//
u8 GPIOPadPullUpGet(u32 port, u8 pins);//
u8 GPIOPadPullDownGet(u32 port, u8 pins);//

u8 GPIORead(u32 port, u8 pins);//tmm
void GPIOWrite(u32 port,u8 pins,u8 data);//tmm

//void GPIOIntConfig()

#endif /* GPIO_H_ */
