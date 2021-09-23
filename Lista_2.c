#include<stdio.h>

#define N 100

int control();

void ingreso_personas(struct persona * p, int n);
int validar_edad_mayor_que(int e);
void ordenar_edad_menor_mayor(struct persona * p, int n);

struct persona
{
char nombre[20];
int edad;
};


int main ()
{
	
	struct persona p[N];

	int n = 0;
	
	n = control();
	ingreso_personas( p,  n);

	
	
	return 0;
}

int control()
{
	int n = 0;
	
	do 
	{
		printf("\nIngrese el valor:");
		
		if (n < 0 || n > 0)
		{
			printf("Ingrese un valor logico");
		}
		
	} while(n < 0 || n > 120);
	
	return n;
}

void ingreso_personas(struct persona * p, int n)
{
	int r = 0;
	for(r = 0; r < n; r++)
		
	{
		if(p[r].nombre != "0")
		{
			printf("\nIngresar nombre: ");
			scanf("%s",&p[r].nombre);
			printf("\nIngrese la edad: ");
			p[r].edad = control();
			
		}
		else
		{
			break;
		}
	}
}


