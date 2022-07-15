/* 2.3) Ejercicio Práctico de Colas

- Hacer un programa que guarde la informacion de contacto de los clientes de un restaurante, los almacene
en cola y finalmente muestre los clientes en el orden correcto. */

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Cliente{
	char nombre[30];
	char numero[12];
	int cedula;
};

struct Nodo{
	Cliente c;
	Nodo *siguiente;	
};

void cargar_cliente(Cliente &);
void insertarCola(Nodo *&,Nodo *&,Cliente);
bool cola_vacia(Nodo *);
void suprimirCola(Nodo *&,Nodo *&,Cliente &);

int main(){
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	Cliente c;
	char rpt;
	
	do{
		cargar_cliente(c);
		insertarCola(frente,fin,c);
		
		printf("\nQuiere agregar mas clientes? (S/N): ");
		scanf("%d", &rpt);
	}while(rpt == 'S' || rpt == 's');
	
	cout<<"\n\n=== Carga de Clientes Exitosa ===\n\n";
	
	cout<<"A continuacion se muestran los clientes:\n\n";
	while(frente != NULL){
		suprimirCola(frente,fin,c);
		printf("Nombre: %s \n", c.nombre);
		printf("Numero de telefono: %s \n", c.numero);
		printf("Cedula de Identidad (C.I): %d \n", c.cedula);	
	}	
	
	getch();
	return 0;
}

void cargar_cliente(Cliente &c){
	fflush(stdin);
	printf("Se agrega un nuevo cliente: \n");
	printf("\nNombre: ");
	scanf("%s", &c.nombre);
	printf("Numero de telefono: ");
	scanf("%s", &c.numero);
	printf("Cedula de Identidad (C.I): ");
	scanf("%d", &c.cedula);
} 

void insertarCola(Nodo *&frente,Nodo *&fin,Cliente c){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->c = c;
	nuevo_nodo->siguiente = NULL;
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin->siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
}

bool cola_vacia(Nodo *frente){
	return (frente == NULL)? true : false;
}

void suprimirCola(Nodo *&frente,Nodo *&fin,Cliente &c){
	c = frente->c;
	Nodo *aux = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente->siguiente;
	}
	
	delete aux;
}
