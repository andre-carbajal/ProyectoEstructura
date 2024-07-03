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
void mostrarSnacks(Snack snacks[], int nSanks);
void mostrarAbarrotes(Abarrote abarrotes[], int nAbarrotes);

//insertar 
void insertarBebidas(Bebida bebidas[], int nBebidas);
void insertarSnacks(Snack snacks[], int nSnacks);
void insertarAbarrotes(Abarrote abarrotes[], int nAbarrotes);

//buscar
void buscarBebidas(Bebida bebidas[], int nBebidas);
void buscarSnacks(Snack snacks[], int nSnacks);
void buscarAbarrotes(Abarrote abarrotes[], int nAbarrotes);

//actualizar
void actualizarBebidas(Bebida bebidas[], int nBebidas);
void actualizarSnacks(Snack snacks[], int nSnacks);
void actualizarAbarrotes(Abarrote abarrotes[], int nAbarrotes);

//eliminar
void eliminarBebida(Bebida bebidas[], int nBebidas);
void eliminarSnack(Snack snacks[], int nSnacks);
void eliminarAbarrote(Abarrote abarrotes[], int nAbarrotes);

#endif //PROYECTOESTRUCTURA_INVENTARIO_H

