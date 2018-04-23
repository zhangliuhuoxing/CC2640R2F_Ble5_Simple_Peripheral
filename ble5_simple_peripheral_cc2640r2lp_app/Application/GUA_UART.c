//**********************************************************************
//name: GUA_UART.c
//introduce: ��������
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

/*********************�궨��************************/
#define GUA_UART_RX IOID_2 //��������
#define GUA_UART_TX IOID_3 //��������

/*********************�ڲ�����************************/
//���ں�
typedef enum{
    GUA_UART0 = 0,
    GUA_UARTCOUNT
}GUA_UARTName;

//���������������
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

//����Ŀ��
static UARTCC26XX_Object GUA_UART_CC26XXObjects[GUA_UARTCOUNT];
static const UART_Config GUA_UART_Config[GUA_UARTCOUNT] = {
    {
        .fxnTablePtr = &UARTCC26XX_fxnTable,
        .object = &GUA_UART_CC26XXObjects[GUA_UART0],
        .hwAttrs = &GUA_UART_CC26XXHWAttrs[GUA_UART0]
    }
};

//���ھ��
static UART_Handle stGUA_UART_Handle;
//���ڲ���
static UART_Params stGUA_UART_Params;

/*********************�ⲿ����************************/
GUA_U8 gaGUA_UART_RxBuf[GUA_UART_MAX_NUM_RX_BYTES] = {0};
GUA_U8 gaGUA_UART_TxBuf[GUA_UART_MAX_NUM_TX_BYTES] = {0};
GUA_U32 gGUA_UART_WantedRxBytes;
GUA_U8 gGUA_UART_Size;

//**********************************************************************
//name: GUA_UART_Init
//introduce: ����������ʼ��
//parameter: none
//return: none
//**********************************************************************
void GUA_UART_Init(GUA_UART_Callback GUA_UART_ReadCallback)
{
    //��ʼ��ΪĬ��ֵ
    UART_Params_init(&stGUA_UART_Params);
    //��������
    stGUA_UART_Params.baudRate = 115200;
    stGUA_UART_Params.writeDataMode = UART_DATA_BINARY;
    stGUA_UART_Params.readMode = UART_MODE_CALLBACK;
    stGUA_UART_Params.readDataMode = UART_DATA_BINARY;
    stGUA_UART_Params.readCallback = GUA_UART_ReadCallback;
    //�򿪴���
    stGUA_UART_Handle =
    GUA_UART_Config[0].fxnTablePtr->openFxn((UART_Handle)&GUA_UART_Config[0],
    &stGUA_UART_Params);
    //�������ھֲ����ع���
    GUA_UART_Config[0].fxnTablePtr->controlFxn(stGUA_UART_Handle,
    UARTCC26XX_CMD_RETURN_PARTIAL_ENABLE, NULL);
    //��ʼ��һ�εĶ�ȡ�ȴ�
    gGUA_UART_WantedRxBytes = GUA_UART_MAX_NUM_RX_BYTES;
    GUA_UART_Receive(gaGUA_UART_RxBuf, gGUA_UART_WantedRxBytes);
}
//**********************************************************************
//name: GUA_UART_Send
//introduce: ���ڵ�д���ݵĺ���
//parameter: npGUA_UART_TxBuf��д������
//           nGUA_UART_Len�����ݳ���
//return: none
//**********************************************************************
void GUA_UART_Send(GUA_U8* npGUA_UART_TxBuf, GUA_U8 nGUA_UART_Len)
{
    GUA_UART_Config[0].fxnTablePtr->writeFxn(stGUA_UART_Handle, npGUA_UART_TxBuf,
    nGUA_UART_Len);
}
//**********************************************************************
//name: GUA_UART_Receive
//introduce: ���ڵ�д���ݵĺ���
//parameter: npGUA_UART_RxBuf����������
//           nGUA_UART_Len�����ݳ���
//return: none
//**********************************************************************
void GUA_UART_Receive(GUA_U8* npGUA_UART_RxBuf, GUA_U8 nGUA_UART_Len)
{
    GUA_UART_Config[0].fxnTablePtr->readFxn(stGUA_UART_Handle, npGUA_UART_RxBuf,
    nGUA_UART_Len);
}
