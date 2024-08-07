#include "ListaEstatica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criarLista(ListaEstatica* lista) {
    lista->tamanho = 0;
};

int adicionaContato(ListaEstatica* lista){
    char contato_novo_nome[50];
    char contato_novo_email[50];
    char contato_novo_telefone[11];

    limpaTerminal();

    printf("Digite o nome do contato: ");

    limpaBuffer();
    
    fgets(contato_novo_nome,sizeof(contato_novo_nome),stdin);

    printf("Nome do contato: %s", contato_novo_nome);

    limpaBuffer();

    printf("Digite o email do contato: ");

    fgets(contato_novo_email,sizeof(contato_novo_email),stdin);

    printf("Email do contato: %s", contato_novo_email);

    limpaBuffer();

    printf("Digite o telefone do contato: ");

    fgets(contato_novo_telefone,sizeof(contato_novo_telefone),stdin);

    printf("Email do contato: %s", contato_novo_telefone);

    Contato novo_contato = {
        .nome = contato_novo_nome,
        .email = contato_novo_email,
        .telefone = contato_novo_telefone
    };

    printf("Novo contato criado!");
};

int removeContato(ListaEstatica* lista, int id){
    printf("Teste");
};

Contato* buscaContato(ListaEstatica* lista, int id){
    printf("Teste");
};

void listaContato(ListaEstatica* lista){
    printf("Teste");
};

void limpaBuffer(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
};

void limpaTerminal() {
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}