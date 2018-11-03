################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/STM32F4xx-Nucleo/stm32f4xx_nucleo.c 

OBJS += \
./Utilities/STM32F4xx-Nucleo/stm32f4xx_nucleo.o 

C_DEPS += \
./Utilities/STM32F4xx-Nucleo/stm32f4xx_nucleo.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/STM32F4xx-Nucleo/%.o: ../Utilities/STM32F4xx-Nucleo/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F411RETx -DNUCLEO_F411RE -DDEBUG -DSTM32F411xE -DUSE_HAL_DRIVER -DUSE_RTOS_SYSTICK -I"D:/Git_Projekte/Fernglas/HAL_Driver/Inc/Legacy" -I"D:/Git_Projekte/Fernglas/Utilities/STM32F4xx-Nucleo" -I"D:/Git_Projekte/Fernglas/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"D:/Git_Projekte/Fernglas/Middlewares/Third_Party/FreeRTOS/Source/include" -I"D:/Git_Projekte/Fernglas/inc" -I"D:/Git_Projekte/Fernglas/CMSIS/device" -I"D:/Git_Projekte/Fernglas/CMSIS/core" -I"D:/Git_Projekte/Fernglas/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"D:/Git_Projekte/Fernglas/HAL_Driver/Inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


