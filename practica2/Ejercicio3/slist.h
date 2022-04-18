
typedef struct _SNodo {
  int dato;
  struct _SNodo *sig;
} SNodo;

typedef struct SList {
  SNodo *primero;
  SNodo *ultimo;
} SList;

SList slist_crear();

SList slist_agregar_inicio(SList list, int dato);

SList slist_agregar_final(SList list, int dato);
