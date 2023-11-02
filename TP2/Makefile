CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
TARGET = $(BIN)/tp2.out
OBJS = $(OBJ)/main.o $(OBJ)/graph.o $(OBJ)/sort.o $(OBJ)/operator.o
HDRS =  $(INC)/graph.hpp $(INC)/sort.hpp $(INC)/operator.hpp
CFLAGS = -Wall -pg -g -c -I$(INC)

EXE = $(BIN)/tp2.out

all: $(TARGET)

run:  $(EXE)

$(BIN)/tp2.out: $(OBJS)
	$(CC) -pg -g -o $(BIN)/tp2.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/graph.o: $(HDRS) $(SRC)/graph.c
	$(CC) $(CFLAGS) -o $(OBJ)/graph.o $(SRC)/graph.c

$(OBJ)/sort.o: $(HDRS) $(SRC)/sort.c
	$(CC) $(CFLAGS) -o $(OBJ)/sort.o $(SRC)/sort.c

$(OBJ)/operator.o: $(HDRS) $(SRC)/operator.c
	$(CC) $(CFLAGS) -o $(OBJ)/operator.o $(SRC)/operator.c
clean:
	rm -f $(EXE) $(OBJS) gmon.out
