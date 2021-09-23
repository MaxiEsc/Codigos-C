#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1

struct Persona
{
	char nombres[30];
	char apellidos[30];
	char DNI[10];
	char FeNa[10];
};

typedef struct Persona DAP;

void cargar_arr(DAP **p, int n);
void Ordenar(DAP *p, int n );
void mostrar(DAP *p, int n );
void quitar(DAP *p, int n);

int main () 
{
	DAP *p = NULL;
	int n,opcion;
	int r = 0;
	n = N;
	
	p = (DAP*) malloc( n * sizeof(DAP)); // asigna espacion en la memoria
		
		if (p == NULL)
	{
			printf("Memoria insuficiente");
			exit(EXIT_FAILURE);
	}
	do
	{
		printf("\n1 - Cargar de datos (Alta)");
		printf("\n2 - Ordenar datos");
		printf("\n3 - Mostrar datos");
		printf("\n4 - Quitar datos");
		printf("\n5 - Salir ");
		
		
		printf("\nOpcion: ");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion)
		{
		case 1: 
			n = n + 1;
			p = (DAP*) realloc( p ,n * sizeof(DAP));
			
			if (p == NULL)
			{
				printf("Memoria insuficiente");
				exit(EXIT_FAILURE);
			}
			
		for (r=0; r < n; r++)
		{
			fflush(stdin);
			printf("\nIngrese el nombre: ");
			gets(p[r].nombres); 
			fflush(stdin);
			printf("\nIngrese el apellido: " );
			gets(p[r].apellidos);
			fflush(stdin);
			printf("\nIngrese el DNI: " );
			gets(p[r].DNI);
			fflush(stdin);
			printf("\nIngrese el Fecha de Nacimiento: " );
			gets(p[r].FeNa);
			
		}
		break;
		case 2: 
			Ordenar(p, n);
		break;
		case 3:
			mostrar(p, n);
			break;
		case 4: 
			
			quitar(p, n);
			
			p = (DAP*) realloc( p ,(n-1) * sizeof(DAP)); //se le reasigna espacio para dar baja a datos vacios 
			
			if (p == NULL)
			{
				printf("Memoria insuficiente");
				exit(EXIT_FAILURE);
			}
			
			
			break;
		case 5:
			free(p);
			exit(EXIT_SUCCESS);
			break;
		}
		
	}while(opcion > 0 || opcion < 5);
	
	
	return 0;
}


void Ordenar(DAP *p, int n)
{
	int o, x, y;
	o = x = y = 0;
	DAP aux;
	printf("Seleccione el campo que desea ordenar: ");
	printf("\n1 - Nombres");
	printf("\n2 - Apellidos");
	printf("\n3 - DNI");
	printf("\n4 - Fecha de Nacimiento");
	printf("\nOpcion: ");
	scanf("%d",&o );
	switch(o) {
	case 1:
		for (x = 0 ; x < n - 1; x++)
		{
			for (y = x + 1; y < n ; n++)
			{
				if(strcmp(p[x].nombres, p[y].nombres)> 0)
				{
					aux = p[x];
					p[x] = p[y];
					p[y] = aux;
				}
			}
		}
		break;
	case 2:
		for (x = 0 ; x < n - 1; x++)
		{
			for (y = x + 1; y < n ; n++)
			{
				if (strcmp (p[x].apellidos, p[y].apellidos)> 0)
				{
					aux = p[x];
					p[x] = p[y];
					p[y] = aux;
				}
			}
		}
		break;
	case 3:
		for (x = 0 ; x < n - 1; x++)
		{
			for (y = x + 1; y < n ; n++)
			{
				if (strcmp (p[x].DNI, p[y].DNI)> 0)
				{
					aux = p[x];
					p[x] = p[y];
					p[y] = aux;
				}
			}
		}
		break;
	case 4:
		for (x = 0 ; x < n - 1; x++)
		{
			for (y = x + 1; y < n ; n++)
			{
				if (strcmp (p[x].FeNa, p[y].FeNa)> 0)
				{
					aux = p[x];
					p[x] = p[y];
					p[y] = aux;
				}
			}
		}
		break;
	}
}

void mostrar(DAP *p, int n )
{
	int x,o,y,OP[4];
	x = y = o = 0;
	do
	{
	printf("Seleccione el campo que desea ordenar: ");
	printf("\n1 - Nombres");
	printf("\n2 - Apellidos");
	printf("\n3 - DNI");
	printf("\n4 - Fecha de Nacimiento");
	printf("\n5 - Mas de una opcion");
	printf("\n6 - Mostrar todo junto");
	printf("\n7 - Salir");
	printf("\nOpcion: ");
	scanf("%d",&o);
		switch(o)
		{
		case 1:	
			for (x = 0 ; x < n ;x++)
			{
				printf("\n %s ",p[x].nombres);
			}
			break;
		case 2:		
			for (x = 0 ; x < n ;x++)
			{
			printf("\n %s ",p[x].apellidos);
			}
			break;
		case 3:
			for (x = 0 ; x < n ;x++)
			{
				printf("\n %s ",p[x].DNI);
			}
			break;
		case 4:		
			for (x = 0 ; x < n ;x++)
			{
			printf("\n %s ",p[x].FeNa);
			}
			break;
		case 5:
			system("cls");
			printf("\nSeleccione una opcion tras otra con lo que desea mostrar");
			printf("\n1 - Nombres");
			printf("\n2 - Apellidos");
			printf("\n3 - DNI");
			printf("\n4 - Fecha de Nacimiento");
			printf("\n5 - Ninguna opcion mas");
			for (x = 0; x < n ; x++)
			{
			printf("\nOpcion : ");
			scanf("%d", &OP[x]);
			
				if (OP[x] == 5)
				{
				x = 4;
				}
			}
			for(x = 0;x < n ; x++)
			{
				if(OP[x]== 1 ) 
				{
					for (x = 0 ; x < n ;x++)
					{
						printf("\n %s ",p[x].nombres);
					}
				}
				if(OP[x]== 2 ) 
				{
					for (x = 0 ; x < n ;x++)
					{
						printf("\n %s ",p[x].apellidos);
					}
				}
				if(OP[x]== 3 ) 
				{
					for (x = 0 ; x < n ;x++)
					{
						printf("\n %s ",p[x].DNI);
					}
				}
				if(OP[x]== 4 ) 
				{
					for (x = 0 ; x < n ;x++)
					{
						printf("\n %s ",p[x].FeNa);
					}
				}
			}
			break;
		case 6:
			for (x = 0 ; x < n ;x++)
			{
				printf("\nNombre: \t Apellido: \t: DNI: \t Fecha de Nacimiento: \t R:%d",x);
				printf("\n %s \t\t %s \t\t %s \t\t %s ", p[x].nombres, p[x].apellidos , p[x].DNI, p[x].FeNa );
			}
			break;
		case 7:;
			break;
		}
	}while(o < 0 || o > 7);
}

void quitar(DAP *p, int n)
{
	int v, k, x, y;
	DAP aux;
	char a[40] = {" "};
	for (v = 0 ; v < n ;v++)
	{
		printf("\n %s \t %s \t %s \t %s ", p[v].nombres, p[v].apellidos , p[v].DNI, p[v].FeNa );
	}
	
	printf("\nSeleccione el numero de fila de vectores que desea quitar");
	scanf("%d", &k);
	
	strcpy(p[k].nombres, a) ;
	strcpy(p[k].apellidos, a);
	strcpy(p[k].DNI, a);
	strcpy(p[k].FeNa, a);
	
	for (x = 0 ; x < n - 1; x++)
	{
		for (y = x + 1; y < n ; n++)
		{
			if(strcmp(p[x].nombres, p[y].nombres)> 0)
			{
				aux = p[x];
				p[x] = p[y];
				p[y] = aux;
			}
		}
	}
	
	
}
