//**********************************************************************
//name: GUA_UART.c
//introduce: 串口驱动
//**********************************************************************
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Log.h>
#include <ti/sysbios/BIOS.h>
#include "board.h"
#include <ti/drivers/power/PowerCC26XX.h>
#include <ti/drivers/UART.h>
#include <ti/drivers/uart/UARTCC26XX.h>
#include "GUA_Uart.h"

/*********************宏定义************************/
#define GUA_UART_RX IOID_2 //接收引脚
#define GUA_UART_TX IOID_3 //发送引脚

/*********************内部变量************************/
//串口号
typedef enum{
    GUA_UART0 = 0,
    GUA_UARTCOUNT
}GUA_UARTName;

//流控制所需的配置
const UARTCC26XX_HWAttrsV2 GUA_UART_CC26XXHWAttrs[GUA_UARTCOUNT] = {
    {
        .baseAddr = UART0_BASE,
        .powerMngrId = PowerCC26XX_PERIPH_UART0,
        .intNum = INT_UART0_COMB,
        .intPriority = ~0,
        .swiPriority = 0,
        .txPin = GUA_UART_TX,
        .rxPin = GUA_UART_RX,
        .ctsPin = PIN_UNASSIGNED,
        .rtsPin = PIN_UNASSIGNED
    }
};

//串口目标
static UARTCC26XX_Object GUA_UART_CC26XXObjects[GUA_UARTCOUNT];
static const UART_Config GUA_UART_Config[GUA_UARTCOUNT] = {
    {
        .fxnTablePtr = &UARTCC26XX_fxnTable,
        .object = &GUA_UART_CC26XXObjects[GUA_UART0],
        .hwAttrs = &GUA_UART_CC26XXHWAttrs[GUA_UART0]
    }
};

//串口句柄
static UART_Handle stGUA_UART_Handle;
//串口参数
static UART_Params stGUA_UART_Params;

/*********************外部变量************************/
GUA_U8 gaGUA_UART_RxBuf[GUA_UART_MAX_NUM_RX_BYTES] = {0};
GUA_U8 gaGUA_UART_TxBuf[GUA_UART_MAX_NUM_TX_BYTES] = {0};
GUA_U32 gGUA_UART_WantedRxBytes;
GUA_U8 gGUA_UART_Size;

//**********************************************************************
//name: GUA_UART_Init
//introduce: 串口驱动初始化
//parameter: none
//return: none
//**********************************************************************
void GUA_UART_Init(GUA_UART_Callback GUA_UART_ReadCallback)
{
    //初始化为默认值
    UART_Params_init(&stGUA_UART_Params);
    //参数设置
    stGUA_UART_Params.baudRate = 115200;
    stGUA_UART_Params.writeDataMode = UART_DATA_BINARY;
    stGUA_UART_Params.readMode = UART_MODE_CALLBACK;
    stGUA_UART_Params.readDataMode = UART_DATA_BINARY;
    stGUA_UART_Params.readCallback = GUA_UART_ReadCallback;
    //打开串口
    stGUA_UART_Handle =
    GUA_UART_Config[0].fxnTablePtr->openFxn((UART_Handle)&GUA_UART_Config[0],
    &stGUA_UART_Params);
    //启动串口局部返回功能
    GUA_UART_Config[0].fxnTablePtr->controlFxn(stGUA_UART_Handle,
    UARTCC26XX_CMD_RETURN_PARTIAL_ENABLE, NULL);
    //开始第一次的读取等待
    gGUA_UART_WantedRxBytes = GUA_UART_MAX_NUM_RX_BYTES;
    GUA_UART_Receive(gaGUA_UART_RxBuf, gGUA_UART_WantedRxBytes);
}
//**********************************************************************
//name: GUA_UART_Send
//introduce: 串口的写数据的函数
//parameter: npGUA_UART_TxBuf：写缓冲区
//           nGUA_UART_Len：数据长度
//return: none
//**********************************************************************
void GUA_UART_Send(GUA_U8* npGUA_UART_TxBuf, GUA_U8 nGUA_UART_Len)
{
    GUA_UART_Config[0].fxnTablePtr->writeFxn(stGUA_UART_Handle, npGUA_UART_TxBuf,
    nGUA_UART_Len);
}
//**********************************************************************
//name: GUA_UART_Receive
//introduce: 串口的写数据的函数
//parameter: npGUA_UART_RxBuf：读缓冲区
//           nGUA_UART_Len：数据长度
//return: none
//**********************************************************************
void GUA_UART_Receive(GUA_U8* npGUA_UART_RxBuf, GUA_U8 nGUA_UART_Len)
{
    GUA_UART_Config[0].fxnTablePtr->readFxn(stGUA_UART_Handle, npGUA_UART_RxBuf,
    nGUA_UART_Len);
}
