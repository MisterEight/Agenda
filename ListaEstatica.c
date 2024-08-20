#include "ListaEstatica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Função que cria e adiciona um contato na última posição da lista.
int adicionaContato(ListaEstatica* lista){
    //Declaração das variáveis que vão segurar os dados do novo contato.
    char contato_novo_nome[50];
    char contato_novo_email[50];
    char contato_novo_telefone[11];

    limpaTerminal();

    //Essa parte do código pega as informações do novo contato.
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

    //Criamos um novo contato e copiamos as informações das variáveis do novo contato para um contato da lista

    Contato novo_contato;
    
    strncpy(novo_contato.nome, contato_novo_nome, sizeof(novo_contato.nome));

    strncpy(novo_contato.email, contato_novo_email, sizeof(novo_contato.nome));

    strncpy(novo_contato.telefone, contato_novo_telefone, sizeof(novo_contato.nome));

    limpaTerminal();
    printf("Novo contato criado!\n");

    //Colocamos o novo contato dentro da lista.

    lista->contatos[lista->tamanho] = novo_contato;

    printf("Nome do contato: %s", lista->contatos[lista->tamanho].nome);
    printf("Email do contato: %s", lista->contatos[lista->tamanho].email);
    printf("Telefone do contato: %s", lista->contatos[lista->tamanho].telefone);

    //Aumenta o tamanho da lista para que o próximo contato possa entrar na próxima posição
    lista->tamanho += 1;

};

void inserirContato(ListaEstatica* lista) {

    int index;

    Contato contato_temp;

    if (lista->tamanho == 0)
    {
        adicionaContato(lista);
    }

    printf("Onde você quer inserir o contato?");
    scanf("%d", &index);

    for (int i = index; i < lista->tamanho; i++)
    {
        contato_temp = lista->tamanho[i];

    }
}


//Função que remove um contato da lista.
void removeContato(ListaEstatica* lista){
    int id;

    //Caso a lista esteja vazia.
    if (lista->tamanho == 0)
    {
        printf("Não há contato parfa remover!");
        return;
    }

    //Caso só tenha um contato na lista.
    if (lista->tamanho == 1)
    {
        printf("Só há um contato para remover, contato removido!");
        lista->tamanho = 0;
        return;
    }

    printf("Digite o número do contato: ");

    limpaBuffer();

    scanf("%d", &id);

    //Caso o número que o usuário tenha digitado seja maior que o tamanho ou menor que 0(Negativo).
    if (id > lista->tamanho || id < 0)
    {
        printf("Número de contato não existe!");
        return;
    }

    //Caso o id seja igual ao tamanho, quer dizer que é o último elemento e não precisa mover a lista.
    if (id == lista->tamanho)
    {
        printf("Contato removido!");
        lista->tamanho -= 1;
        return;
    }

    //Esse loop, tira o elemento id, coloca o próximo no lugar dele, e faz isso até mover toda a lista.
    for (int i = id-1; i < lista->tamanho; i++)
    {
        lista->contatos[i] = lista->contatos[i+1];
    }
    
    //Diminui o tamanho da lista para o próximo contato. 
    lista->tamanho -= 1;

    printf("Contato removido!");
};

int buscaContato(ListaEstatica* lista){
    //Declaração das variáveis que vão segurar os dados do novo contato.
    int id; 
    char nome_buscar[50];

    //Caso a lista esteja vazia.
    if (lista->tamanho == 0)
    {
        printf("Não há contato para buscar!");
        return;
    }

    printf("Digite o nome do contato: ");

    limpaBuffer();

    fgets(nome_buscar,sizeof(nome_buscar),stdin);

    //Procura por cada contato, comparado seu nome com o nome digitado.
    for (int i = 0; i < lista->tamanho; i++)
    {
        if (strcmp(nome_buscar,lista->contatos[i].nome) == 0)
        {
            printf("\nContato número %d.", i+1);

            printf("\nNome do contato: %s", lista->contatos[i].nome);
            printf("Email do contato: %s", lista->contatos[i].email);
            printf("Telefone do contato: %s", lista->contatos[i].telefone);

            return i;
        }
    }
    return;
};

void listaContato(ListaEstatica* lista){    
    limpaTerminal();

    //Caso a lista esteja vazia.
    if (lista->tamanho == 0)
    {
        printf("Não há contatos para listar!");
    }
    
    //Viaja pela lista mostrando todos os contatos.
    for (int i = 0; i < lista->tamanho; i++)
    {
        
        printf("\nContato número %d.", i+1);

        printf("\nNome do contato: %s", lista->contatos[i].nome);
        printf("Email do contato: %s", lista->contatos[i].email);
        printf("Telefone do contato: %s", lista->contatos[i].telefone);

    }    
};

void limpaBuffer(){
    //Limpa o buffer de teclado.
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF && ch != 0);
}

void limpaTerminal() {
    //Verifica o sistema e usa o comando correto.
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}