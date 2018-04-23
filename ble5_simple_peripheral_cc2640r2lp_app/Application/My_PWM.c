#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Log.h>
#include <ti/sysbios/BIOS.h>
#include "board.h"
#include <ti/drivers/power/PowerCC26XX.h>
#include <ti/drivers/PWM.h>

#include "My_PWM.h"

PWM_Handle pwm;

// Initialize the PWM driver.
PWM_STATUS My_PWM_init(void)
{
    PWM_Params pwmParams;

    // Initialize the PWM parameters
    PWM_init();

    PWM_Params_init(&pwmParams);
    pwmParams.idleLevel = PWM_IDLE_LOW;      // Output low when PWM is not running
    pwmParams.periodUnits = PWM_PERIOD_HZ;   // Period is in Hz
    pwmParams.periodValue = 50;             // 1MHz
    pwmParams.dutyUnits = PWM_DUTY_FRACTION; // Duty is in fractional percentage
    pwmParams.dutyValue = 0;                 // 0% initial duty cycle
    // Open the PWM instance
    pwm = PWM_open(Board_PWM0, &pwmParams);

    if (pwm == NULL)
    {
        // PWM_open() failed
        return -1;
    }
    PWM_start(pwm);                          // start PWM with 0% duty cycle
    PWM_setDuty(pwm,
         (PWM_DUTY_FRACTION_MAX / 2));       // set duty cycle to 50%

    return 0;


//    PWM_Params params;
//
//    PWM_init();
//
//    PWM_Params_init(&params);
//
//    params.dutyUnits = PWM_DUTY_COUNTS;
//    params.dutyValue = 240; //starting at 10% duty cycle
//    params.periodUnits = PWM_PERIOD_COUNTS;
//    params.periodValue = 2400;
//
//    pwm = PWM_open(Board_PWM0, &params);
//
//    if (pwm == NULL) {
//     /* Board_PWM0 did not open */
//    // Display_printf(dispHandle, 0, 0, "PWM did not open\n");
//     while (1);
//    }
//    else
//    {
//    // Display_printf(dispHandle, 0, 0, " PWM is initialized \n");
//    }
//
//    // start PWM
//    PWM_start(pwm);
//
//    return 0;
}
