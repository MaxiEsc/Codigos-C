#include <stdio.h>
#include <stdlib.h>

struct nodoCola{
	int dato;
	struct nodoCola *p_sig;
};

void agregarCola(nodoCola **ptrCabeza, nodoCola **ptrTalon);
int quitarCola(nodoCola **ptrCabeza, nodoCola **ptrTalon);
void imprimeCola(nodoCola *ptrCabeza);

int main () {
	nodoCola *ptrCabeza = NULL;
	nodoCola *ptrTalon = NULL;
	ptrCabeza = (nodoCola*) malloc(sizeof(nodoCola));
	if (ptrCabeza = NULL ) 
	{
		printf("Error al asignar memoria");
	} 
	ptrTalon = (nodoCola*) malloc(sizeof(nodoCola));
	if (ptrTalon = NULL ) 
	{
		printf("Error al asignar memoria");
	}    
	
	int menu;
	
	printf("\nPrimero en la cola");
	do
	{
		printf("\nOpciones:");
		printf("\n1 - Agregar elemento a la cola");
		printf("\n2 - Quitar elemento a la cola");
		printf("\n3 - Salir");
		printf("\nOpcion: ");
		scanf("%d",&menu);
		
		switch(menu)
		{
		case 1:agregarCola( &ptrCabeza, &ptrTalon);
			 imprimeCola(ptrCabeza);   
			break;
		case 2:quitarCola( &ptrCabeza, &ptrTalon);
			break;
		case 3:;
		break;
		}                      
	}while(menu > 0 || menu < 2);	
	
	
	
	return 0;
}

void agregarCola(nodoCola **ptrCabeza, nodoCola **ptrTalon)
{
	nodoCola *nodo_tmp;  
	int imp=0;
	
	nodo_tmp =(nodoCola*) malloc(sizeof(nodoCola));
	if(nodo_tmp == NULL)
	{
		printf("No hay memoria suficiente");
	}
	printf("\nIngrese el n:de dato: ");
	scanf("%d",&imp);
	
	nodo_tmp->p_sig = NULL;
	nodo_tmp->dato = 2;
	if(*ptrCabeza == NULL)
	{
		*ptrTalon = nodo_tmp;
	}
	else
	{
		(*ptrCabeza)->p_sig = nodo_tmp;
	}
	
	*ptrCabeza = nodo_tmp;
	
} 

int quitarCola(nodoCola **ptrCabeza, nodoCola **ptrTalon)
{
	nodoCola *nodo_tmp;
	int d;
	if(*ptrCabeza != NULL)
	{
		nodo_tmp = *ptrCabeza;
		d = (*ptrCabeza)->dato;
		(*ptrCabeza) = (*ptrCabeza)->p_sig;
		free(nodo_tmp);
		
	}
	
	if (ptrCabeza == NULL)
	{
		ptrTalon = NULL;
	}
	
	return d;
}

void imprimeCola(nodoCola *ptrCabeza)
{
	if (ptrCabeza == NULL)
	{
		printf("\nla lista de cola es:");      
	}
	else
	{
		printf("\nLa cola es: \n");
		while ( ptrCabeza != NULL)
		{
			printf("%d ->", ptrCabeza->dato);
			ptrCabeza = ptrCabeza ->p_sig;
		}
	}
	
}

// agregar una funcion para preguntar el valor de pilas o colas a devolver
