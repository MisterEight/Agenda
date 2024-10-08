#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEstatica.c"
#include <math.h>

//Criamos a variável que irá representar a lista.
ListaEstatica lista;

int main() {
    int option;

    limpaTerminal();
    //Inicia nossa lista.
    lista.tamanho = 0;
    printf("Bem-vindo a sua agenda!");

    //Esse loop serve como nosso menu principal, funciona enquanto o usuário não sair.
    do
    {
        printf("\nSelecione a opção desejada:");
        printf("\n1 - Adicionar contato.");
        printf("\n2 - Remover contato.");
        printf("\n3 - Buscar contato.");
        printf("\n4 - Listar contatos.");
        printf("\n5 - Fechar a agenda.");
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
            printf("Remover contato.\n");
            removeContato(&lista);
            break;
        case 3:
            limpaTerminal();
            printf("Buscar contato.\n");
            buscaContato(&lista);
            break;
        case 4:
            limpaTerminal();
            printf("Listar contato.\n");
            listaContato(&lista);
            break;
        case 5:
            limpaTerminal();
            printf("Obrigado por usar agenda!");
            break;
        default:
            limpaTerminal();
            printf("Opção invalida!\n");
            break;
        }
    } while (option != 5);
}