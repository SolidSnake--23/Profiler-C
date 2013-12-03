CC=gcc
EXEC=main
CFLAGS=-O2 -Wall -g -DPROFILE_MODE
LFLAGS=-lm -lrt
OBJECTS=main.o macro_profiler.o
################################

all: m
	$(CC) -o $(EXEC) $(OBJECTS) $(LFLAGS)

m: macro_profiler
	$(CC) -c main.c $(CFLAGS) $(LFLAGS)

macro_profiler:
	$(CC) -c macro_profiler.c $(CFLAGS) $(LFLAGS)

clean:
	rm -rf $(OBJECTS)

mrproper: clean
	rm -rf $(EXEC)
