#include <iostream>
#include "Inventario.h"
#include "funciones.h"

using namespace std;

//mostrar 
void mostrarBebidas(Bebida bebidas[], int nBebidas){
		cout<<"ID     ";
		cout<<"NOMBRE     ";
		cout<<"COSTO     ";
		cout<<"CANTIDAD     ";
		cout<<"CAPACIDAD (ml)"<<endl;
	for (int i=0; i<nBebidas; i++){
		cout<<bebidas[i].ID<<"     ";
		cout<<bebidas[i].nombre<<"     ";
		cout<<bebidas[i].costo<<"     ";
		cout<<bebidas[i].cantidad<<"     ";
		cout<<bebidas[i].ml<<endl;
	}
}

void mostrarSnacks(Snack snacks[], int nSnacks){
		cout<<"ID     ";
		cout<<"NOMBRE     ";
		cout<<"COSTO     ";
		cout<<"CANTIDAD     "<<endl;
	for (int i=0; i<nSnacks; i++){
		cout<<snacks[i].ID<<"     ";
		cout<<snacks[i].nombre<<"     ";
		cout<<snacks[i].costo<<"     ";
		cout<<snacks[i].cantidad<<endl;
	}

}

void mostrarAbarrotes(Abarrote abarrotes[], int nAbarrotes){
		cout<<"ID     ";
		cout<<"NOMBRE     ";
		cout<<"COSTO     ";
		cout<<"CANTIDAD     "<<endl;
	for (int i=0; i<nAbarrotes; i++){
		cout<<abarrotes[i].ID<<"     ";
		cout<<abarrotes[i].nombre<<"     ";
		cout<<abarrotes[i].costo<<"     ";
		cout<<abarrotes[i].cantidad<<endl;
	}

}

//insertar 
void insertarBebida(Bebida bebidas[], int nBebidas){
	int opcion;
	bool continuar;
	do{
		cout<<"Ingresa ID del producto:"<<endl;
		cin>>bebidas[nBebidas].ID;
		cout<<"Ingresa nombre del producto: "<<endl;
		cin>>bebidas[nBebidas].nombre;
		cout<<"Ingresa el costo del producto:"<<endl;
		cin>>bebidas[nBebidas].costo;
		cout<<"Ingresa la cantidad del producto:"<<endl;
		cin>>bebidas[nBebidas].cantidad;
		cout<<"Capacidad en militros (ml) del producto:"<<endl;
		cin>>bebidas[nBebidas].ml;
		limpiar();
		nBebidas++;
		cout<<"?Desea agregar otro producto?"<<endl;
		cout<<"1) S?"<<endl;
		cout<<"2) No"<<endl;
		cout<<"Ingresa tu opci?n: ";
		cin>>opcion;
		if(opcion == 1){
			continuar = true;
			limpiar();
		}else{
			continuar = false;
			limpiar();
		}
	}while(continuar);
}

void insertarSnack(Snack snacks[], int nSnacks){
	int option;
	bool continuar;
	do{
		cout<<"Ingresa ID del producto:"<<endl;
		cin>>snacks[nSnacks].ID;
		cout<<"Ingresa nombre del producto: "<<endl;
		cin>>snacks[nSnacks].nombre;
		cout<<"Ingresa el costo del producto:"<<endl;
		cin>>snacks[nSnacks].costo;
		cout<<"Ingresa la cantidad del producto:"<<endl;
		cin>>snacks[nSnacks].cantidad;
		limpiar();
		nSnacks++;
		cout<<"?Desea agregar otro producto?"<<endl;
		cout<<"1) S?"<<endl;
		cout<<"2) No"<<endl;
		cout<<"Ingresa tu opci?n: ";
		cin>>option;
		if(option == 1){
			continuar = true;
			limpiar();
		}else{
			continuar = false;
			limpiar();
		}
	}while(continuar);
}

void insertarAbarrote(Abarrote abarrotes[], int nAbarrotes){
	int option;
	bool continuar;
	do{
		cout<<"Ingresa ID del producto:"<<endl;
		cin>>abarrotes[nAbarrotes].ID;
		cout<<"Ingresa nombre del producto: "<<endl;
		cin>>abarrotes[nAbarrotes].nombre;
		cout<<"Ingresa el costo del producto:"<<endl;
		cin>>abarrotes[nAbarrotes].costo;
		cout<<"Ingresa la cantidad del producto:"<<endl;
		cin>>abarrotes[nAbarrotes].cantidad;
		limpiar();
		nAbarrotes++;
		cout<<"?Desea agregar otro producto?"<<endl;
		cout<<"1) S?"<<endl;
		cout<<"2) No"<<endl;
		cout<<"Ingresa tu opci?n: ";
		cin>>option;
		if(option == 1){
			continuar = true;
			limpiar();
		}else{
			continuar = false;
			limpiar();
		}
	}while(continuar);
}

//buscar
void buscarBebidas(Bebida bebidas[], int nBebidas){
	
}

void buscarSnacks(Snack snacks[], int nSnacks){
	
}

void buscarAbarrotes(Abarrote abarrotes[], int nAbarrotes){
	
}

//actualizar
void actualizarBebidas(Bebida bebidas[], int nBebidas){
	
}

void actualizarSnack(Snack snacks[], int nSnacks){
	
}

void actualizarAbarrote(Abarrote abarrotes[], int nAbarrotes){
	
}

//eliminar
void eliminarBebida(Bebida bebidas[], int nBebidas){
	
}

void eliminarSnack(Snack snacks[], int nSnacks){
	
}

void eliminarAbarrote(Abarrote abarrotes[], int nAbarrotes){
	
}
