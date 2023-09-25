#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

StackNode* createNode(char data);

void push(StackNode** top, char data);

char pop(StackNode** top);



#endif 
