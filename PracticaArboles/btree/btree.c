#include "btree.h"
#include <assert.h>
#include <stdlib.h>

struct _BTNodo {
  int dato;
  struct _BTNodo *left;
  struct _BTNodo *right;
};

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear() { return NULL; }

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo) {
  if (nodo != NULL) {
    btree_destruir(nodo->left);
    btree_destruir(nodo->right);
    free(nodo);
  }
}

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo) { return nodo == NULL; }

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right) {
  BTree nuevoNodo = malloc(sizeof(struct _BTNodo));
  assert(nuevoNodo != NULL);
  nuevoNodo->dato = dato;
  nuevoNodo->left = left;
  nuevoNodo->right = right;
  return nuevoNodo;
}

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden,
                    FuncionVisitante visit) {
  if(arbol)
    switch(orden) {
      case BTREE_RECORRIDO_IN:
        visit(arbol->dato);
        btree_recorrer(arbol->left, orden, visit);
        btree_recorrer(arbol->right, orden, visit);
        break;
      case BTREE_RECORRIDO_PRE:
        btree_recorrer(arbol->left, orden, visit);
        visit(arbol->dato);
        btree_recorrer(arbol->right, orden, visit);
        break;
      case BTREE_RECORRIDO_POST:
        btree_recorrer(arbol->right, orden, visit);
        visit(arbol->dato);
        btree_recorrer(arbol->left, orden, visit);
        break;
    }
}

int btree_nnodos(BTree arbol) {
  if (!arbol)
    return 0;
  else return 1 + btree_nnodos(arbol -> left) + btree_nnodos(arbol -> right);
}

int btree_buscar(BTree arbol, int dato) {
  if(!arbol) {
    return 0;
  } else if (arbol -> dato == dato) {
    return 1;
  } else {
    return btree_buscar(arbol -> left, dato) || btree_buscar(arbol -> right, dato);
  }
}

int max(int a, int b) {
  return a > b ? a : b;
}

int btree_altura(BTree arbol) {
  if(!arbol) return -1;
  else return max(btree_altura(arbol -> left), btree_altura(arbol -> right)) + 1;
}

int btree_nnodos_profundidad(BTree arbol, int profundidad) {
  if(!arbol) return 0;
  else if(profundidad == 0) return 1;
  else return btree_nnodos_profundidad(arbol->left, profundidad-1) +
        btree_nnodos_profundidad(arbol->right, profundidad-1);
}

int btree_profundidad(BTree arbol, int dato) {
  if(arbol) {
    if(arbol->dato == dato) return 0;
    else if(btree_profundidad(arbol -> left, dato) != -1) return 1 + btree_profundidad(arbol -> left, dato);
    else if(btree_profundidad(arbol -> right, dato) != -1) return 1 + btree_profundidad(arbol -> right, dato);
  }
  return -1;
}

int btree_sumar(BTree arbol) {
  if(!arbol) return 0;
  else return (arbol -> dato) + btree_sumar(arbol -> left) + btree_sumar(arbol -> right);
}

void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden,FuncionVisitanteExtra visit, void *extra) {
  if(arbol)
    switch(orden) {
      case BTREE_RECORRIDO_IN:
        visit(arbol->dato, extra);
        btree_recorrer_extra(arbol->left, orden, visit, extra);
        btree_recorrer_extra(arbol->right, orden, visit, extra);
        break;
      case BTREE_RECORRIDO_PRE:
        btree_recorrer_extra(arbol->left, orden, visit, extra);
        visit(arbol->dato, extra);
        btree_recorrer_extra(arbol->right, orden, visit, extra);
        break;
      case BTREE_RECORRIDO_POST:
        btree_recorrer_extra(arbol->right, orden, visit, extra);
        visit(arbol->dato, extra);
        btree_recorrer_extra(arbol->left, orden, visit, extra);
        break;
    }
}

void btree_recorrer_profundidad(BTree arbol, int profundidad, FuncionVisitante visit) {
  if(arbol) {
    if(profundidad == 0) visit(arbol->dato);
    else {
      btree_recorrer_profundidad(arbol -> left, profundidad -1, visit);
      btree_recorrer_profundidad(arbol -> right, profundidad -1, visit);
    }
  }
}

void btree_recorrer_bfs(BTree arbol, FuncionVisitante visit) {
  int profundidad = btree_altura(arbol);
  for(int i = 0; i <= profundidad; i++) btree_recorrer_profundidad(arbol, i, visit);
}
