#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
int arvore[21];
int i, j, aux;
int resp = 0, troca, busca;
int menu()
{
    system("clear");
    printf("\n____________________________________________________________\n\n");
    printf("\t\t | -- -- -- -- -- --->MENU < -- -- -- -- -- - |");
    printf("\n\t\t | ______________________________ |\n");
    printf("\t\t | 1 - Inserir numeros |\n");
    printf("\t\t | 2 - Exibir numeros inseridos |\n");
    printf("\t\t | 3 - Exibir arvore binaria |\n");
    printf("\t\t | 4 - Sair |");
    printf("\n\t\t | ______________________________ |\n");
    printf("\t\t\n\t\t\t Digite sua opcao: \a");
    scanf("%d", &resp);
    return resp;
}
void comandos(int resp)
{
    if (resp == 0)
    {
        resp = menu();
    }
    switch (resp)
    {
    // insere numeros
    case 1:
        system("clear");
        printf("\n______________________________________________________\n\n");
        printf(" -- >> Informe os números a serem inseridos na arvore\n\n");
        for (i = 0; i < 15; i++)
        {
            printf("\t\tPosicao %d: ", i + 1);
            scanf("%d", &arvore[i]);
            // arvore[i]=rand()%100;
        }
        printf("\n__________________________________________________________\n\n");
        comandos(0);
        break;
    case 2:
        system("clear");
        printf("\n__________________________________________________\n\n");
        printf(" -- >> Elementos no vetor da arvore !\n\n");
        for (i = 0; i < 15; i++)
        {
            printf("\n\t-- >> POSICAO %d = %d", i, arvore[i]);
        }
        printf("\n______________________________________________________________\n\n");
        //system("pause");
        int yps = 0;
        scanf("%d", &yps);
        comandos(0);
        break;
    case 3:
        system("clear");
        printf("\n___________________________________________________________\n\n");
        printf("\n\n-- >> ARVORE BINARIA !\n\n");
        printf("                                   %d\n", arvore[0]);
        printf("                                  / \\ \n");
        printf("                                 /   \\ \n");
        printf("                                /     \\ \n");
        printf("                               /       \\ \n");
        printf("                              /         \\ \n");
        printf("                             /           \\ \n");
        printf("                            /             \\ \n");
        printf("                           %d               %d \n", arvore[1], arvore[2]);
        printf("                          / \\             / \\ \n");
        printf("                         /   \\           /   \\ \n");
        printf("                        /     \\         /     \\ \n");
        printf("                       %d      %d         %d      %d \n", arvore[3], arvore[4], arvore[5], arvore[6]);
        printf("                      / \\    / \\       / \\    / \\ \n");
        printf("                     %d  %d   %d %d    %d %d  %d %d \n", arvore[7], arvore[8], arvore[9], arvore[10], arvore[11], arvore[12], arvore[13], arvore[14]);
        printf("\n___________________________________________________________\n\n");
        //system("pause");
        int yps2 = 0;
        scanf("%d", &yps2);
        comandos(0);
        break;
    // finaliza
    case 4:
        resp = 0;
        system("clear");
        printf("\n_________________________________________________\n");
        printf(" -- >> Ate Logo !");
        printf("\n______________________________________________________\n\n\n");
    }
}
int main()
{
    for (i = 0; i < 21; i++)
    {
        arvore[i] = i;
    }
    comandos(0);
}