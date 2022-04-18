
typedef struct _DNodo {
  int dato;
  struct _DNodo* sig;
  struct _DNodo* ant;
} DNodo;

typedef struct {
  DNodo* primero;
  DNodo* ultimo;
} DList;

typedef enum {
  DList_RECORRIDO_HACIA_ADELANTE,
  DList_RECORRIDO_HACIA_ATRAS
} DListOrdenDeRecorrido;

DList crear_dlist();

DList dlist_agregar_inicio(DList lista, int dato);

DList dlist_agregar_final(DList lista, int dato);

void dlist_recorrer(DList lista, DListOrdenDeRecorrido orden);
