################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Cliente.c \
../src/Parcial_1_Lab_1H\ 2020.c \
../src/utn.c 

OBJS += \
./src/Cliente.o \
./src/Parcial_1_Lab_1H\ 2020.o \
./src/utn.o 

C_DEPS += \
./src/Cliente.d \
./src/Parcial_1_Lab_1H\ 2020.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Parcial_1_Lab_1H\ 2020.o: ../src/Parcial_1_Lab_1H\ 2020.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Parcial_1_Lab_1H 2020.d" -MT"src/Parcial_1_Lab_1H\ 2020.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


