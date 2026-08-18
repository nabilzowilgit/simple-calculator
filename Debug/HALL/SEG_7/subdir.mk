################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HALL/SEG_7/SEG_7_priviteconfig.c \
../HALL/SEG_7/SEG_7_prog.c 

OBJS += \
./HALL/SEG_7/SEG_7_priviteconfig.o \
./HALL/SEG_7/SEG_7_prog.o 

C_DEPS += \
./HALL/SEG_7/SEG_7_priviteconfig.d \
./HALL/SEG_7/SEG_7_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HALL/SEG_7/%.o: ../HALL/SEG_7/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


