#include <stdio.h>
#include <curses.h>
void intercala(int X[], int inicio, int fim, int meio)
{
    int posLivre, inicio_vetor1, inicio_vetor2, i;
    int aux[10];
    inicio_vetor1 = inicio;
    inicio_vetor2 = meio + 1;
    posLivre = inicio;
    while (inicio_vetor1 <= meio && inicio_vetor2 <= fim)
    {
        if (X[inicio_vetor1] <= X[inicio_vetor2])
        {
            aux[posLivre] = X[inicio_vetor1];
            inicio_vetor1++;
        }
        else
        {
            aux[posLivre] = X[inicio_vetor2];
            inicio_vetor2++;
        }
        posLivre++;
    }
    // se ainda existem numeros no primeiro vetor
    // que nao foram intercalados
    for (int i = inicio_vetor1; i <= meio; ++i)
    {
        aux[posLivre] = X[i];
        posLivre++;
    }
    // se ainda existem numeros no segundo vetor
    // que nao foram intercalados
    for (int i = inicio_vetor2; i <= fim; ++i)
    {
        aux[posLivre] = X[i];
        posLivre++;
    }
    // retorne os valores do vetor aux para o vetor X
    for (int i = inicio; i <= fim; ++i)
    {
        X[i] = aux[i];
    }
}
void merge(int X[], int inicio, int fim)
{
    int meio;
    if (inicio < fim)
    {
        meio = (inicio + fim) / 2;
        merge(X, inicio, meio);
        merge(X, meio + 1, fim);
        intercala(X, inicio, fim, meio);
    }
}
int main()
{
    int X[8], i;
    for (i = 0; i <= 7; i++)
    {
        printf("Digite um numero para o índice %d: ", i);
        scanf("%d", &X[i]);
    }
    printf("\n\nVetor antes do metodo MergeSort\n");
    for (i = 0; i <= 7; i++)
    {
        printf("Vetor %d: %d\n", i, X[i]);
    }
    // ordenando de forma crescente
    merge(X, 0, 7);
    printf("\n\nVetor depois do metodo MergeSort\n");
    // mostrando o vetor ordenado
    for (i = 0; i <= 7; i++)
    {
        printf("Vetor %d: %d\n", i, X[i]);
    }
}