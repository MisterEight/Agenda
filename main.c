#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEstatica.c"

ListaEstatica lista;

int main() {
    //Variável para guardar a opção escolhida.
    int option;

    system("cls");
    criarLista(&lista);
    printf("\nBem-vindo a sua agenda!\n");

    //Loop para garantir o funcionamento do programa até a opção de saída é escolhida.
    do
    {
        printf("Selecione a opção desejada:");
        printf("\n1 - Adicionar contato.");
        printf("\n2 - Remover contato.");
        printf("\n3 - Buscar contato.");
        printf("\n4 - Listar contatos.");
        printf("\n5 - Fechar a agenda.");
        printf("\nOpção desejada: ");
        scanf("%d", &option);

        //Lógica para acionar as funções
        switch (option)
        {
        case 1:
            system("cls");
            printf("Adicionar contato.\n");
            adicionaContato(&lista);
            break;
        case 2:
            system("cls");
            printf("Remove contato.\n");
            break;
            //removeContato();
        case 3:
            system("cls");
            printf("Buscar contato.\n");
            break;
            //buscaContato();
        case 4:
            system("cls");
            printf("Listar contato.\n");
            //listaContato();
            break;
        case 5:
            system("cls");
            printf("Obrigado por usar agenda!");
            break;
        default:
            system("cls");
            printf("Opção invalida!\n");
            break;
        }
    } while (option != 5);
    
    

    
}