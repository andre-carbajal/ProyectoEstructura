#include <iostream>
#include <locale>
#include "Persona.h"
#include "funciones.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Spanish");

    int nPersonas = 5;
    Persona usuarios[nPersonas];
    initUsuarios(usuarios);

    string usuario, contrasena;

    int opcion, opcionInv;
    bool encontrado;
    int maxintentos = 3;
    int intentos = 0;

    do {
        opcion = menulogin();

        switch (opcion) {
            case 1:
                encontrado = login(usuarios, usuario, contrasena, nPersonas);

                if (encontrado) {
                    system("title Sistema integrado");
                    limpiar();

                    menuinvs();
                    cin >> opcionInv;

                    limpiar();

                    switch (opcionInv) {
                        case 1:
                            system("title Bebidas");
                            menuusos();
                            break;
                        case 2:
                            system("title Snacks");
                            menuusos();
                            break;
                        case 3:
                            system("title Abarrotes");
                            menuusos();
                            break;
                        case 4:
                            return 0;
                        default:
                            cout << "Opción invalida" << endl;
                            break;
                    }

                    return 0;
                } else {
                    limpiar();
                    intentos++;
                    cout << "Usuario o contrasena incorrectos." << endl;
                    cout << "Te quedan " << maxintentos - intentos << " intentos." << endl;
                }

                break;

            case 2:
                return 0;

            default:
                limpiar();
                cout << "Opción invalida" << endl;
                break;
        }
    } while (intentos < maxintentos);

    return 0;
}
