#ifndef PROYECTOESTRUCTURA_FUNCIONES_H
#define PROYECTOESTRUCTURA_FUNCIONES_H

#include "Persona.h"
#include "Inventario.h"

void limpiar();
int menulogin();
bool login(Persona usuarios[], string usuario, std::string contrasena, int nUsuarios);
void menuinvs();
int menuusos();
int registrar(Persona usuarios[], int nPersonas);
void registrarProducto(bool esBebida, Inventario producto[]);

#endif //PROYECTOESTRUCTURA_FUNCIONES_H

