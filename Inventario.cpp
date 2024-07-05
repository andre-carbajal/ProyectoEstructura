#include <iostream>
#include "Inventario.h"
#include "funciones.h"

using namespace std;

//mostrar 
void mostrarBebidas(Bebida bebidas[], int nBebidas){
	cout<<"ID     ";
	cout<<"NOMBRE     ";
	cout<<"COSTO     ";
	cout<<"CANTIDAD     ";
	cout<<"CAPACIDAD (ml)"<<endl;
	for (int i=0; i<nBebidas; i++){
		cout<<bebidas[i].ID<<"     ";
		cout<<bebidas[i].nombre<<"     ";
		cout<<bebidas[i].costo<<"     ";
		cout<<bebidas[i].cantidad<<"     ";
		cout<<bebidas[i].ml<<endl;
	}
}

void mostrarSnacks(Snack snacks[], int nSnacks){
	cout<<"ID     ";
	cout<<"NOMBRE     ";
	cout<<"COSTO     ";
	cout<<"CANTIDAD     "<<endl;
	for (int i=0; i<nSnacks; i++){
		cout<<snacks[i].ID<<"     ";
		cout<<snacks[i].nombre<<"     ";
		cout<<snacks[i].costo<<"     ";
		cout<<snacks[i].cantidad<<endl;
	}
}

void mostrarAbarrotes(Abarrote abarrotes[], int nAbarrotes){
	cout<<"ID     ";
	cout<<"NOMBRE     ";
	cout<<"COSTO     ";
	cout<<"CANTIDAD     "<<endl;
	for (int i=0; i<nAbarrotes; i++){
		cout<<abarrotes[i].ID<<"     ";
		cout<<abarrotes[i].nombre<<"     ";
		cout<<abarrotes[i].costo<<"     ";
		cout<<abarrotes[i].cantidad<<endl;
	}
}

//insertar 
int insertarBebida(Bebida bebidas[], int nBebidas){
	int opcion;
	bool continuar;
	do{
		bebidas[nBebidas].ID = nBebidas;
		cout<<"Ingresa nombre del producto: "<<endl;
		cin>>bebidas[nBebidas].nombre;
		cout<<"Ingresa el costo del producto:"<<endl;
		cin>>bebidas[nBebidas].costo;
		cout<<"Ingresa la cantidad del producto:"<<endl;
		cin>>bebidas[nBebidas].cantidad;
		cout<<"Capacidad en militros (ml) del producto:"<<endl;
		cin>>bebidas[nBebidas].ml;
		limpiar();
		nBebidas++;
		cout<<"¿Desea agregar otro producto?"<<endl;
		cout<<"1) Sí"<<endl;
		cout<<"2) No"<<endl;
		cout<<"Ingresa tu opción: ";
		cin>>opcion;
		if(opcion == 1){
			continuar = true;
			limpiar();
		}else{
			continuar = false;
			limpiar();
		}
	}while(continuar);
	return nBebidas;
}

int insertarSnack(Snack snacks[], int nSnacks){
	int option;
	bool continuar;
	do{
		snacks[nSnacks].ID = nSnacks;
		cout<<"Ingresa nombre del producto: "<<endl;
		cin>>snacks[nSnacks].nombre;
		cout<<"Ingresa el costo del producto:"<<endl;
		cin>>snacks[nSnacks].costo;
		cout<<"Ingresa la cantidad del producto:"<<endl;
		cin>>snacks[nSnacks].cantidad;
		limpiar();
		nSnacks++;
		cout<<"¿Desea agregar otro producto?"<<endl;
		cout<<"1) Sí"<<endl;
		cout<<"2) No"<<endl;
		cout<<"Ingresa tu opción: ";
		cin>>option;
		if(option == 1){
			continuar = true;
			limpiar();
		}else{
			continuar = false;
			limpiar();
		}
	}while(continuar);
	return nSnacks;
}

int insertarAbarrote(Abarrote abarrotes[], int nAbarrotes){
	int option;
	bool continuar;
	do{
		abarrotes[nAbarrotes].ID = nAbarrotes;
		cout<<"Ingresa nombre del producto: "<<endl;
		cin>>abarrotes[nAbarrotes].nombre;
		cout<<"Ingresa el costo del producto:"<<endl;
		cin>>abarrotes[nAbarrotes].costo;
		cout<<"Ingresa la cantidad del producto:"<<endl;
		cin>>abarrotes[nAbarrotes].cantidad;
		limpiar();
		nAbarrotes++;
		cout<<"¿Desea agregar otro producto?"<<endl;
		cout<<"1) Sí"<<endl;
		cout<<"2) No"<<endl;
		cout<<"Ingresa tu opción: ";
		cin>>option;
		if(option == 1){
			continuar = true;
			limpiar();
		}else{
			continuar = false;
			limpiar();
		}
	}while(continuar);
	return nAbarrotes;
}

//buscar
void buscarBebidas(Bebida bebidas[], int nBebidas){
	
}

void buscarSnacks(Snack snacks[], int nSnacks){
	
}

void buscarAbarrotes(Abarrote abarrotes[], int nAbarrotes){
	
}

//actualizar
void actualizarBebida(Bebida bebidas[], int nBebidas){
	int option, ID, a, optionContinuar;
	bool continuar, optinvalida;
	do{
		cout<<"Digite ID del producto que desea modificar: ";
		cin>>ID;
		for (int i = 0; i < nBebidas; i++) {
        	if (bebidas[i].ID == ID) {
            	a = i;
        	}
    	}
		cout<<"¡ID encontrado!"<<endl;
		retrasar();
		limpiar();
		do{
			cout<<"¿Que desea modificar en "<<bebidas[a].nombre<<" de "<<bebidas[a].ml<<"ml? "<<endl;
			cout<<"1) Costo"<<endl;
			cout<<"2) Cantidad"<<endl;
			cout<<"Ingresa tu opción: ";
			cin>>option;
			limpiar();
			if(option == 1){
				cout<<"Ingresa el nuevo costo del producto:"<<endl;
				cin>>bebidas[a].costo;
				optionContinuar = false;
				limpiar();
			} else if(option == 2) {
				cout<<"Ingresa la nueva cantidad del producto:"<<endl;
				cin>>bebidas[a].cantidad;
				optionContinuar = false;
				limpiar();
			} else {
				cout<<"Opción inválida. Intente de nuevo."<<endl;
				optionContinuar = true;
				retrasar();
				limpiar();
			}
		}while(optionContinuar);
		limpiar();
		continuar = continuarModificar();
	}while(continuar);
}

void actualizarSnack(Snack snacks[], int nSnacks){
	int option, ID, a, optionContinuar;
	bool continuar, optinvalida;
	do{
		cout<<"Digite ID del producto que desea modificar: ";
		cin>>ID;
		for (int i = 0; i < nSnacks; i++) {
        	if (snacks[i].ID == ID) {
            	a = i;
        	}
    	}
		cout<<"¡ID encontrado!"<<endl;
		retrasar();
		limpiar();
		do{
			cout<<"¿Que desea modificar en "<<snacks[a].nombre<<"? "<<endl;
			cout<<"1) Costo"<<endl;
			cout<<"2) Cantidad"<<endl;
			cout<<"Ingresa tu opción: ";
			cin>>option;
			limpiar();
			if(option == 1){
				cout<<"Ingresa el nuevo costo del producto:"<<endl;
				cin>>snacks[a].costo;
				optionContinuar = false;
				limpiar();
			} else if(option == 2) {
				cout<<"Ingresa la nueva cantidad del producto:"<<endl;
				cin>>snacks[a].cantidad;
				optionContinuar = false;
				limpiar();
			} else {
				cout<<"Opción inválida. Intente de nuevo."<<endl;
				optionContinuar = true;
				retrasar();
				limpiar();
			}
		}while(optionContinuar);
		limpiar();
		continuar = continuarModificar();
	}while(continuar);
}

void actualizarAbarrote(Abarrote abarrotes[], int nAbarrotes){
	int option, ID, a, optionContinuar;
	bool continuar, optinvalida;
	do{
		cout<<"Digite ID del producto que desea modificar: ";
		cin>>ID;
		for (int i = 0; i < nAbarrotes; i++) {
        	if (abarrotes[i].ID == ID) {
            	a = i;
        	}
    	}
		cout<<"¡ID encontrado!"<<endl;
		retrasar();
		limpiar();
		do{
			cout<<"¿Que desea modificar en "<<abarrotes[a].nombre<<"? "<<endl;
			cout<<"1) Costo"<<endl;
			cout<<"2) Cantidad"<<endl;
			cout<<"Ingresa tu opción: ";
			cin>>option;
			limpiar();
			if(option == 1){
				cout<<"Ingresa el nuevo costo del producto:"<<endl;
				cin>>abarrotes[a].costo;
				optionContinuar = false;
				limpiar();
			} else if(option == 2) {
				cout<<"Ingresa la nueva cantidad del producto:"<<endl;
				cin>>abarrotes[a].cantidad;
				optionContinuar = false;
				limpiar();
			} else {
				cout<<"Opción inválida. Intente de nuevo."<<endl;
				optionContinuar = true;
				retrasar();
				limpiar();
			}
		}while(optionContinuar);
		limpiar();
		continuar = continuarModificar();
	}while(continuar);
}

//eliminar
int eliminarBebida(Bebida bebidas[], int nBebidas) {
    int ID;
    cout << "Ingrese el ID del producto a eliminar: ";
    cin >> ID;
    for (int i = 0; i < nBebidas; ++i) {
        if (bebidas[i].ID == ID) {
            bebidas[i] = bebidas[nBebidas - 1];
            nBebidas--;
            cout << "Producto eliminado." << endl;
            return nBebidas;
        }
    }
    cout << "Producto no encontrado." << endl;
    return nBebidas;
}

int eliminarSnack(Snack snacks[], int nSnacks) {
    int ID;
    cout << "Ingrese el ID del producto a eliminar: ";
    cin >> ID;
    for (int i = 0; i < nSnacks; ++i) {
        if (snacks[i].ID == ID) {
            snacks[i] = snacks[nSnacks - 1];
            nSnacks--;
            cout << "Producto eliminado." << endl;
            return nSnacks;
        }
    }
    cout << "Producto no encontrado." << endl;
    return nSnacks;
}

int eliminarAbarrote(Abarrote abarrotes[], int nAbarrotes) {
    int ID;
    cout << "Ingrese el ID del producto a eliminar: ";
    cin >> ID;
    for (int i = 0; i < nAbarrotes; ++i) {
        if (abarrotes[i].ID == ID) {
            abarrotes[i] = abarrotes[nAbarrotes - 1];
            nAbarrotes--;
            cout << "Producto eliminado." << endl;
            return nAbarrotes;
        }
    }
    cout << "Producto no encontrado." << endl;
    return nAbarrotes;
}

bool continuarModificar(){
	int optionContinuar;
	cout<<"¿Desea modificar otro producto?"<<endl;
	cout<<"1) Sí"<<endl;
	cout<<"2) No"<<endl;
	cout<<"Ingresa tu opción: ";
	cin>>optionContinuar;
	if(optionContinuar == 1){
		limpiar();
		return true;
	} 
	limpiar();
	return false;
}

void ordenamientoBebidas(Bebida bebidas[], int nBebidas) {
    for (int i = 0; i < nBebidas - 1; i++) {
        for (int j = 0; j < nBebidas - i - 1; j++) {
            if (bebidas[j].ID > bebidas[j + 1].ID) {
                Bebida temp = bebidas[j];
                bebidas[j] = bebidas[j + 1];
                bebidas[j + 1] = temp;
            }
        }
    }
}

void ordenamientoSnacks(Snack snacks[], int nSnacks) {
    for (int i = 0; i < nSnacks - 1; i++) {
        for (int j = 0; j < nSnacks - i - 1; j++) {
            if (snacks[j].ID > snacks[j + 1].ID) {
                Snack temp = snacks[j];
                snacks[j] = snacks[j + 1];
                snacks[j + 1] = temp;
            }
        }
    }
}

void ordenamientoAbarrotes(Abarrote abarrotes[], int nAbarrotes) {
    for (int i = 0; i < nAbarrotes - 1; i++) {
        for (int j = 0; j < nAbarrotes - i - 1; j++) {
            if (abarrotes[j].ID > abarrotes[j + 1].ID) {
                Abarrote temp = abarrotes[j];
                abarrotes[j] = abarrotes[j + 1];
                abarrotes[j + 1] = temp;
            }
        }
    }
}

