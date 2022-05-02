#include "bstree.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Estructura del nodo del arbol de busqueda binaria.
 * Tiene un puntero al dato (dato),
 * un puntero al nodo raiz del subarbol izquierdo (izq),
 * y un puntero al nodo raiz del subarbol derecho (der).
 */
struct _BST_Nodo {
  void *dato;
  struct _BST_Nodo *izq, *der;
};

/**
 * bstee_crear: Retorna un arbol de busqueda binaria vacio
 */
BSTree bstee_crear() { return NULL; }

/**
 * bstree_destruir: Destruye el arbol y sus datos
 */
void bstree_destruir(BSTree raiz, FuncionDestructora destr) {
  if (raiz != NULL) {
    bstree_destruir(raiz->izq, destr);
    bstree_destruir(raiz->der, destr);
    destr(raiz->dato);
    free(raiz);
  }
};

/**
 * bstree_buscar: Retorna 1 si el dato se encuentra y 0 en caso
 * contrario
 */
int bstree_buscar(BSTree raiz, void *dato, FuncionComparadora comp) {
  if (raiz == NULL)
    return 0;
  else if (comp(dato, raiz->dato) == 0) // raiz->dato == dato
    return 1;
  else if (comp(dato, raiz->dato) < 0) // dato < raiz->dato
    return bstree_buscar(raiz->izq, dato, comp);
  else // raiz->dato < dato
    return bstree_buscar(raiz->der, dato, comp);
}

/**
 * bstree_insertar: Inserta un dato no repetido en el arbol, manteniendo la
 * propiedad del arbol de busqueda binaria
 */
BSTree bstree_insertar(BSTree raiz, void *dato, FuncionCopiadora copia,
                       FuncionComparadora comp) {
  if (raiz == NULL) { // insertar el dato en un nuevo nodo
    struct _BST_Nodo *nuevoNodo = malloc(sizeof(struct _BST_Nodo));
    assert(nuevoNodo != NULL);
    nuevoNodo->dato = copia(dato);
    nuevoNodo->izq = nuevoNodo->der = NULL;
    return nuevoNodo;
  } else if (comp(dato, raiz->dato) < 0) // dato < raiz->dato
    raiz->izq = bstree_insertar(raiz->izq, dato, copia, comp);
  else if (comp(dato, raiz->dato) > 0) // raiz->dato < dato
    raiz->der = bstree_insertar(raiz->der, dato, copia, comp);
  // si el dato ya se encontraba, no es insertado
  return raiz;
}

/**
 * bstree_recorrer: Recorrido DSF del arbol
 */
void bstree_recorrer(BSTree raiz, BSTreeRecorrido orden,
                     FuncionVisitanteExtra visita, void *extra) {
  if (raiz != NULL) {

    if (orden == BTREE_RECORRIDO_PRE)
      visita(raiz->dato, extra);

    bstree_recorrer(raiz->izq, orden, visita, extra);

    if (orden == BTREE_RECORRIDO_IN)
      visita(raiz->dato, extra);

    bstree_recorrer(raiz->der, orden, visita, extra);

    if (orden == BTREE_RECORRIDO_POST)
      visita(raiz->dato, extra);

  }
}

BSTree buscar_hoja_mas_grande(BSTree arbol) {
  if(arbol->der->der == NULL) return arbol;
  else return buscar_hoja_mas_grande(arbol->der);
}

BSTree remover_hoja_mas_grande(BSTree arbol, BSTree* hoja_mas_grande)
{
  if (arbol->der) {
    arbol->der = remover_hoja_mas_grande(arbol->der, hoja_mas_grande);
    return arbol;
  } else {
    *hoja_mas_grande = arbol;
    return arbol->izq;
  }
}

BSTree bstree_eliminar(BSTree arbol, void *dato, FuncionComparadora comp, FuncionDestructora destr) {
  if(!arbol) return NULL;
  else if(comp(arbol->dato, dato) == 0) {
    BSTree nuevo_arbol;
    if(arbol->izq == NULL) {
      nuevo_arbol = arbol->der;
    } else if(arbol->der == NULL) {
      nuevo_arbol = arbol->izq;
    } else {
      BSTree nueva_izq = remover_hoja_mas_grande(arbol->izq, &nuevo_arbol);
      nuevo_arbol->izq = nueva_izq;
      nuevo_arbol->der = arbol->der;
    }
    destr(arbol->dato);
    free(arbol);
    return nuevo_arbol;
  }
  else {
    if(comp(arbol->dato, dato) < 0)
      arbol->der = bstree_eliminar(arbol->der, dato, comp, destr);
    else
      arbol->izq = bstree_eliminar(arbol->izq, dato, comp, destr);

    return arbol;
  }
}

BSTree bstree_kesimo_menor(BSTree arbol, int k) {
  if(!arbol) return NULL;
  else if(k==0) return arbol;
  else if(bstree_kesimo_menor(arbol->izq, k-1)) return bstree_kesimo_menor(arbol->izq, k-1);
  else return bstree_kesimo_menor(arbol->der, k-1);
}
