#ifndef LISTADUPLA_H
#define LISTADUPLA_H

typedef struct No {
    int dado;
    struct No *proximo;
    struct No *anterior;
} No;

typedef struct {
    No *primeiro;
    No *ultimo;
    int tamanho;
} ListaDupla;

// Inicialização e finalização

ListaDupla *criar_ListaDupla();

void liberar_ListaDupla(ListaDupla *lista);

// Gerenciamento de músicas

void adicionar_no(ListaDupla *lista, int dado);

int remover_no(ListaDupla *lista, int dado);

// Navegação

// Visualização

void listar_nos(ListaDupla *lista);

No *buscar_no(ListaDupla *lista, int dado);


#endif