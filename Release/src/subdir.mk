################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ClientParamBuilder.cpp \
../src/Customer.cpp \
../src/Environment.cpp \
../src/Shop.cpp \
../src/ShopParamBuilder.cpp \
../src/SimulationBuilder.cpp \
../src/simulation.cpp 

OBJS += \
./src/ClientParamBuilder.o \
./src/Customer.o \
./src/Environment.o \
./src/Shop.o \
./src/ShopParamBuilder.o \
./src/SimulationBuilder.o \
./src/simulation.o 

CPP_DEPS += \
./src/ClientParamBuilder.d \
./src/Customer.d \
./src/Environment.d \
./src/Shop.d \
./src/ShopParamBuilder.d \
./src/SimulationBuilder.d \
./src/simulation.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


