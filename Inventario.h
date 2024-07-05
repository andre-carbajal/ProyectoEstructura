#ifndef PROYECTOESTRUCTURA_INVENTARIO_H
#define PROYECTOESTRUCTURA_INVENTARIO_H

#include <string>

using namespace std;

struct Bebida{
	int ID;
	string nombre;
	float costo;
	int cantidad;
	int ml;
};

struct Snack{
	int ID;
	string nombre;
	float costo;
	int cantidad;
};

struct Abarrote{
	int ID;
	string nombre;
	float costo;
	int cantidad;
};

//mostrar 
void mostrarBebidas(Bebida bebidas[], int nBebidas);
void mostrarSnacks(Snack snacks[], int nSnacks);
void mostrarAbarrotes(Abarrote abarrotes[], int nAbarrotes);

//insertar 
int insertarBebida(Bebida bebidas[], int nBebidas);
int insertarSnack(Snack snacks[], int nSnacks);
int insertarAbarrote(Abarrote abarrotes[], int nAbarrotes);

//buscar
void buscarBebidas(Bebida bebidas[], int nBebidas);
void buscarSnacks(Snack snacks[], int nSnacks);
void buscarAbarrotes(Abarrote abarrotes[], int nAbarrotes);

//actualizar
void actualizarBebida(Bebida bebidas[], int nBebidas);
void actualizarSnack(Snack snacks[], int nSnacks);
void actualizarAbarrote(Abarrote abarrotes[], int nAbarrotes);

//eliminar
int eliminarBebida(Bebida bebidas[], int nBebidas);
int eliminarSnack(Snack snacks[], int nSnacks);
int eliminarAbarrote(Abarrote abarrotes[], int nAbarrotes);

bool continuarModificar();

//ordenamiento
void ordenamientoBebidas(Bebida bebidas[], int nBebidas);
void ordenamientoSnacks(Snack snacks[], int nSnacks);
void ordenamientoAbarrotes(Abarrote abarrotes[], int nAbarrotes);

#endif //PROYECTOESTRUCTURA_INVENTARIO_H

