#include <stdio.h>
#include "lista_dupla.h"
#include <stdlib.h>
#include <string.h>

ListaDupla *criar_ListaDupla() {
    ListaDupla *lista = (ListaDupla *)malloc(sizeof(ListaDupla));
    if (!lista) return NULL;
    lista->ultimo = NULL;
    lista->primeiro = NULL;
    lista->tamanho = 0;
    return lista;
}


void liberar_ListaDupla(ListaDupla *lista) {
    if (!lista) return;

    No *no = lista->primeiro;

    if (no != NULL) {
        No *inicio = no;
        No *prox;

        do { 
            prox = no->proximo;
            free(no);
            no = prox;
        } while (no != inicio);
    }
    
    free(lista);
}


void adicionar_no(ListaDupla *lista, int dado) {
    
    if (!lista) return;

    No *novo_no = (No*)malloc(sizeof(No));
    if (!novo_no) return;

    novo_no->dado = dado;

    if (lista->primeiro == NULL) {
        novo_no->proximo = novo_no;
        novo_no->anterior = novo_no;
        lista->primeiro = novo_no;
        lista->ultimo = novo_no;
    } else {
        novo_no->anterior = lista->ultimo;
        novo_no->proximo = lista->primeiro;
        lista->ultimo->proximo = novo_no;
        lista->ultimo = novo_no;
    }

    lista->tamanho++;
    
}

int remover_no(ListaDupla *lista, int dado) {
    No *no = buscar_no(lista, dado);
    if (!no) return 0;

    if (lista->tamanho == 1) {
        lista->primeiro = NULL;
        lista->ultimo = NULL;
    } else {
        no->anterior->proximo = no->proximo;
        no->proximo->anterior = no->anterior;

        if (lista->primeiro == no) {
            lista->primeiro = no->proximo;
        }
        if (lista->ultimo == no) {
            lista->ultimo = no->anterior;
        } 
    }

    free(no);
    lista->tamanho--;
    return 1;

}

// retorna o primeiro no que contenha o dado solicitado
No *buscar_no(ListaDupla *lista, int dado) {
    if (!lista || lista->tamanho == 0) return NULL;

    No *no = lista->primeiro;

    // para caso so tenha 1 no na lista
    if (lista->tamanho == 1) {
        if (no->dado == dado) {
            return no;
        } else {
            return NULL;
        }
    }

    do {
        if (no->dado == dado) return no;
        no = no->proximo;
    } while (no != lista->primeiro);

    return NULL;
}


void listar_nos(ListaDupla *lista) {
    if (!lista || lista->tamanho == 0) return;

    No *no = lista->primeiro;
    int i = 1;
    do {
        printf("[no %d] dado: %d\n", i, no->dado);
        no = no->proximo;
        i++;
    } while (no != lista->primeiro);
}