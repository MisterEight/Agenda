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
    
    printf("Digite o email do contato: ");

    fgets(contato_novo_email,sizeof(contato_novo_email),stdin);

    printf("Email do contato: %s", contato_novo_email);

    printf("Digite o telefone do contato: ");

    fgets(contato_novo_telefone,sizeof(contato_novo_telefone),stdin);

    printf("Telefone do contato: %s", contato_novo_telefone);

    Contato novo_contato;
    
    strncpy(novo_contato.nome, contato_novo_nome, sizeof(novo_contato.nome));

    strncpy(novo_contato.email, contato_novo_email, sizeof(novo_contato.nome));

    strncpy(novo_contato.telefone, contato_novo_telefone, sizeof(novo_contato.nome));

    limpaTerminal();
    printf("Novo contato criado!\n");

    lista->contatos[lista->tamanho] = novo_contato;

    printf("Nome do contato: %s", lista->contatos[lista->tamanho].nome);
    printf("Email do contato: %s", lista->contatos[lista->tamanho].email);
    printf("Telefone do contato: %s", lista->contatos[lista->tamanho].telefone);

    lista->tamanho += 1;

};

void removeContato(ListaEstatica* lista){
    int id;

    if (lista->tamanho == 0)
    {
        printf("Não há contato para remover!");
        return;
    }

    if (lista->tamanho == 1)
    {
        printf("Só há um contato para remover, contato removido!");
        lista->tamanho = 0;
        return;
    }

    printf("Digite o número do contato: ");

    limpaBuffer();

    scanf("%d", &id);

    if (id > lista->tamanho || id < 0)
    {
        printf("Número de contato não existe!");
        return;
    }

    if (id == lista->tamanho)
    {
        printf("Contato removido!");
        lista->tamanho -= 1;
        return;
    }

    for (int i = id-1; i < lista->tamanho; i++)
    {
        lista->contatos[i] = lista->contatos[i+1];
    }
    
    lista->tamanho -= 1;

    printf("Contato removido!");
};

int buscaContato(ListaEstatica* lista){
    int id;
    char nome_buscar[50];

    if (lista->tamanho == 0)
    {
        printf("Não há contato para buscar!");
        return;
    }

    printf("Digite o nome do contato: ");

    limpaBuffer();

    fgets(nome_buscar,sizeof(nome_buscar),stdin);

    for (int i = 0; i < lista->tamanho; i++)
    {
        if (strcmp(nome_buscar,lista->contatos[i].nome) == 0)
        {
            printf("\nContato número %d.", i+1);

            printf("\nNome do contato: %s", lista->contatos[i].nome);
            printf("Email do contato: %s", lista->contatos[i].email);
            printf("Telefone do contato: %s", lista->contatos[i].telefone);
            
        }
    }
    return;
};

void listaContato(ListaEstatica* lista){
    limpaTerminal();

    if (lista->tamanho == 0)
    {
        printf("Não há contatos para listar!");
    }
    
    for (int i = 0; i < lista->tamanho; i++)
    {
        
        printf("\nContato número %d.", i+1);

        printf("\nNome do contato: %s", lista->contatos[i].nome);
        printf("Email do contato: %s", lista->contatos[i].email);
        printf("Telefone do contato: %s", lista->contatos[i].telefone);

    }    
};

void limpaBuffer(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF && ch != 0);
}

void limpaTerminal() {
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}