// Archivo pila_postfixexpr.c

#include <stdio.h>
#include "pila_int.h"

int main()
{
	char cadena[]="45+72-*5/";
	int i=0, num1=0, num2=0, result=0;
	ptrPila pila = NULL;
	
	// Muestra la cadena
	printf("La cadena a analizar es la siguiente:\n\n");
	while (cadena[i] != '\0')
	{
		printf("%c", cadena[i]);        
		i++;
	}
	
	i=0;
	printf("\n\n");
	// Recorre la cadena
	while (cadena[i] != '\0')
	{
		// Si el elemento no es un operador, lo ingresa en la pila
		if (cadena[i]!='+' && cadena[i]!='-' && cadena[i]!='*' && cadena[i]!='/')          
			push(&pila, ((int)cadena[i])-48);   // El código ASCII de 0 es 48
		else
		{
			num2=pop(&pila);
			num1=pop(&pila);
			switch (cadena[i])
			{
			case '+':
				result = num1+num2;
				printf("suma %d + %d = %d\n",num1, num2, result);
				push(&pila, result);
				break;
			case '-':
				result = num1-num2;
				printf("resta %d - %d = %d\n",num1, num2, result);
				push(&pila, result);
				break;
			case '*':
				result = num1*num2;
				printf("multiplica %d * %d = %d\n",num1, num2, result);
				push(&pila, result);
				break;
			case '/':
				result = num1/num2;
				printf("divide %d / %d = %d\n",num1, num2, result);
				push(&pila, result);
				break;
			}           
		}
		i++;
	}
	
	if (pila_vacia(&pila)!=1)
	{
		printf("\n\nLos elementos en la pila son los siguientes;\n\n");
		// Muestra los elementos que están en la pila
		nodos_pila(pila);
	}
	
	return 0;
}
