//Verifica se a variável LISTAESTATICA_H, já foi criada para evitar conflitos e reescrever o arquivo.
#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H

//Struct do contato que será guardado dentro da lista.
typedef struct {
    char email[50];
    char nome[50];
    char telefone[15];
} Contato;

//Cria uma lista de contatos que tem um tamanho.
typedef struct {
    Contato contatos[100];
    int tamanho;
} ListaEstatica;


//Declaração das funções necessárias.
void adicionaContato(ListaEstatica* lista);
int compareContatos(Contato *contato1,Contato *contato2);
void removeContato(ListaEstatica* lista);
int buscaContato(ListaEstatica* lista);
void listaContato(ListaEstatica* lista);
void ordenarListaContatos(ListaEstatica* lista);
void limpaBuffer();
void limpaTerminal();

#endif
