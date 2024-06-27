#ifndef PROYECTOESTRUCTURA_FUNCIONES_H
#define PROYECTOESTRUCTURA_FUNCIONES_H

#include "Persona.h"

void limpiar();
int menulogin();
bool login(Persona usuarios[], std::string usuario, std::string contrasena, int nUsuarios);
void menuinvs();
int menuusos();

#endif //PROYECTOESTRUCTURA_FUNCIONES_H
