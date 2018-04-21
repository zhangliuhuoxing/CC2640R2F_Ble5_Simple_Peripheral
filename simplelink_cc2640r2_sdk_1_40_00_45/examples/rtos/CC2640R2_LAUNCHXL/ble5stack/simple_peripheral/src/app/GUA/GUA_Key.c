#include <stdbool.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/family/arm/m3/Hwi.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/drivers/pin/PINCC26XX.h>
#ifdef USE_ICALL
#include <iCall.h>
#endif
#include <inc/hw_ints.h>
#include "util.h"
#include "Board.h"
#include "GUA_Key.h"
/*********************宏定义************************/
#define GUA_KEY_LEFT IOID_13
#define GUA_KEY_RIGHT IOID_14
/*********************内部变量************************/
//键值
static GUA_U8 GUA_keysPressed;

//按键消抖时钟
static Clock_Struct GUA_keyChangeClock;
//对应应用层回调函数的函数指针
static GUA_keysPressedCB_t GUA_appKeyChangeHandler = NULL;
//IO配置需要的数组
static PIN_Config GUA_keyPinsCfg[] =
{
    GUA_KEY_LEFT | PIN_GPIO_OUTPUT_DIS | PIN_INPUT_EN | PIN_PULLUP,
    GUA_KEY_RIGHT | PIN_GPIO_OUTPUT_DIS | PIN_INPUT_EN | PIN_PULLUP,
    PIN_TERMINATE
};
//IO状态结构体
static PIN_State GUA_keyPins;
//IO句柄结构体
static PIN_Handle GUA_hKeyPins;
/*********************内部函数************************/
static void GUA_keyChangeHandler(UArg a0);
static void GUA_keyCallback(PIN_Handle hPin, PIN_Id pinId);

static void GUA_keyCallback(PIN_Handle hPin, PIN_Id pinId)
{
    //清除键值
    GUA_keysPressed = 0;

    //判断按键是否按下
    if(PIN_getInputValue(GUA_KEY_LEFT) == 0)
    {
        //保存键值
        GUA_keysPressed |= GUA_KEY_LEFT_VALUE;
    }
    //判断按键是否按下
    if(PIN_getInputValue(GUA_KEY_RIGHT) == 0)
    {
        //保存键值
        GUA_keysPressed |= GUA_KEY_RIGHT_VALUE;
    }
    //启动定时器进行消抖
    Util_startClock(&GUA_keyChangeClock);
}

static void GUA_keyChangeHandler(UArg a0)
{
    //清除键值
    GUA_keysPressed = 0;
    //判断是否有注册
    if(GUA_appKeyChangeHandler != NULL)
    {
        if(PIN_getInputValue(GUA_KEY_LEFT) == 0)
        {
            GUA_keysPressed |= GUA_KEY_LEFT_VALUE;
        }
        //消抖
        if(PIN_getInputValue(GUA_KEY_RIGHT) == 0)
        {
            GUA_keysPressed |= GUA_KEY_RIGHT_VALUE;
        }
        //调用按键应用层处理函数
        (*GUA_appKeyChangeHandler)(GUA_keysPressed);
    }
}
//**********************************************************************
//name: GUA_initKeys
//introduce: 香瓜按键驱动的初始化函数
//parameter: GUA_appKeyCB：应用层的按键处理函数
//return: none
//author: 甜甜的大香瓜
//email: 897503845@qq.com
//QQ group: 香瓜BLE之CC2640R2F(557278427)
//shop:
//https://shop217632629.taobao.com/?spm=2013.1.1000126.d21.hd2o8i
//changetime: 2017.11.09
//**********************************************************************
void GUA_initKeys(GUA_keysPressedCB_t GUA_appKeyCB)
{
    //初始化按键的IO
    GUA_hKeyPins = PIN_open(&GUA_keyPins, GUA_keyPinsCfg);
    //注册回调函数
    PIN_registerIntCb(GUA_hKeyPins, GUA_keyCallback);
    //修改成双沿中断触发，以避免睡眠之后中断不灵
    PIN_setConfig(GUA_hKeyPins, PIN_BM_IRQ, GUA_KEY_LEFT | PIN_IRQ_BOTHEDGES);
    PIN_setConfig(GUA_hKeyPins, PIN_BM_IRQ, GUA_KEY_RIGHT | PIN_IRQ_BOTHEDGES);

    //低功耗下的配置
    #ifdef POWER_SAVING
    PIN_setConfig(GUA_hKeyPins, PINCC26XX_BM_WAKEUP, GUA_KEY_LEFT |
    PINCC26XX_WAKEUP_NEGEDGE);
    PIN_setConfig(GUA_hKeyPins, PINCC26XX_BM_WAKEUP, GUA_KEY_RIGHT |
    PINCC26XX_WAKEUP_NEGEDGE);
    #endif

    //初始化按键定时事件
    Util_constructClock(&GUA_keyChangeClock, GUA_keyChangeHandler,
    GUA_KEY_DEBOUNCE_TIMEOUT, 0, false, 0);
    //保存应用层的函数指针
    GUA_appKeyChangeHandler = GUA_appKeyCB;
}
