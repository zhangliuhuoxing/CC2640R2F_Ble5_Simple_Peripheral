#ifndef _My_MOTOR_H_
#define _My_MOTOR_H_

#include <ti/drivers/PWM.h>

/*********************�궨��************************/
#define PWM_FRE     50      //400hz

//���ͺ�
#ifndef PWM_STATUS
    typedef signed char PWM_STATUS;
#endif

extern PWM_Handle gPWM0;
extern float raw_value;

PWM_STATUS my_Motor_init(void);

#endif
