CC=gcc
CFLAGS=-O2 -std=c11 -Wall -Wextra -Werror -pedantic

all: primes-i primes steg-decode xvinar00.zip

primes-i: primes.o bit_array.o eratosthenes.o error.o
	$(CC) $(CFLAGS) -DUSE_INLINE -o primes-i primes.o bit_array.o eratosthenes.o error.o -lm

primes: primes.o bit_array.o eratosthenes.o error.o
	$(CC) $(CFLAGS) -o primes primes.o bit_array.o eratosthenes.o error.o -lm

steg-decode: steg-decode.o bit_array.o eratosthenes.o error.o ppm.o
	$(CC) $(CFLAGS) -o steg-decode steg-decode.o bit_array.o eratosthenes.o error.o ppm.o -lm

primes.o: primes.c
	$(CC) $(CFLAGS) -c primes.c -lm

eratosthenes.o: eratosthenes.c eratosthenes.h
	$(CC) $(CFLAGS) -c eratosthenes.c -lm

bit_array.o: bit_array.c bit_array.h
	$(CC) $(CFLAGS) -c bit_array.c

error.o: error.c error.h
	$(CC) $(CFLAGS) -c error.c

ppm.o: ppm.c ppm.h
	$(CC) $(CFLAGS) -c ppm.c

xvinar00.zip:
	zip xvinar00.zip *.c *.h Makefile

clean:
	rm -f primes-i primes steg-decode xvinar00.zip *.o

run:
	make
	time ./primes-i
	time ./primes
