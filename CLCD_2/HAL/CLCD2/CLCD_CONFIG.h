/*
 * CLCD_CONFIG.h
 *
 *  Created on: Mar 12, 2022
 *      Author: INTEL
 */

#ifndef HAL_CLCD2_CLCD_CONFIG_H_
#define HAL_CLCD2_CLCD_CONFIG_H_

const U8 CLCD_u8SptialChar[]=
       {  0x00, 0x00, 0x07, 0x04, 0x04, 0x1F, 0x00,   0x00,
		  0x00, 0x00, 0x07, 0x05, 0x05, 0x1F, 0x00,   0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08,   0x10,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   0x00,
		  0x00, 0x00, 0x07, 0x05, 0x05, 0x1F, 0x00,   0x00,
		  0x00, 0x00, 0x07, 0x01, 0x01, 0x1F, 0x00,   0x00,
		  0x00, 0x00, 0x07, 0x05, 0x05, 0x1F, 0x00,   0x00,
		  0x00, 0x00, 0x01, 0x01, 0x01, 0x1F, 0x00,   0x00
};

//Data&Control PORT
/*OPTION PORT
 * DIO_PORTA
 * DIO_PORTB
 * DIO_PORTC
 * DIO_PORTD*/
#define CLCD_Data_Port      DIO_PORTA
#define CLCD_control_Port   DIO_PORTB
//CONTROL PINS
/*OPTION
 * DIO_PIN0
 * DIO_PIN1
 * DIO_PIN2
 * DIO_PIN3
 * DIO_DIO_PIN4
 * DIO_PIN5
 * DIO_PIN6
 * DIO_PIN7*/
#define CLCD_RSPIN  DIO_PIN0
#define CLCD_RWPIN  DIO_PIN1
#define CLCD_ENPIN  DIO_PIN2
/*
 * CLCD_4BIT
 * CLCD_8BIT*/
#define CLCD_MODE CLCD_4BIT
/*
 * CLCD_1_line
 * CLCD_2_line*/
#define CLCD_NUMBER_of_Line_Display CLCD_2_line
/*
 * CLCD_5_7_Font
 * CLCD_5_8_Font*/
#define ClCD_Display_Font CLCD_5_7_Font
/*
 * CLCD_Display_ON
 * CLCD_Display_OFF*/
#define CLCD_Display  CLCD_Display_ON
/*
 * CLCD_CURSOR_ON
 * CLCD_CURSOR_OFF */
#define CLCD_Cursor  CLCD_CURSOR_ON
/*
 * CLCD_CURSOR_BLINK_ON
 * CLCD_CURSOR_BLINK_OFF*/
#define CLCD_Cursor_Blink CLCD_CURSOR_BLINK_OFF
/*
 * CLCD_Shift_Left
 * CLCD_Shift_Right
 * CLCD_Disable_Shift*/
#define CLCD_Shift_Mode  CLCD_Disable_Shift

#endif /* HAL_CLCD2_CLCD_CONFIG_H_ */
