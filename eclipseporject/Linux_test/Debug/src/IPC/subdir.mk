################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/ysun/project/github/linux_common/linux_test/linuxSample/IPC/testPipe.cpp 

OBJS += \
./src/IPC/testPipe.o 

CPP_DEPS += \
./src/IPC/testPipe.d 


# Each subdirectory must supply rules for building sources it contributes
src/IPC/testPipe.o: /home/ysun/project/github/linux_common/linux_test/linuxSample/IPC/testPipe.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/boost-168/include -I../../../linux_test/linuxSample/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


