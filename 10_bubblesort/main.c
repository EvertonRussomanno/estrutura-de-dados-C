#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
int main()
{
    int X[5], n, i, aux;
    // inserindo os números no vetor
    for (i = 0; i <= 4; i++)
    {
        printf("Digite um numero para o índice %d: ", i);
        scanf("%d", &X[i]);
    }
    printf("\n\nVetor antes do metodo BubbleSort\n");
    for (i = 0; i <= 4; i++)
    {
        printf("Vetor %d: %d \n", i, X[i]);
    }

    // ordenação de forma crescente
    for (n = 1; n <= 5; n++)
    {
        // Laço que percorre e ordena o vetor
        for (i = 0; i < 4; i++)
        {
            if (X[i] > X[i + 1])
            {
                aux = X[i];
                X[i] = X[i + 1];
                X[i + 1] = aux;
            }
        }
    }
    printf("\n\nVetor depois do metodo BubbleSort\n");
    // mostrando o vetor ordenado
    for (i = 0; i <= 4; i++)
    {
        printf("Vetor %d: %d \n", i, X[i]);
    }
}