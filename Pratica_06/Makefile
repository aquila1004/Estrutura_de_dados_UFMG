CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
TARGET = $(BIN)/pa6.out
OBJS = $(OBJ)/main.o $(OBJ)/graph.o 
HDRS =  $(INC)/graph.hpp
CFLAGS = -Wall -pg -g -c -I$(INC)

EXE = $(BIN)/pa6.out

all: $(TARGET)

run:  $(EXE)

$(BIN)/pa6.out: $(OBJS)
	$(CC) -pg -g -o $(BIN)/pa6.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/graph.o: $(HDRS) $(SRC)/graph.c
	$(CC) $(CFLAGS) -o $(OBJ)/graph.o $(SRC)/graph.c

clean:
	rm -f $(EXE) $(OBJS) gmon.out
