#include "RTOS_KERNAL_Private.h"
#include "RTOS_KERNAL_Cfg.h"
#include "RTOS_MCAL_Interface.h"
TCB_t Task[MaxNTask][MaxSamePerTask]={};

void IdleTask(void)
{
	for(;;)
	{
		
	}
}

void SCH_InitTasks(void)
{
	u8 i , j ;
	for (j = 0 ; j < MaxNTask ; j ++)
	{
		for(i =0 ; i< MaxSamePerTask ; i++)
		{
			Task[j][i].State = Dormant;
			Task[j][i].TaskExecutable = IdleTask;
		}
	}
	
}
// 0	1	2
// 
// 1	0	0
// 1	0	0
// 0	0	0
void SCH_voidCreateTask(u8 Copy_u8Priority , u32 Copy_u32Priodicity , u32 Copy_u8FirstDelay, v_P2F_v Lpf)
{
	for(u8 i = 0 ; i<MaxSamePerTask ; i++)
	{
		if (Task[Copy_u8Priority][i].State == Dormant)
		{
			Task[Copy_u8Priority][i].State = Ready;
			Task[Copy_u8Priority][i].Periodicity = Copy_u32Priodicity;
			Task[Copy_u8Priority][i].FirestDelay = Copy_u8FirstDelay;
			Task[Copy_u8Priority][i].TaskExecutable = Lpf;
			break;
		}
	}
}
void Private_voidSchedularStart()
{
	u8 Col ,Row;
	for (Col = 0;Col< MaxNTask;Col++)
	{
		for (Row = 0 ; (Row < MaxSamePerTask)&&(Task[Col][Row].State==Ready) ; Row++)
		{
			if (Task[Col][Row].FirestDelay == 0)
			{
				Task[Col][Row].TaskExecutable();
				Task[Col][Row].FirestDelay = Task[Col][Row].Periodicity-1;
			}
			else
			{
				Task[Col][Row].FirestDelay--;
			}
		}
		
	}
}
void SCH_voidStartOs()
{
	/*init system clock*/
	T1_voidInit();
	T1_SetCallBack(Private_voidSchedularStart);
	T1_voidStart();

}