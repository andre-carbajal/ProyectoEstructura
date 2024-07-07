#include <iostream>
#include <locale.h>
#include <wchar.h>
#include "Persona.h"
#include "funciones.h"
#include "Inventario.h"

using namespace std;

int main(){
	setlocale(LC_ALL, "es_ES.UTF-8");
	system("chcp 65001 > null");
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
	
	FILE *inventario = fopen("inventario.csv", "r");
    if (!inventario) {
        cout<<"No se encontro el archivo"<<endl;
    }
    
    char linea[5000];
    
    while (fgets(linea, sizeof(linea), inventario)) {
    	if (strcmp(linea, "Bebidas;;;;\n") == 0) {
            nBebidas = initBebidas(bebidas, nBebidas, inventario);
        } else if (strcmp(linea, "Snacks;;;;\n") == 0) {
            nSnacks = initSnacks(snacks, nSnacks, inventario);
        } else if (strcmp(linea, "Abarrotes;;;;\n") == 0) {
            nAbarrotes = initAbarrotes(abarrotes, nAbarrotes, inventario);
        }
	}
	
	fclose(inventario);
	
	//limpiar();

	do{
		opcionLogin = menulogin();
		limpiar();
		switch (opcionLogin){
		case 1:
			usu = loginUsuario(usuarios, usuario, contrasena, nPersonas);
			limpiar();
			
			if (usu != -1 && (usuarios[usu].role == 1 || usuarios[usu].role == 0)){
				intentos = 0;
				system("title Sistema integrado");
				
				do{
					opcionInv = menuinvs();
					limpiar();
					
					switch (opcionInv){
						case 1:
							continuarInv = true;
							system("title Bebidas");
							
							do{
								opcionUsos = menuusos();
								limpiar();
								
								switch(opcionUsos){
									case 1:
										mostrarBebidas(bebidas, nBebidas);
										continuarMenu = true;
										break;
									case 2:
										nBebidas = insertarBebida(bebidas, nBebidas);
										continuarMenu = true;
										break;
									case 3:
										ordenamientoBebidas(bebidas, nBebidas);
										buscarBebidas(bebidas, nBebidas);
										continuarMenu = true;
										break;
									case 4:
										actualizarBebida(bebidas, nBebidas);
										continuarMenu = true;
										break;
									case 5:
										nBebidas = eliminarBebida(bebidas, nBebidas);
										ordenamientoBebidas(bebidas, nBebidas);
										continuarMenu = true;
										break;
									case 6:
										continuarMenu = false;
										break;
									default:
										cout << "Opción invalida" << endl;
										continuarMenu = true;
										break;
								}
							}while(continuarMenu);
							
							break;
						case 2:
							continuarInv = true;
							system("title Snacks");
							
							do{
								opcionUsos = menuusos();
								limpiar();
								
								switch(opcionUsos){
									case 1:
										mostrarSnacks(snacks, nSnacks);
										continuarMenu = true;
										break;
									case 2:
										nSnacks = insertarSnack(snacks, nSnacks);
										continuarMenu = true;
										break;
									case 3:
										ordenamientoSnacks(snacks, nSnacks);
										buscarSnacks(snacks, nSnacks);
										continuarMenu = true;
										break;
									case 4:
										actualizarSnack(snacks, nSnacks);
										continuarMenu = true;
										break;
									case 5:
										nSnacks = eliminarSnack(snacks, nSnacks);
										ordenamientoSnacks(snacks, nSnacks);
										continuarMenu = true;
										break;
									case 6:
										continuarMenu = false;
										break;
									default:
										cout << "Opción invalida" << endl;
										continuarMenu = true;
										break;
								}
							}while(continuarMenu);
							
							break;
						case 3:
							continuarInv = true;
							system("title Abarrotes");
							
							do{
								opcionUsos = menuusos();
								limpiar();
								
								switch(opcionUsos){
									case 1:
										mostrarAbarrotes(abarrotes, nAbarrotes);
										continuarMenu = true;
										break;
									case 2:
										nAbarrotes = insertarAbarrote(abarrotes, nAbarrotes);
										continuarMenu = true;
										break;
									case 3:
										ordenamientoAbarrotes(abarrotes, nAbarrotes);
										buscarAbarrotes(abarrotes, nAbarrotes);
										continuarMenu = true;
										break;
									case 4:
										actualizarAbarrote(abarrotes, nAbarrotes);
										continuarMenu = true;
										break;
									case 5:
										nAbarrotes = eliminarAbarrote(abarrotes, nAbarrotes);
										ordenamientoAbarrotes(abarrotes, nAbarrotes);
										continuarMenu = true;
										break;
									case 6:
										continuarMenu = false;
										break;
									default:
										cout << "Opción invalida" << endl;
										continuarMenu = true;
										break;
								}
							}while(continuarMenu);
							
							break;
						case 4:
							guardar(bebidas, nBebidas, snacks, nSnacks, abarrotes, nAbarrotes);
							continuarInv = false;
							break;
						default:
							cout << "Opción invalida" << endl;
							continuarInv = true;
							break;
					}
				}while(continuarInv);
				
			}else{
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
