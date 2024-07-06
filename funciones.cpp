#include "funciones.h"
#include "Inventario.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>

using namespace std;

void limpiar() {
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

void retrasar(){
    sleep(2);
}

int menulogin() {
    system("title Tiendita de don pepe");
    int option;
    cout << "1. Iniciar sesion" << endl;
    cout << "2. Registrar nuevo usuario" << endl;
    cout << "3. Salir" << endl;
    cout << "Ingrese una opción : ";
    cin >> option;

    return option;
}

int menuinvs() {
	int option;
    cout << "!BIENVENIDO!" << endl;
    cout << "Seleccione el inventario que desea modificar o usar: " << endl;
    cout << "1) Bebidas" << endl;
    cout << "2) Snacks" << endl;
    cout << "3) Abarrotes" << endl;
    cout << "4) Guardar y salir" << endl;
    cout << "Ingrese una opción: ";
    
    cin >> option;

    return option;
}

int menuusos() {
    int option;
    cout << "MENÚ" << endl;
    cout << "1) Mostrar" << endl;
    cout << "2) Insertar" << endl;
    cout << "3) Buscar" << endl;
    cout << "4) Actualizar" << endl;
    cout << "5) Eliminar" << endl;
    cout << "6) Regresar" << endl;
    cout << "Ingrese una opción: ";
    cin >> option;

    return option;
}

bool continuar(){
	int optionContinuar;
	cout<<"¿Desea modificar otro producto?"<<endl;
	cout<<"1) Sí"<<endl;
	cout<<"2) No"<<endl;
	cout<<"Ingresa tu opción: ";
	cin>>optionContinuar;
	if(optionContinuar == 1){
		limpiar();
		return true;
	} 
	limpiar();
	return false;
}

void guardar(Bebida bebidas[], int nBebidas, Snack snacks[], int nSnacks, Abarrote abarrotes[], int nAbarrotes){
	FILE *inventario;
	
	inventario = fopen("inventario.csv", "w");
	
	fprintf(inventario, "%s\n", "Inventario de Sistema Integrado;;;;");
	fprintf(inventario, "%s\n", ";;;;");
	
	fprintf(inventario, "%s\n", "Bebidas;;;;");
	fprintf(inventario, "%s\n", "ID;nombre;costo;cantidad;ml");
	for(int i = 0; i<nBebidas; i++){
		fprintf(inventario, "%d;%s;%.2f;%d;%d\n",
		bebidas[i].ID, bebidas[i].nombre, bebidas[i].costo, bebidas[i].cantidad, bebidas[i].ml);
	}
	fprintf(inventario, "%s\n", ";;;;");
	
	fprintf(inventario, "%s\n", "Snacks;;;;");
	fprintf(inventario, "%s\n", "ID;nombre;costo;cantidad");
	for(int i = 0; i<nSnacks; i++){
		fprintf(inventario, "%d;%s;%.2f;%d;%d\n",
		snacks[i].ID, snacks[i].nombre, snacks[i].costo, snacks[i].cantidad);
	}
	fprintf(inventario, "%s\n", ";;;;");
	
	fprintf(inventario, "%s\n", "Abarrotes;;;;");
	fprintf(inventario, "%s\n", "ID;nombre;costo;cantidad");
	for(int i = 0; i<nAbarrotes; i++){
		fprintf(inventario, "%d;%s;%.2f;%d;%d\n",
		abarrotes[i].ID, abarrotes[i].nombre, abarrotes[i].costo, abarrotes[i].cantidad);
	}
	
	fclose(inventario);
}
