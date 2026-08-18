################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HALL/PUSHBUTTON/PUSHBUTTON_config.c \
../HALL/PUSHBUTTON/PUSHBUTTON_prog.c 

OBJS += \
./HALL/PUSHBUTTON/PUSHBUTTON_config.o \
./HALL/PUSHBUTTON/PUSHBUTTON_prog.o 

C_DEPS += \
./HALL/PUSHBUTTON/PUSHBUTTON_config.d \
./HALL/PUSHBUTTON/PUSHBUTTON_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HALL/PUSHBUTTON/%.o: ../HALL/PUSHBUTTON/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


