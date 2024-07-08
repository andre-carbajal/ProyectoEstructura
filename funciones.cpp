#include "funciones.h"
#include <iostream>
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
    sleep(1);
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

int menuusosAdm() {
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

int menuusosEmp(){
    int option;
    cout << "MENÚ" << endl;
    cout << "1) Mostrar" << endl;
    cout << "2) Buscar" << endl;
    cout << "3) Regresar" << endl;
    cout << "Ingrese una opción: ";
    cin >> option;
    if(option == 1){
		option = 1;
	} else if(option == 2){
		option = 3;
	} else if(option == 3){
		option = 6;
	} else {
		option = 6;
	}
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

void gotoxy(int x, int y){
	HANDLE Manipulador;
	COORD Coordenadas;
	Manipulador = GetStdHandle(STD_OUTPUT_HANDLE);
	Coordenadas.X = x;  
    Coordenadas.Y = y;
	SetConsoleCursorPosition(Manipulador, Coordenadas);
}
