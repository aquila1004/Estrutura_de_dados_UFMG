CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
TARGET = $(BIN)/pa8.out
OBJS = $(OBJ)/main.o $(OBJ)/unionFind.o 
HDRS =  $(INC)/unionFind.h
CFLAGS = -Wall -pg -g -c -I$(INC)

EXE = $(BIN)/pa8.out

all: $(TARGET)

run:  $(EXE)

$(BIN)/pa8.out: $(OBJS)
	$(CC) -pg -g -o $(BIN)/pa8.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/unionFind.o: $(HDRS) $(SRC)/unionFind.c
	$(CC) $(CFLAGS) -o $(OBJ)/unionFind.o $(SRC)/unionFind.c

clean:
	rm -f $(EXE) $(OBJS) gmon.out

