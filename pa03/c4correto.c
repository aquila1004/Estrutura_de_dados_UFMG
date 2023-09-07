#include <stdlib.h>

struct Matrix
{
    int rows, cols;
    int **data;
};

int main()
{
    int i, j;
    struct Matrix *rotation3D;

    rotation3D = (struct Matrix *)malloc(sizeof(struct Matrix));
    rotation3D->rows = 4;
    rotation3D->cols = 4;

    // Aloque memória para a matriz de dados
    rotation3D->data = (int **)malloc(sizeof(int *) * rotation3D->rows);
    for (i = 0; i < rotation3D->rows; i++)
    {
        rotation3D->data[i] = (int *)malloc(sizeof(int) * rotation3D->cols);
    }

    // Preencha a matriz de dados com valores (apenas como exemplo)
    for (i = 0; i < rotation3D->rows; i++)
    {
        for (j = 0; j < rotation3D->cols; j++)
        {
            rotation3D->data[i][j] = i * rotation3D->cols + j;
        }
    }

    // Libere a memória alocada para a matriz de dados
    for (i = 0; i < rotation3D->rows; i++)
    {
        free(rotation3D->data[i]);
    }
    free(rotation3D->data);

    // Libere a memória alocada para a struct Matrix
    free(rotation3D);

    return 0;
}
