/*
 * My_Uart.h
 *
 *  Created on: 2018年6月6日
 *      Author: dd
 */

#ifndef APPLICATION_MY_UART_H_
#define APPLICATION_MY_UART_H_

#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Log.h>
#include <ti/sysbios/BIOS.h>
#include "board.h"
#include <ti/drivers/power/PowerCC26XX.h>
#include <ti/drivers/UART.h>
#include <ti/drivers/uart/UARTCC26XX.h>

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

//缓冲区数据长度
#define GUA_UART_MAX_NUM_RX_BYTES 60 //最大接收字节
#define GUA_UART_MAX_NUM_TX_BYTES 60 //最大发送字节

/*********************外部变量************************/
extern GUA_U8 gaGUA_UART_RxBuf[GUA_UART_MAX_NUM_RX_BYTES];
extern GUA_U8 gaGUA_UART_TxBuf[GUA_UART_MAX_NUM_TX_BYTES];
extern GUA_U32 gGUA_UART_WantedRxBytes;
extern GUA_U8 gGUA_UART_Size;

/*********************函数声明************************/
typedef void (*GUA_UART_Callback) (UART_Handle nGUA_Handle, void *npGUA_Buf, size_t
nGUA_Count);
extern void GUA_UART_Init(GUA_UART_Callback GUA_UART_ReadCallback);
extern void GUA_UART_Send(GUA_U8* npGUA_UART_TxBuf, GUA_U8 nGUA_UART_Len);
extern void GUA_UART_Receive(GUA_U8* npGUA_UART_RxBuf, GUA_U8 nGUA_UART_Len);

#endif /* APPLICATION_MY_UART_H_ */
