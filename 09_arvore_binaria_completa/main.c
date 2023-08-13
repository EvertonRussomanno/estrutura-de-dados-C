#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura do nó
typedef struct str_no
{
    char dado;
    int FilhoEsq;
    int FilhoDir;
    int pai;
} str_no;
// Constantes
#define tamanho 100
#define E 0
#define D 1
#define R -1
// Variáveis
struct str_no arvore[tamanho];
int lado, indice = 0;
int opt = -1;
char pai, no;
// Protítipos das funções
void InserirElemento(int pai, char dado, int lado);
int ProcurarElemento(char dado);
void menu_mostrar(void);
// Procura nó
int ProcurarElemento(char dado)
{
    int i;
    if (indice != 0)
    {
        for (i = 0; i < indice; i++)
        {
            if (arvore[i].dado == dado)
            {
                return (i);
            }
        }
    }
    else
    {
        return (0);
    }
}
// Inserir nó
void InserirElemento(int pai, char dado, int lado)
{
    switch (lado)
    {
    case E:
        arvore[pai].FilhoEsq = indice;
        arvore[indice].dado = dado;
        arvore[indice].pai = pai;
        arvore[indice].FilhoEsq = -1;
        arvore[indice].FilhoDir = -1;
        indice++;
        break;
    case D:
        arvore[pai].FilhoDir = indice;
        arvore[indice].dado = dado;
        arvore[indice].pai = pai;
        arvore[indice].FilhoEsq = -1;
        arvore[indice].FilhoDir = -1;
        indice++;
        break;
    case R:
        arvore[indice].dado = dado;
        arvore[indice].pai = -1;
        arvore[indice].FilhoEsq = -1;
        arvore[indice].FilhoDir = -1;
        indice++;
        break;
    }
}
// Função principal
int main(void)
{
    setlocale(LC_ALL, "");
    // ajuste do idioma
    int temp;
    do
    {
        menu_mostrar();
        scanf("%d", &opt);
        fflush(stdin);
        switch (opt)
        {
        case 1:
            printf("\nInforme qual é o Elemento PAI (deixar em Branco caso for a Raiz): ");
            scanf("%s", &pai);
            fflush(stdin);
            // scanf("%c",&pai);
            printf("Digite o elmento do NO: ");
            scanf("%s", &no);
            fflush(stdin);
            // scanf("%c",&no);
            printf("Digite o lado da subarvore \n Filho a Esquerda = %d \n Filho a Direita = %d \n Nó Raiz = %d: ", E, D, R);
            scanf("%d", &lado);
            fflush(stdin);
            temp = ProcurarElemento(pai);
            InserirElemento(temp, no, lado);
            break;
        case 2:
            printf("Digite o Elemento a ser pesquisado: ");
            scanf("%s", &no);
            fflush(stdin);
            // scanf("%c",&no);
            temp = ProcurarElemento(no);
            printf("No %c\nFilho Esquerda: %c \nFilho Direita: %c\n\n", arvore[temp].dado, arvore[arvore[temp].FilhoEsq].dado, arvore[arvore[temp].FilhoDir].dado);
            printf("Pressione qualquer letra para voltar ao menu...");
            char lixo;
            scanf("%s", &lixo);
            break;
        }
    } while (opt != 0);
    return (0);
}
// Desenha o menu na tela
void menu_mostrar(void)
{
    int i;
    system("clear");
    for (i = 0; i <= indice; i++)
    {
        printf("| %c ", arvore[i].dado);
    }
    printf("\n1 - Inserir um Elemento na arvore(A - Z)");
    printf("\n2 - Pesquisar um Elemento na arvore(A - Z)");
    printf("\n0 - Sair do Programa\n\n");
}