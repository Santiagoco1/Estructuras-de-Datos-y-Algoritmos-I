#include "dlist.h"
#include "stdio.h"
#include "stdlib.h"

DList crear_dlist(){
  DList lista;
  lista.primero = NULL;
  lista.ultimo = NULL;
  return lista;
}

DList dlist_agregar_inicio(DList lista, int dato) {
  DNodo *nuevo_nodo = malloc(sizeof(DNodo));
  nuevo_nodo->dato = dato;
  nuevo_nodo->ant = NULL;
  if(lista.primero == NULL) {
    nuevo_nodo->sig = NULL;
    lista.primero = nuevo_nodo;
    lista.ultimo = nuevo_nodo;
  } else {
    lista.primero->ant = nuevo_nodo;
    nuevo_nodo->sig = lista.primero;
    lista.primero = nuevo_nodo;
  }
  return lista;
}

DList dlist_agregar_final(DList lista, int dato) {
  DNodo *nuevo_nodo = malloc(sizeof(DNodo));
  nuevo_nodo->dato = dato;
  nuevo_nodo->sig = NULL;
  if(lista.ultimo == NULL) {
    nuevo_nodo->ant = NULL;
    lista.primero = nuevo_nodo;
    lista.ultimo = nuevo_nodo;
  } else {
    lista.ultimo->sig = nuevo_nodo;
    nuevo_nodo->ant = lista.ultimo;
    lista.ultimo = nuevo_nodo;
  }

  return lista;
}

void dlist_recorrer(DList lista, DListOrdenDeRecorrido orden) {
  if(orden == DList_RECORRIDO_HACIA_ADELANTE) {
    for(DNodo *nodo = lista.primero; nodo != NULL; nodo = nodo->sig) printf("%d\n", nodo->dato);
  } else {
    for(DNodo *nodo = lista.ultimo; nodo != NULL; nodo = nodo->ant) {
      printf("%d\n", nodo->dato);
    }
  }
}
