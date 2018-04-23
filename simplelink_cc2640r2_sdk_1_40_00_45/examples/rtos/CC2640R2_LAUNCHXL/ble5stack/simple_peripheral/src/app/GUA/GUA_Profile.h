//**********************************************************************
//name: GUA_profile.h
//introduce: 自定义的服务的头文件，内含一个可读、可写、可通知的特征值
//**********************************************************************

#ifndef _GUA_PROFILE_H_
#define _GUA_PROFILE_H_
#ifdef __cplusplus
extern "C"
{
    #endif
    /*********************************************************************
    * INCLUDES
    */

    /*********************************************************************
    * CONSTANTS
    */

    // Profile Parameters
    #define GUAPROFILE_CHAR1 0 // RW uint8 - Profile GUA Characteristic 1 value

    // GUA Service UUID
    #define GUAPROFILE_SERV_UUID 0xFFE0

    // GUA CHAR1 UUID
    #define GUAPROFILE_CHAR1_UUID 0xFFE1

    // GUA Profile Services bit fields
    #define GUAPROFILE_SERVICE 0x00000001

    // Length of GUA Characteristic 1 in bytes
    #define GUAPROFILE_CHAR1_LEN 20

    /*********************************************************************
    * TYPEDEFS
    */

    /*********************************************************************
    * MACROS
    */

    /*********************************************************************
    * Profile Callbacks
    */

    // Callback when a characteristic value has changed
    typedef void (*GUAProfileChange_t)(uint8 paramID);
    typedef struct
    {
        GUAProfileChange_t pfnGUAProfileChange; // Called when characteristic value changes
    }GUAProfileCBs_t;

    /*********************************************************************
    * API FUNCTIONS
    */

    /*
    * GUAProfile_AddService- Initializes the GUA service by registering
    * GATT attributes with the GATT server.
    *
    * @param services - services to add. This is a bit map and can
    * contain more than one service.
    */
    extern bStatus_t GUAProfile_AddService(uint32 services);

    /*
    * GUAProfile_RegisterAppCBs - Registers the application callback function.
    * Only call this function once.
    *
    * appCallbacks - pointer to application callbacks.
    */
    extern bStatus_t GUAProfile_RegisterAppCBs(GUAProfileCBs_t *appCallbacks);

    /*
     * * GUAProfile_SetParameter - Set a Simple Key Profile parameter.
    *
    * param - Profile parameter ID
    * len - length of data to right
    * pValue - pointer to data to write. This is dependent on
    * the parameter ID and WILL be cast to the appropriate
    * data type (example: data type of uint16 will be cast to
    * uint16 pointer).
    */
    extern bStatus_t GUAProfile_SetParameter(uint8 param, uint8 len, void *pValue);

    /*
    * GUA_GetParameter - Get a Simple Key Profile parameter.
    *
    * param - Profile parameter ID
    * pValue - pointer to data to write. This is dependent on
    * the parameter ID and WILL be cast to the appropriate
    * data type (example: data type of uint16 will be cast to
    * uint16 pointer).
    */
    extern bStatus_t GUAProfile_GetParameter(uint8 param, void *pValue);

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
    /*********************函数声明************************/
    extern void GUA_Profile_Notify(GUA_U8 nGUA_Param, GUA_U16 nGUA_ConnHandle, GUA_U8 *pGUA_Value,
    GUA_U8 nGUA_Len);
    /*********************************************************************
    *********************************************************************/
    #ifdef __cplusplus
}
#endif
#endif /* GUA_PROFILE_H */
