#include<iostream>
#include<stdlib.h>
using namespace std;
struct nodo{
	int numero;
	struct nodo *siguiente;};
typedef nodo *ptrPila; 
void push(ptrPila &p, int valor)
{ptrPila aux;
	aux = new (struct nodo);
	aux->numero = valor;
	aux->siguiente = p;
	p = aux;}

int pop( ptrPila &p)
{int numero;
	ptrPila aux;
	aux = p;
	numero = aux->numero;
	p = aux->siguiente;
	delete(aux);
	return numero;}
void listar_pila( ptrPila p)
{
	ptrPila aux;
	aux = p;
	while(aux != NULL)
	{cout<<"\t"<<aux->numero<<endl;
		aux = aux->siguiente;}
}

int main(void)
{
	ptrPila p = NULL;
	int dato;
	int opc;
	int x;	
	
	do
	{
		cout<<"\n\t\tElija una opcion del bus\n "<<endl;
		cout<<"\t1. Subir Pasajero"<<endl;
		cout<<"\t2. Bajar Pasajero"<<endl;
		cout<<"\t3. Listado de los Pasajeros "<<endl;
		cout<<"\t4. Salir   "<<endl;
		cout<<"\n Ingrese Opcion: ";
		cin>>opc;
		switch (opc)
		{
			case 1:
			cout<<"\nIngrese Numero del Pasajero\n";
			cin>>dato;
			push(p,dato);
			break;
			case 2:
				x = pop(p);
				cout<<"Pasajero a Bajar\n";
				cout<<"Pasajero "<< x <<" Bajado\n";
			break;	
			case 3:
				cout<<"\nLista\n";
				if(p!=NULL)
				listar_pila(p);
				else
				cout<<"NO Hay Pasajeros disponibles\n";
			break;	
		}
		cout<<endl<<endl;
		system("pause"); system("cls");
	}while(opc!=4);
	return 0 ;
}