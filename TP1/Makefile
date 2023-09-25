CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
TARGET = $(BIN)/main
OBJS = $(OBJ)/main.o $(OBJ)/EvaluateExpression.o $(OBJ)/Stack.o 
HDRS = $(INC)/EvaluateExpression.h $(INC)/Stack.h
CFLAGS = -Wall -pg -g -c -I$(INC)

EXE = $(BIN)/main

all: $(TARGET)

run:  $(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -g -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/EvaluateExpression.o: $(HDRS) $(SRC)/EvaluateExpression.c
	$(CC) $(CFLAGS) -o $(OBJ)/EvaluateExpression.o $(SRC)/EvaluateExpression.c

$(OBJ)/Stack.o: $(HDRS) $(SRC)/Stack.c
	$(CC) $(CFLAGS) -o $(OBJ)/Stack.o $(SRC)/Stack.c


clean:
	rm -f $(EXE) $(OBJS) gmon.out