CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99 -Wl,--no-as-needed -lrt
 
EXEC = iterative recursive pattern

all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

pattern: pattern.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

run: $(EXEC)
	@ echo "iterative:"
	@./pattern 10
	@./iterative 10
	@./pattern 100
	@./iterative 100
	@./pattern 1000
	@./iterative 1000
	@./pattern 10000
	@./iterative 10000
	@./pattern 100000
	@./iterative 100000
	@./pattern 1000000
	@./iterative 1000000
	@ echo
	@ echo "recursive:"
	@./pattern 10
	@./recursive 10
	@./pattern 100
	@./recursive 100
	@./pattern 1000
	@./recursive 1000
	@./pattern 10000
	@./recursive 10000
	@./pattern 100000
	@./recursive 100000
	@./pattern 1000000
	@./recursive 1000000
	

clean:
	$(RM) $(EXEC) *.o perf.*
