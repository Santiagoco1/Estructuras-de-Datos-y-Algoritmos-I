#include "dlist.h"
#include "stdio.h"
#include "stdlib.h"

int main() {

  DList lista = crear_dlist();

  lista = dlist_agregar_inicio(lista, 3);
  lista = dlist_agregar_inicio(lista, 2);
  lista = dlist_agregar_inicio(lista, 1);

  lista = dlist_agregar_final(lista, 4);
  lista = dlist_agregar_final(lista, 5);
  lista = dlist_agregar_final(lista, 6);

  dlist_recorrer(lista, 0);

  return 0;
}
