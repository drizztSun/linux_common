################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/ysun/project/github/linux_common/linux_test/linuxSample/Thread_Process/multiThread.cpp \
/home/ysun/project/github/linux_common/linux_test/linuxSample/Thread_Process/process.cpp \
/home/ysun/project/github/linux_common/linux_test/linuxSample/Thread_Process/semaphone.cpp \
/home/ysun/project/github/linux_common/linux_test/linuxSample/Thread_Process/sigal.cpp \
/home/ysun/project/github/linux_common/linux_test/linuxSample/Thread_Process/signal2.cpp 

OBJS += \
./src/Thread_Process/multiThread.o \
./src/Thread_Process/process.o \
./src/Thread_Process/semaphone.o \
./src/Thread_Process/sigal.o \
./src/Thread_Process/signal2.o 

CPP_DEPS += \
./src/Thread_Process/multiThread.d \
./src/Thread_Process/process.d \
./src/Thread_Process/semaphone.d \
./src/Thread_Process/sigal.d \
./src/Thread_Process/signal2.d 


# Each subdirectory must supply rules for building sources it contributes
src/Thread_Process/multiThread.o: /home/ysun/project/github/linux_common/linux_test/linuxSample/Thread_Process/multiThread.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/boost-168/include -I../../../linux_test/linuxSample/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Thread_Process/process.o: /home/ysun/project/github/linux_common/linux_test/linuxSample/Thread_Process/process.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/boost-168/include -I../../../linux_test/linuxSample/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Thread_Process/semaphone.o: /home/ysun/project/github/linux_common/linux_test/linuxSample/Thread_Process/semaphone.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/boost-168/include -I../../../linux_test/linuxSample/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Thread_Process/sigal.o: /home/ysun/project/github/linux_common/linux_test/linuxSample/Thread_Process/sigal.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/boost-168/include -I../../../linux_test/linuxSample/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Thread_Process/signal2.o: /home/ysun/project/github/linux_common/linux_test/linuxSample/Thread_Process/signal2.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/boost-168/include -I../../../linux_test/linuxSample/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


