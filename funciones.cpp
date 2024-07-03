#include "funciones.h"
#include "Inventario.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void limpiar() {
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

bool login(Persona personas[], string usuario, string contrasena, int nUsuarios) {
    system("title Login");
    cout << "Ingrese su usuario: ";
    cin >> usuario;
    cout << "Ingrese su contrasena: ";
    cin >> contrasena;
    for (int i = 0; i < nUsuarios; i++) {
        if (personas[i].usuario == usuario && personas[i].contrasena == contrasena) {
            return true;
        }
    }
    return false;
}

int registrar(Persona personas[], int nPersonas){
	system("title Nuevo Usuario");
	cout << "Ingrese el usuario: ";
	cin >> personas[nPersonas].usuario;
	cout << "Ingrese la contraseña: ";
	cin >> personas[nPersonas].contrasena;
	personas[nPersonas].role = 0;
	return nPersonas+1;
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

void menuinvs() {
    cout << "?BIENVENIDO!" << endl;
    cout << "Seleccione el inventario que desea modificar o usar: " << endl;
    cout << "1) Bebidas" << endl;
    cout << "2) Snacks" << endl;
    cout << "3) Abarrotes" << endl;
    cout << "4) Salir" << endl;
    cout << "Ingrese una opción: ";
}

int menuusos() {
    int option;
    cout << "MENU" << endl;
    cout << "1) Insertar" << endl;
    cout << "2) Buscar" << endl;
    cout << "3) Actualizar" << endl;
    cout << "4) Eliminar" << endl;
    cout << "5) Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> option;

    return option;
}

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


