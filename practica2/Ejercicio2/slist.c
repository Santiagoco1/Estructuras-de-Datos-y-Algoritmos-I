#include "slist.h"
#include <stdlib.h>
#include <stdio.h>

SList slist_crear() {
  return NULL;
}

void slist_destruir(SList lista) {
  SNodo *nodoAEliminar;
  while (lista != NULL) {
    nodoAEliminar = lista;
    lista = lista->sig;
    free(nodoAEliminar);
  }
}

int slist_vacia(SList lista) {
  return lista == NULL;
}

SList slist_agregar_final(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;

  if (lista == NULL)
    return nuevoNodo;

  SList nodo = lista;
  for (;nodo->sig != NULL;nodo = nodo->sig);
  /* ahora 'nodo' apunta al ultimo elemento en la lista */

  nodo->sig = nuevoNodo;
  return lista;
}

SList slist_agregar_inicio(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista;
  return nuevoNodo;
}

void slist_recorrer(SList lista, FuncionVisitante visit) {
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}

int slist_largo(SList lista) {
  int largo = 0;
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig) largo++;
  return largo;
}

void slist_concatenar(SList lista1, SList lista2) {
  if(lista1 == NULL) lista1 = lista2;
  else {
    SNodo *nodo = lista1;
    for(; nodo->sig != NULL; nodo = nodo->sig);
    nodo->sig = lista2;
  }
}

void slist_insertar(SList lista, int pos, int dato) {
  SNodo *nodo = lista;
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;

  if(pos == 0) {
    slist_agregar_inicio(lista, dato);
  }
  else {
    for(int i = 0; i != pos-1; nodo = nodo->sig, i++);
    SNodo *aux = nodo->sig;
    nodo->sig = nuevoNodo;
    nuevoNodo->sig = aux;
  }
}

void slist_eliminar(SList lista, int pos) {
  SNodo *nodo = lista;
  if(pos == 0) {
    SNodo *aux = nodo->sig;
    free(nodo);
    lista = aux;
  }
  else {
    for(; pos != 0; nodo = nodo->sig, pos--);
    SNodo *aux = nodo->sig;
    nodo->sig = aux->sig;
    free(aux);
  }
}

int slist_contiene(SList lista, int dato) {
  for(SNodo *nodo = lista; dato != nodo->dato; nodo = nodo->sig) return 1;
  return 0;
}

int slist_indice(SList lista, int dato) {
  int pos = 0;
  SNodo *nodo = lista;
  for(; nodo != NULL && dato != nodo->dato; nodo = nodo->sig, pos++);
  if(nodo == NULL) return -1;
  else return pos;
}

SList slist_intersecar(SList lista1, SList lista2) {
  SList interseccion = slist_crear();
  for(SNodo *nodo1 = lista1; nodo1 != NULL; nodo1 = nodo1->sig) {
    for(SNodo *nodo2 = lista2; nodo2 != NULL; nodo2 = nodo2->sig){
      if(nodo1->dato == nodo2->dato) interseccion = slist_agregar_inicio(interseccion, nodo1->dato);
    }
  }
  return interseccion;
}

SList slist_intersecar_custom(SList lista1, SList lista2, int cmp()) {
  SList interseccion = slist_crear();
  for(SNodo *nodo1 = lista1; nodo1 != NULL; nodo1 = nodo1->sig) {
    for(SNodo *nodo2 = lista2; nodo2 != NULL; nodo2 = nodo2->sig){
      if(cmp(nodo1->dato == nodo2->dato)) interseccion = slist_agregar_inicio(interseccion, nodo1->dato);
    }
  }
  return interseccion;
}

SList slist_ordenar(SList lista, int cmp()) {
  return lista;
}

SList slist_reverso(SList lista) {
  if(lista == NULL) return lista;
  else return slist_agregar_final(slist_reverso(lista->sig), lista->dato);
}

SList slist_intercalar(SList lista1, SList lista2) {
  SList intercalacion = slist_crear();
  SNodo *nodo1 = lista1;
  SNodo *nodo2 = lista2;
  while(nodo1 != NULL || nodo2 != NULL) {
    if(nodo1 != NULL) {
      intercalacion = slist_agregar_final(intercalacion, nodo1->dato);
      nodo1 = nodo1->sig;
    };
    if(nodo2 != NULL) {
      intercalacion = slist_agregar_final(intercalacion, nodo2->dato);
      nodo2 = nodo2->sig;
    };
  }
  return intercalacion;
}

SList slist_partir(SList lista) {
  int largo = slist_largo(lista), mitad;
  if(largo % 2 == 0) mitad = largo/2;
  else mitad = (largo/2)+1;

  SNodo *nodo = lista;
  for(; mitad != 0; nodo = nodo->sig, mitad--) printf("%d\n", nodo->dato);
  return nodo;
}
