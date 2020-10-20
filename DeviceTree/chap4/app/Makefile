
PROGRAM = sample
SRC = hello.c

CC = arm-linux-gnueabihf-gcc
CFLAGS = -Wall -Wextra

.PHONY: all clean

all: $(PROGRAM)

$(PROGRAM): $(SRC)
	$(CC) -o $(PROGRAM) $(CFLAGS) $<

clean:
	rm -f $(PROGRAM) *.o

