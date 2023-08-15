#include <stdio.h>
#include <curses.h>
int main()
{
    int X[5], j, i, select, menor, troc;
    // inserindo os números no vetor
    for (i = 0; i <= 4; i++)
    {
        printf("Digite um numero para o índice %d: ", i);
        scanf("%d", &X[i]);
    }
    printf("\n\nVetor antes do metodo SelectionSort\n");
    for (i = 0; i <= 4; i++)
    {
        printf("Vetor %d: %d \n", i, X[i]);
    }
    // ordenando de forma crescente
    for (i = 0; i <= 3; i++)
    {
        select = X[i];
        menor = X[i + 1];
        troc = i + 1;
        for (j = i + 1; j <= 4; j++)
        {
            if (X[j] < menor)
            {
                menor = X[j];
                troc = j;
            }
        }
        if (menor < select)
        {
            X[i] = X[troc];
            X[troc] = select;
        }
    }
    printf("\n\nVetor depois do metodo SelectionSort\n");
    // monstrando o vetor ordenado
    for (i = 0; i <= 4; i++)
    {
        printf("Vetor %d: %d \n", i, X[i]);
    }
}