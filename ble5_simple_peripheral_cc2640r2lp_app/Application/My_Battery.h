#ifndef _My_ADC_H_
#define _My_ADC_H_

#include <sys/stdint.h>
#include <ti/drivers/ADC.h>

/*********************∫Í∂®“Â************************/

extern ADC_Handle battery_adc_handle;

int8_t My_Battery_init(void);
int32_t My_Battery_Get_Voltage(ADC_Handle ADCn);

#endif
