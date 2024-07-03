#include <iostream>
#include "Inventario.h"
#include "funciones.h"

using namespace std;

void registrarProducto(bool esBebida, Inventario producto[]){
	int i=0;
	do{
		cout<<"ID del producto:"<<endl;
		cin>>producto[i].ID;
		cout<<"nombre del producto: "<<endl;
		cin>>producto[i].nombre;
		cout<<"Costo producto:"<<endl;
		cin>>producto[i].costo;
		cout<<"Cantidad del producto:"<<endl;
		cin>>producto[i].cantidad;
		if(esBebida){
			cout<<"ml del producto:"<<endl;
			cin>>producto[i].ml;break;
		 }
		limpiar();
		i++;
	}while(i<=6);	
}

