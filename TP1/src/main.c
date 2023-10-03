#include "../include/Stack.h"
#include "../include/EvaluateExpression.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMBINATIONS 1000                               // Defina um tamanho máximo para o vetor
#define MAX_EXPRESSION_LENGTH 1000                          // Defina um tamanho máximo para as expressões
char combinations[MAX_COMBINATIONS][MAX_EXPRESSION_LENGTH]; // Suponha um tamanho máximo para as expressões
int numCombinations = 0;

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
        addCombination(currentCombination); // Adicione a combinação atual ao vetor
        return;
    }

    if (isalpha(values[index]))
    {
        char original = values[index]; // Salva o caractere original
        currentCombination[index] = '0';
        generateAllCombinations(values, index + 1, currentCombination);

        currentCombination[index] = '1';
        generateAllCombinations(values, index + 1, currentCombination);

        // Restaura o caractere original
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
    else if (strcmp(option, "-p") == 0)
    {
        char currentCombination[MAX_EXPRESSION_LENGTH];          // Declare uma string temporária para armazenar a combinação atual
        memset(currentCombination, '\0', MAX_EXPRESSION_LENGTH); // Inicialize a string com nulos
        // variavle auxilixiar para armazenar expression original
        char expressionOriginal[MAX_EXPRESSION_LENGTH];
        strcpy(expressionOriginal, expression);
        generateAllCombinations(values, 0, currentCombination);

        // Exibir todas as combinações armazenadas
        for (int i = 0; i < numCombinations; i++)
        {
            printf("%s\n", combinations[i]);
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
            // volta a expressoa orginal para a proxima combinação
            printf("combinacao %s\n", combinations[i]);
            printf("expresio pos %s\n", expression);
            
            printf("expresio pos %s\n", expression);
            
            bool result = evaluateExpression(expression, combinations[i]);
            strcpy(expression, expressionOriginal);
            if (result)
            {
                printf("\n1\n");
            }
            else
            {
                printf("\n0\n");
            }
        }
    }
    else
    {
        printf("Opcao invalida!\n");
        return 1;
    }

    return 0;
}
