#include "LIB_STD.h"
#include "LIB_BIT_MATH.h"
#include "RTOS_MCAL_Interface.h"
#include "RTOS_KERNAL_Cfg.h"

v_P2F_v SystemTimerGP2F = NULL;

void GIE_Disable(void)
{
	CLEAR_BIT(GIn,SREG_I);
}

void GIE_Enable(void)
{
	SET_BIT(GIn,SREG_I);
}

void T1_voidInit(void)
{
	//Set Timer CTC TOP OCR1A
	T1.TCCR1A.Bits.WGM10_Bit =	LOW	;
	T1.TCCR1A.Bits.WGM11_Bit =	LOW	;
	T1.TCCR1B.Bits.WGM12_Bit =	HIGH;
	T1.TCCR1B.Bits.WGM13_Bit =	LOW	;
	SET_BIT(T1.TIMSK,4);
	T1.OCR1A = 249;
	SET_BIT(GIn,7);
}

void T1_voidStart(void)
{// Set Prescaling 64
	T1.TCCR1B.Bits.CS10_Bit	= HIGH;
	T1.TCCR1B.Bits.CS11_Bit	= HIGH;
	T1.TCCR1B.Bits.CS12_Bit	= LOW;
}

void T1_voidStop(void)
{
	T1.TCCR1B.Bits.CS10_Bit	= LOW;
	T1.TCCR1B.Bits.CS11_Bit	= LOW;
	T1.TCCR1B.Bits.CS12_Bit	= LOW;
	
}

void T1_SetCallBack(v_P2F_v LP2F)
{
	SystemTimerGP2F = LP2F;
}

void __vector_7 (void) __attribute__ ((signal));
void __vector_7 (void)
{
	static u8 counter = 1 ;
	if ((NULL != SystemTimerGP2F)&&(counter == SysTimeMS))
	{
		SystemTimerGP2F();
		counter = 1;
	}
	else
	{
		counter ++ ;
	}
}