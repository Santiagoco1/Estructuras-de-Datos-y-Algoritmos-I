#include "gtree.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct _GTNodo {
  void *dato;
  struct _GTNodo hijo;
  struct _GTNodo hno;
};

GTree gtree_crear() { return NULL; }

int gtree_vacio(GTree arbol) { return nodo == NULL; }

void gtree_destruir(GTree arbol, FuncionDestructora destr) {
  if(arbol) {
    gtree_destruir(arbol->hijo);
    gtree_destruir(arbol->hno);
    destr(arbol);
  }
}

GTree gtree_buscar_nodo(GTree arbol, void *datoPadre, FuncionComparadora comp) {
  if(arbol) {
    if(comp(arbol->dato, datoPadre) == 0) return arbol;
    else if(comp(arbol->dato, datoPadre) > 0) gtree_buscar_nodo(arbol->hijo, datoPadre, comp);
    else if(comp(arbol->dato, datoPadre) < 0) gtree_buscar_nodo(arbol->hno, datoPadre, comp);
  }
}

void gtree_agregar_hijo_nodo(GTree padre, void* dato, FuncionCopiadora copiar, FuncionComparadora comp) {
  GTNodo *nodo = padre -> hijo;
  struct _GTNodo nuevo_nodo = malloc(sizeof(struct _GTNodo))
  nuevo_nodo -> dato = copiar(dato)
  if (nodo) {
    for(; comp(arbol -> hno -> dato, dato) < 0 || nodo -> hno == NULL ; nodo = nodo -> hno) {

    }
  } else {
    padre -> hijo
  }
}

GTree gtree_agregar(GTree arbol, void *datoPadre, void *dato, FuncionCopiadora copiar, FuncionComparadora comp) {
  GTree padre = gtree_buscar_nodo(arbol, datoPadre, comp);
  gtree_agregar_hijo_nodo(padre, dato, copiar, comp);
}

void gtree_recorrer_extra(GTree arbol, FuncionVisitanteExtra visit, void *extra) {
  if(arbol) {

  }
}

int gtree_nnodos(GTree arbol) {
  if(!arbol) return 0;
  else 1 + gtree_nnodos(arbol->hijo) + gtree_nnodos(arbol->hno);
}
