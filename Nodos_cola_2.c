#include <stdlib.h>


struct nodoCola{
	int dato;
	struct nodoCola *ptrsig;
};

int main () {
	nodoCola *ptrCabeza;
	nodoCola *ptrTalon;
	printf("\nPrimero en la cola");
	
	
	
	return 0;
}

void agregar(nodoCola **ptrCabeza, nodoCola **ptrTalon)
{
	nodoCola *nodo_tmp;
	nodo_tmp =(nodoCola*) malloc(sizeof(nodoCola));
	if(nodoCola == NULL)
	{
		printf("No hay memoria suficiente");
	}
	
	nodo_tmp->p_sig = NULL;
	nodo_tmp->dato = 2;
	
	if(*ptrCabeza == null)
	{
		*ptrTalon = nodo_tmp;
	}
	else
	   {
		(*ptrCabeza)->p_sig = nodo_tmp;
	}
	*ptrCabeza = nodo_tmp;
	
} 

int quitar(nodoCola **ptrCabeza, nodoCola **ptrTalon)
{
	nodoCola *nodo_tmp;
	int d;
	if(*ptrCabeza != NULL)
	{
		nodo_tmp = *ptrCabeza;
		d = (*ptrCabeza)->dato;
		(*ptrCabeza) = (ptrCabeza)->p_sig;
		free(nodo_tmp);
		
	}
	
	if (ptrCabeza == NUll)
	{
		ptrTalon = NUll;
	}
	return d;
}

void imprime()
