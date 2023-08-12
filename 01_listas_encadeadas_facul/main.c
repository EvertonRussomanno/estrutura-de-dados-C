#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct elem elemento;
struct elem
{
    int dado;
    elemento *prox;
};

//recebe valor e lista
void insere(int x, elemento *p)
{
    elemento *nova;
    nova = (elemento *)malloc(sizeof(elemento));
    nova->dado = x;
    nova->prox = p->prox;
    p->prox = nova;
}
void imprime(elemento *ini)
{
    elemento *p;
    system("clear");
    printf("\nElementos na lista:\n");
    for (p = ini->prox; p != NULL; p = p->prox)
    {
        printf("%d\n", p->dado);
    }
    printf("\n");
}
int main()
{
    setlocale(LC_ALL, "");
    int op = -1, valor;
    elemento *lista = NULL;
    lista = (elemento *)malloc(sizeof(elemento));
    while (op != 0)
    {
        printf("\nOpções do Menu:\n");
        printf("\t1 - mostrar lista.\n");
        printf("\t2 - inserir novo elemento na lista.\n");
        printf("\t0 - sair do programa.\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            printf("\n\nSair do sistema\n");
            break;
        case 1:
            imprime(lista);
            break;
        case 2:
        {
            printf("\nEntre valor a ser inserido na lista: ");
            scanf("%d", &valor);
            insere(valor, lista);
            system("clear");
            break;
        }
        default:
            printf("\n\nOpção invalida !\n");
        }
    }
    return 0;
}