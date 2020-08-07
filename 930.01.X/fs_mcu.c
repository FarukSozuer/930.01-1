/**
******************************************************************************
  * @file		: fs_timer.c
  * @brief		: TIMER Interface Class
  *				  This file contains Timer interface class
  * @author		: Faruk Sozuer
  * @date		: 14.07.2020
  * @version	: 0.0.1
 ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 Faruk Sozuer, All Rights Reserved </center></h2>
  *
  * All information contained herein is, and remains the property of Faruk Sozuer. The
  * intellectual and technical concepts contained herein are proprietary to Faruk Sozuer
  * and are protected by trade secret or copyright law. Dissemination of this
  * information or reproduction of this material is strictly forbidden unless
  * prior written permission is obtained from Faruk Sozuer.  Access to the source code
  * contained herein is hereby forbidden to anyone except current Faruk Sozuer employees,
  * managers or contractors who have executed Confidentiality and Non-disclosure
  * agreements explicitly covering such access.
 ******************************************************************************
  */


#include <proc/pic18f46k22.h>
#include "fs_mcu.h"
#include "fs_adc.h"
#include "fs_speed_controller.h"
#include "fs_timer.h"
#include "fs_menu_controller.h"
#include "fs_eeprom.h"
/*
 * @brief  MCU Clock/oscillattor setting 
 * @param  none
 * @return none
 */
void mcu_init(void)
{
   OSCCONbits.IRCF = 0b111; // OSSCON registerının IRCF bayrağı kullanılarak 16Mhz RC osilatör seçildi.
   // OSCCONbits.SCS = 0b11;
   OSCTUNEbits.PLLEN = 0b1; //OSCTUNE registerının PLLEN bayrağı kullanılarak 4XLL aktif edildi.
     
   while(!OSCCONbits.HFIOFS); //Frekans kararlı olana kadar bekle
}



/*
 * @brief  MCU GPIO setting 
 * @param  none
 * @return none
 */
void gpio_init(void)
{    
   ANSELB = 0x00;
   TRISBbits.RB0 = 0; // RD0 is an output pin.
   TRISBbits.RB1 = 0; // RD1 is an output pin.
   TRISBbits.RB2 = 0; // RD2 is an output pin.
   TRISBbits.RB3 = 0; // RD3 is an output pin.
   TRISBbits.RB4 = 0; // RD3 is an output pin.
   TRISBbits.RB5 = 0; // RD3 is an output pin.
   
   
   ANSELDbits.ANSD2 = 0;
   ANSELDbits.ANSD3 = 0;
   TRISDbits.RD2 = 1; // RD0 is an input pin.
   TRISDbits.RD3 = 1; // RD0 is an input pin.
    
   ANSELCbits.ANSC5 = 0;
   ANSELCbits.ANSC4 = 0;
   TRISCbits.RC5 = 1; // RD0 is an input pin.
   TRISCbits.RC4 = 1; // RD0 is an input pin.
}



/*
 * @brief  MCU Clock/oscillattor setting 
 * @param  none
 * @return none
 */
void system_init(void)
{
    driver_limit.pay = 0;
    driver_limit.payda = 0;
    driver_limit.ortalama = 0;
    convert_data.convert_channel_0 = 0;
    convert_data.convert_channel_1 = 0;
    convert_data.convert_channel_2 = 0;
    convert_data.convert_channel_3 = 0;
    convert_data.convert_channel_4 = 0;
    convert_data.convert_channel_5 = 0;
    convert_data.convert_channel_6 = 0;
    convert_data.convert_channel_7 = 0;
    controller.leftMotorSpeed  = 0;
    controller.rightMotorSpeed  = 0;
    timer_value.timer_0_counter = 0;
    controller.error = 0;
    
    button_bounce_controller.menu = 0;
    button_bounce_controller.pause = 0;
    button_bounce_controller.start = 0;
    button_bounce_controller.stop = 0;
    menu_value.driver_time = (uint8_t)eepromRead(DRIVER_TIME_EEPROM_ADDRESS); // Eepromdan okunacak
    menu_value.stop_time   = (uint8_t)eepromRead(STOP_TIME_EEPROM_ADDRESS); // Eepromdan okunacak
    menu_value.speed_limit = (uint8_t)eepromRead(SPEED_LIMIT_EEPROM_ADDRESS); // Eepromdan okunacak
    __delay_ms(100);
    timer_value.remainingMinute = menu_value.driver_time; 
    timer_value.remainingSecond = 0;  // Eepromdan okunacaks
    
    //timer_value.all_driver_time_finish = ((menu_value.driver_time +1) * 60);
}