#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct DPessoa
{
    char nome[30];
    int idade;
    char sexo;
} Pessoa;

typedef struct No
{
    Pessoa p;
    struct No *ant, *prox;
} ListaDE;

ListaDE *insere(ListaDE *l)
{
    ListaDE *novo;
    char nome[30], sexo;
    int idade;
    novo = (ListaDE *)malloc(sizeof(ListaDE));
    printf("Nome: ");
    scanf("%s", &novo->p.nome);
    printf("Idade: ");
    scanf("%d", &novo->p.idade);
    printf("Sexo(F ou M): ");
    scanf("%s", &novo->p.sexo);
    novo->prox = l;
    novo->ant = NULL;
    if (l != NULL)
        l->ant = novo;
    l = novo;
    return l;
}

void percorre(ListaDE *l)
{
    if (l == NULL)
    {
        return;
    }
    else
    {
        printf("%s - %d - %c \n", l->p.nome, l->p.idade, l->p.sexo);
        percorre(l->prox);
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int op = -1, valor;
    ListaDE *l;
    l = NULL;
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
        {
            system("clear");
            percorre(l);
            break;
        }
        case 2:
        {
            l = insere(l);
            system("clear");
            break;
        }
        default:
            printf("\n\nOpção invalida !\n");
        }
    }
}