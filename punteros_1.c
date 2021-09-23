// Archivo pila_parentesis.c

#include <stdio.h>
#include "pila_char.h"

int verifica_balance(char expresion[], char cabre, char ccierra);

int main()
{
	char cadena[]="2*[x+q(3s-2)]/[((x+1)*x+(s-2))]";
	int i=0;
	
	// Muestra la cadena
	printf("La cadena a analizar es la siguiente:\n\n");
	while (cadena[i] != '\0')
	{
		printf("%c", cadena[i]);
		i++;
	}
	
	printf("\n\n");
	// Verifica si los par�ntesis est�n balanceados
	if (verifica_balance(cadena, '(', ')') == 1)
		printf("Los par�ntesis est�n balanceados\n");
	else
		printf("Los par�ntesis NO est�n balanceados\n");
	
	// Verifica si los corchetes est�n balanceados
	if (verifica_balance(cadena, '[', ']') == 1)
		printf("Los corchetes est�n balanceados\n");
	else
		printf("Los corchetes NO est�n balanceados\n");
	
	return 0;
}

int verifica_balance(char expresion[], char cabre, char ccierra)
{
	int x=0, balanceados=1;
	ptrPila pila = NULL;
	
	// Recorre la cadena
	while (expresion[x] != '\0' && balanceados == 1)
	{
		// Si el elemento coincide con el caracter que abre, lo ingresa en la pila
		if (expresion[x]==cabre)
			push(&pila, expresion[x]);
		else
			// Si el elemento coincide con el caracter que cierra, lo saca de la pila
			if (expresion[x]==ccierra)
		{
				/* Si la pila est� vac�a, significa que los caracteres no est�n balanceados
				porque se encontr� un caracter que cierra sin que exista antes un caracter que abre
				*/
				if (pila_vacia(&pila) != 1)
					pop(&pila);
				else
					balanceados = 0;
		}
			x++;
	}
	
	/* Si balanceados = 1 pero la pila no est� vac�a, los caracteres no est�n balanceados
	porque quedaron caracteres que abren sin tener su caracter que cierra
	*/
	if (balanceados == 1 && pila_vacia(&pila) != 1)
		balanceados = 0;
	
	// Se asegura de dejar la pila vacia
	while (pila_vacia(&pila) != 1)
		pop(&pila);
	
	return balanceados; 
}
