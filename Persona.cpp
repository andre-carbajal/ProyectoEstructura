#include <iostream>
#include "Persona.h"

using namespace std;

void initUsuarios(Persona personas[]) {
    personas[0].usuario = "andre";
    personas[0].contrasena = "andre";
    personas[0].role = 1;
    personas[1].usuario = "marymar";
    personas[1].contrasena = "marymar";
    personas[1].role = 1;
    personas[2].usuario = "fatima";
    personas[2].contrasena = "fatima";
    personas[2].role = 1;
    personas[3].usuario = "mariela";
    personas[3].contrasena = "mariela";
    personas[3].role = 1;
    personas[4].usuario = "haydee";
    personas[4].contrasena = "haydee";
    personas[4].role = 0;
}

int registrarUsuario(Persona personas[], int nPersonas){
	system("title Nuevo Usuario");
	cout << "Ingrese el usuario: ";
	cin >> personas[nPersonas].usuario;
	cout << "Ingrese la contraseña: ";
	cin >> personas[nPersonas].contrasena;
	personas[nPersonas].role = 0;
	return nPersonas+1;
}
