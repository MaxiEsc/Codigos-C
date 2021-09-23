#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define FILAS 3
#define COLUM 3  
#define CANT_ELEM 3

void crea_matriz(float ***matriz);
void crea_vector(float **vector);
void carga_vector(float **vector);
void carga_matriz(float ***matriz, float numero);
void Mostrar_matriz(float ***matriz, float **vector);

void resultado(float ***matriz, float **vector);
void gauss(float ***matriz, float **vector);

int main() 
{
	float numero = 0;  
	float hora = time(NULL);  
	srand(hora); 
	
	float **matriz, *vector;
	crea_matriz(&matriz);
	crea_vector(&vector);
	printf("Por favor ingrese los valores para el vector resultante de las 3 ecuaciones\n");
	carga_vector(&vector);
	carga_matriz(&matriz, numero);
	Mostrar_matriz(&matriz, &vector);
	gauss(&matriz, &vector);
	Mostrar_matriz(&matriz, &vector);
	resultado(&matriz, &vector);
	
	
	return 0;
}

void crea_matriz(float ***matriz)
{
	int i;
	
	*(matriz) = (float**)malloc(FILAS*sizeof(float*));
	if (*(matriz) == NULL)
	{
		printf("\nError de realocalizacion de memoria");
		exit(EXIT_FAILURE);
	}
	for ( i = 0; i < FILAS; i++)
	{
		(*matriz)[i] = (float*)malloc(COLUM*sizeof(float));
		if((*matriz)[i] == NULL)
		{
			printf("\nError de realocalizacion de memoria");
			exit(EXIT_FAILURE);
		}
	}
	
}




void crea_vector(float **vector)
{
	
	*vector = (float*)malloc(COLUM*sizeof(float*));
	if (vector == NULL)
	{
		printf("\nError de realocalizacion de memoria");
		exit(EXIT_FAILURE);
	}
	
}

void carga_vector(float **vector)
{
	int i;
	for(i = 0; i < COLUM; i++)
	{
		/*numero = rand()%10;
		(*vector)[i] = numero;*/
		
		printf(" | %d | : ", i);
		scanf("%f",&(*vector)[i]);
	}
	
}

void carga_matriz(float ***matriz, float numero)
{
	int i ,j;
	printf("\nIngresar datos a la Matriz\n");
	for (i = 0; i < FILAS ; i++)
	{
		for( j = 0; j < COLUM; j++)
		{
			numero = rand()%10;
			
			(*matriz)[i][j] = numero;
		}
		
	}
	
}

void Mostrar_matriz(float ***matriz, float **vector)
{
	int a,b;
	printf("\nMuestra de datos de Matriz");
	printf("\n");
	for (a = 0; a < FILAS ; a++)
	{
		for (b = 0; b < COLUM; b++)
		{
			printf(" |%f| ", (*matriz)[a][b]);
			
		}
		printf(" |%f|",(*vector)[a]);
		printf("\n");
	}
	
} 

void resultado(float ***matriz, float **vector)
{
	int k = 0; 
	printf("\nEcuacion de X: \n");
	printf("%.2f X", (*vector)[k]);
	printf("\nEcuacion de Y: \n");
	printf("%.2f Y", (*vector)[k + 1]);
	printf("\nEcuacion de Z: \n");
	printf("%.2f Z", (*vector)[k + 2]);
}
	
	
void gauss(float ***matriz, float **vector)
{
	int i , j , k;
	double aux, aux2;
	
	for(i = 0 ; i < FILAS ; i++)
	{
		if((*matriz)[i][i] != 0)
		{
			aux = 1 / (*matriz)[i][i];
			for( j = 0 ; j < FILAS  ; j++)
			{
				(*matriz)[i][j] = aux * (*matriz)[i][j];
				(*vector)[i] = aux * (*matriz)[i][j];
			}
			for( j = 0 ; j < FILAS ; j++)
			{
				if(j != i)
				{
					aux = -(*matriz)[j][i];
					for(k = 0 ; k < COLUM ; k++)
					{
						(*matriz)[j][k] =(*matriz)[j][k] + aux * (*matriz)[i][k];
						aux2 = aux * (*matriz)[i][k];
					}
					(*vector)[i] = aux2;
				}
			}
		}
	}
}




