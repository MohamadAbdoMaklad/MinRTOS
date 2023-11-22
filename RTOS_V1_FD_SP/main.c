#include "RTOS_KERNAL_Interface.h"
#include <avr/io.h>
void toggle1(void)
{
	PORTA ^=0b00000001;
}
void toggle2(void)
{
	PORTA ^=0b00000010;
}
void toggle3(void)
{
	PORTA ^=0b00000100;
}
int main(void)
{
	DDRA |= 0b00000111;
	SCH_InitTasks();
	SCH_voidCreateTask( 0 ,3000  ,	1500 ,toggle1);
	SCH_voidCreateTask( 0 ,1500  ,	2000 ,toggle2);
	SCH_voidCreateTask( 1 ,3000  ,	1500 ,toggle3);
	SCH_voidStartOs();
    while (1) 
    {
	
    }
}

