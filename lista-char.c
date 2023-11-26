#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _nodo {
   char texto[100];  // Cambiando el tipo de valor a un array de caracteres para almacenar texto
   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

void Insertar(Lista *l, const char *texto);
void Borrar(Lista *l, const char *texto);
void BorrarLista(Lista *l);
void MostrarLista(Lista l);

int main() {
   Lista lista = NULL;

   Insertar(&lista, "a");
   Insertar(&lista, "b");
   Insertar(&lista, "c");
   Insertar(&lista, "d");
   Insertar(&lista, "e");

   MostrarLista(lista);

   Borrar(&lista, "d");
   Borrar(&lista, "a");

   MostrarLista(lista);

   BorrarLista(&lista);
   return 0;
}

void Insertar(Lista *lista, const char *texto) {
   pNodo nodo;
   nodo = (pNodo)malloc(sizeof(tipoNodo));
   strcpy(nodo->texto, texto);

   if (*lista == NULL) {
      *lista = nodo;
      nodo->siguiente = nodo;  // Update the last node's next to itself
   } else {
      nodo->siguiente = (*lista)->siguiente;
      (*lista)->siguiente = nodo;
   }
   *lista = nodo;  // Update the list pointer to the newly added node
}




void Borrar(Lista *lista, const char *texto) {
   pNodo nodo = *lista;
   do {
      if (strcmp((*lista)->siguiente->texto, texto) != 0)
         *lista = (*lista)->siguiente;
   } while (strcmp((*lista)->siguiente->texto, texto) != 0 && *lista != nodo);

   if (strcmp((*lista)->siguiente->texto, texto) == 0) {
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
      printf("%s -> ", nodo->texto);
      nodo = nodo->siguiente;
   } while (nodo != lista);
   printf("\n");
}
