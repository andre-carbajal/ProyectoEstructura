#include <iostream>
#include <locale>
#include "Persona.h"
#include "funciones.h"
#include "Inventario.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Spanish");
    system("COLOR F1");
    
    Bebida bebidas[999];
    Snack snacks[999];
    Abarrote abarrotes[999];
    int nBebidas = 0;
    int nSnacks = 0;
    int nAbarrotes = 0;

	Persona usuarios[999];
    int nPersonas = 5;

    string usuario, contrasena;

    int opcionLogin, opcionInv, opcionUsos, usu;
    bool continuarInv, continuarMenu;
    int maxintentos = 3;
    int intentos = 0;
    
    initUsuarios(usuarios);

    do {
        opcionLogin = menulogin();
        limpiar();
        switch (opcionLogin) {
            case 1:
                usu = loginUsuario(usuarios, usuario, contrasena, nPersonas);
                limpiar();
                if (usu != -1 && (usuarios[usu].role == 1 || usuarios[usu].role == 0)){
                    intentos = 0;

                    system("title Sistema integrado");
                    
                    do{
                    	opcionInv = menuinvs();

	                    limpiar();
	
	                    switch (opcionInv) {
	                        case 1:
	                            system("title Bebidas");
	                            opcionUsos = menuusos();
	                            limpiar();
	                            accionesBebidas(opcionInv, bebidas);
	                            continuarInv = true;
	                            break;
	                        case 2:
	                            system("title Snacks");
	                            opcionUsos = menuusos();
	                            limpiar();
	                            accionesSnacks(opcionInv, snacks);
	                            continuarInv = true;
	                            break;
	                        case 3:
	                            system("title Abarrotes");
	                            opcionUsos = menuusos();
	                            limpiar();
	                            accionesAbarrotes(opcionInv, abarrotes);
	                            continuarInv = true;
	                            break;
	                        case 4:
	                            continuarInv = false;
	                            break;
	                        default:
	                            cout << "Opción invalida" << endl;
	                            break;
	                    }
					}while(continuarInv);
                    
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

