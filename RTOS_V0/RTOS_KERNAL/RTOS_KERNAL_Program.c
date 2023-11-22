#include "RTOS_KERNAL_Private.h"
#include "RTOS_KERNAL_Cfg.h"
#include "RTOS_MCAL_Interface.h"
TCB_t Task[MaxNTask]={};

void IdleTask(void)
{
	for(;;)
	{
		
	}
}

void SCH_InitTasks(void)
{
	for(u8 i =0 ; i< MaxNTask ; i++)
	{
		Task[i].State = Dormant;
		Task[i].TaskExecutable = IdleTask;
	}
}
void SCH_voidCreateTask(u8 Copy_u8Priority , u32 Copy_u32Priodicity , v_P2F_v Lpf)
{
	Task[Copy_u8Priority].State = Ready;
	Task[Copy_u8Priority].Periodicity = Copy_u32Priodicity;
	Task[Copy_u8Priority].TaskExecutable = Lpf;
}

void Private_voidSchedularStart()
{
	u8 Local_U8CopyCounter;
	for (Local_U8CopyCounter = 0;Local_U8CopyCounter< MaxNTask;Local_U8CopyCounter++)
	{
		
			Task[Local_U8CopyCounter].TaskExecutable();
		
	}
}
void SCH_voidStartOs()
{
	/*init system clock*/
	T1_voidInit();
	T1_SetCallBack(Private_voidSchedularStart);
	T1_voidStart();

}