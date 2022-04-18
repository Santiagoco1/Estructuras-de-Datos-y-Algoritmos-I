#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int main(int argc, char *argv[]) {

  SList lista = slist_crear();

  lista = slist_agregar_inicio(lista, 3);
  lista = slist_agregar_inicio(lista, 2);
  lista = slist_agregar_inicio(lista, 1);
  lista = slist_agregar_final(lista, 4);
  lista = slist_agregar_final(lista, 5);

  lista = slist_partir(lista);

  printf("Largo de la lista: %d", slist_largo(lista));
  puts("");

  slist_recorrer(lista, imprimir_entero);
  puts("");

  slist_destruir(lista);

  return 0;
}
