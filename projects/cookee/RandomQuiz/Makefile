CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme: testme.o
	gcc -o testme testme.c -g $(CFLAGS)
	./testme

testme.o: testme.c
	gcc -c testme.c -g $(CFLAGS)

all: testme

clean:
	rm -f testme *.o *.gcno *.gcov *.gcda