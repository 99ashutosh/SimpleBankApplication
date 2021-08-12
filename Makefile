# change application name here (executable output name)
TARGET=bank_application

# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

GTKLIB=$(shell pkg-config --libs gtk+-3.0)

# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) -export-dynamic
LDLIBS = $(shell pkg-config --libs gtk+-3.0)

OBJS= src/main.o src/bank_management.o src/dashboard.c src/greet_main.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)

main.o: src/main.o src/bank_management.o src/dashboard.o src/greet_main.o
	$(CC) -c $(CCFLAGS) src/main.c src/bank_management.c src/dashboard.c src/greet_main.c $(GTKLIB) -o main.o bank_management.o greet_main.o dashboard.o

clean:
	rm -f *.o $(TARGET)