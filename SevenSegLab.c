/*
 * SevenSegLab.c
 *
 *  Created on: Aug 17, 2019
 *      Author: Reem
 */
#include "../MCAL/DIO/DIO.h"
#include "../HAL/BCDSevenSeg/BCDSevenSeg.h"
#include <AVR/delay.h>
#include "../LIB/Bit_Math.h"
void SevenSegments (void)
{
	BCDSevenSegment_Initialization();
	int Right, Left, i;
	for(i=-1 ; i<100 ; i++){
		Right=i%10;
		Left=i/10;
		if(i<10){
			BCDSevenSegment_WriteNumberAndSelect(i,Right7Seg);
		}
		else if((i>10)&&(Right!=0)){
			BCDSevenSegment_WriteNumberAndSelect(Right,Right7Seg);
			_delay_ms(10);
			BCDSevenSegment_WriteNumberAndSelect(Left,Left7Seg);
		}
		else if((i>10)&&(Right==0)){
			BCDSevenSegment_WriteNumberAndSelect(Right,Right7Seg);
			_delay_ms(10);
			BCDSevenSegment_WriteNumberAndSelect(Left,Left7Seg);
		}
		_delay_ms(1000);
	}



}

void bin(void){
	DIO_SetPortDirection(PORTA,DIO_Output);
	DIO_SetPortDirection(PORTB,DIO_Output);
	DIO_SetPortDirection(PORTC,DIO_Output);
	DIO_SetPortDirection(PORTD,DIO_Output);

	int i ;
	while(1){
	for(i=0 ;i<8 ;i++){
		switch (i){
		case 0:
			DIO_SetPinValue(PORTC,Pin2,STD_LOW);
			DIO_SetPinValue(PORTC,Pin7,STD_LOW);
			DIO_SetPinValue(PORTD,Pin3,STD_LOW);
			break;

		case 1:
			DIO_SetPinValue(PORTC,Pin2,STD_HIGH);
			DIO_SetPinValue(PORTC,Pin7,STD_LOW);
			DIO_SetPinValue(PORTD,Pin3,STD_LOW);
			break;

		case 2:
			DIO_SetPinValue(PORTC,Pin2,STD_LOW);
			DIO_SetPinValue(PORTC,Pin7,STD_HIGH);
			DIO_SetPinValue(PORTD,Pin3,STD_LOW);
			break;

		case 3:
			DIO_SetPinValue(PORTC,Pin2,STD_HIGH);
			DIO_SetPinValue(PORTC,Pin7,STD_HIGH);
			DIO_SetPinValue(PORTD,Pin3,STD_LOW);
			break;

		case 4:
			DIO_SetPinValue(PORTC,Pin2,STD_LOW);
			DIO_SetPinValue(PORTC,Pin7,STD_LOW);
			DIO_SetPinValue(PORTD,Pin3,STD_HIGH);
			break;

		case 5:
			DIO_SetPinValue(PORTC,Pin2,STD_HIGH);
			DIO_SetPinValue(PORTC,Pin7,STD_LOW);
			DIO_SetPinValue(PORTD,Pin3,STD_HIGH);
			break;

		case 6:
			DIO_SetPinValue(PORTC,Pin2,STD_LOW);
			DIO_SetPinValue(PORTC,Pin7,STD_HIGH);
			DIO_SetPinValue(PORTD,Pin3,STD_HIGH);
			break;

		case 7:
		DIO_SetPinValue(PORTC,Pin2,STD_HIGH);
		DIO_SetPinValue(PORTC,Pin7,STD_HIGH);
		DIO_SetPinValue(PORTD,Pin3,STD_HIGH);
			break;

		}
		_delay_ms(1000);
	}
}
}

void LeftToRight (void){
	DIO_SetPortDirection(PORTA,DIO_Output);
	DIO_SetPortDirection(PORTB,DIO_Output);
	DIO_SetPortDirection(PORTC,DIO_Output);
	DIO_SetPortDirection(PORTD,DIO_Output);

	while(1){
	DIO_SetPinValue(PORTD,Pin3,STD_HIGH);
	_delay_ms(1000);
	DIO_SetPinValue(PORTD,Pin3,STD_LOW);
	DIO_SetPinValue(PORTC,Pin7,STD_HIGH);
	_delay_ms(1000);
	DIO_SetPinValue(PORTC,Pin7,STD_LOW);
	DIO_SetPinValue(PORTC,Pin2,STD_HIGH);
	_delay_ms(1000);
	DIO_SetPinValue(PORTC,Pin2,STD_LOW);


}
}

void BothDirections(void){
	DIO_SetPortDirection(PORTA,DIO_Output);
	DIO_SetPortDirection(PORTB,DIO_Output);
	DIO_SetPortDirection(PORTC,DIO_Output);
	DIO_SetPortDirection(PORTD,DIO_Output);

	while(1){
	DIO_SetPinValue(PORTD,Pin3,STD_HIGH);
	_delay_ms(1000);
	DIO_SetPinValue(PORTD,Pin3,STD_LOW);
	DIO_SetPinValue(PORTC,Pin7,STD_HIGH);
	_delay_ms(1000);
	DIO_SetPinValue(PORTC,Pin7,STD_LOW);
	DIO_SetPinValue(PORTC,Pin2,STD_HIGH);
	_delay_ms(1000);
	DIO_SetPinValue(PORTC,Pin2,STD_LOW);
	_delay_ms(1000);
	DIO_SetPinValue(PORTC,Pin2,STD_HIGH);
	_delay_ms(1000);
	DIO_SetPinValue(PORTC,Pin2,STD_LOW);
	DIO_SetPinValue(PORTC,Pin7,STD_HIGH);
	_delay_ms(1000);
	DIO_SetPinValue(PORTC,Pin7,STD_LOW);
	DIO_SetPinValue(PORTD,Pin3,STD_HIGH);
	_delay_ms(1000);
	DIO_SetPinValue(PORTD,Pin3,STD_LOW);
	_delay_ms(1000);



}
}

void PressButton0 (void){
	DIO_SetPortDirection(PORTA,DIO_Output);
	DIO_SetPortDirection(PORTB,DIO_Output);
	DIO_SetPortDirection(PORTC,DIO_Output);
	DIO_SetPortDirection(PORTD,DIO_Output);

	DIO_SetPinDirection(PORTB,Pin0,DIO_Input);
	DIO_SetPinDirection(PORTB,Pin0,DIO_Output);


	STD_levelType Current,Prev;
	int i;

	Current=STD_LOW;
	Prev=STD_LOW;

	while(1){
		Current = DIO_GetPinValue(PORTB,Pin0);
		if((STD_HIGH== Current)&&(STD_LOW==Prev)){
			DIO_SetPinValue(PORTC,Pin2,STD_HIGH);

			for(i=0;i<100;i++){

				DIO_SetPinValue(PORTC,Pin2,STD_HIGH);
				_delay_ms(150);
				if(i<10){
					BCDSevenSegment_WriteNumberAndSelect(i,Right7Seg);
				}
				else if((i>10)&&(i%10 != 0)){
					int Right =i%10;
					int Left=i/10;
					BCDSevenSegment_WriteNumberAndSelect(Right,Right7Seg);
					_delay_ms(10);
					BCDSevenSegment_Disable1();
					BCDSevenSegment_Disable2();
					BCDSevenSegment_WriteNumberAndSelect(Left,Left7Seg);
				}
				else if((i>10)&&(i%10 == 0)){
					/*int Right =i & 0x00 ;*/
					int Left=i/10;
					DIO_SetPinValue(PORTA, Pin4, STD_LOW);
					DIO_SetPinValue(PORTA, Pin5, STD_LOW);
					DIO_SetPinValue(PORTA, Pin6, STD_LOW);
					DIO_SetPinValue(PORTA, Pin7, STD_LOW);
					_delay_ms(10);
					BCDSevenSegment_Disable1();
					BCDSevenSegment_Disable2();
					BCDSevenSegment_WriteNumberAndSelect(Left,Left7Seg);

				}
				DIO_SetPinValue(PORTC,Pin2,STD_LOW);
				_delay_ms(1000);

			}

		}
		else if((STD_LOW == Current)&&(STD_HIGH ==Prev)){
			DIO_SetPinValue(PORTC,Pin2,STD_LOW);
			_delay_ms(1000);
		}
		Current=Prev;

	}


}

void Traffic(void){
	DIO_SetPortDirection(PORTA,DIO_Output);
	DIO_SetPortDirection(PORTB,DIO_Output);
	DIO_SetPortDirection(PORTC,DIO_Output);
	DIO_SetPortDirection(PORTD,DIO_Output);

	int Right , Left;
while(1){
	DIO_SetPinValue(PORTD,Pin3,STD_HIGH);
	for(int i=0;i<61;i++){
		Right=i%10;
		Left=i/10;
		if(i<10){
			BCDSevenSegment_WriteNumberAndSelect(i,Right7Seg);
			_delay_ms(1000);
		}

		else if(i>10){
			BCDSevenSegment_WriteNumberAndSelect(Right,Right7Seg);
			_delay_ms(10);
			BCDSevenSegment_WriteNumberAndSelect(Left,Left7Seg);
			_delay_ms(1000);
		}
	}

	DIO_SetPinValue(PORTD,Pin3,STD_LOW);
	DIO_SetPinValue(PORTC,Pin7,STD_HIGH);

	for(int i=0;i<6;i++){

		Right=i%10;
		Left=i/10;
		if(i<10){
			BCDSevenSegment_WriteNumberAndSelect(i,Right7Seg);
			_delay_ms(1000);
		}

		else if(i>10){
			BCDSevenSegment_WriteNumberAndSelect(Right,Right7Seg);
			_delay_ms(10);
			BCDSevenSegment_WriteNumberAndSelect(Left,Left7Seg);
			_delay_ms(1000);
		}

	}

	DIO_SetPinValue(PORTC,Pin7,STD_LOW);
	DIO_SetPinValue(PORTC,Pin2,STD_HIGH);

	for(int i=0;i<31;i++){

		Right=i%10;
		Left=i/10;
		if(i<10){
			BCDSevenSegment_WriteNumberAndSelect(i,Right7Seg);
			_delay_ms(1000);
		}

		else if(i>10){
			BCDSevenSegment_WriteNumberAndSelect(Right,Right7Seg);
			_delay_ms(10);
			BCDSevenSegment_WriteNumberAndSelect(Left,Left7Seg);
			_delay_ms(1000);
		}

	}

	DIO_SetPinValue(PORTC,Pin2,STD_LOW);
}

}

void SwitchButtons(void){
	DIO_SetPortDirection(PORTA,DIO_Output);
	DIO_SetPortDirection(PORTB,DIO_Output);
	DIO_SetPortDirection(PORTC,DIO_Output);
	DIO_SetPortDirection(PORTD,DIO_Output);

	DIO_SetPinDirection(PORTB,Pin0,DIO_Input); //Button 0
	DIO_SetPinDirection(PORTB,Pin4,DIO_Input); //Button 1
	DIO_SetPinDirection(PORTD,Pin2,DIO_Input); //Button 2

	STD_levelType Button0, Button1, Button2;
	Button0 = DIO_GetPinValue(PORTB,Pin0);
	Button1 = DIO_GetPinValue(PORTB,Pin4);
	Button2 = DIO_GetPinValue(PORTD,Pin2);

	int i , Right , Left;

	for (i=-1;i<100;i++){
		if(STD_HIGH == Button0){
			i++;
			Right=i%10;
			Left=i/10;
			if(i<10){
				BCDSevenSegment_WriteNumberAndSelect(i,Right7Seg);
				_delay_ms(1000);
			}

			else if(i>10){
				BCDSevenSegment_WriteNumberAndSelect(Right,Right7Seg);
				_delay_ms(10);
				BCDSevenSegment_WriteNumberAndSelect(Left,Left7Seg);
				_delay_ms(1000);
			}


		}

		 if(STD_HIGH == Button0){
			i--;
			Right=i%10;
			Left=i/10;
			if(i<10){
				BCDSevenSegment_WriteNumberAndSelect(i,Right7Seg);
				_delay_ms(1000);
			}

			else if(i>10){
				BCDSevenSegment_WriteNumberAndSelect(Right,Right7Seg);
				_delay_ms(10);
				BCDSevenSegment_WriteNumberAndSelect(Left,Left7Seg);
				_delay_ms(1000);
			}


		}


			if(STD_HIGH == Button2){

				break;
			}


	}

}
