#ifndef _My_PWM_H_
#define _My_PWM_H_
/*********************�궨��************************/
//���ͺ�
#ifndef PWM_STATUS
    typedef signed char PWM_STATUS;
#endif

extern PWM_Handle pwm;
extern float g_pwm_duty;

PWM_STATUS My_PWM_init(void);

#endif
