#include "../include/Stack.h"
#include "../include/EvaluateExpression.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMBINATIONS 1000
#define MAX_EXPRESSION_LENGTH 1000

char combinations[MAX_COMBINATIONS][MAX_EXPRESSION_LENGTH];
bool resultados[MAX_COMBINATIONS];
char combinacoesVerdadeiras[MAX_COMBINATIONS][MAX_EXPRESSION_LENGTH];

int numCombinations = 0;
int numCombinationsVerdadeiras = 0;

void addCombination(const char *combination) {
    if (numCombinations < MAX_COMBINATIONS) {
        strcpy(combinations[numCombinations], combination);
        numCombinations++;
    } else {
        printf("O vetor de combinações está cheio. Aumente MAX_COMBINATIONS se necessário.\n");
        exit(1);
    }
}

void generateAllCombinations(char *values, int index, char *currentCombination) {
    if (index == strlen(values)) {
        addCombination(currentCombination);
        return;
    }

    if (isalpha(values[index])) {
        char original = values[index];
        currentCombination[index] = '0';
        generateAllCombinations(values, index + 1, currentCombination);

        currentCombination[index] = '1';
        generateAllCombinations(values, index + 1, currentCombination);

        currentCombination[index] = original;
    } else {
        currentCombination[index] = values[index];
        generateAllCombinations(values, index + 1, currentCombination);
    }
}

void substituteValues(char *expression, const char *values) {
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i]) && isdigit(expression[i + 1])) {
            int index = (expression[i] - '0') * 10 + (expression[i + 1] - '0');
            expression[i] = values[index];
            memmove(&expression[i + 1], &expression[i + 2], strlen(&expression[i + 2]) + 1);
        } else if (isdigit(expression[i])) {
            int index = expression[i] - '0';
            expression[i] = values[index];
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Uso: %s <opcao> <expressao_logica> <valores>\n", argv[0]);
        return 1;
    }

    char *option = argv[1];
    char *expression = argv[2];
    char *values = argv[3];

    if (strcmp(option, "−a") == 0) {
        removeSpaces(expression);
        substituteValues(expression, values);
        bool result = evaluateExpression(expression, values);
        printf("%d\n", result ? 1 : 0);
    } else if (strcmp(option, "−s") == 0) {
        char currentCombination[MAX_EXPRESSION_LENGTH];
        memset(currentCombination, '\0', MAX_EXPRESSION_LENGTH);

        char expressionOriginal[MAX_EXPRESSION_LENGTH];
        strcpy(expressionOriginal, expression);
        generateAllCombinations(values, 0, currentCombination);

        bool allCombinationsTrue = true;
        bool atLeastOneTrue = false;

        for (int i = 0; i < numCombinations; i++) {
            substituteValues(expression, combinations[i]);
            bool result = evaluateExpression(expression, combinations[i]);
            resultados[i] = result;

            if (result) {
                strcpy(combinacoesVerdadeiras[numCombinationsVerdadeiras], combinations[i]);
                numCombinationsVerdadeiras++;
                atLeastOneTrue = true;
            }

            strcpy(expression, expressionOriginal);

            if (!result) {
                allCombinationsTrue = false;
            }
        }

        if (allCombinationsTrue) {
            for (int i = 0; values[i] != '\0'; i++) {
                if (values[i] == 'e') {
                    values[i] = 'a';
                }
            }

            printf("1 %s\n", values);
        } else if (atLeastOneTrue) {
            printf("1 ");
            for (int i = 0; i < numCombinationsVerdadeiras; i++) {
                printf("%s  ", combinacoesVerdadeiras[i]);
            }
            printf("\n");
        } else {
            printf("0\n");
        }
    } else {
        printf("Opcao invalida!\n");
        return 1;
    }

    return 0;
}
