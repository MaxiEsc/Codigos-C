// Archivo pila_int.h

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_s
{
	int dato;
	struct nodo_s *siguiente;
} nodo_t;

typedef nodo_t *ptrNodo;
typedef nodo_t *ptrPila;

/*
Agrega un nodo al inicio de la lista ligada
*pila es el apuntador que apunta al primer nodo de la lista ligada (la cima de la pila)
*/
void push(ptrPila *pila, int x)
{
	// Crea un nuevo nodo
	ptrNodo nodo;
	nodo = (ptrNodo)malloc(sizeof(nodo_t));
	if (nodo != NULL)
	{
		nodo->dato = x;
		// El apuntador nodo->siguiente va a apuntar al primer nodo de la lista ligada
		nodo->siguiente = *pila;
		// pila va a apuntar al nuevo nodo, con esto hacemos que el nuevo nodo sea ahora el primer nodo de la lista ligada
		*pila=nodo;
	}
}

/*
Elimina el primer nodo de la lista ligada
*pila es el apuntador que apunta al primer nodo de la lista ligada (la cima de la pila)
*/
int pop(ptrPila *pila)
{
	// Crea un nuevo nodo
	ptrNodo nodo;
	int x=0;
	
	// El nuevo nodo va a apuntar al primer nodo de la lista ligada
	nodo = *pila;
	x = (*pila)->dato;
	// Ahora el segundo nodo de la lista ligada va a ser el primero
	*pila = (*pila)->siguiente;
	// Borra el primer nodo de la lista ligada
	free(nodo);
	// Regresa el valor que contenía el nodo que se eliminó
	return x;
}

/*
Regresa 1 si no hay nodos en la lista ligada y cero en caso contrario
*pila es el apuntador que apunta al primer nodo de la lista ligada (la cima de la pila)
*/
int pila_vacia(ptrPila *pila)
{
	return (*pila == NULL ? 1:0);
}

void nodos_pila(ptrNodo nodo)
{
	if (nodo == NULL)
		printf("La pila está vacia\n");
	else
	{
		while (nodo != NULL)
		{
			printf("%d\n",nodo->dato);
			nodo = nodo->siguiente;
		}
		printf("\n");
	}
}
