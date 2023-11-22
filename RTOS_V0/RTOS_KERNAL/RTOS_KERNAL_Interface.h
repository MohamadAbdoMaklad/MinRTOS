#ifndef RTOS_KERNAL_INTERFACE_H_
#define RTOS_KERNAL_INTERFACE_H_
#include "LIB_BIT_MATH.h"
#include "LIB_STD.h"
#include "RTOS_MCAL_Interface.h"
#include "RTOS_KERNAL_Private.h"
#include "RTOS_KERNAL_Cfg.h"
void IdleTask(void);
void SCH_InitTasks(void);
void SCH_voidCreateTask(u8 Copy_u8Priority , u32 Copy_u32Priodicity , v_P2F_v Lpf);
void Private_voidSchedularStart();
void SCH_voidStartOs();



#endif /* RTOS_KERNAL_INTERFACE_H_ */