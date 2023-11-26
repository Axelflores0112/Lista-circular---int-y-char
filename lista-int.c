#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo {
   int valor;
   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

void Insertar(Lista *l, int v);
void Borrar(Lista *l, int v);
void BorrarLista(Lista *);
void MostrarLista(Lista l);

int main() {
   Lista lista = NULL;
   pNodo p;

   Insertar(&lista, 10);
   Insertar(&lista, 40);
   Insertar(&lista, 30);
   Insertar(&lista, 20);
   Insertar(&lista, 50);

   MostrarLista(lista);

   Borrar(&lista, 30);
   Borrar(&lista, 50);

   MostrarLista(lista);

   BorrarLista(&lista);
   return 0;
}

void Insertar(Lista *lista, int v) {
   pNodo nodo;
   nodo = (pNodo)malloc(sizeof(tipoNodo));
   nodo->valor = v;

   if (*lista == NULL)
      *lista = nodo;
   else
      nodo->siguiente = (*lista)->siguiente;

   (*lista)->siguiente = nodo;
}

void Borrar(Lista *lista, int v) {
   pNodo nodo;
   nodo = *lista;
   do {
      if ((*lista)->siguiente->valor != v)
         *lista = (*lista)->siguiente;
   } while ((*lista)->siguiente->valor != v && *lista != nodo);

   if ((*lista)->siguiente->valor == v) {
      if (*lista == (*lista)->siguiente) {
         free(*lista);
         *lista = NULL;
      } else {
         nodo = (*lista)->siguiente;
         (*lista)->siguiente = nodo->siguiente;
         free(nodo);
      }
   }
}

void BorrarLista(Lista *lista) {
   pNodo nodo;
   while ((*lista)->siguiente != *lista) {
      nodo = (*lista)->siguiente;
      (*lista)->siguiente = nodo->siguiente;
      free(nodo);
   }
   free(*lista);
   *lista = NULL;
}

void MostrarLista(Lista lista) {
   pNodo nodo = lista;
   do {
      printf("%d -> ", nodo->valor);
      nodo = nodo->siguiente;
   } while (nodo != lista);
   printf("\n");
}

