/**
******************************************************************************
  * @file		: fs_adc.c
  * @brief		: ADC Interface Class
  *				  This file contains adc interface class
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

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif

#define GIYOTIN
    
#ifdef GIYOTIN   
    #define RS PORTEbits.RE0
    #define EN PORTAbits.RA3 
    #define D4 PORTDbits.RD0
    #define D5 PORTDbits.RD1
    #define D6 PORTDbits.RD2
    #define D7 PORTDbits.RD3
#endif
  
#ifdef TIRTIL
    #define RS PORTBbits.RB0
    #define EN PORTBbits.RB1
    #define D4 PORTBbits.RB2
    #define D5 PORTBbits.RB3
    #define D6 PORTBbits.RB4
    #define D7 PORTBbits.RB5
#endif
    
void Lcd_Port(char a);
void Lcd_Cmd(char a);
void Lcd_Clear(void);
void Lcd_Set_Cursor(char a, char b);
void lcd_init(void);
void Lcd_Write_Char(char a);
void Lcd_Write_String(char *a);
void Lcd_Shift_Right(void);
void Lcd_Shift_Left(void);


#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */
