#include "ListaEstatica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Função que cria e adiciona um contato na última posição da lista.
void adicionaContato(ListaEstatica* lista){
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
    
    //Copiando as informações que o usuário digitou para uma nova variável que será adicionada na lista.
    strncpy(novo_contato.nome, contato_novo_nome, sizeof(novo_contato.nome));

    strncpy(novo_contato.email, contato_novo_email, sizeof(novo_contato.nome));

    strncpy(novo_contato.telefone, contato_novo_telefone, sizeof(novo_contato.nome));

    limpaTerminal();
    printf("Novo contato criado!\n");

    //Colocamos o novo contato dentro da lista.

    //acessando essa lista.
    //acessando o tamanho dela.
    //colocando um contato
    lista->contatos[lista->tamanho] = novo_contato;

    printf("Nome do contato: %s", lista->contatos[lista->tamanho].nome);
    printf("Email do contato: %s", lista->contatos[lista->tamanho].email);
    printf("Telefone do contato: %s", lista->contatos[lista->tamanho].telefone);

    //Aumenta o tamanho da lista para que o próximo contato possa entrar na próxima posição
    lista->tamanho += 1;

    ordenarListaContatos(lista);
}

/*void inserirContato(ListaEstatica* lista) {

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
}*/


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
}

int buscaContato(ListaEstatica* lista){
    //Declaração das variáveis que vão segurar os dados do novo contato.
    char nome_buscar[50];
    
    int inicio = 0;

    int fim = lista->tamanho-1;

    //Caso a lista esteja vazia.
    if (lista->tamanho == 0)
    {
        printf("Não há contato para buscar!");
        return -1;
    }

    printf("Digite o nome do contato: ");

    limpaBuffer();

    fgets(nome_buscar,sizeof(nome_buscar),stdin);

    //Procura por cada contato, comparado seu nome com o nome digitado.
    
    for (int i = 0; inicio <= fim; i++)
    {
        int index_meio = inicio + (fim - inicio) / 2;

        if (strcmp(nome_buscar,lista->contatos[index_meio].nome) == 0)
        {
            printf("\nContato número %d.", index_meio+1);

            printf("\nNome do contato: %s", lista->contatos[index_meio].nome);
            printf("Email do contato: %s", lista->contatos[index_meio].email);
            printf("Telefone do contato: %s", lista->contatos[index_meio].telefone);

            return i;
        } 
        else if (strcmp(nome_buscar,lista->contatos[index_meio].nome) == -1)
        {
            fim = index_meio-1;
        } else {
            inicio = index_meio+1;
        }
    }
    printf("Não achamos o contato!");
}
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
}

void ordenarListaContatos(ListaEstatica* lista) {
    //Se tiver apenas um contato, não terá como ordenar a lista
    if (lista->tamanho == 1)
    {
        return;
    }

    //Algoritmo para sortear a lista.
    //Cada letra tem um valor.
    //Um valor pode ser maior ou menor que o próximo e o antepassado
    
    //Organizar a lista de forma alfabetica

    // Beto, Carlos, Arthur = Arthur, Beto, Carlos

    // Atrevessar pela lista
    // 
    // 0 
    qsort(lista->contatos, lista->tamanho, sizeof(Contato), compareContatos);
}

int compareContatos(Contato *contato1,Contato *contato2) {
    return strcmp(contato1->nome, contato2->nome);
}

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