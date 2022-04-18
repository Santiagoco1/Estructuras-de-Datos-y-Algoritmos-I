#include "slist.h"
#include <stdio.h>
#include <stdlib.h>

SList slist_crear() {
  SList lista;
  lista.primero = NULL;
  lista.ultimo = NULL;
  return lista;
}

SList slist_agregar_inicio(SList list, int dato) {
  SNodo *nuevonodo = malloc(sizeof(SNodo));
  nuevonodo->dato = dato;
  if(list.primero == NULL) {
    nuevonodo->sig = NULL;
    list.primero = nuevonodo;
    list.ultimo = nuevonodo;
  } else {
    nuevonodo->sig = list.primero;
    list.primero = nuevonodo;
  }

  return list;
}

SList slist_agregar_final(SList list, int dato) {
  SNodo *nuevonodo = malloc(sizeof(SNodo));
  nuevonodo->dato = dato;
  if(list.ultimo == NULL) {
    nuevonodo->sig = NULL;
    list.primero = nuevonodo;
    list.ultimo = nuevonodo;
  } else {
    (list.ultimo)->sig = nuevonodo;
    list.ultimo = nuevonodo;
  }

  return list;
}
