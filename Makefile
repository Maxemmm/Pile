OBJ = main.o piles.o
SRC = main.c piles.c
HDR = piles.h

OUT = pile
CC = gcc
FLAGS = -g -c -Wall
LFLAGS = 

all: $(OBJ)
	$(CC) -g $(OBJ) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c

piles.o: piles.c
	$(CC) $(FLAGS) piles.c

clean:
	rm -f $(OUT)

mproper:
	rm -f ^$(OBJ) $(OUT)
