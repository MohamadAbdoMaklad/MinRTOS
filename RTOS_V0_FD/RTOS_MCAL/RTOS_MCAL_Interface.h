#ifndef RTOS_MCAL_INTERFACE_H_
#define RTOS_MCAL_INTERFACE_H_
#include "LIB_STD.h"
#include "LIB_BIT_MATH.h"
#include "RTOS_MCAL_Private.h"

void GIE_Disable(void);

void GIE_Enable(void);

void T1_voidInit(void);

void T1_voidStart(void);

void T1_voidStop(void);

void T1_SetCallBack(v_P2F_v LP2F);


#endif /* ROS_MCAL_INTERFACE_H_ */