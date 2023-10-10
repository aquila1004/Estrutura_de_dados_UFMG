#include "../include/EvaluateExpression.h"
#include "../include/Stack.h"

void removeSpaces(char *str)
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
        {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

bool isOperator(char c)
{
    return (c == '~' || c == '&' || c == '|');
}

bool evaluateBinary(char op, bool operand1, bool operand2)
{
    return (op == '|') ? (operand1 || operand2) : (operand1 && operand2);
}

bool evaluateUnary(char op, bool operand)
{
    return (op == '~') ? !operand : false;
}

void evaluateOperator(StackNode **operatorStack, StackNode **operandStack)
{
    char op = pop(operatorStack);
    bool result = false;

    if (isOperator(op))
    {
        if (op == '~')
        {
            bool operand = pop(operandStack);
            result = evaluateUnary(op, operand);
        }
        else
        {
            bool operand2 = pop(operandStack);
            bool operand1 = pop(operandStack);

            if (op == '|')
            {
                result = operand1 || operand2;
            }
            else if (op == '&')
            {
                result = operand1 && operand2;
            }
        }
    }

    push(operandStack, result);
}

int getPrecedence(char op)
{
    if (op == '|')
        return 1;
    if (op == '&')
        return 2;
    if (op == '~')
        return 3;
    return 0;
}

bool operatorStackIsEmpty(StackNode *top)
{
    return top == NULL;
}

bool evaluateExpression(const char *expression, const char *values)
{
    StackNode *operatorStack = NULL;
    StackNode *operandStack = NULL;

    int valIndex = 0;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == ' ')
        {
            continue;
        }
        else if (expression[i] == '(')
        {
            push(&operatorStack, expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (operatorStack->data != '(')
            {
                evaluateOperator(&operatorStack, &operandStack);
            }
            pop(&operatorStack);
        }
        else if (expression[i] == '0' || expression[i] == '1')
        {
            push(&operandStack, expression[i] == '1');
        }
        else if (expression[i] == '~')
        {
            if (expression[i + 1] == '(')
            {
                push(&operatorStack, expression[i]);
                continue;
            }
            int negationCount = 0;
            while (expression[i] == '~')
            {
                negationCount++;
                i++;
            }

            if (negationCount % 2 == 0)
            {
                
                push(&operandStack, true);
            }
            else
            {
                
                push(&operandStack, false);
            }
        }
        else if (isOperator(expression[i]))
        {
            while (!operatorStackIsEmpty(operatorStack) &&
                   operatorStack->data != '(' &&
                   getPrecedence(expression[i]) <= getPrecedence(operatorStack->data))
            {
                evaluateOperator(&operatorStack, &operandStack);
            }
            push(&operatorStack, expression[i]); 
        }
        
        else if (expression[i] >= 'a' && expression[i] <= 'z')
        {
            int value = values[valIndex] - '0';
            push(&operandStack, value);
            valIndex++;
        }
        else
        {
            printf("Erro: Caractere desconhecido '%c'\n", expression[i]);
            exit(EXIT_FAILURE);
        }
    }

    while (operatorStack != NULL && operatorStack->data != '(')
    {
        evaluateOperator(&operatorStack, &operandStack);
    }

    return pop(&operandStack);
}