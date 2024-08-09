//Verifica se a variável LISTAESTATICA_H, já foi criada para evitar conflitos e reescrever o arquivo.
#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H

//Define o tamanho máximo do array
#define MAX 100

typedef struct {
    char email[50];
    char nome[50];
    char telefone[15];
} Contato;


typedef struct {
    Contato contatos[MAX];
    int tamanho;
} ListaEstatica;

void criarLista(ListaEstatica* lista);
int adicionaContato(ListaEstatica* lista);
void removeContato(ListaEstatica* lista);
int buscaContato(ListaEstatica* lista);
void listaContato(ListaEstatica* lista);
void limpaBuffer();
void limpaTerminal();

#endif
