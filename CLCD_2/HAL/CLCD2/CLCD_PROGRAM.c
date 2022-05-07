/*
 * CLCD_PROGRAM.c
 *
 *  Created on: Mar 12, 2022
 *      Author: INTEL
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/DIO_interface.h"
#include"CLCD_INTERFACE.h"
#include"CLCD_PRIVET.h"
#include"CLCD_CONFIG.h"
#include"util/delay.h"
void CLCD_voidInit(void){
	U8 LOC_u8FunctionSet=FUNCTION_SET_COMMEND;
	U8 LOC_u8Display=DISPLAY_ON_OFF_COMMEND;
	U8 LOC_u8EntryMode=ENTRY_MODE_COMMEND;
	DIO_enumSetPortDirection(CLCD_Data_Port,255);
	DIO_enumSetPinDirection(CLCD_RSPIN,CLCD_control_Port,DIO_OUTPUT);
	DIO_enumSetPinDirection(CLCD_RWPIN,CLCD_control_Port,DIO_OUTPUT);
	DIO_enumSetPinDirection(CLCD_ENPIN,CLCD_control_Port,DIO_OUTPUT);
	_delay_ms(50);
#if CLCD_NUMBER_of_Line_Display==CLCD_2_line
	SET_BIT(LOC_u8FunctionSet,3);
#elif CLCD_NUMBER_of_Line_Display==CLCD_1_line
	CLR_BIT(LOC_u8FunctionSet,3);
#endif

#if ClCD_Display_Font==CLCD_5_7_Font
	SET_BIT(LOC_u8FunctionSet,2);
#elif ClCD_Display_Font==CLCD_5_8_Font
	CLR_BIT(LOC_u8FunctionSet,2);
#endif

#if CLCD_Display==CLCD_Display_ON
	SET_BIT(LOC_u8Display,2);
#elif CLCD_Display==CLCD_Display_OFF
	CLR_BIT(LOC_u8Display,2);
#endif

#if CLCD_Cursor==CLCD_CURSOR_OFF
	CLR_BIT(LOC_u8Display,1);
#elif CLCD_Cursor==CLCD_CURSOR_ON
	SET_BIT(LOC_u8Display,1);
#endif

#if CLCD_Cursor_Blink==CLCD_CURSOR_BLINK_OFF
	CLR_BIT(LOC_u8Display,0);
#elif CLCD_Cursor_Blink==CLCD_CURSOR_BLINK_ON
	SET_BIT(LOC_u8Display,0);
#endif

#if CLCD_Shift_Mode==CLCD_Disable_Shift
	CLR_BIT(LOC_u8EntryMode,0);
#elif CLCD_Shift_Mode==CLCD_Shift_Left
	SET_BIT(LOC_u8EntryMode,0);
	SET_BIT(LOC_u8EntryMode,1);
#elif CLCD_Shift_Mode==CLCD_Shift_Right
	SET_BIT(LOC_u8EntryMode,0);
	CLR_BIT(LOC_u8EntryMode,1);
#endif

#if CLCD_MODE==CLCD_8BIT
	SET_BIT(LOC_u8FunctionSet,4);
#elif CLCD_MODE==CLCD_4BIT
	CLR_BIT(LOC_u8FunctionSet,4);
	CLCD_voidSendCommand(LOC_u8FunctionSet>>4);

#endif

	CLCD_voidSendCommand(LOC_u8FunctionSet);
	_delay_ms(1);
	CLCD_voidSendCommand(LOC_u8Display);
	_delay_ms(1);
	CLCD_voidSendCommand(CLCD_DISLAY_CLEAR);
	_delay_ms(2);
	CLCD_voidSendCommand(LOC_u8EntryMode);
	_delay_ms(1);
}
void CLCD_voidSendCommand(U8 Copy_u8Command){
	DIO_enumSetPinValue(CLCD_RSPIN,CLCD_control_Port,DIO_LOW);
	DIO_enumSetPinValue(CLCD_RWPIN,CLCD_control_Port,DIO_LOW);

#if CLCD_MODE==CLCD_8BIT
	DIO_enumSetPortValue(CLCD_Data_Port,Copy_u8Command);
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_LOW);
	_delay_ms(1);

#elif CLCD_MODE==CLCD_4BIT
	DIO_enumSetPortValue(CLCD_Data_Port,(Copy_u8Command&0XF0));
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_LOW);
	_delay_ms(1);
	DIO_enumSetPortValue(CLCD_Data_Port,(Copy_u8Command<<4));
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_LOW);
	_delay_ms(2);
#endif
}
void CLCD_voidSendData(U8 Copy_u8Data){

	DIO_enumSetPinValue(CLCD_RSPIN,CLCD_control_Port,DIO_HIGH);
	DIO_enumSetPinValue(CLCD_RWPIN,CLCD_control_Port,DIO_LOW);

#if CLCD_MODE==CLCD_8BIT
	DIO_enumSetPortValue(CLCD_Data_Port,Copy_u8Data);
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_LOW);
	_delay_ms(1);

#elif CLCD_MODE==CLCD_4BIT
	DIO_enumSetPortValue(CLCD_Data_Port,(Copy_u8Data&0XF0));
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_LOW);
	_delay_ms(1);
	DIO_enumSetPortValue(CLCD_Data_Port,(Copy_u8Data<<4));
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_LOW);
	_delay_ms(2);

#endif
}
void CLCD_voidSendString(U8 *Copy_u8ptrString){
	U8 LOC_u8iteration=0;
	while(Copy_u8ptrString[LOC_u8iteration]!='\0'){
		CLCD_voidSendData(Copy_u8ptrString[LOC_u8iteration]);
		LOC_u8iteration++;
	}
}
void CLCD_voidSendNumber(U64 Copy_u64Number){
	U64 LOC_u64Revers=1;
	if(Copy_u64Number==0){
		CLCD_voidSendData('0');
	}else{
		while(Copy_u64Number!=0){
			LOC_u64Revers=(LOC_u64Revers*10)+(Copy_u64Number%10);
			Copy_u64Number/=10;
		}
	}
	while(LOC_u64Revers!=1){
		CLCD_voidSendData((LOC_u64Revers%10)+48);
		LOC_u64Revers/=10;
	}
}
void CLCD_voidSetPostion(U8 Copy_u8Raw,U8 Copy_u8Colum){
	if(Copy_u8Raw==CLCD_ROW_1){
		CLCD_voidSendCommand(CLCD_ROW1_Address+(Copy_u8Colum));
	}else if(Copy_u8Raw==CLCD_ROW_2){
		CLCD_voidSendCommand(CLCD_ROW2_Address+(Copy_u8Colum));
	}
}

void CLCD_voidDrawCharachter(void){
	CLCD_voidSendCommand(CLCD_Set_CGRAM);
	U8 LOC_u8ITERATION=0;
	for(LOC_u8ITERATION=0;LOC_u8ITERATION<(sizeof(CLCD_u8SptialChar))/(sizeof(CLCD_u8SptialChar[LOC_u8ITERATION]));LOC_u8ITERATION++){
		CLCD_voidSendData(CLCD_u8SptialChar[LOC_u8ITERATION]);
	}
}
void CLCD_voidClearDisplay(void){
	CLCD_voidSendCommand(0X1);
	_delay_ms(2);
}
void CLCD_voidClearLine(U8 Copy_u8Raw){
	if(Copy_u8Raw==CLCD_ROW_1){
		CLCD_voidSetPostion(CLCD_ROW_1,CLCD_COL_1);
		CLCD_voidSendString((U8*)"                ");
	}else if(Copy_u8Raw==CLCD_ROW_2){
		CLCD_voidSetPostion(CLCD_ROW_2,CLCD_COL_1);
		CLCD_voidSendString((U8*)"                ");
	}
}
void CLCD_voidMoveDirection(U8 Copy_u8Direction){
	if(Copy_u8Direction==Lift_TO_Right){
		CLCD_voidSendCommand(0b00000110);
	}else if(Copy_u8Direction==Right_To_Lift){
		CLCD_voidSendCommand(0b00000100);
	}
}

