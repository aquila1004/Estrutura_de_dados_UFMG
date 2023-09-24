#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Estrutura para um nó da pilha
typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

// Protótipos das funções
StackNode* createNode(char data);
void push(StackNode** top, char data);
char pop(StackNode** top);
void removeSpaces(char* str);
bool isOperator(char c);
bool evaluateExpression(const char* expression, const char* values);

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Uso: %s <opcao> <expressao_logica> <valores>\n", argv[0]);
        return 1;
    }

    char* option = argv[1];
    char* expression = argv[2];
    char* values = argv[3];

    if (strcmp(option, "−a") == 0) {
        removeSpaces(expression);

        for (int i = 0; expression[i] != '\0'; i++) {
            // Check if the character is a digit and the next character is also a digit
            if (isdigit(expression[i]) && isdigit(expression[i + 1])) {
                int index = (expression[i] - '0') * 10 + (expression[i + 1] - '0');
                expression[i] = values[index];
                // Shift the rest of the expression to fill the gap
                memmove(&expression[i + 1], &expression[i + 2], strlen(&expression[i + 2]) + 1);
            } else if (isdigit(expression[i])) {
                int index = expression[i] - '0';
                expression[i] = values[index];
            }
        }

        bool result = evaluateExpression(expression, values);

        if (result) {
            printf("\n1\n");
        } else {
            printf("\n0\n");
        }
    } else if (strcmp(option, "-p") == 0) {
        printf("Opção -p selecionada. Imprimindo 'ok'.\n");
    }

    return 0;
}


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

// Remove espaços em branco de uma string
void removeSpaces(char* str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

// Verifica se um caractere é um operador lógico
bool isOperator(char c) {
    return (c == '!' || c == '&' || c == '|');
}

bool evaluateBinary(char op, bool operand1, bool operand2) {
    return (op == '|') ? (operand1 || operand2) : (operand1 && operand2);
}

bool evaluateUnary(char op, bool operand) {
    return (op == '!') ? !operand : false;
}

void evaluateOperator(StackNode** operatorStack, StackNode** operandStack) {
    char op = pop(operatorStack);
    bool result = false;

    if (isOperator(op)) {
        if (op == '!') {
            bool operand = pop(operandStack);
            result = evaluateUnary(op, operand);
        } else {
            bool operand2 = pop(operandStack);
            bool operand1 = pop(operandStack);

            if (op == '|') {
                result = operand1 || operand2;
            } else if (op == '&') {
                result = operand1 && operand2;
            }
        }
    }

    push(operandStack, result);
}


bool evaluateExpression(const char* expression, const char* values) {
    StackNode* operatorStack = NULL;
    StackNode* operandStack = NULL;

    int valIndex = 0;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == ' ') {
            continue;
        } else if (expression[i] == '(') {
            push(&operatorStack, expression[i]);
        } else if (expression[i] == ')') {
            while (operatorStack->data != '(') {
                evaluateOperator(&operatorStack, &operandStack);
            }
            pop(&operatorStack); // Pop the '('
        } else if (expression[i] == '0' || expression[i] == '1') {
            push(&operandStack, expression[i] == '1');
        } else if (isOperator(expression[i])) {
            while (operatorStack != NULL && operatorStack->data != '(' &&
                   isOperator(operatorStack->data) &&
                   (expression[i] <= operatorStack->data)) {
                evaluateOperator(&operatorStack, &operandStack);
            }
            push(&operatorStack, expression[i]);
        } else if (expression[i] == '!') {
            if (expression[i + 1] == '(') {
                // Handle negation of an expression
                push(&operatorStack, expression[i]);
            } else {
                // Handle negation of a single value
                bool valueToNegate = expression[i + 1] == '1';
                push(&operandStack, !valueToNegate);
                i++; // Skip the next character (the value)
            }
        } else if (expression[i] >= 'a' && expression[i] <= 'z') {
            int value = values[valIndex] - '0';
            push(&operandStack, value);
            valIndex++;
        } else {
            printf("Erro: Caractere desconhecido '%c'\n", expression[i]);
            exit(EXIT_FAILURE);
        }
    }

    while (operatorStack != NULL && operatorStack->data != '(') {
        evaluateOperator(&operatorStack, &operandStack);
    }

    return pop(&operandStack);
}
