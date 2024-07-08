#ifndef PROYECTOESTRUCTURA_FUNCIONES_H
#define PROYECTOESTRUCTURA_FUNCIONES_H

#include "Persona.h"

void limpiar();
void retrasar();
void opcioninvalida(int opcion);
int menulogin();
int menuinvs(Persona usuarios[], int numdUsu);
int menuusosAdm();
int menuusosEmp();
bool continuar();
void gotoxy(int x, int y);

#endif //PROYECTOESTRUCTURA_FUNCIONES_H
