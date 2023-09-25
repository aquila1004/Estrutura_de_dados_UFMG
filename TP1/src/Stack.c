#include "Stack.h"

// Cria um novo nó da pilha
StackNode* createNode(char data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// Empurra um valor para a pilha
void push(StackNode** top, char data) {
    StackNode* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Pop um valor da pilha
char pop(StackNode** top) {
    if (*top == NULL) {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
    StackNode* temp = *top;
    char data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}