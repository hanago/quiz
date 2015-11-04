CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99 -Wl,--no-as-needed -lrt
 
EXEC = iterative recursive

all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

pattern: pattern.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

run: $(EXEC)
	@ echo "iterative:"
	@./iterative
	@ echo
	@ echo "recursive:"
	@./recursive

clean:
	$(RM) $(EXEC) *.o perf.*
