all: files.o
	gcc -o trab1 *.o -lm

files.o:
	gcc -c *.c

clean:
	rm -f *.o

input1:
	./trab1 < inputs/input1

input2:
	./trab1 < inputs/input2

input3:
	./trab1 < inputs/input3

input4:
	./trab1 < inputs/input4

valgrind:
	valgrind ./trab1 < inputs/input1