################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include HALL/SEG_7/subdir.mk
-include HALL/PUSHBUTTON/subdir.mk
-include HALL/LCD/subdir.mk
-include HALL/KEYPAD/subdir.mk
-include HALL/BCD/subdir.mk
-include App/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Amit_D_102.lss \

FLASH_IMAGE += \
Amit_D_102.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Amit_D_102.elf secondary-outputs

# Tool invocations
Amit_D_102.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Amit_D_102.map -mmcu=atmega16 -o "Amit_D_102.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Amit_D_102.lss: Amit_D_102.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Amit_D_102.elf  >"Amit_D_102.lss"
	@echo 'Finished building: $@'
	@echo ' '

Amit_D_102.hex: Amit_D_102.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Amit_D_102.elf  "Amit_D_102.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Amit_D_102.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Amit_D_102.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Amit_D_102.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
