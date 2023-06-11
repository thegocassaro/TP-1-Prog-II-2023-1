all: files.o
	gcc -o trab1 *.o -lm

files.o:
	gcc -c *.c

clean:
	rm -f *.o

valgrind:
	valgrind -s --leak-check=full --track-origins=yes ./trab1 < testes/teste_1/entrada_1