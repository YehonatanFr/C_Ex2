CC = gcc
Ar = ar
Flags = -Wall -g

all: connections

main.o: main.c my_mat.h
	$(CC) $(Flags) -fPIC -c main.c -lm

my_mat.a: my_mat.o
	$(AR) rcs my_mat.a my_mat.o

my_mat.o: my_mat.c my_mat.h
	$(CC) $(Flags) -fPIC -c my_mat.c -lm

connections: main.o my_mat.a
	$(CC) $(Flags) main.o my_mat.a -lm -o connections

.PHONY: clean all

clean:
	rm -f *.o *.a connections

leakTest: clean connections
	valgrind --leak-check=full  --track-origins=yes --show-leak-kinds=all --error-exitcode=1 ./connections

