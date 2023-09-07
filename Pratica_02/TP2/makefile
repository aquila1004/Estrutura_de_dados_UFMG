CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/fib.o $(OBJ)/fat.o $(OBJ)/timer.o
HDRS = $(INC)/fat.h $(INC)/fib.h $(INC)/timer.h
CFLAGS = -Wall -pg -c -I$(INC)

EXE = $(BIN)/main
N = 5 

run: $(EXE)
	./$(EXE) $(N)

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c 

$(OBJ)/fat.o: $(HDRS) $(SRC)/fat.c
	$(CC) $(CFLAGS) -o $(OBJ)/fat.o $(SRC)/fat.c 
	
$(OBJ)/fib.o: $(HDRS) $(SRC)/fib.c
	$(CC) $(CFLAGS) -o $(OBJ)/fib.o $(SRC)/fib.c 

$(OBJ)/timer.o: $(HDRS) $(SRC)/timer.c
	$(CC) $(CFLAGS) -o $(OBJ)/timer.o $(SRC)/timer.c 

clean:
	rm -f $(EXE) $(OBJS) gmon.out
