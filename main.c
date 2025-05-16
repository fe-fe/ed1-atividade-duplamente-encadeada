#include "lista_dupla.h"
#include <stdio.h>


int main() {

    ListaDupla *lista = criar_ListaDupla();
    adicionar_no(lista, 10);
    adicionar_no(lista, 5);
    adicionar_no(lista, 7);
    adicionar_no(lista, 8);
    adicionar_no(lista, 1);

    listar_nos(lista);

    getchar();

    remover_no(lista, 7);

    printf("removeu no com dado 7!\n");

    adicionar_no(lista, 2);

    listar_nos(lista);
    getchar();

    liberar_ListaDupla(lista);

    printf("liberou a lista!\n");
    getchar();
}