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
    Sleep(1500);
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
