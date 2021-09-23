#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int carga_codigo();
int carga_tipo();
float carga_importe();
void carga_vectores(int codigo[], int tipo[], float precio[]);
void ordenar(int codigo[], int tipo[], float precio[]);
void mayor_imp_venta(int codigo[], int tipo[], float precio[]);
void imp_vend_tipo(int codigo[], int tipo[], float precio[]);
void cant_por_tipo(int codigo[], int tipo[], float precio[]);
void porcentaje(int codigo[], int tipo[], float precio[]);
void mostrar(int codigo[], int tipo[], float precio[]);
void porcentaje(int codigo[], int tipo[], float precio[]);

int buscar(int codigo[], int tipo[], float precio[]);


int main() {

	int codigo[10]; int tipo[10]; float precio[10];
	int opcion;
	
	cout << "carga de vectores maximo 10" << endl;
	carga_vectores(codigo, tipo, precio);
	
	do
	{
		cout << "1 - Articulo con mayor importe de venta" << endl; 
		cout << "2 - Importe total vendido" << endl;
		cout << "3 - Cantidad de articulos de cada tipo"<< endl;
		cout << "4 - Calcular los porcentajes" << endl;
		cout << "5 - Ordenar los productos" << endl;
		cout << "6 - Buscar un un producto" << endl;
		cin >> opcion ; 
		
		switch(opcion)
		{
		case 1:mayor_imp_venta(codigo, tipo,precio);
			break;
		case 2:imp_vend_tipo(codigo, tipo,precio);
			break;
		case 3:cant_por_tipo(codigo, tipo,precio);
			break;
		case 4:porcentaje(codigo,tipo,precio);
			break;
		case 5:ordenar(codigo,tipo, precio);
			break;
		case 6:
			int b  = buscar(codigo,tipo,precio);
			if (b < 0)
			{
				cout << "No se encontro el producto" << endl;
			}
			else{
				cout << "El producto se encontro sus datos son" << endl;
				}
			break;
		}
		
	} while(opcion < 0 || opcion > 7);
	
	
	system("pause");
	return 0;
}


//funcion independiente que carga el codigo
int carga_codigo()
{
	int codaux;
	do
	{ 
		cout << "Ingrese el valor del codigo" << endl;
		cout << "Codigo: ";
		cin >> codaux;
		
		if(codaux < 0 || codaux > 10000)
		{
			cout << "Ingrese un valor correspondiente " << endl; 
		}
		
	} while(codaux < 0 || codaux > 10000);
	
	return codaux;
	
}
//Funcion de carga de tipo, devuelve el tipo
int carga_tipo()
{
//Funcion de carga de importe devuelve el importe
	int tipoaux;
	
	do 
	{
		cout << "Ingrese el tipo de producto que desea realizar" << endl;
		cout << "Tipo: ";
		cin >> tipoaux;
		
		if(tipoaux < 0 || tipoaux > 10)
		{
			cout << "Ingrese un tipo de dato existente" << endl; 
		}
		
	} while(tipoaux < 0 || tipoaux > 10);
	
	return tipoaux;
}

float carga_importe()
{
	float impaux;
	do
	{
		cout << "Ingrese el precio del producto para cargar" << endl;
		cout << "Importe: ";
		cin >> impaux;
		
		if(impaux < 0 || impaux > 10000000)
		{
			cout << "Ingrese el valor existente " << endl;
		}
		
	} while(impaux < 0 || impaux > 10000000);
	
	return impaux;
}



//cargar los vectores
void carga_vectores(int codigo[], int tipo[], float precio[])
{
	cout << "Ingrese los valores para los productos" << endl;
	system("cls");//Limpiar pantalla.
	for (int i; i < 10 ; i++)
	{
		cout << "Ingrese el codigo del producto: N°:" << i+1 << endl;
		codigo[i] = carga_codigo();
		cout << "Ingrese el tipo de producto: N°:" << i+1 << endl;
		tipo[i] = carga_tipo();
		cout << "Ingrese el precio de producto: N°:" << i+1 << endl;
		precio[i] = carga_importe();
	}
	cout << "Carga realizada" << endl;
}
//funcion para ordenar los arreglos
void ordenar(int codigo[], int tipo[], float precio[])
{
	int opaux;
	do 
	{
		cout << "Ingrese de la opcion de acuerdo a lo desea ordenar" << endl;
		cout << "1 - Ordenar por codigo" << endl;
		cout << "2 - Ordenar por tipo" << endl;
		cout << "3 - Ordenar por precio" << endl;
		cout << "Opcion: ";
		cin >> opaux; 
		system("cls");
		switch(opaux)
		{
	case 1:
			for(int i= 0; i < 10; i++)
			{
				for (int j = i + 1 ; j < 10; j++ )
				{
					if (codigo[i] > codigo [j])
					{
						int aux;
						aux = codigo[i];
						codigo[i] = codigo[j];
						codigo[j] = aux;
						
						int aux2;
						aux2 = tipo[i];
						tipo[i] = tipo[j];
						tipo[j] = aux2;
						
						float aux3;
						aux3 = precio[i];
						precio[i] = precio[j];
						precio[j] = aux3;
					}
				}
			} 
		break;
	case 2:
			for(int i= 0; i < 10; i++)
			{
				for (int j = i + 1 ; j < 10; j++ )
				{
					if (tipo[i] > tipo[j])
					{
						int aux;
						aux = tipo[i];
						tipo[i] = tipo[j];
						tipo[j] = aux;
						
						int aux1;
						aux1 = codigo[i];
						codigo[i] = codigo[j];
						codigo[j] = aux1;
						
						float aux2;
						aux2 = precio[i];
						precio[i] = precio[j];
						precio[j] = aux2;
					}
				}
			} 
		break;
	case 3:
			for(int i= 0; i < 10; i++)
			{
				for (int j = i + 1 ; j < 10; j++ )
				{
					if (precio[i] > precio[j])
					{
						float aux;
						aux = precio[i];
						precio[i] = precio[j];
						precio[j] = aux;
						
						
						int aux1;
						aux1 = codigo[i];
						codigo[i] = codigo[j];
						codigo[j] = aux1;
						
						int aux2;
						aux2 = tipo[i];
						tipo[i] = tipo[j];
						tipo[j] = aux2;
						
					}
				}
			} 
		break;
		}
		
	} while(opaux < 0 || opaux > 3);
	
	cout << "Ordenadando" << endl;
	system("pause"); //No te preocupes pusa la tecla y sigue...XD
}

//Funcion del enunciado
void mayor_imp_venta(int codigo[], int tipo[], float precio[])
{
	int pos;float comp = 0;
	for (int h = 0; h < 10 ; h++)
	{
		if (comp < precio[h])
		{
			comp = precio[h];
				pos = h;
		}
	}
	
	cout << "Articulo con mayor importe de venta es... Codigo: " << codigo[pos] << "Precio: " << comp << endl;
	system("pause");
}
void cant_por_tipo(int codigo[], int tipo[], float precio[])
{
	float aux[10];
	
	for (int r = 0; r < 10 ; r++)
	{
		if (tipo[r] == 1)aux[0]++;  
		if (tipo[r] == 2)aux[1]++;
		if (tipo[r] == 3)aux[2]++;
		if (tipo[r] == 4)aux[3]++;
		if (tipo[r] == 5)aux[4]++;
		if (tipo[r] == 6)aux[5]++;
		if (tipo[r] == 7)aux[6]++;
		if (tipo[r] == 8)aux[7]++;
		if (tipo[r] == 9)aux[8]++;
		if (tipo[r] == 10)aux[9]++;
	}
	
	for (int p = 0; p < 10; p++)
	{
		cout << "Articulos de tipo N°: "  <<  p+1 << "Cant. Productos: " << aux[p] << endl;  
	}
	
	
}
//consigna XD

void imp_vend_tipo(int codigo[], int tipo[], float precio[])
{
	float aux[10]; float preart[10];
	
	for (int r = 0; r < 10 ; r++)
	{
		if (tipo[r] == 1)preart[0]++;  
		if (tipo[r] == 2)preart[1]++;
		if (tipo[r] == 3)preart[2]++;
		if (tipo[r] == 4)preart[3]++;
		if (tipo[r] == 5)preart[4]++;
		if (tipo[r] == 6)preart[5]++;
		if (tipo[r] == 7)preart[6]++;
		if (tipo[r] == 8)preart[7]++;
		if (tipo[r] == 9)preart[8]++;
		if (tipo[r] == 10)preart[9]++;
	}
	for (int r = 0; r < 10 ; r++)
	{
		if (tipo[r] == 1)aux[0]++;  
		if (tipo[r] == 2)aux[1]++;
		if (tipo[r] == 3)aux[2]++;
		if (tipo[r] == 4)aux[3]++;
		if (tipo[r] == 5)aux[4]++;
		if (tipo[r] == 6)aux[5]++;
		if (tipo[r] == 7)aux[6]++;
		if (tipo[r] == 8)aux[7]++;
		if (tipo[r] == 9)aux[8]++;
		if (tipo[r] == 10)aux[9]++;
	}
	
	for (int o = 0; 0 < 10; o++ )
	{
		aux[o] = aux[o]*preart[o];
	}
	cout << "Cantidad total de vendidos por tipo " << endl;
	for(int t= 0; t < 10 ; t++)
	{
		cout << "Tipo :" << tipo[t] << " Precio : " << aux[t] << endl;  
	}
	system("pause");
}
//funcion para calcular el porcentaje
void porcentaje(int codigo[], int tipo[], float precio[])
{
	float porcentaje;
	
	float aux[10]; float preart[10];
	
	for (int r = 0; r < 10 ; r++)
	{
		if (tipo[r] == 1)preart[0]= preart[0] + precio[r];  
		if (tipo[r] == 2)preart[1]= preart[1] + precio[r];
		if (tipo[r] == 3)preart[2]= preart[2] + precio[r];
		if (tipo[r] == 4)preart[3]= preart[3] + precio[r];
		if (tipo[r] == 5)preart[4]= preart[4] + precio[r];
		if (tipo[r] == 6)preart[5]= preart[5] + precio[r];
		if (tipo[r] == 7)preart[6]= preart[6] + precio[r];
		if (tipo[r] == 8)preart[7]= preart[7] + precio[r];
		if (tipo[r] == 9)preart[8]= preart[8] + precio[r];
		if (tipo[r] == 10)preart[9]= preart[9] + precio[r];
	}
	for (int r = 0; r < 10 ; r++)
	{
		if (tipo[r] == 1)aux[0]++;  
		if (tipo[r] == 2)aux[1]++;
		if (tipo[r] == 3)aux[2]++;
		if (tipo[r] == 4)aux[3]++;
		if (tipo[r] == 5)aux[4]++;
		if (tipo[r] == 6)aux[5]++;
		if (tipo[r] == 7)aux[6]++;
		if (tipo[r] == 8)aux[7]++;
		if (tipo[r] == 9)aux[8]++;
		if (tipo[r] == 10)aux[9]++;
	}
	//calcukar el porcentaje
	for (int u = 0; u < 10;u++ )
	{
		
		porcentaje = (preart[u] * aux[u])/100;
		preart[u]= porcentaje;
			
		
	}
	
	system("pause");
}
//funcion para mostrar ls vectores
void mostrar(int codigo[], int tipo[], float precio[])
{
	for (int w = 0 ; w < 10 ; w++)
	{
		cout << " | " << codigo[w] << " |  -  | " << tipo[w] << " |  -  | " << precio[w] << " | " << endl;	
	}
	system("pause");
}

int buscar(int codigo[], int tipo[], float precio[])
{
	int busca;
	cout << "Ingrese el codigo que desea buscar" << endl;
	cout << "Ingrese el codigo: ";
	cin >> busca;
		
	for (int r = 0 ; r < 10 ; r++)
	{
		if (codigo[r] == busca)
		{
			cout << "Encontrado..." << endl;
			cout << "Producto: " << codigo[r] << " | " << tipo[r] << " | " << precio[r] << endl;
			return busca;
		}
	}
	return -1;
	system("pause");
}
