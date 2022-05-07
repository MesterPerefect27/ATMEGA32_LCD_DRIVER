/*
 * main.c

 *
 *  Created on: Mar 4, 2022
 *      Author: INTEL
 */
#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../HAL/CLCD2/CLCD_interface.h"
#include"util/delay.h"
int main(void){

	CLCD_voidInit();
	//CLCD_voidDrawCharachter();
	CLCD_voidSendNumber(1234);

	while(1){
		//Task(1)-->shifting name in LCD English&Arabic
	/*	U8 i=1;
		S8 I=13;
		for(;i<13&&I>1;i++,I--){
			CLCD_voidSetPostion(CLCD_ROW_1,i);
			CLCD_voidSendString((U8*)"OMAR");
			CLCD_voidDrawCharachter();
			CLCD_voidSetPostion(CLCD_ROW_2,I);
			for(U8 j=0;j<3;j++){
				CLCD_voidSendData(j);
			}
			_delay_ms(1000);
			CLCD_voidClearDisplay();

		}
		if((i==13)){
			CLCD_voidSetPostion(CLCD_ROW_1,13);
			CLCD_voidSendString((U8*)"OMA");
			CLCD_voidSetPostion(CLCD_ROW_1,CLCD_COL_1);
			CLCD_voidSendData('R');
			CLCD_voidSetPostion(CLCD_ROW_2,I);
			for(U8 j=0;j<3;j++){
				CLCD_voidSendData(j);
			}
			_delay_ms(1000);
			CLCD_voidClearDisplay();

			I--;

			i++;
		}
		if((i==14)){
			CLCD_voidSetPostion(CLCD_ROW_1,14);
			CLCD_voidSendString((U8*)"OM");
			CLCD_voidSetPostion(CLCD_ROW_1,CLCD_COL_1);
			CLCD_voidSendData('A');
			CLCD_voidSetPostion(CLCD_ROW_1,CLCD_COL_2);
			CLCD_voidSendData('R');
			CLCD_voidSetPostion(CLCD_ROW_2,I);
			for(U8 j=0;j<3;j++){
				CLCD_voidSendData(j);
			}
			_delay_ms(1000);
			CLCD_voidClearDisplay();

			i++;
		}
		if(i==15){
			CLCD_voidSetPostion(CLCD_ROW_1,15);
			CLCD_voidSendString((U8*)"O");
			CLCD_voidSetPostion(CLCD_ROW_1,CLCD_COL_1);
			CLCD_voidSendData('M');
			CLCD_voidSetPostion(CLCD_ROW_1,CLCD_COL_2);
			CLCD_voidSendData('A');
			CLCD_voidSetPostion(CLCD_ROW_1,CLCD_COL_3);
			CLCD_voidSendData('R');
			CLCD_voidSetPostion(CLCD_ROW_2,1);
			CLCD_voidSendData(2);
			CLCD_voidSetPostion(CLCD_ROW_2,0);
			CLCD_voidSendData(1);
			CLCD_voidSetPostion(CLCD_ROW_2,CLCD_COL_16);
			CLCD_voidSendData(0);
			_delay_ms(1000);
			CLCD_voidClearDisplay();
			CLCD_voidSetPostion(CLCD_ROW_1,CLCD_COL_1);
			CLCD_voidSendString((U8*)"OMAR");
			CLCD_voidSetPostion(CLCD_ROW_2,0);
			CLCD_voidSendData(2);
			CLCD_voidSetPostion(CLCD_ROW_2,CLCD_COL_15);
			CLCD_voidSendData(0);
			CLCD_voidSetPostion(CLCD_ROW_2,CLCD_COL_16);
			CLCD_voidSendData(1);
			_delay_ms(500);
			CLCD_voidClearDisplay();

			i=2;

		}*/
		//CLCD_voidSendString((U8*)"MMAR");
		//CLCD_voidSendData('A');
		//Task(2)-->story mo salah


		/*for(U8 i=0;i<15;i++){
			CLCD_voidSetPostion(CLCD_ROW_1,CLCD_COL_1);
			CLCD_voidSendString((U8*)"HELLO WORLD");
			CLCD_voidSendString((U8*)" ");
			CLCD_voidSetPostion(CLCD_ROW_1,CLCD_COL_1);
			CLCD_voidSendString((U8*)"MY NAME MO SALAH");
			CLCD_voidSendString((U8*)" ");
			CLCD_voidDrawCharachter();
			CLCD_voidSetPostion(CLCD_ROW_2,i);
			CLCD_voidSendData(3);
			CLCD_voidSendData(4);
			CLCD_voidSetPostion(CLCD_ROW_2,15);
			CLCD_voidSendData(5);
			_delay_ms(100);
			CLCD_voidSendString((U8*)" ");

		}
		//_delay_ms(1000);
		//CLCD_voidClearDisplay();

		//_delay_ms(1000);
		//CLCD_voidClearDisplay();
		/*for(U8 i=0;i<15;i++){
			CLCD_voidSetPostion(CLCD_ROW_1,CLCD_COL_1);
			CLCD_voidSendString((U8*)"MY NAME MO SALAH");
			CLCD_voidDrawCharachter();
			CLCD_voidSetPostion(CLCD_ROW_2,i);
			CLCD_voidSendData(3);
			CLCD_voidSendData(4);
			CLCD_voidSetPostion(CLCD_ROW_2,15);
			CLCD_voidSendData(5);
			_delay_ms(100);
			CLCD_voidClearDisplay();

		}*/
		/*U8 arr[]="omar";
         CLCD_voidSendCommand(0b00000110);
       CLCD_voidSetPostion(CLCD_ROW_1,CLCD_COL_1);
  for(U8 i=3;i>4;i--){
	CLCD_voidSendData(arr[i]);
	_delay_ms(1000);
}*/
		/*CLCD_voidSetPostion(CLCD_ROW_1,CLCD_COL_1);
        CLCD_voidSendString((U8*)"OMAR");
        _delay_ms(1000);
        CLCD_voidClearLine(CLCD_ROW_1);
        _delay_ms(1000);
        CLCD_voidSetPostion(CLCD_ROW_2,CLCD_COL_1);
        CLCD_voidSendString((U8*)"MEROO");
        _delay_ms(1000);
        CLCD_voidClearLine(CLCD_ROW_2);
        _delay_ms(1000);*/
		//CLCD_voidSendCommand(0b00000100);

		/*CLCD_voidSetPostion(CLCD_ROW_2,CLCD_COL_16);
		CLCD_voidSendCommand(0b00000101);
		_delay_ms(1);
		CLCD_voidSendString((U8*)"RAMO");
		_delay_ms(1000);*///SHIFT RIGHT
		/*CLCD_voidSetPostion(CLCD_ROW_1,CLCD_COL_1);
		CLCD_voidSendCommand(0b00000111);
		_delay_ms(1);
		CLCD_voidSendString((U8*)"OMAR");

		_delay_ms(1000);//SHIFT LEFT
		/*for(U8 i=0;i<8;i++){
			CLCD_voidSendData(i);
		}*/


	}

	return 0;
}

