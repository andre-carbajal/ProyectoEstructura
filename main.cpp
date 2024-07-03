#include <iostream>
#include <locale>
#include "Persona.h"
#include "funciones.h"
#include "Inventario.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Spanish");
    
    Bebida bebidas[999];
    Snack snacks[999];
    Abarrote abarrotes[999];
    int nBebidas = 0;
    int nSnacks = 0;
    int nAbarrotes = 0;

	Persona usuarios[999];
    int nPersonas = 5;

    string usuario, contrasena;

    int opcionLogin, opcionInv, opcionUsos;
    bool encontrado;
    int maxintentos = 3;
    int intentos = 0;
    
    initUsuarios(usuarios);

    do {
        opcionLogin = menulogin();

        switch (opcionLogin) {
            case 1:
                encontrado = loginUsuario(usuarios, usuario, contrasena, nPersonas);

                if (encontrado) {
                    intentos = 0;

                    system("title Sistema integrado");
                    limpiar();

                    opcionInv = menuinvs();

                    limpiar();

                    switch (opcionInv) {
                        case 1:
                            system("title Bebidas");
                            opcionUsos = menuusos();
                            limpiar();
                            accionesBebidas(opcionInv, bebidas);
                            break;
                        case 2:
                            system("title Snacks");
                            opcionUsos = menuusos();
                            limpiar();
                            accionesSnacks(opcionInv, snacks);
                            break;
                        case 3:
                            system("title Abarrotes");
                            opcionUsos = menuusos();
                            limpiar();
                            accionesAbarrotes(opcionInv, abarrotes);
                            break;
                        case 4:
                            break;
                        default:
                            cout << "Opción invalida" << endl;
                            break;
                    }
                } else {
                    limpiar();
                    intentos++;
                    cout << "Usuario o contrasena incorrectos." << endl;
                    cout << "Te quedan " << maxintentos - intentos << " intentos." << endl;
                }

                break;
                
            case 2:
				nPersonas = registrarUsuario(usuarios, nPersonas);
				limpiar();
				break;

            case 3:
                cout << "Saliendo..." << endl;
                return 0;

            default:
                limpiar();
                cout << "Opción invalida" << endl;
                break;
        }
    } while (intentos < maxintentos);

    return 0;
}

