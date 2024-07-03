#ifndef PROYECTOESTRUCTURA_PERSONA_H
#define PROYECTOESTRUCTURA_PERSONA_H

#include <string>

using namespace std;

struct Persona {
    string usuario;
    string contrasena;
    int role; // role 0: admin, role 1: user
};

void initUsuarios(Persona personas[]);

#endif //PROYECTOESTRUCTURA_PERSONA_H

