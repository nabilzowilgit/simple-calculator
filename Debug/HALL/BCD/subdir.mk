################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HALL/BCD/BCD_config.c \
../HALL/BCD/BCD_prog.c 

OBJS += \
./HALL/BCD/BCD_config.o \
./HALL/BCD/BCD_prog.o 

C_DEPS += \
./HALL/BCD/BCD_config.d \
./HALL/BCD/BCD_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HALL/BCD/%.o: ../HALL/BCD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


