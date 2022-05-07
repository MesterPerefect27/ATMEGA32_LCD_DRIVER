/*
 * CLCD_INTERFACE.h
 *
 *  Created on: Mar 12, 2022
 *      Author: INTEL
 */

#ifndef HAL_CLCD2_CLCD_INTERFACE_H_
#define HAL_CLCD2_CLCD_INTERFACE_H_

#define CLCD_ROW_1  0
#define CLCD_ROW_2  1


#define CLCD_COL_1  0
#define CLCD_COL_2  1
#define CLCD_COL_3  2
#define CLCD_COL_4  3
#define CLCD_COL_5  4
#define CLCD_COL_6  5
#define CLCD_COL_7  6
#define CLCD_COL_8  7
#define CLCD_COL_9  8
#define CLCD_COL_10  9
#define CLCD_COL_11 10
#define CLCD_COL_12 11
#define CLCD_COL_13 12
#define CLCD_COL_14 13
#define CLCD_COL_15 14
#define CLCD_COL_16 15

#define Lift_TO_Right 0
#define Right_To_Lift 1


void CLCD_voidInit(void);
void CLCD_voidSendCommand(U8 Copy_u8Command);
void CLCD_voidSendData(U8 Copy_u8Data);
void CLCD_voidSendString(U8 *Copy_u8ptrString);
void CLCD_voidSendNumber(U64 Copy_u64Number);
void CLCD_voidSetPostion(U8 Copy_u8Raw,U8 Copy_u8Colum);
void CLCD_voidDrawCharachter(void);
void CLCD_voidClearDisplay(void);
void CLCD_voidClearLine(U8 Copy_u8Raw);
void CLCD_voidMoveDirection(U8 Copy_u8Direction);



#endif /* HAL_CLCD2_CLCD_INTERFACE_H_ */
