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
    cout << "4) Regresar" << endl;
    cout << "Ingrese una opción: ";
    
    cin >> option;

    return option;
}

int menuusos() {
    int option;
    cout << "MENU" << endl;
    cout << "1) Insertar" << endl;
    cout << "2) Buscar" << endl;
    cout << "3) Actualizar" << endl;
    cout << "4) Eliminar" << endl;
    cout << "5) Regresar" << endl;
    cout << "Ingrese una opción: ";
    cin >> option;

    return option;
}

void accionesBebidas(int opcionUsos,Bebida bebidas[]){
	switch(opcionUsos){
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
            cout << "Opción invalida" << endl;
            break;
	}
}

void accionesSnacks(int opcionUsos,Snack snaks[]){
	switch(opcionUsos){
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
            cout << "Opción invalida" << endl;
            break;
	}	
}

void accionesAbarrotes(int opcionUsos,Abarrote abarrotes[]){
	switch(opcionUsos){
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
            cout << "Opción invalida" << endl;
            break;
	}
}


