#include "../include/Stack.h"
#include "../include/EvaluateExpression.h"

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
            if (isdigit(expression[i]) && isdigit(expression[i + 1])) {
                int index = (expression[i] - '0') * 10 + (expression[i + 1] - '0');
                expression[i] = values[index];
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
