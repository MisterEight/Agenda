#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEstatica.c"

ListaEstatica lista;

int main() {
    int option;

    limpaTerminal();
    criarLista(&lista);
    printf("Bem-vindo a sua agenda!");

    do
    {
        printf("\nSelecione a opção desejada:");
        printf("\n1 - Adicionar contato.");
        printf("\n2 - Inserir contato.");
        printf("\n3 - Remover contato.");
        printf("\n4 - Buscar contato.");
        printf("\n5 - Listar contatos.");
        printf("\n6 - Fechar a agenda.");
        printf("\nOpção desejada: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            limpaTerminal();
            printf("Adicionar contato.\n");
            adicionaContato(&lista);
            break;
        case 2:
            limpaTerminal();
            printf("Inserir contato.\n");
            inserirContato(&lista);
            break;    
        case 3:
            limpaTerminal();
            printf("Remover contato.\n");
            removeContato(&lista);
            break;
        case 4:
            limpaTerminal();
            printf("Buscar contato.\n");
            buscaContato(&lista);
            break;
        case 5:
            limpaTerminal();
            printf("Listar contato.\n");
            listaContato(&lista);
            break;
        case 6:
            limpaTerminal();
            printf("Obrigado por usar agenda!");
            break;
        default:
            limpaTerminal();
            printf("Opção invalida!\n");
            break;
        }
    } while (option != 6);
    
    

    
}