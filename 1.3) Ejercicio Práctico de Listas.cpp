/* 1.3) Ejercicio Práctico de Listas

- Hacer una lista que pueda almacenar "n" números enteros y calcular el menor y mayor 
entre ellos. */

#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct Nodo{
int dato;
Nodo *siguiente;	
};

void insertarLista(Nodo *&,int);
void mostrarLista(Nodo *);
void calcularMayorMenor(Nodo *);

int main(){
	Nodo *lista = NULL;
	int dato;
	char opcion;
	
	do{
		printf("Ingrese un numero para agregarlo a lista: ");
		scanf("%d", &dato);
		insertarLista(lista,dato);
		
		printf("\nQuiere agregar un nuevo numero? (S/N): ");
		scanf("%s", &opcion);
	}while(opcion == 's' || opcion == 'S');
	
	printf("\nElementos de la lista: \n");
	mostrarLista(lista);
	
	calcularMayorMenor(lista);	
	
	getch();
	return 0;
}

void insertarLista(Nodo *&lista,int n){
	Nodo *nuevo_nodo = new Nodo();
	Nodo *aux;
	
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(lista == NULL){
		lista = nuevo_nodo;
	}
	else{
		aux = lista;
		while(aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo_nodo;
	}
	printf("\nElemento %d agregado a lista correctamente\n", n);
}

void mostrarLista(Nodo *lista){	
	Nodo *actual = new Nodo();
	
	actual = lista;
	while(actual != NULL){
		printf(" %d -> ", actual->dato);
		actual = actual->siguiente;
	}
}

void calcularMayorMenor(Nodo *lista){
	int mayor=0,menor=99999;
	
	while(lista != NULL){
		if((lista->dato)>mayor){
			mayor = lista->dato;
		}
		if((lista->dato)<menor){
			menor = lista->dato;
		}
		lista = lista->siguiente;
	}
	
	printf("\n\nEl mayor numero es: %d", mayor);
	printf("\nEl menor numero es: %d", menor);	
}

