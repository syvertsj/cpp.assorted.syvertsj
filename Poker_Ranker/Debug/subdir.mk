################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Card.cpp \
../Categorizer.cpp \
../FlushCategorizer.cpp \
../FourOfAKindCategorizer.cpp \
../FullHouseCategorizer.cpp \
../Hand.cpp \
../HighCardCategorizer.cpp \
../OnePairCategorizer.cpp \
../PokerRanker.cpp \
../StraightCategorizer.cpp \
../StraightFlushCategorizer.cpp \
../ThreeOfAKindCategorizer.cpp \
../TwoPairCategorizer.cpp \
../mainPokerRanker.cpp 

OBJS += \
./Card.o \
./Categorizer.o \
./FlushCategorizer.o \
./FourOfAKindCategorizer.o \
./FullHouseCategorizer.o \
./Hand.o \
./HighCardCategorizer.o \
./OnePairCategorizer.o \
./PokerRanker.o \
./StraightCategorizer.o \
./StraightFlushCategorizer.o \
./ThreeOfAKindCategorizer.o \
./TwoPairCategorizer.o \
./mainPokerRanker.o 

CPP_DEPS += \
./Card.d \
./Categorizer.d \
./FlushCategorizer.d \
./FourOfAKindCategorizer.d \
./FullHouseCategorizer.d \
./Hand.d \
./HighCardCategorizer.d \
./OnePairCategorizer.d \
./PokerRanker.d \
./StraightCategorizer.d \
./StraightFlushCategorizer.d \
./ThreeOfAKindCategorizer.d \
./TwoPairCategorizer.d \
./mainPokerRanker.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


