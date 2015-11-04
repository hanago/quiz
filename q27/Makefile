CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99 -Wl,--no-as-needed -lrt

EXEC = main
all: $(EXEC)

main: main.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

run: $(EXEC)
	@./main

clean:
	$(RM) $(EXEC) *.o perf.*
