#include <My_Battery.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Log.h>
#include <ti/sysbios/BIOS.h>
#include "board.h"
#include <ti/drivers/power/PowerCC26XX.h>

ADC_Handle battery_adc_handle;

int8_t My_Battery_init(void)
{
    ADC_Params params;
    ADC_init();
    ADC_Params_init(&params);
    battery_adc_handle = ADC_open(BATTERY_ADC, &params); //Board_ADCCHANNEL_A0
    if (battery_adc_handle == NULL)
    {
        // ADC_open() failed
        return -1;
    }

    return 0;
}

int32_t My_Battery_Get_Voltage(ADC_Handle ADCn)
{
    int_fast16_t res;
    uint16_t adcValue;
    res = ADC_convert(ADCn, &adcValue);
    if (res == ADC_STATUS_ERROR)
    {
        //ADC_convert() failed
        return -1;
    }

    return adcValue;
}




