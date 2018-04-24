//**********************************************************************
//name: GUA_profile.c
//introduce: 自定义的服务，内含一个可读、可写、可通知的特征值
//**********************************************************************

#include <string.h>
#include "bcomdef.h"
#include "OSAL.h"
#include "linkdb.h"
#include "att.h"
#include "gatt.h"
#include "gatt_uuid.h"
#include "gattservapp.h"
#include "gapbondmgr.h"
#include "GUA_Profile.h"

/*********************************************************************
* MACROS
*/

/*********************************************************************
* CONSTANTS
*/
//属性表的数据长度
#define SERVAPP_NUM_ATTR_SUPPORTED 5

//属性在属性表中的偏移值
#define ATTRTBL_GUA_CHAR1_IDX 2     //char1 在属性表的偏移值
#define ATTRTBL_GUA_CHAR1_CCC_IDX 3 //char1 的 notify 开关在属性表的偏移值

/*********************************************************************
* TYPEDEFS
* */

/*********************************************************************
* GLOBAL VARIABLES
*/
// GUA Service UUID: 0xFFE0
CONST uint8 GUAServUUID[ATT_BT_UUID_SIZE] =
{
     LO_UINT16(GUAPROFILE_SERV_UUID), HI_UINT16(GUAPROFILE_SERV_UUID)
};
// GUA char1 UUID: 0xFFE1
CONST uint8 GUAChar1UUID[ATT_BT_UUID_SIZE] =
{
     LO_UINT16(GUAPROFILE_CHAR1_UUID), HI_UINT16(GUAPROFILE_CHAR1_UUID)
};
/*********************************************************************
* EXTERNAL VARIABLES
*/

/*********************************************************************
* EXTERNAL FUNCTIONS
*/

/*********************************************************************
* LOCAL VARIABLES
*/
static GUAProfileCBs_t *GUAProfile_AppCBs = NULL;

/*********************************************************************
* Profile Attributes - variables
*/
// GUA Service attribute
static CONST gattAttrType_t GUAProfile_Service = { ATT_BT_UUID_SIZE, GUAServUUID };
// GUA Characteristic 1 Properties
static uint8 GUAProfile_Char1_Props = GATT_PROP_READ | GATT_PROP_WRITE | GATT_PROP_NOTIFY;
// GUA Characteristic 1 Value
static uint8 GUAProfile_Char1[GUAPROFILE_CHAR1_LEN] = {0};
// GUA Characteristic 1 Configs
static gattCharCfg_t *GUAProfile_Char1_Config;
// GUA Characteristic 1 User Description
static uint8 GUAProfile_Char1_UserDesp[10] = "GUA Char1\0";

/*********************************************************************
* Profile Attributes - Table
*/
static gattAttribute_t GUAProfileAttrTbl[SERVAPP_NUM_ATTR_SUPPORTED] =
{
    // GUA Service
    {
        { ATT_BT_UUID_SIZE, primaryServiceUUID }, /* type */
        GATT_PERMIT_READ, /* permissions */
        0, /* handle */
        (uint8 *)&GUAProfile_Service /* pValue */
    },
    // GUA Characteristic 1 Declaration
    {
        { ATT_BT_UUID_SIZE, characterUUID },
        GATT_PERMIT_READ,
        0,
        &GUAProfile_Char1_Props
    },
    // GUA Characteristic 1 Value
    {
        { ATT_BT_UUID_SIZE, GUAChar1UUID },
        GATT_PERMIT_READ | GATT_PERMIT_WRITE,
        0,
        GUAProfile_Char1
    },
    // GUA Characteristic 1 configuration
    {
        { ATT_BT_UUID_SIZE, clientCharCfgUUID },
        GATT_PERMIT_READ | GATT_PERMIT_WRITE,
        0,
        (uint8 *)&GUAProfile_Char1_Config
    },
    // GUA Characteristic 1 User Description
    {
        { ATT_BT_UUID_SIZE, charUserDescUUID },
        GATT_PERMIT_READ,
        0,
        GUAProfile_Char1_UserDesp
    },
};

/*********************************************************************
* LOCAL FUNCTIONS
*/
static uint8 GUAProfile_ReadAttrCB( uint16 connHandle, gattAttribute_t *pAttr,
uint8 *pValue, uint16 *pLen, uint16 offset, uint16 maxLen, uint8
method );
static bStatus_t GUAProfile_WriteAttrCB( uint16 connHandle, gattAttribute_t *pAttr,
uint8 *pValue, uint16 len, uint16 offset, uint8 method );

/*********************************************************************
* PROFILE CALLBACKS
*/
// GUAProfile Service Callbacks
CONST gattServiceCBs_t GUAProfileCBs =
{
    GUAProfile_ReadAttrCB, // Read callback function pointer
    GUAProfile_WriteAttrCB, // Write callback function pointer
    NULL // Authorization callback function pointer
};

/*********************************************************************
* PUBLIC FUNCTIONS
*/
/*********************************************************************
* @fn GUAProfile_AddService
*
* @brief Initializes the GUA service by registering
* GATT attributes with the GATT server.
*
* @param services - services to add. This is a bit map and can
* contain more than one service.
* @return Success or Failure
*/
bStatus_t GUAProfile_AddService( uint32 services )
{
    uint8 status = SUCCESS;
    // Allocate Client Characteristic Configuration table
    GUAProfile_Char1_Config = (gattCharCfg_t *)ICall_malloc( sizeof(gattCharCfg_t) *
    linkDBNumConns );
    if ( GUAProfile_Char1_Config == NULL )
    {
        return ( bleMemAllocError );
    }
    // Initialize Client Characteristic Configuration attributes
    GATTServApp_InitCharCfg( INVALID_CONNHANDLE, GUAProfile_Char1_Config );
    if ( services & GUAPROFILE_SERVICE )
    {
        // Register GATT attribute list and CBs with GATT Server App
        status = GATTServApp_RegisterService( GUAProfileAttrTbl,
        GATT_NUM_ATTRS( GUAProfileAttrTbl ),
        GATT_MAX_ENCRYPT_KEY_SIZE,
        &GUAProfileCBs );
    }
    return ( status );
}

/*********************************************************************
* @fn GUAProfile_RegisterAppCBs
*
* @brief Registers the application callback function. Only call
* this function once.
*
* @param callbacks - pointer to application callbacks.
*
* @return SUCCESS or bleAlreadyInRequestedMode
*/
bStatus_t GUAProfile_RegisterAppCBs( GUAProfileCBs_t *appCallbacks )
{
    if ( appCallbacks )
    {
        GUAProfile_AppCBs = appCallbacks;
        return ( SUCCESS );
    }
    else
    {
        return ( bleAlreadyInRequestedMode );
    }
}

/*********************************************************************
* @fn GUAProfile_SetParameter
*
* @brief Set a GUA Profile parameter.
*
* @param param - Profile parameter ID
* @param len - length of data to right
* @param pValue - pointer to data to write. This is dependent on
* the parameter ID and WILL be cast to the appropriate
* data type (example: data type of uint16 will be cast to
* uint16 pointer).
*
* @return bStatus_t
*/
bStatus_t GUAProfile_SetParameter( uint8 param, uint8 len, void *pValue )
{
    bStatus_t ret = SUCCESS;
    switch ( param )
    {
        case GUAPROFILE_CHAR1:
            if ( len == GUAPROFILE_CHAR1_LEN )
            {
                VOID memcpy( GUAProfile_Char1, pValue, GUAPROFILE_CHAR1_LEN );
            }
            else
            {
                ret = bleInvalidRange;
            }
        break;
        default:
            ret = INVALIDPARAMETER;
        break;
    }
    return ( ret );
}

/*********************************************************************
* @fn GUAProfile_GetParameter
*
* @brief Get a GUA Profile parameter.
*
* @param param - Profile parameter ID
* @param pValue - pointer to data to put. This is dependent on
* the parameter ID and WILL be cast to the appropriate
* data type (example: data type of uint16 will be cast to
* uint16 pointer).
*
* @return bStatus_t
*/
bStatus_t GUAProfile_GetParameter( uint8 param, void *pValue )
{
    bStatus_t ret = SUCCESS;
    switch ( param )
    {
        case GUAPROFILE_CHAR1:
            VOID memcpy( pValue, GUAProfile_Char1, GUAPROFILE_CHAR1_LEN );
        break;
        default:
            ret = INVALIDPARAMETER;
        break;
    }
    return ( ret );
}

/*********************************************************************
* @fn GUAProfile_ReadAttrCB
*
* @brief Read an attribute.
*
* @param connHandle - connection message was received on
* @param pAttr - pointer to attribute
* @param pValue - pointer to data to be read
* @param pLen - length of data to be read
* @param offset - offset of the first octet to be read
* * @param maxLen - maximum length of data to be read
*
* @return Success or Failure
*/
static uint8 GUAProfile_ReadAttrCB( uint16 connHandle, gattAttribute_t *pAttr,
uint8 *pValue, uint16 *pLen, uint16 offset, uint16 maxLen, uint8_t
method )
{
    bStatus_t status = SUCCESS;
    // If attribute permissions require authorization to read, return error
    if ( gattPermitAuthorRead( pAttr->permissions ) )
    {
        // Insufficient authorization
        return ( ATT_ERR_INSUFFICIENT_AUTHOR );
    }
    // Make sure it's not a blob operation (no attributes in the profile are long
    if ( offset > 0 )
    {
        return ( ATT_ERR_ATTR_NOT_LONG );
    }
    if ( pAttr->type.len == ATT_BT_UUID_SIZE )
    {
        // 16-bit UUID
        uint16 uuid = BUILD_UINT16( pAttr->type.uuid[0], pAttr->type.uuid[1]);
        switch ( uuid )
        {
            // No need for "GATT_SERVICE_UUID" or "GATT_CLIENT_CHAR_CFG_UUID" cases;
            // gattserverapp handles this type for reads
            // GUA characteristic does not have read permissions, but because it
            // can be sent as a notification, it must be included here
            case GUAPROFILE_CHAR1_UUID:
                *pLen = GUAPROFILE_CHAR1_LEN;
                VOID memcpy( pValue, pAttr->pValue, GUAPROFILE_CHAR1_LEN );
            break;
            default:
                // Should never get here!
                *pLen = 0;
                status = ATT_ERR_ATTR_NOT_FOUND;
            break;
        }
    }
    else
    {
    // 128-bit UUID
    *pLen = 0;
    status = ATT_ERR_INVALID_HANDLE;
    }
    return ( status );
}

/*********************************************************************
* @fn GUAProfile_WriteAttrCB
*
* @brief Validate attribute data prior to a write operation
*
* @param connHandle - connection message was received on
* @param pAttr - pointer to attribute
* @param pValue - pointer to data to be written
* @param len - length of data
* @param offset - offset of the first octet to be written
*
* @return Success or Failure
*/
static bStatus_t GUAProfile_WriteAttrCB( uint16 connHandle, gattAttribute_t *pAttr,
uint8 *pValue, uint16 len, uint16 offset, uint8_t method )
{
    bStatus_t status = SUCCESS;
    uint8 notifyApp = 0xFF;
    // If attribute permissions require authorization to write, return error
    if ( gattPermitAuthorWrite( pAttr->permissions ) )
    {
        // Insufficient authorization
        return ( ATT_ERR_INSUFFICIENT_AUTHOR );
    }
    if ( pAttr->type.len == ATT_BT_UUID_SIZE )
    {
        // 16-bit UUID
        uint16 uuid = BUILD_UINT16( pAttr->type.uuid[0], pAttr->type.uuid[1]);
        switch ( uuid )
        {
            case GUAPROFILE_CHAR1_UUID:
                if ( offset == 0 )
                {
                    if ( len != GUAPROFILE_CHAR1_LEN )
                    {
                        status = ATT_ERR_INVALID_VALUE_SIZE;
                    }
                }
                else
                {
                    status = ATT_ERR_ATTR_NOT_LONG;
                }

                //将接收到的数据写进特征值中，并且置标志位
                if ( status == SUCCESS )
                {
                    VOID memcpy( pAttr->pValue, pValue, GUAPROFILE_CHAR1_LEN );
                    notifyApp = GUAPROFILE_CHAR1;
                }
                break;
            case GATT_CLIENT_CHAR_CFG_UUID:
                //char1 通道，则打开 notify 开关
                if ( pAttr->handle == GUAProfileAttrTbl[ATTRTBL_GUA_CHAR1_CCC_IDX].handle )//GUA CHAR1 NOTIFY
                {
                    status = GATTServApp_ProcessCCCWriteReq( connHandle, pAttr, pValue, len,
                    offset, GATT_CLIENT_CFG_NOTIFY );
                }
                else
                {
                    status = ATT_ERR_INVALID_HANDLE;
                }
                break;
            default:
                status = ATT_ERR_ATTR_NOT_FOUND;
            break;
        }
    }
    else
    {
        // 128-bit UUID
        status = ATT_ERR_INVALID_HANDLE;
    }

    // If a charactersitic value changed then callback function to notify application of change
    if ( (notifyApp != 0xFF ) && GUAProfile_AppCBs && GUAProfile_AppCBs->pfnGUAProfileChange )
    {
        GUAProfile_AppCBs->pfnGUAProfileChange( notifyApp );
    }
    return ( status );
}

//**********************************************************************
//name: GUA_Profile_Notify
//introduce: notify 发送函数
//parameter: nGUA_Param:特征值通道参数
// nGUA_ConnHandle:连接句柄
// pGUA_Value:要通知的数据
// nGUA_Len:要通知的数据长度，范围为 0~SIMPLEPROFILE_CHAR6，最多 20 个字节
//return: none
//**********************************************************************
void GUA_Profile_Notify(GUA_U8 nGUA_Param, GUA_U16 nGUA_ConnHandle, GUA_U8 *pGUA_Value, GUA_U8 nGUA_Len)
{
    attHandleValueNoti_t stGUA_Noti;
    GUA_U16 nGUA_Value;
    switch(nGUA_Param)
    {
        //特征值 1
        case GUAPROFILE_CHAR1:
        {
            //读出 CCC
            nGUA_Value = GATTServApp_ReadCharCfg(nGUA_ConnHandle, GUAProfile_Char1_Config);
            //判断 CCC 是否被打开
            if(nGUA_Value & GATT_CLIENT_CFG_NOTIFY)
            {
                //分配发送数据缓冲区
                stGUA_Noti.pValue = GATT_bm_alloc(nGUA_ConnHandle, ATT_HANDLE_VALUE_NOTI,
                GUAPROFILE_CHAR1_LEN, NULL);
                //分配成功，则发送数据
                if(stGUA_Noti.pValue != NULL)
                {
                    //填充数据
                    stGUA_Noti.handle = GUAProfileAttrTbl[ATTRTBL_GUA_CHAR1_IDX].handle;
                    stGUA_Noti.len = nGUA_Len;
                    memcpy( stGUA_Noti.pValue, pGUA_Value, nGUA_Len);
                    //发送数据
                    if (GATT_Notification(nGUA_ConnHandle, &stGUA_Noti, FALSE) != SUCCESS)
                    {
                        GATT_bm_free((gattMsg_t *)&stGUA_Noti, ATT_HANDLE_VALUE_NOTI);
                    }
                }
            }
            break;
        }
        default:
        break;
    }
}
