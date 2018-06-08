#ifndef _MY_KEY_H_
#define _MY_KEY_H_

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

/*********************宏定义************************/
//类型宏
#ifndef GUA_C
    typedef char GUA_C;
#endif

#ifndef GUA_U8
    typedef unsigned char GUA_U8;
#endif
#ifndef GUA_8
    typedef signed char GUA_8;
#endif

#ifndef GUA_U16
    typedef unsigned short GUA_U16;
#endif
#ifndef GUA_16
    typedef signed short GUA_16;
#endif

#ifndef GUA_U32
    typedef unsigned long GUA_U32;
#endif
#ifndef GUA_32
    typedef signed long GUA_32;
#endif

#ifndef GUA_U64
    typedef unsigned long long GUA_U64;
#endif
#ifndef GUA_64
    typedef signed long long GUA_64;
#endif
//键值
#define GUA_KEY_LEFT_VALUE 0x0001
#define GUA_KEY_RIGHT_VALUE 0x0002
//超时时间
#define GUA_KEY_DEBOUNCE_TIMEOUT 20
/*********************外部函数************************/
typedef void (*GUA_keysPressedCB_t)(GUA_U8 GUA_keysPressed);

extern void GUA_initKeys(GUA_keysPressedCB_t GUA_appKeyCB);
#endif
