/*
 * My_PID.c
 *
 *  Created on: 2018Äê6ÔÂ11ÈÕ
 *      Author: dd
 */
#include "My_PID.h"

void PID_Reset(PID_Regulator_t *pid)
{
    pid->ref = 0;
    pid->fdb = 0;
    pid->err[0] = 0;
    pid->err[1] = 0;
    pid->kp = 0;
    pid->ki = 0;
    pid->kd = 0;
    pid->componentKp = 0;
    pid->componentKi = 0;
    pid->componentKd = 0;
    pid->componentKpMax = 0;
    pid->componentKiMax = 0;
    pid->componentKdMax = 0;
    pid->output = 0;
    pid->outputMax = 0;
    pid->kp_offset = 0;
    pid->ki_offset = 0;
    pid->kd_offset = 0;
}

void PID_Calc(PID_Regulator_t *pid)
{
    pid->err[0] = pid->ref - pid->fdb;

    pid->componentKp = pid->kp * pid->err[0];

    pid->componentKi += pid->ki * pid->err[0];
    pid->componentKiMax = pid->outputMax - pid->componentKp;
    pid->componentKi = pid->componentKi > pid->componentKiMax ? pid->componentKiMax : pid->componentKi;
    pid->componentKi = pid->componentKi < -pid->componentKiMax ? -pid->componentKiMax : pid->componentKi;

    pid->componentKd = pid->kd * (pid->err[0] - pid->err[1]);

    pid->output = pid->componentKp + pid->componentKi + pid->componentKd;
    pid->output = pid->output > pid->outputMax ? pid->outputMax : pid->output;
    pid->output = pid->output < -pid->outputMax ? -pid->outputMax : pid->output;

    pid->err[1] = pid->err[0];
}
