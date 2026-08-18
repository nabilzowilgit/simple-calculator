################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HALL/LCD/LCD_config.c \
../HALL/LCD/LCD_prog.c 

OBJS += \
./HALL/LCD/LCD_config.o \
./HALL/LCD/LCD_prog.o 

C_DEPS += \
./HALL/LCD/LCD_config.d \
./HALL/LCD/LCD_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HALL/LCD/%.o: ../HALL/LCD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


