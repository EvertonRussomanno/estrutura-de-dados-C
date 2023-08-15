#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

void quick_sort(int *vet, int total)
{
    int i, j, p, t;
    if (total < 2)
        return;
    p = vet[total / 2];
    for (i = 0, j = total - 1;; i++, j--)
    {
        while (vet[i] < p)
            i++;
        while (p < vet[j])
            j--;
        if (i >= j)
            break;
        t = vet[i];
        vet[i] = vet[j];
        vet[j] = t;
    }
    quick_sort(vet, i);
    quick_sort(vet + i, total - i);
}
int main()
{
    int X[5], i;
    // inserindo os números no vetor
    for (i = 0; i <= 4; i++)
    {
        printf("Digite um numero para o índice %d: ", i);
        scanf("%d", &X[i]);
    }
    printf("\n\nVetor antes do metodo QuickSort\n");
    for (i = 0; i <= 4; i++)
    {
        printf("Vetor %d: %d \n", i, X[i]);
    }
    // ordenação de forma crescente
    quick_sort(X, 5);

    printf("\n\nVetor depois do metodo QuickSort\n");
    // mostrando o vetor ordenado
    for (i = 0; i <= 4; i++)
    {
        printf("Vetor %d: %d \n", i, X[i]);
    }
}