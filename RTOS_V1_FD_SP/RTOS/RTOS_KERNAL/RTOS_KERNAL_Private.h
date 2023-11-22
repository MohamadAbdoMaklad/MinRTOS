#ifndef RTOS_KERNAL_PRIVATE_H_
#define RTOS_KERNAL_PRIVATE_H_
#include "LIB_BIT_MATH.h"
#include "LIB_STD.h"
#include "RTOS_KERNAL_Interface.h"
typedef enum
{
	Dormant = 0,
	Ready,
	Running,
	Wating
	
}TaskState_t;


typedef struct
{
	TaskState_t State;
	u32 Periodicity;
	u32 FirestDelay;
	v_P2F_v TaskExecutable;
}TCB_t;

#endif /* RTOS_KERNAL_PRIVATE_H_ */