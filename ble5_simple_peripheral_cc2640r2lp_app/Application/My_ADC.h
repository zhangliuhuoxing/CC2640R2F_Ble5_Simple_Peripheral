#ifndef _My_ADC_H_
#define _My_ADC_H_

#include <ti/drivers/ADC.h>

/*********************∫Í∂®“Â************************/

extern ADC_Handle adc;
extern uint16_t adc_value;
extern uint32_t micro_volt;

int8_t My_ADC_init(void);
uint16_t My_ADC_Get(ADC_Handle ADCn);

#endif
