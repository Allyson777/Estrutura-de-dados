all: teste
teste: arvore.o main.o
	gcc -o teste arvore.o main.o
arvore.o: arvore.c arvore.h
	gcc -c arvore.c
main.o: main.c arvore.c
	gcc -c main.c