#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
typedef struct LISTA
{
    int dado;
    struct LISTA *prox;
} lista;
lista *inserirElemento(lista *p, int valor)
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->dado = valor;
    novo->prox = p;
    return novo;
}
void mostrarLista(lista *p)
{
    lista *novo;
    for (novo = p; novo != NULL; novo = novo->prox)
    {
        printf("%d - ", novo->dado);
    }
}
lista *ordenarLista(lista *p)
{
    lista *aux = p;
    lista *t;
    int c;
    if (p == NULL || p->prox == NULL)
        return NULL;
    while (aux != NULL)
    {
        t = aux->prox;
        while (t != NULL)
        {
            if (aux->dado > t->dado)
            {
                c = aux->dado;
                aux->dado = t->dado;
                t->dado = c;
            }
            t = t->prox;
        }
        aux = aux->prox;
    }
    return p;
}
main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    int op = -1, valor;
    lista *l, i;
    lista *primeiro, *ultimo;
    l = NULL;
    while (op != 0)
    {
        printf("\nOpções do Menu:\n");
        printf("\t1 - Inserir novo elemento na lista.\n");
        printf("\t2 - Mostrar lista.\n");
        printf("\t3 - Ordenar lista.\n");
        printf("\t0 - Sair do programa.\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            printf("\n\nSair do sistema\n");
            break;
        case 1:
        {
            printf("\nInforme uma valor a ser inserido na lista: ");
            scanf("%d", &valor);
            l = inserirElemento(l, valor);
            system("clear");
            break;
        }
        case 2:
        {
            system("clear");
            mostrarLista(l);
            break;
        }
        case 3:
        {
            system("clear");
            l = ordenarLista(l);
            mostrarLista(l);
            break;
        }
        default:
            printf("\n\nOpção invalida !\n");
        }
    }
}