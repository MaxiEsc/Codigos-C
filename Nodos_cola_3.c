#include <stdio.h>
#include <stdlib.h>


typedef struct nodo_cola{
	int dato;
	struct nodo_cola *p_sig;
}nodo_cola_p;

typedef struct cola{
	nodo_cola_p *p_cabeza;
	nodo_cola_p *p_talon;
	int c;
}cola_N;

void menu(void);
void menuestado(cola_N *cec,cola_N *cc,cola_N *ec);
void iniciar_cola(cola_N *a);
void encolar (cola_N *a,int b);
int desencolar(cola_N *a,int b);
void limpiar(cola_N *a);
int control(cola_N *a);

int main(void){
	cola_N cec, ec ,cc; 
	int b = 1;
	int opcion;
	iniciar_cola(&cec);
	iniciar_cola(&ec);
	iniciar_cola(&cc);
	do{
		system("cls");
		menuestado(&cec,&cc,&ec);
		menu();
		scanf("%d",&opcion);
		switch(opcion)
		{
		case 1:
			encolar(&cec,b);
			encolar(&ec,b);
			encolar(&cc,b);
			
			break;
		case 2:
			limpiar(&ec);
			break;
		case 3:
			desencolar(&cec,b);
			desencolar(&cc,b);
			break;
		case 4:
			exit(EXIT_SUCCESS);
		}
		
	} while(opcion > 0 || opcion < 2);
	
	
	
	return 0;
}

void menu(void){
	
	printf("\n\nOpciones: ");
	printf("\n1) Llega el cliente");
	printf("\n2) Cliente a las cajas");
	printf("\n3) Sale cliente");
	printf("\n4) Fin");
	printf("\n? ");	
}


void menuestado(cola_N *cc,cola_N *cec,cola_N *ec){
	int r;
	if ( cec->c > 15)
	{	
		printf("\nClientes esperando carrito: ");
		printf("\nCarritos esperando a cliente: %d", ((cec->c)-15));
		printf("\nClientes comprando: %d", cc->c);
	}
	printf("\nClientes esperando carrito: ");
	for (r = 0; r < cec->c ; r++)
	{
		printf("0");
	}
	printf("\nCarritos esperando a cliente: ");
	for (r = 0; r < ec->c; r++)
	{
		printf("#");
	}
	if(cec->c > 0 && control(ec))
	{
		printf("\nCaja 0:");
		if(cec->c > 0)
		{
			if(cec->c <= 3){
				for (r = 0; r < cec->c;r++)
				{
					printf("*");
				}
			}
			else{
				for (r = 0; r < 3;r++)
				{
					printf("*");
				}
			}
			if(cec->c > 3)
			{
				printf("\nCaja 1:");
				if(cec->c <= 6){
					for (r = 0; r < ((cec->c)-3);r++)
					{
						printf("*");
					}
				}
				else{
					for (r = 0; r < 3;r++)
					{
						printf("*");
					}
					
				}
				if(cec->c > 6)
				{
					printf("\nCaja 2:");
					if(cec->c <= 9){
						for (r = 0; r < ((cec->c)-6);r++)
						{
							printf("*");
						}
					}
					else{
						for (r = 0; r < 3;r++)
						{
							printf("*");
						}
						
					}
					if(cec->c > 9)
					{
						printf("\nCaja 3:");
						if(cec->c <= 12){
							for (r = 0; r < ((cec->c)-9);r++)
							{
								printf("*");
							}
						}
						else{
							for (r = 0; r < 3;r++)
							{
								printf("*");
							}
						}
						if(cec->c > 12)
						{
							printf("\nCaja 4:");
							if(cec->c <= 15){
								for (r = 0; r < ((cec->c)-12);r++)
								{
									printf("*");
								}
							}
							else{
								for (r = 0; r < 3;r++)
								{
									printf("*");
								}
							}
							if(cec->c > 15)
							{
								printf("\nNo hay cajas disponibles");
							}
						}
					}
				}
			}
		}
	}
	else{
		printf("\nCaja 0:");
		printf("\nCaja 1:");
		printf("\nCaja 2:");
		printf("\nCaja 3:");
		printf("\nCaja 4:");
	}
}
	
void iniciar_cola(cola_N *a)
{
	a->p_cabeza = NULL;
	a->p_talon = NULL;
	a->c = 0;
}
	
void encolar (cola_N *a,int b){
	nodo_cola_p *nodo_temp;
	nodo_temp = (nodo_cola_p*)malloc(sizeof(nodo_cola_p));
	if (nodo_temp == NULL)
	{
		printf("\nError al inicializar la memoria...Memoria insuficiete");
		exit(EXIT_FAILURE);
	}
	nodo_temp->p_sig = NULL;
	nodo_temp->dato = b;
	if (control(a))
	{
		a->p_cabeza = nodo_temp;
	}
	else{
		a->p_talon->p_sig = nodo_temp;
	}
	if(a->p_talon == NULL)
	{
		a->p_cabeza = nodo_temp;
	}
	else{
		a->p_talon->p_sig = nodo_temp;
		}
	a->p_talon = nodo_temp;
	a->c++;
}

	
int desencolar(cola_N *a,int b){
	nodo_cola_p *nodo_temp;
	int d;
	if( a->p_cabeza != NULL)
	{
		nodo_temp = a->p_cabeza;
		d = a->p_cabeza->dato;
		a->p_cabeza = a->p_cabeza->p_sig;
		free(nodo_temp);
	}
	
	if(a->p_cabeza == NULL)
	{
		a->p_talon = NULL;
	}
	a->c--;
	
	return d;
}
void limpiar(cola_N *a)
{
	nodo_cola_p *aux;
	aux = (nodo_cola_p*)malloc(sizeof(nodo_cola_p));
	if(aux == NULL)
	{
		printf("Error al asignar la memoria... Memoria insuficiente");
	}
	while(a->p_cabeza !=  NULL)
	{
		aux = a->p_cabeza;
		a->p_cabeza = aux->p_sig;
		free(aux);
	}
	a->p_cabeza =NULL ;
	a->p_talon = NULL ;
	
	a->c = 0;
	
}
	
int control(cola_N *a){
	int con;
	if (a->p_cabeza == NULL)
	{
		con = 1;
	}
	else{
		con = 0;
	}
	return con;
	
}
	
