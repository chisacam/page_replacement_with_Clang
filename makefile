CC = gcc
TARGET = page_replacement

$(TARGET): page_replacement.o
	$(CC) -o page_replacement page_replacement.o

page_replacement.o: page_replacement.c
	$(CC) -c -o page_replacement.o page_replacement.c