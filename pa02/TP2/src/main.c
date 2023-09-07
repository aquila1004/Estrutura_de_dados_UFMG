#include "../include/fat.h"
#include "../include/fib.h"
#include "../include/timer.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

// Função para calcular e imprimir os tempos
void calcularTempo(int N, unsigned long long (*funcao)(int), const char* nomeFuncao) {
    double start_time, end_time;
    clock_t inicio, fim;

    // Medir o tempo do sistema 
    start_time = get_system_time();
    unsigned long long resultado = funcao(N);
    end_time = get_system_time();
    double elapsed_time_system = end_time - start_time;

    start_time = get_user_time_seconds();
    resultado = funcao(N);
    end_time = get_user_time_seconds();
    double elapsed_time_user = end_time - start_time;

    // Medir o tempo de relógio
    inicio = clock();
    resultado = funcao(N);
    fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Imprimir os resultados
    printf("\n%s de (%d) = %llu\n", nomeFuncao, N, resultado);
    printf("Tempo do sistema: %.9f seconds\n", elapsed_time_system);
    printf("Tempo de usuário: %.9f seconds\n", elapsed_time_user);
    printf("Tempo de relógio: %f segundos\n", tempo);
}

int main(int argc, char *argv[]) {
    int choice;
    
    // Calcular e exibir todos os resultados possíveis para N=5
     if (argc != 2) {
        fprintf(stderr, "Uso: %s <N>\n", argv[0]);
        return 1;
    }
   int N = atoi(argv[1]);

    printf("---------------------- Fibonacci ----------------------\n");
    calcularTempo(N, fibonacciRecursivo, "Fibonacci Recursivo");
    calcularTempo(N, fibonacciterativo, "Fibonacci Iterativo");
    printf("---------------------- Fatorial ----------------------\n");
    calcularTempo(N, fatorialRecursivo, "Fatorial Recursivo");
    calcularTempo(N, fatorialIterativo, "Fatorial Iterativo");

    do {
        printf("\nEscolha a opção:\n");
        printf("1. Fibonacci\n");
        printf("2. Fatorial\n");
        printf("3. Sair\n");
        scanf("%d", &choice);
        
        if (choice >= 1 && choice <= 2) {
            printf("Digite o valor para o qual deseja calcular (inteiro positivo):\n");
            scanf("%d", &N);

            if (choice == 1) {
                printf("---------------------- Fibonacci ----------------------\n");
                calcularTempo(N, fibonacciRecursivo, "Fibonacci Recursivo");
                calcularTempo(N, fibonacciterativo, "Fibonacci Iterativo");
            } else if (choice == 2) {
                printf("---------------------- Fatorial ----------------------\n");
                calcularTempo(N, fatorialRecursivo, "Fatorial Recursivo");
                calcularTempo(N, fatorialIterativo, "Fatorial Iterativo");
            }
        }
    } while (choice != 3);

    return 0;
}
