all:
	nasm -f elf64 zad2.asm
	gcc  -c main.c
	gcc  zad2.o main.o -o zad2
