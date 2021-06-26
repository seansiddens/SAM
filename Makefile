SIMULATE_SOURCES = simulate.c
ASSEMBLE_SOURCES = assemble.c

CC       = clang
CFLAGS   = -Wall -Wpedantic -Wextra -Werror
LFLAGS   = 

.PHONY: all clean

all: simulate assemble

simulate: simulate.o
	$(CC) $(LFLAGS) -o $@ $^

simulate.o: $(SIMULATE_SOURCES)
	$(CC) $(CFLAGS) -c $<

assemble: $(ASSEMBLE_SOURCES)
	$(CC) $(LFLAGS) -o $@ $^

assemble.o: assemble.

clean:
	rm -f simulate assemble *.o

format: 
	clang-format -i *.[ch] -style="{IndentWidth: 4, ColumnLimit: 90}"

