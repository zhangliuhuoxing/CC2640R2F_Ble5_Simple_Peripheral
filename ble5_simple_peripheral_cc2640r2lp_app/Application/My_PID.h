/*
 * My_PID.h
 *
 *  Created on: 2018年6月11日
 *      Author: dd
 */

#ifndef APPLICATION_MY_PID_H_
#define APPLICATION_MY_PID_H_
//0.001
//0.1
//0.05
//0.1
#define PID_ACC \
{\
    0,\
    0,\
    {0,0},\
    0,\
    0.003,\
    0,\
    0,\
    0,\
    0,\
    0,\
    1,\
    0,\
    0.05,\
    0.1,\
    0,\
    0,\
    0,\
    &PID_Calc,\
    &PID_Reset,\
}\

typedef struct PID_Regulator_t
{
    float ref;
    float fdb;
    float err[2];
    float kp;
    float ki;
    float kd;
    float componentKp;
    float componentKi;
    float componentKd;
    float componentKpMax;
    float componentKiMax;
    float componentKdMax;
    float output;
    float outputMax;
    float kp_offset;
    float ki_offset;
    float kd_offset;
    void (*Calc)(struct PID_Regulator_t *pid);
    void (*Reset)(struct PID_Regulator_t *pid);
}PID_Regulator_t;

void PID_Reset(PID_Regulator_t *pid);
void PID_Calc(PID_Regulator_t *pid);

#endif /* APPLICATION_MY_PID_H_ */
