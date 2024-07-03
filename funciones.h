#ifndef PROYECTOESTRUCTURA_FUNCIONES_H
#define PROYECTOESTRUCTURA_FUNCIONES_H

#include "Persona.h"
#include "Inventario.h"

void limpiar();
int menulogin();
bool login(Persona personas[], string usuario, string contrasena, int nPersonas);
void menuinvs();
int menuusos();
void registrarProducto(bool esBebida, Inventario producto[]);

#endif //PROYECTOESTRUCTURA_FUNCIONES_H

