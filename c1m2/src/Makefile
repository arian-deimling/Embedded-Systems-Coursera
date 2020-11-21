#------------------------------------------------------------------------------
# Makefile to generate executable for two separate platforms,
# MSP432 or HOST, and is able to generate pre-processed 
# implementation files and compiled assembly code as well.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      build - compiles all source files to object files
#	   		   then links the files to produce and executable
#
# 	   compile-all - compiles all source files (no linking)
#
#	   [FILENAME].o - creates assembled object file from source
#
#	   [FILENAME].asm - create compiled output assembly code
#
#	   [FILENAME].i - create preprocessed implementation file
#
#	   clean - cleans up any/all generated files
#
# Platform Overrides:
#      HOST - build the target for the host machine using gcc
# 			  compiler
#
#	   MSP432 - build the target for the MSP432 development
#				board
#
#------------------------------------------------------------------------------
include sources.mk

BASENAME = c1m2

TARGET = $(BASENAME).out
OBJECTS = $(SOURCES:.c=.o)

# MSP432 info for the compiler
CPU = cortex-m4
ARCH = armv7e-m
FLOAT = hard
FPU = fpv4-sp-d16
SPECS = nosys.specs
LINKER_FILE = ../msp432p401r.lds

# standard compiler flags for either target platform
CFLAGS = -Wall -Werror -g -O0 -std=c99
LDFLAGS = -Wl,-Map=$(BASENAME).map

# Platform info passed in the make command
PLATFORM := $(PLATFORM)

# if building for the MSP432 platform
ifeq ($(PLATFORM), MSP432)

# need to use arm cross-compiler for MSP432 target
CC = arm-none-eabi-gcc

# add MSP432 specific flags
CFLAGS += -T $(LINKER_FILE) \
		-DMSP432 \
		-mcpu=$(CPU) \
		-mthumb \
		-march=$(ARCH) \
		-mfloat-abi=$(FLOAT) \
		-mfpu=$(FPU) \
		--specs=$(SPECS)

# if building for the host platform
else 

	# host machine uses gcc compiler
	CC = gcc

	# add host-specific flags
	CFLAGS += -DHOST

endif

# ----- BUILD TARGETS FOR OBJECT FILES AND EXECUTABLE ----- #

# `make build` builds the executable
.PHONY: build
build: $(TARGET)

# `make compile-all` compiles all dependencies but does not
# performing the linking step
.PHONY: compile-all
compile-all: $(OBJECTS)

# build the executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ $^

# build object files required for all platforms
main.o: main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

memory.o: memory.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

# additional object files required for MSP432 build
ifeq ($(PLATFORM), MSP432)

interrupts_msp432p401r_gcc.o: interrupts_msp432p401r_gcc.c memory.o
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

startup_msp432p401r_gcc.o: startup_msp432p401r_gcc.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

system_msp432p401r.o: system_msp432p401r.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<
endif

# ----- GENERATE PREPROCESSED IMPLEMENTATION FILES ----- #
main.i: main.c
	$(CC) $(CFLAGS) $(INCLUDES) -E -o $@ $<

memory.i: memory.c
	$(CC) $(CFLAGS) $(INCLUDES) -E -o $@ $<

# implementation files only available with MSP432 platform
ifeq ($(PLATFORM), MSP432)

interrupts_msp432p401r_gcc.i: interrupts_msp432p401r_gcc.c
	$(CC) $(CFLAGS) $(INCLUDES) -E -o $@ $<

startup_msp432p401r_gcc.i: startup_msp432p401r_gcc.c
	$(CC) $(CFLAGS) $(INCLUDES) -E -o $@ $<

system_msp432p401r.i: system_msp432p401r.c
	$(CC) $(CFLAGS) $(INCLUDES) -E -o $@ $<
endif

# ----- GENERATE OUTPUT ASSEMBLY FROM COMPILATION ----- #
$(BASENAME).asm: $(TARGET)
	objdump -f $<

main.asm: main.c
	$(CC) $(CFLAGS) $(INCLUDES) -S -o $@ $<

memory.asm: memory.c
	$(CC) $(CFLAGS) $(INCLUDES) -S -o $@ $<

# assembly files only available with MSP432 platform
ifeq ($(PLATFORM), MSP432)

interrupts_msp432p401r_gcc.asm: interrupts_msp432p401r_gcc.c
	$(CC) $(CFLAGS) $(INCLUDES) -S -o $@ $<

startup_msp432p401r_gcc.asm: startup_msp432p401r_gcc.c
	$(CC) $(CFLAGS) $(INCLUDES) -S -o $@ $<

system_msp432p401r.asm: system_msp432p401r.c
	$(CC) $(CFLAGS) $(INCLUDES) -S -o $@ $<
endif

# ----- CLEAN UP ANY/ALL GENERATED FILES ----- #
.PHONY: clean
clean:
	echo $(INCLUDES)
	rm -f *.o *.i *.asm $(TARGET) $(BASENAME).map

#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************
