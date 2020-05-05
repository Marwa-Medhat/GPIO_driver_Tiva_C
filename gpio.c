/*
 * gpio.c
 *
 *  Created on: 17 Feb 2020
 *      Author: DELL
 */

#include "gpio.h"
#include "regmap.h"
#include "std_types.h"

#define SETBIT(reg,n_bits) ( reg) |= (1<<n_bits)
#define CLRBIT(reg, bit) (reg) &= ~(1<<bit)
#define TOGGLEBIT(reg, bit) (reg) ^= (1<<bit)
#define GETBIT(reg, bit) (((reg)>>(bit)) & 0x01)


//---SELECT MODE& DIRECTION-----------
void GPIODirModeSet(u32 port, u8 pins, gpio_mode_t Mode)
//port 32 3shan ba5od al address nfso//pins hya al pins 2li a5trtha w 3yza azbta
{
    //--------------b5tar ALF wla GPIO-----------------------
//     GPIODirModeSet(PORTF_AHB, 0x02, MODE_OUT); //tmm mf

    volatile u32 * reg1 = port + GPIOAFSEL; //addres of register mn al base+offset

    u32 data = *reg1;//by7ot al 7agat 2li fe register fe variable data
    data &= ~(pins);//awl 7aga b3mla hia any h3ml clear lmkan el bit ely hstdmha
    //mode select 0 0 1 0
                 // 1 1 0 1//inv pin
                  //0 0 1 1//data
                  //0 0 0 1
                  //0 0 1 0
    //              0 0 1 1           data
   if (Mode == MODE_AF){ //b5tar alternate lw and m3 ff
        data |= (0xff & pins);
   }else{
        data |= (0x00 & pins);//b5tar l GPIO b2ni b3m and m3 0
*reg1 = data;
   }//by7ot value al data gwa al register
//------------b7dd al direction bta3 al AFSL w al GPIO input wla aoutput --------------------------
       volatile u32 * reg2 = port + GPIODIR; //addres of register mn al base+offset
       u32 data1 = *reg2;//by7ot al 7agat 2li fe register fe variable data   GPIODIR
       data1 &= ~(pins);//awl 7aga b3mla hia any h3ml clear lmkan el bit ely hstdmha
       if (Mode == MODE_OUT){
              data1 = (0xff & pins);
}else if(Mode == MODE_IN){
              data1 = (0x00 & pins);
}
*reg2 = data1;
 // 0 0 1 0 pins
 //1 1 0 1 not pin
 //0 0 1 1      data
 //0 0 0 1 data&not pins
 //0 0 1 0



}

u8 GPIODirGet(u32 port, u8 pins){//y3ni hy5tar mask m3in llbits ely 3aiz y3rf  el directon bta3ha
    volatile u32 * reg = port + GPIODIR; //addres of register mn al base+offset
                                            u32 data = *reg;
                                            //data&=pins;//b5tar bits m3ina yrg3ha wl ba2y laa yr3ha zeros kda kda hia dont care blnsbaly
                                            return data;
}


u8 GPIOModeGet(u32 port, u8 pins)
{
    volatile u32 * reg = port + GPIOAFSEL; //addres of register mn al base+offset
                                               u32 data = *reg;
                                               //data&=pins;//b5tar bits m3ina yrg3ha wl ba2y laa yr3ha zeros kda kda hia dont care blnsbaly
                                               return data;
}

//--------------------------------------tzbet al bus ----------------------------
void GPIOBusSet(u32 port,gpio_bus_t bus)
{

   if(bus==AHB){
        //register ms2ol ano by5atr AHB w APB
        //bs a7na 3mlna handle 3n tre2 al enum a5trna AHB wla APB
        SETBIT(GPIOHBCTL,port);

      if(port == PORTA){
       //  PORTA= PORTA_AHB; kda bt3mla error
          #define PORTA   PORTA_AHB;
      }else if(port == PORTB){
          #define PORTB   PORTB_AHB;

      }else if(port == PORTC){
          #define  PORTC   PORTC_AHB;
      }else if(port == PORTD){
          #define PORTD   PORTD_AHB;
      }else if(port == PORTE){
           #define PORTE   PORTE_AHB;
      }else if(port == PORTF){
        #define PORTF  PORTF_AHB;
      }
  }
    else if(bus==APB){
      CLRBIT(GPIOHBCTL,port);

      if(port == 0){
             //  PORTA= PORTA_AHB; kda bt3mla error
                #define PORTA   PORTA_APB;
            }else if(port == 1){

                #define PORTB   PORTB_APB;
            }else if(port == 2){

                #define  PORTC   PORTC_APB;
            }else if(port == 3){

                #define PORTD   PORTD_APB;
            }else if(port == 4){

                 #define PORTE   PORTE_APB;
            }else if(port == 5){

              #define PORTF  PORTF_APB;
            }
  }



}
/*
gpio_bus_t GPIOBusGet(u32 port){
     if(port==PORTA_APB||PORTB_APB||PORTC_APB||PORTD_APB||PORTE_APB||PORTF_APB){
         return APB ;
     }else if(port==PORTA_AHB||PORTB_AHB||PORTC_AHB||PORTD_AHB||PORTE_AHB||PORTF_AHB){
         return AHB ;
     }
}
*/
//------------------------------------------------------------------------
//clock fn
void GPIOClockSet( u32 port) //m3 kol call lfn bdi clock llport
{

 if(port==PORTF_AHB){
     SETBIT(RCGCGPIO,5);

 }else if(port==PORTE_AHB){
     SETBIT(RCGCGPIO,4);

 }else if(port==PORTD_AHB){
     SETBIT(RCGCGPIO,3);

 }else if(port==PORTC_AHB){
     SETBIT(RCGCGPIO,2);

 }else if(port==PORTB_AHB){
     SETBIT(RCGCGPIO,1);

 }else if(port==PORTA_AHB){
     SETBIT(RCGCGPIO,1);

 }


}

void GPIOClockRst( gpio_port_t port)
{
    if(port==PORTF_AHB){
        CLRBIT(RCGCGPIO,5);

    }else if(port==PORTE_AHB){
        CLRBIT(RCGCGPIO,4);

    }else if(port==PORTD_AHB){
        CLRBIT(RCGCGPIO,3);

    }else if(port==PORTC_AHB){
        CLRBIT(RCGCGPIO,2);

    }else if(port==PORTB_AHB){
        CLRBIT(RCGCGPIO,1);

    }else if(port==PORTA_AHB){
        CLRBIT(RCGCGPIO,1);

    }
}
u8 GPIOClockGet(gpio_port_t port){ //(value of CLock)byd5l al enum 2li hya portA=0 l2ano awl rkm gwa al enum w hakza lkol al ports
                      return port; //retun rkm al port
                       }
//--------------------------------------------------------------
//-----------------------------------------set pad control-------------------------------------------------------------------------
void GPIOPadSet(u32 port, u8 pins, gpio_drive_t str, gpio_pad_t pad){
       //typedef enum {Drive_2mA, Drive_4mA, Drive_8mA, Drive_8mA_Selw} gpio_drive_t;
       // typedef enum {Pad_PU,Pad_PD,PAD_NPU_NPD,PAD_OD} gpio_pad_t;
    volatile u32  *reg1 = (port + GPIODEN); //addres of register mn al base+offset
    *reg1 = pins;
       if (str == Drive_2mA){
           volatile u32 * reg = port + GPIODR2R; //addres of register mn al base+offset
               u32 data = *reg;
               data &= ~(pins);
               data |= (0xff & pins);
       }else if(str == Drive_4mA){
               volatile u32 * reg = port + GPIODR4R; //addres of register mn al base+offset
               u32 data = *reg;
               data &= ~(pins);
               data |= (0xff & pins);

       }else if(str == Drive_8mA){
                       volatile u32 * reg = port + GPIODR8R; //addres of register mn al base+offset
                       u32 data = *reg;
                       data &= ~(pins);
                       data |= (0xff & pins);

       }else if(str==Drive_8mA_Selw){
                          volatile u32 * reg1 = port + GPIODR8R; //addres of register mn al base+offset
                          u32 data1 = *reg1;
                          data1 &= ~(pins);
                          data1 |= (0xff & pins);//
                          volatile u32 * reg2 = port + GPIOSLR; //addres of register mn al base+offset
                          u32 data = *reg2;
                          data &= ~(pins);
                          data |= (0xff & pins);
       }
       if(pad==Pad_PU){
                      volatile u32 * reg = port + GPIOPUR; //addres of register mn al base+offset
                      u32 data = *reg;
                       data &= ~(pins);
                       data |= (0xff & pins);
       }else if(pad==Pad_PD){
                            volatile u32 * reg = port + GPIOPDR; //addres of register mn al base+offset
                            u32 data = *reg;
                            data &= ~(pins);
                            data |= (0xff & pins);

       }else if(pad==PAD_OD){
                             volatile u32 * reg = port + GPIOODR; //addres of register mn al base+offset
                             u32 data = *reg;
                             data &= ~(pins);
                             data |= (0xff & pins);

       }else if(pad==PAD_NPU_NPD){
                                      volatile u32 * reg1 = port + GPIOPUR; //addres of register mn al base+offset
                                       u32 data1 = *reg1;
                                       data1 &= ~(pins);
                                       data1 |= (0x00 & pins);
                                       volatile u32 * reg = port + GPIOPDR; //addres of register mn al base+offset
                                       u32 data = *reg;
                                       data &= ~(pins);
                                        data |= (0x00 & pins);
       }





}
//-----------------------------------------get pad fun--------------------------------------------------------------------------

u8 GPIOPadDriveStrGet(u32 port, u8 pins){//typedef enum {Drive_2mA, Drive_4mA, Drive_8mA, Drive_8mA_Selw} gpio_drive_t;

    volatile u32 * reg1 = port + GPIODR2R; //addres of register mn al base+offset
    volatile u32 * reg2 = port + GPIODR4R; //addres of register mn al base+offset
    volatile u32 * reg3 = port + GPIODR8R; //addres of register mn al base+offset
    volatile u32 * reg4 = port + GPIOSLR; //addres of register mn al base+offset

    u32 data1 = *reg1&pins;
    u32 data2 = *reg2&pins;
    u32 data3 = *reg3&pins;
    u32 data4 = *reg4&pins;

if(data1==0&&data2==0&&data4==0){
    return Drive_8mA;
}else if(data2==0&&data3==0&&data4==0){
    return Drive_2mA;
}else if(data1==0&&data3==0&&data4==0){
    return Drive_4mA;
}else if(data1==0&&data3==0&&data2==0){
    return Drive_8mA_Selw;

}
}

u8 GPIOPadOpenDrainGet(u32 port,  u8 pins){
    volatile u32 * reg = port + GPIOODR; //addres of register mn al base+offset
                                        u32 data = *reg;
                                        //data&=pins;//b5tar bits m3ina yrg3ha wl ba2y laa yr3ha zeros kda kda hia dont care blnsbaly
                                        return data;
}
u8 GPIOPadPullUpGet(u32 port, u8 pins){//bs return type mt3rf 8 bits bs m4 mfrod ykon 32bit 34an kimt
    volatile u32 * reg = port + GPIOPUR; //addres of register mn al base+offset
                                    u32 data = *reg;
                                    //data&=pins;//b5tar bits m3ina yrg3ha wl ba2y laa yr3ha zeros kda kda hia dont care blnsbaly
                                    return data;
}
u8 GPIOPadPullDownGet(u32 port, u8 pins){
    volatile u32 * reg = port + GPIOPDR; //addres of register mn al base+offset
                                u32 data = *reg;
                                //data&=pins;//b5tar bits m3ina yrg3ha wl ba2y laa yr3ha zeros kda kda hia dont care blnsbaly
                                return data;

}
//------------------------------------------*****DATA READ*****------------------------------------------------------------------
u8 GPIORead(u32 port, u8 pins){

    volatile u32  *reg = (0x4005D000 + GPIODATA); //addres of register mn al base+offset
    //kda bzbt pin ely 3aizaha digital 7sb el mask bta3y bits ele h5tarha hia ely 3aiza 3ndha digital en


return *reg;
}
//----------------------------------------****DATA WRITE*****-------------------------------------------------------------------
void GPIOWrite(u32 port, u8 pins, u8 data){
   volatile u32  *reg = (0x4005D000 + GPIODATA); //addres of register mn al base+offset
//
    //data&=pins;
  *reg|=data;
  //data&=pins;//bktb data bta3ty bs fe al amakn al mask fiha =1 //m4 3rfa hl da lih lazma wla laa

   // volatile u32 *GPIODATA;

}




/*
    *GPIOHBCTL |= (1<<5);
    *GPIO_F_RCGCGPIO |= (1<<5);
    *GPIO_F_DEN |=(1<<PIN);
    * GPIO_F_DIR |= (1<<PIN);
    *GPIOAFSEL_F &= ~(1<<PIN);
    *GPIODR8R_F |=(1<<PIN);
    *GPIO_F_DATA = (1<<PIN);

    */



































//typedef enum {AHB, APB} gpio_bus_t;
//typedef enum {PORTA, PORTB, PORTC,PORTD,PORTE,PORTF} gpio_port_t;
//msh kmla
/*
void GPIOBusSet(unsigned long int port,gpio_bus_t bus)
{
if(port==PORTA&&bus=AHB)
{


}

}
// PORTD_AHB       0x40007000
gpio_bus_t GPIOBusGet(unsigned long int port)
{
//if(port==PORTA&&//kema gya mn busSet )
//{

//}

}


*/

