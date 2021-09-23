#include <stdio.h>
#include <string.h>

typedef struct {
	char ** palabra;
	int palabras;
} lista_t;

lista_t crea_lista(void);
void liberar_lista(lista_t);
void inserta_palabra_en_lista(char *,lista_t);
void eliminar_palabra_de_la_lista(char *, lista_t);
int busca_palabra_en_lista(char *, lista_t);
void ordenar_palabras_en lista(lista_t);
void muestra_lista(lista_t);
	
int main () {
	lista_t *m = NULL;
	printf("Creando lista");
	m = liberar_lista(lista_t);
	
	
	
	return 0;
}

lista_t crea_lista(void)
{
	lista_t p* = NULL;
	
	p = (lista_t*) malloc(n, sizeof(lista_t))
	if (p = NULL)
	{
		printf("\nError de relocalizacion de memoria");
	}	
	
	return p;
}

void liberar_lita(lista_t)
{
	free(p);
}

void inserta_palabra_en_lista(char *,lista_t)
{
	
}
