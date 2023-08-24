#include <stdio.h>
#include <curses.h>

int main()
{
    int X[8], j, i, value, gap = 1, size;
    // inserindo os números no vetor
    for (i = 0; i <= 7; i++)
    {
        printf("Digite um numero para o índice %d: ", i);
        scanf("%d", &X[i]);
    }
    printf("\n\nVetor antes do metodo ShellSort\n");
    for (i = 0; i <= 7; i++)
    {
        printf("Vetor %d: %d\n", i, X[i]);
    }
    // ordenando de forma crescente
    while (gap < 8)
    {
        gap = 3 * gap + 1;
    }
    while (gap > 1)
    {
        gap /= 3;
        for (i = gap; i <= 7; i++)
        {
            value = X[i];
            j = i - gap;
            while (j >= 0 && value < X[j])
            {
                X[j + gap] = X[j];
                j -= gap;
            }
            X[j + gap] = value;
        }
    }
    printf("\n\nVetor depois do metodo ShellSort\n");
    // mostrando o vetor ordenado
    for (i = 0; i <= 7; i++)
    {
        printf("Vetor %d: %d\n", i, X[i]);
    }
}