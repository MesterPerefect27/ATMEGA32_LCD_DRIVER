/*
 * CLCD_PRIVET.h
 *
 *  Created on: Mar 12, 2022
 *      Author: INTEL
 */

#ifndef HAL_CLCD2_CLCD_PRIVET_H_
#define HAL_CLCD2_CLCD_PRIVET_H_
/*Commend Bits
 * Bit4-->DL=1(4BIT/8BIT)
 * Bit3-->N=0(1LINE/2LINE)
 * Bit2-->F=0(5*8/5*7)
 * */
#define FUNCTION_SET_COMMEND  0b00110000
/*Commend Bits
 * Bit2-->D=1(ON/OFF)
 * Bit1-->C=0(CursorON/OFF)
 * Bit0-->B=0(BlinkON/OFF)
 * */
#define DISPLAY_ON_OFF_COMMEND 0b00001100
/*Commend Bits
 * Bit1-->I/D=1(INCREASED/DECREASED)
 * Bit0-->SH=0(SHIFT)
 * */
#define ENTRY_MODE_COMMEND 0b00000110
/*CLER COMMEND*/
#define CLCD_DISLAY_CLEAR  0b00000001
/*DDRAM*/
#define CLCD_ROW1_Address 0X80
#define CLCD_ROW2_Address 0X80+64
/*CGRAM*/
#define CLCD_Set_CGRAM    0X40
/*CLCD_MODE*/
#define CLCD_4BIT   0
#define CLCD_8BIT   1
/*CLCD_LINE*/
#define CLCD_1_line 2
#define CLCD_2_line 3
/*CLCD_FONT*/
#define CLCD_5_7_Font 4
#define CLCD_5_8_Font 5
/*CLCD_DISPLAY*/
#define CLCD_Display_ON  6
#define CLCD_Display_OFF 7
/*CLCD_CURSOR*/
#define CLCD_CURSOR_ON  8
#define CLCD_CURSOR_OFF 9
/*CLCD_CURSOR_BLINK*/
#define CLCD_CURSOR_BLINK_ON  10
#define CLCD_CURSOR_BLINK_OFF 11
/*CLCD_SHIFT*/
#define CLCD_Shift_Left    12
#define CLCD_Shift_Right   13
#define CLCD_Disable_Shift 14

#endif /* HAL_CLCD2_CLCD_PRIVET_H_ */
