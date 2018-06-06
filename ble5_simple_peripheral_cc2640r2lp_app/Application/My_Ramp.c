/*
 * My_Ramp.c
 *
 *  Created on: 2018Äê6ÔÂ4ÈÕ
 *      Author: dd
 */
#include "My_Ramp.h"

void RampInit(RampGen_t *ramp, int32_t XSCALE)
{
    ramp->count = 0;
    ramp->XSCALE = XSCALE;
    ramp->out = 0;
    ramp->Init = &RampInit;
    ramp->Calc = &RampCalc;
    ramp->SetCounter = &RampSetCounter;
    ramp->ResetCounter = &RampResetCounter;
    ramp->SetScale = &RampSetScale;
    ramp->IsOverflow = &RampIsOverflow;
}

float RampCalc(RampGen_t *ramp)
{

}

void RampSetCounter(struct RampGen_t *ramp, int32_t count)
{

}

void RampResetCounter(struct RampGen_t *ramp)
{

}

void RampSetScale(struct RampGen_t *ramp, int32_t scale)
{

}

uint8_t RampIsOverflow(struct RampGen_t *ramp)
{

}


