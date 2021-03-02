# compiler setup
CC=gcc
CFLAGS=-Wall -Wextra -std=c99

# define targets
TARGETS=nomogram

build: $(TARGETS)

nomogram: nomogram.c
	$(CC) $(CFLAGS) nomogram.c -o nomogram

clean:
	rm -f $(TARGETS)
