################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32f411xe.s 

OBJS += \
./startup/startup_stm32f411xe.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"D:/Git_Projekte/Fernglas/HAL_Driver/Inc/Legacy" -I"D:/Git_Projekte/Fernglas/Utilities/STM32F4xx-Nucleo" -I"D:/Git_Projekte/Fernglas/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"D:/Git_Projekte/Fernglas/Middlewares/Third_Party/FreeRTOS/Source/include" -I"D:/Git_Projekte/Fernglas/inc" -I"D:/Git_Projekte/Fernglas/CMSIS/device" -I"D:/Git_Projekte/Fernglas/CMSIS/core" -I"D:/Git_Projekte/Fernglas/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"D:/Git_Projekte/Fernglas/HAL_Driver/Inc" -I"D:/Git_Projekte/Fernglas/Hillcrest" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


