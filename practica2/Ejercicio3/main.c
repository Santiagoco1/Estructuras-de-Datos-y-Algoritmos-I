#include "slist.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  SList lista = slist_crear();

  lista = slist_agregar_inicio(lista, 3);
  lista = slist_agregar_inicio(lista, 2);
  lista = slist_agregar_inicio(lista, 1);

  lista = slist_agregar_final(lista, 4);
  lista = slist_agregar_final(lista, 5);
  lista = slist_agregar_final(lista, 6);

  for(SNodo *nodo = lista.primero; nodo != NULL; nodo = nodo->sig) printf("%d", nodo->dato);

  return 0;
}
