#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>

typedef void (*FuncionVisitante) (int dato);

typedef struct _SNodo {
  int dato;
  struct _SNodo *sig;
} SNodo;

typedef SNodo *SList;

/**
 * Devuelve una lista vacía.
 */
SList slist_crear();

/**
 * Destruccion de la lista.
 */
void slist_destruir(SList lista);

/**
 * Determina si la lista es vacía.
 */
int slist_vacia(SList lista);

/**
 * Agrega un elemento al final de la lista.
 */
SList slist_agregar_final(SList lista, int dato);

/**
 * Agrega un elemento al inicio de la lista.
 */
SList slist_agregar_inicio(SList lista, int dato);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void slist_recorrer(SList lista, FuncionVisitante visit);

int slist_largo(SList lista);

void slist_concatenar(SList lista1, SList lista2); //Mejorar

void slist_insertar(SList lista, int pos, int dato); //Mejorar

void slist_eliminar(SList lista, int pos); //Mejorar

int slist_contiene(SList lista, int dato);

int slist_indice(SList lista, int dato);

SList slist_intersecar(SList lista1, SList lista2); //Probar

SList slist_intersecar_custom(SList lista1, SList lista2, int cmp()); //Probar

SList slist_ordenar(SList lista, int cmp()); //Hacer

SList slist_reverso(SList lista);

SList slist_intercalar(SList lista1, SList lista2);

SList slist_partir(SList lista);

#endif /* __SLIST_H__ */
