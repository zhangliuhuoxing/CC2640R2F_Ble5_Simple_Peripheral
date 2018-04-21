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
/*********************�궨��************************/
#define GUA_KEY_LEFT IOID_13
#define GUA_KEY_RIGHT IOID_14
/*********************�ڲ�����************************/
//��ֵ
static GUA_U8 GUA_keysPressed;

//��������ʱ��
static Clock_Struct GUA_keyChangeClock;
//��ӦӦ�ò�ص������ĺ���ָ��
static GUA_keysPressedCB_t GUA_appKeyChangeHandler = NULL;
//IO������Ҫ������
static PIN_Config GUA_keyPinsCfg[] =
{
    GUA_KEY_LEFT | PIN_GPIO_OUTPUT_DIS | PIN_INPUT_EN | PIN_PULLUP,
    GUA_KEY_RIGHT | PIN_GPIO_OUTPUT_DIS | PIN_INPUT_EN | PIN_PULLUP,
    PIN_TERMINATE
};
//IO״̬�ṹ��
static PIN_State GUA_keyPins;
//IO����ṹ��
static PIN_Handle GUA_hKeyPins;
/*********************�ڲ�����************************/
static void GUA_keyChangeHandler(UArg a0);
static void GUA_keyCallback(PIN_Handle hPin, PIN_Id pinId);

static void GUA_keyCallback(PIN_Handle hPin, PIN_Id pinId)
{
    //�����ֵ
    GUA_keysPressed = 0;

    //�жϰ����Ƿ���
    if(PIN_getInputValue(GUA_KEY_LEFT) == 0)
    {
        //�����ֵ
        GUA_keysPressed |= GUA_KEY_LEFT_VALUE;
    }
    //�жϰ����Ƿ���
    if(PIN_getInputValue(GUA_KEY_RIGHT) == 0)
    {
        //�����ֵ
        GUA_keysPressed |= GUA_KEY_RIGHT_VALUE;
    }
    //������ʱ����������
    Util_startClock(&GUA_keyChangeClock);
}

static void GUA_keyChangeHandler(UArg a0)
{
    //�����ֵ
    GUA_keysPressed = 0;
    //�ж��Ƿ���ע��
    if(GUA_appKeyChangeHandler != NULL)
    {
        if(PIN_getInputValue(GUA_KEY_LEFT) == 0)
        {
            GUA_keysPressed |= GUA_KEY_LEFT_VALUE;
        }
        //����
        if(PIN_getInputValue(GUA_KEY_RIGHT) == 0)
        {
            GUA_keysPressed |= GUA_KEY_RIGHT_VALUE;
        }
        //���ð���Ӧ�ò㴦����
        (*GUA_appKeyChangeHandler)(GUA_keysPressed);
    }
}
//**********************************************************************
//name: GUA_initKeys
//introduce: ��ϰ��������ĳ�ʼ������
//parameter: GUA_appKeyCB��Ӧ�ò�İ���������
//return: none
//author: ����Ĵ����
//email: 897503845@qq.com
//QQ group: ���BLE֮CC2640R2F(557278427)
//shop:
//https://shop217632629.taobao.com/?spm=2013.1.1000126.d21.hd2o8i
//changetime: 2017.11.09
//**********************************************************************
void GUA_initKeys(GUA_keysPressedCB_t GUA_appKeyCB)
{
    //��ʼ��������IO
    GUA_hKeyPins = PIN_open(&GUA_keyPins, GUA_keyPinsCfg);
    //ע��ص�����
    PIN_registerIntCb(GUA_hKeyPins, GUA_keyCallback);
    //�޸ĳ�˫���жϴ������Ա���˯��֮���жϲ���
    PIN_setConfig(GUA_hKeyPins, PIN_BM_IRQ, GUA_KEY_LEFT | PIN_IRQ_BOTHEDGES);
    PIN_setConfig(GUA_hKeyPins, PIN_BM_IRQ, GUA_KEY_RIGHT | PIN_IRQ_BOTHEDGES);

    //�͹����µ�����
    #ifdef POWER_SAVING
    PIN_setConfig(GUA_hKeyPins, PINCC26XX_BM_WAKEUP, GUA_KEY_LEFT |
    PINCC26XX_WAKEUP_NEGEDGE);
    PIN_setConfig(GUA_hKeyPins, PINCC26XX_BM_WAKEUP, GUA_KEY_RIGHT |
    PINCC26XX_WAKEUP_NEGEDGE);
    #endif

    //��ʼ��������ʱ�¼�
    Util_constructClock(&GUA_keyChangeClock, GUA_keyChangeHandler,
    GUA_KEY_DEBOUNCE_TIMEOUT, 0, false, 0);
    //����Ӧ�ò�ĺ���ָ��
    GUA_appKeyChangeHandler = GUA_appKeyCB;
}
