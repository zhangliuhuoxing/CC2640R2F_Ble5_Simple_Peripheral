################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Application/board_key.obj: ../Application/board_key.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" --cmd_file="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/config/build_components.opt" --cmd_file="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/config/factory_config.opt" --cmd_file="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_stack_library/TOOLS/build_config.opt"  -mv7M3 --code_state=16 -me -O4 --opt_for_speed=0 --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/Application" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/Startup" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/PROFILES" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/Include" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/controller/cc26xx_r2/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/rom" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/common/cc26xx" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/icall/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/target" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/hal/src/target/_common" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/hal/src/target/_common/cc26xx" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/hal/src/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/heapmgr" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/icall/src/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/osal/src/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/services/src/saddr" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/services/src/sdata" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/devices/cc26x0r2" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=DeviceFamily_CC26X0R2 --define=BOARD_DISPLAY_USE_LCD=0 --define=BOARD_DISPLAY_USE_UART=1 --define=BOARD_DISPLAY_USE_UART_ANSI=1 --define=CC2640R2_LAUNCHXL --define=CC26XX --define=CC26XX_R2 --define=ICALL_EVENTS --define=ICALL_JT --define=ICALL_LITE --define=ICALL_MAX_NUM_ENTITIES=6 --define=ICALL_MAX_NUM_TASKS=3 --define=ICALL_STACK0_ADDR --define=POWER_SAVING --define=RF_SINGLEMODE --define=STACK_LIBRARY --define=TBM_ACTIVE_ITEMS_ONLY --define=USE_ICALL --define=xdc_runtime_Assert_DISABLE_ALL --define=xdc_runtime_Log_DISABLE_ALL -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="Application/board_key.d_raw" --obj_directory="Application" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Application/simple_peripheral.obj: ../Application/simple_peripheral.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" --cmd_file="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/config/build_components.opt" --cmd_file="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/config/factory_config.opt" --cmd_file="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_stack_library/TOOLS/build_config.opt"  -mv7M3 --code_state=16 -me -O4 --opt_for_speed=0 --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/Application" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/Startup" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/PROFILES" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/Include" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/controller/cc26xx_r2/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/rom" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/common/cc26xx" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/icall/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/target" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/hal/src/target/_common" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/hal/src/target/_common/cc26xx" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/hal/src/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/heapmgr" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/icall/src/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/osal/src/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/services/src/saddr" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/services/src/sdata" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/devices/cc26x0r2" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=DeviceFamily_CC26X0R2 --define=BOARD_DISPLAY_USE_LCD=0 --define=BOARD_DISPLAY_USE_UART=1 --define=BOARD_DISPLAY_USE_UART_ANSI=1 --define=CC2640R2_LAUNCHXL --define=CC26XX --define=CC26XX_R2 --define=ICALL_EVENTS --define=ICALL_JT --define=ICALL_LITE --define=ICALL_MAX_NUM_ENTITIES=6 --define=ICALL_MAX_NUM_TASKS=3 --define=ICALL_STACK0_ADDR --define=POWER_SAVING --define=RF_SINGLEMODE --define=STACK_LIBRARY --define=TBM_ACTIVE_ITEMS_ONLY --define=USE_ICALL --define=xdc_runtime_Assert_DISABLE_ALL --define=xdc_runtime_Log_DISABLE_ALL -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="Application/simple_peripheral.d_raw" --obj_directory="Application" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Application/simple_peripheral_menu.obj: ../Application/simple_peripheral_menu.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" --cmd_file="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/config/build_components.opt" --cmd_file="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/config/factory_config.opt" --cmd_file="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_stack_library/TOOLS/build_config.opt"  -mv7M3 --code_state=16 -me -O4 --opt_for_speed=0 --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/Application" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/Startup" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/PROFILES" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/Include" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/controller/cc26xx_r2/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/rom" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/common/cc26xx" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/icall/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/target" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/hal/src/target/_common" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/hal/src/target/_common/cc26xx" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/hal/src/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/heapmgr" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/icall/src/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/osal/src/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/services/src/saddr" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/services/src/sdata" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/devices/cc26x0r2" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=DeviceFamily_CC26X0R2 --define=BOARD_DISPLAY_USE_LCD=0 --define=BOARD_DISPLAY_USE_UART=1 --define=BOARD_DISPLAY_USE_UART_ANSI=1 --define=CC2640R2_LAUNCHXL --define=CC26XX --define=CC26XX_R2 --define=ICALL_EVENTS --define=ICALL_JT --define=ICALL_LITE --define=ICALL_MAX_NUM_ENTITIES=6 --define=ICALL_MAX_NUM_TASKS=3 --define=ICALL_STACK0_ADDR --define=POWER_SAVING --define=RF_SINGLEMODE --define=STACK_LIBRARY --define=TBM_ACTIVE_ITEMS_ONLY --define=USE_ICALL --define=xdc_runtime_Assert_DISABLE_ALL --define=xdc_runtime_Log_DISABLE_ALL -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="Application/simple_peripheral_menu.d_raw" --obj_directory="Application" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Application/two_btn_menu.obj: ../Application/two_btn_menu.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" --cmd_file="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/config/build_components.opt" --cmd_file="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/config/factory_config.opt" --cmd_file="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_stack_library/TOOLS/build_config.opt"  -mv7M3 --code_state=16 -me -O4 --opt_for_speed=0 --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/Application" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/Startup" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/PROFILES" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/Include" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/controller/cc26xx_r2/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/rom" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/common/cc26xx" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/icall/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/target" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/hal/src/target/_common" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/hal/src/target/_common/cc26xx" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/hal/src/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/heapmgr" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/icall/src/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/osal/src/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/services/src/saddr" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/services/src/sdata" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/devices/cc26x0r2" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=DeviceFamily_CC26X0R2 --define=BOARD_DISPLAY_USE_LCD=0 --define=BOARD_DISPLAY_USE_UART=1 --define=BOARD_DISPLAY_USE_UART_ANSI=1 --define=CC2640R2_LAUNCHXL --define=CC26XX --define=CC26XX_R2 --define=ICALL_EVENTS --define=ICALL_JT --define=ICALL_LITE --define=ICALL_MAX_NUM_ENTITIES=6 --define=ICALL_MAX_NUM_TASKS=3 --define=ICALL_STACK0_ADDR --define=POWER_SAVING --define=RF_SINGLEMODE --define=STACK_LIBRARY --define=TBM_ACTIVE_ITEMS_ONLY --define=USE_ICALL --define=xdc_runtime_Assert_DISABLE_ALL --define=xdc_runtime_Log_DISABLE_ALL -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="Application/two_btn_menu.d_raw" --obj_directory="Application" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Application/util.obj: ../Application/util.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" --cmd_file="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/config/build_components.opt" --cmd_file="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/config/factory_config.opt" --cmd_file="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_stack_library/TOOLS/build_config.opt"  -mv7M3 --code_state=16 -me -O4 --opt_for_speed=0 --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/Application" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/Startup" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/PROFILES" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/ble5_simple_peripheral_cc2640r2lp_app/Include" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/controller/cc26xx_r2/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/rom" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/common/cc26xx" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/icall/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/target" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/hal/src/target/_common" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/hal/src/target/_common/cc26xx" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/hal/src/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/heapmgr" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/icall/src/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/osal/src/inc" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/services/src/saddr" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/services/src/sdata" --include_path="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Simple_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/devices/cc26x0r2" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=DeviceFamily_CC26X0R2 --define=BOARD_DISPLAY_USE_LCD=0 --define=BOARD_DISPLAY_USE_UART=1 --define=BOARD_DISPLAY_USE_UART_ANSI=1 --define=CC2640R2_LAUNCHXL --define=CC26XX --define=CC26XX_R2 --define=ICALL_EVENTS --define=ICALL_JT --define=ICALL_LITE --define=ICALL_MAX_NUM_ENTITIES=6 --define=ICALL_MAX_NUM_TASKS=3 --define=ICALL_STACK0_ADDR --define=POWER_SAVING --define=RF_SINGLEMODE --define=STACK_LIBRARY --define=TBM_ACTIVE_ITEMS_ONLY --define=USE_ICALL --define=xdc_runtime_Assert_DISABLE_ALL --define=xdc_runtime_Log_DISABLE_ALL -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="Application/util.d_raw" --obj_directory="Application" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


