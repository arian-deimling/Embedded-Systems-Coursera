BASENAME = c1m3

TARGET = $(BASENAME).out
SOURCES = main.c misc.c
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = -I.

LINKER_FILE = ./msp432p401r.lds

LDFLAGS = -Wl,-Map=$(BASENAME).map
CFLAGS = -Wall -Werror -g -O0 -std=c99 $(LDFLAGS)

CC = gcc

.PHONY: build
build: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ $^

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

.PHONY: clean
clean:
	rm -f *.o *.out *.map *.asm *.s