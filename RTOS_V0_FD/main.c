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
	SCH_voidCreateTask( 0 ,1000  ,	1000 ,toggle1);
	SCH_voidCreateTask( 1 ,2000  ,	2000 ,toggle2);
	SCH_voidCreateTask( 2 ,3000  ,	3000 ,toggle3);
	SCH_voidStartOs();
    while (1) 
    {
	
    }
}

