#include "../include/Stack.h"
#include "../include/EvaluateExpression.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMBINATIONS 1000
#define MAX_EXPRESSION_LENGTH 1000
char combinations[MAX_COMBINATIONS][MAX_EXPRESSION_LENGTH];
int numCombinations = 0;
bool resultados[MAX_COMBINATIONS];                                   
char combinacoesVerdadeiras[MAX_COMBINATIONS][MAX_EXPRESSION_LENGTH]; 
int numCombinationsVerdadeiras = 0;

void addCombination(const char *combination)
{
    if (numCombinations < MAX_COMBINATIONS)
    {
        strcpy(combinations[numCombinations], combination);
        numCombinations++;
    }
    else
    {
        printf("O vetor de combinações está cheio. Aumente MAX_COMBINATIONS se necessário.\n");
        exit(1);
    }
}

void generateAllCombinations(char *values, int index, char *currentCombination)
{
    if (index == strlen(values))
    {
        addCombination(currentCombination);
        return;
    }

    if (isalpha(values[index]))
    {
        char original = values[index];
        currentCombination[index] = '0';
        generateAllCombinations(values, index + 1, currentCombination);

        currentCombination[index] = '1';
        generateAllCombinations(values, index + 1, currentCombination);

        currentCombination[index] = original;
    }
    else
    {
        currentCombination[index] = values[index];
        generateAllCombinations(values, index + 1, currentCombination);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Uso: %s <opcao> <expressao_logica> <valores>\n", argv[0]);
        return 1;
    }

    char *option = argv[1];
    char *expression = argv[2];
    char *values = argv[3];

    if (strcmp(option, "−a") == 0)
    {
        removeSpaces(expression);

        for (int i = 0; expression[i] != '\0'; i++)
        {
            if (isdigit(expression[i]) && isdigit(expression[i + 1]))
            {
                int index = (expression[i] - '0') * 10 + (expression[i + 1] - '0');
                expression[i] = values[index];
                memmove(&expression[i + 1], &expression[i + 2], strlen(&expression[i + 2]) + 1);
            }
            else if (isdigit(expression[i]))
            {
                int index = expression[i] - '0';
                expression[i] = values[index];
            }
        }

        bool result = evaluateExpression(expression, values);

        if (result)
        {
            printf("\n1\n");
        }
        else
        {
            printf("\n0\n");
        }
    }
    else if (strcmp(option, "−s") == 0)
    {
        char currentCombination[MAX_EXPRESSION_LENGTH];
        memset(currentCombination, '\0', MAX_EXPRESSION_LENGTH);

        char expressionOriginal[MAX_EXPRESSION_LENGTH];
        strcpy(expressionOriginal, expression);
        generateAllCombinations(values, 0, currentCombination);

        for (int i = 0; i < numCombinations; i++)
        {
            for (int j = 0; expression[j] != '\0'; j++)
            {
                if (isdigit(expression[j]) && isdigit(expression[j + 1]))
                {
                    int index = (expression[j] - '0') * 10 + (expression[j + 1] - '0');
                    expression[j] = combinations[i][index];
                    memmove(&expression[j + 1], &expression[j + 2], strlen(&expression[j + 2]) + 1);
                }
                else if (isdigit(expression[j]))
                {
                    int index = expression[j] - '0';
                    expression[j] = combinations[i][index];
                }
            }
            bool result = evaluateExpression(expression, combinations[i]);

            resultados[i] = result;
            if (result)
            {
                strcpy(combinacoesVerdadeiras[numCombinationsVerdadeiras], combinations[i]);
                numCombinationsVerdadeiras++;
            }

            strcpy(expression, expressionOriginal);
        }

        bool peloMenosUmVerdadeiro = false;
        for (int i = 0; i < numCombinations; i++)
        {
            if (resultados[i])
            {
                peloMenosUmVerdadeiro = true;
                break;
            }
        }
        if (peloMenosUmVerdadeiro)
        {
            printf("1 ");
            for (int i = 0; i < numCombinationsVerdadeiras; i++)
            {
                printf("%s  ", combinacoesVerdadeiras[i]);
            }
        }
        else
        {
            printf("0\n");
        }
    }
    else
    {
        printf("Opcao invalida!\n");
        return 1;
    }

    return 0;
}