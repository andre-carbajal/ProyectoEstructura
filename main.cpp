#include <iostream>
#include <locale>
#include "Persona.h"
#include "funciones.h"
#include "Inventario.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Spanish");
    
    Inventario productos[999];

    int nPersonas = 5;
    Persona usuarios[999];
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
                encontrado = loginUsuario(usuarios, usuario, contrasena, nPersonas);

                if (encontrado) {
                    intentos = 0;

                    system("title Sistema integrado");
                    limpiar();

                    menuinvs();
                    cin >> opcionInv;

                    limpiar();

                    switch (opcionInv) {
                        case 1:
                            system("title Bebidas");
                            menuusos();
                            limpiar();
                            registrarProducto(true, productos);
                            break;
                        case 2:
                            system("title Snacks");
                            menuusos();
                            limpiar();
                            registrarProducto(false, productos);
                            break;
                        case 3:
                            system("title Abarrotes");
                            menuusos();
                            limpiar();
                            registrarProducto(false, productos);
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

