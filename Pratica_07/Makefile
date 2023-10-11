CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
TARGET = $(BIN)/pa7.out
OBJS = $(OBJ)/main.o $(OBJ)/heap.o 
HDRS =  $(INC)/heap.hpp
CFLAGS = -Wall -pg -g -c -I$(INC)

EXE = $(BIN)/pa7.out

all: $(TARGET)

run:  $(EXE)

$(BIN)/pa7.out: $(OBJS)
	$(CC) -pg -g -o $(BIN)/pa7.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/heap.o: $(HDRS) $(SRC)/heap.c
	$(CC) $(CFLAGS) -o $(OBJ)/heap.o $(SRC)/heap.c

clean:
	rm -f $(EXE) $(OBJS) gmon.out
