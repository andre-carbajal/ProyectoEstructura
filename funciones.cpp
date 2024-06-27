#include "funciones.h"
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
    cout << "2. Salir" << endl;
    cout << "Ingrese una opción : ";
    cin >> option;
    return option;
}

bool login(Persona usuarios[], string usuario, string contrasena, int nUsuarios) {
    system("title Login");
    cout << "Ingrese su usuario: ";
    cin >> usuario;
    cout << "Ingrese su contrasena: ";
    cin >> contrasena;

    for (int i = 0; i < nUsuarios; ++i) {
        if (usuarios[i].usuario == usuario && usuarios[i].contrasena == contrasena) {
            return true;
        }
    }
    return false;
}

void menuinvs() {
    cout << "¡BIENVENIDO!" << endl;
    cout << "Seleccione el inventario que desea modificar o usar: " << endl;
    cout << "1) Bebidas" << endl;
    cout << "2) Snacks" << endl;
    cout << "3) Abarrotes" << endl;
    cout << "4) Salir" << endl;
    cout << "Ingrese una opcion: ";
}

int menuusos() {
    int op2;
    cout << "MENU" << endl;
    cout << "1) Insertar" << endl;
    cout << "2) Buscar" << endl;
    cout << "3) Actualizar" << endl;
    cout << "4) Eliminar" << endl;
    cout << "5) Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> op2;
    return op2;
}
