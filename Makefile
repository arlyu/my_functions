CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -g
SOURCES = polinomios.c main.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = program

.PHONY: clean

$(TARGET):
	$(CC) $(CFLAGS) $(SOURCES) -c
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

clean:
	$(RM) $(OBJECTS) $(TARGET)

