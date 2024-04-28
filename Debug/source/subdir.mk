################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/buzzer_ir_sensor.c \
../source/i2c_functions.c \
../source/main.c \
../source/mtb.c \
../source/pwm_red.c \
../source/semihost_hardfault.c \
../source/zx_gesture.c 

C_DEPS += \
./source/buzzer_ir_sensor.d \
./source/i2c_functions.d \
./source/main.d \
./source/mtb.d \
./source/pwm_red.d \
./source/semihost_hardfault.d \
./source/zx_gesture.d 

OBJS += \
./source/buzzer_ir_sensor.o \
./source/i2c_functions.o \
./source/main.o \
./source/mtb.o \
./source/pwm_red.o \
./source/semihost_hardfault.o \
./source/zx_gesture.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"U:\PES\Final Project\i2c_test\board" -I"U:\PES\Final Project\i2c_test\source" -I"U:\PES\Final Project\i2c_test" -I"U:\PES\Final Project\i2c_test\drivers" -I"U:\PES\Final Project\i2c_test\CMSIS" -I"U:\PES\Final Project\i2c_test\utilities" -I"U:\PES\Final Project\i2c_test\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/buzzer_ir_sensor.d ./source/buzzer_ir_sensor.o ./source/i2c_functions.d ./source/i2c_functions.o ./source/main.d ./source/main.o ./source/mtb.d ./source/mtb.o ./source/pwm_red.d ./source/pwm_red.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o ./source/zx_gesture.d ./source/zx_gesture.o

.PHONY: clean-source

