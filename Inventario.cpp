#include <iostream>
#include <cstring>
#include "Inventario.h"
#include "funciones.h"

using namespace std;

//init 
pair<int, int> initBebidas(struct Bebida bebidas[], int nBebidas, int idMaxBebidas, FILE *inventario) {
    char linea[5000];
    
    while (fgets(linea, sizeof(linea), inventario) && strcmp(linea, ";;;;\n") != 0) {
    	if (strncmp(linea, "ID", 2) == 0) {
            continue;
        }
        char *token = strtok(linea, ";");
        if (token != nullptr) {
        	int currentID = atoi(token);
            bebidas[nBebidas].ID = currentID;
            token = strtok(nullptr, ";");
            strcpy(bebidas[nBebidas].nombre, token);
            token = strtok(nullptr, ";");
            bebidas[nBebidas].costo = atof(token);
            token = strtok(nullptr, ";");
            bebidas[nBebidas].cantidad = atoi(token);
            token = strtok(nullptr, ";");
            bebidas[nBebidas].ml = atoi(token);
            nBebidas++; 
            
            if (currentID > idMaxBebidas) {
                idMaxBebidas = currentID;
            }
        }
    }
    return make_pair(nBebidas, idMaxBebidas);
}

pair<int, int> initSnacks(struct Snack snacks[], int nSnacks, int idMaxSnacks, FILE *inventario) {
    char linea[5000];

    while (fgets(linea, sizeof(linea), inventario) && strcmp(linea, ";;;;\n") != 0) {
    	if (strncmp(linea, "ID", 2) == 0) {
        	continue;
    	}
	    char *token = strtok(linea, ";");
	    if (token != nullptr) {
	    	int currentID = atoi(token);
	        snacks[nSnacks].ID = currentID;
	        token = strtok(nullptr, ";");
	        strcpy(snacks[nSnacks].nombre, token);
	        token = strtok(nullptr, ";");
	        snacks[nSnacks].costo = atof(token);
	        token = strtok(nullptr, ";");
	        snacks[nSnacks].cantidad = atoi(token);
	        nSnacks++;
	        
	        if (currentID > idMaxSnacks) {
                idMaxSnacks = currentID;
            }
	    }
    }
    return make_pair(nSnacks, idMaxSnacks);
}

pair<int, int> initAbarrotes(struct Abarrote abarrotes[], int nAbarrotes, int idMaxAbarrotes, FILE *inventario) {
    char linea[5000];

    while (fgets(linea, sizeof(linea), inventario) && strcmp(linea, ";;;;\n") != 0) {
    	if (strncmp(linea, "ID", 2) == 0) {
        	continue;
    	}
        char *token = strtok(linea, ";");
        if (token != nullptr) {
        	int currentID = atoi(token);
            abarrotes[nAbarrotes].ID = currentID;
            token = strtok(nullptr, ";");
            strcpy(abarrotes[nAbarrotes].nombre, token);
            token = strtok(nullptr, ";");
            abarrotes[nAbarrotes].costo = atof(token);
            token = strtok(nullptr, ";");
            abarrotes[nAbarrotes].cantidad = atoi(token);
            nAbarrotes++;
            
            if (currentID > idMaxAbarrotes) {
                idMaxAbarrotes = currentID;
            }
        }
    }
    return make_pair(nAbarrotes, idMaxAbarrotes);
}

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
	cout<<"Precione una tecla para continuar...";
	cin.ignore();
	cin.get();
	limpiar();
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
	cout<<"Precione una tecla para continuar...";
	cin.ignore();
	cin.get();
	limpiar();
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
	cout<<"Precione una tecla para continuar...";
	cin.ignore();
	cin.get();
	limpiar();
}

//insertar 
pair<int, int> insertarBebida(Bebida bebidas[], int nBebidas, int idMaxBebidas){
	int opcion;
	bool continuar;
	do{
		bebidas[nBebidas].ID = idMaxBebidas + 1;
		gotoxy(35,12);
		cout << "--------------------------------------------------" <<endl;
		gotoxy(35,17);
		cout << "--------------------------------------------------" <<endl;
		gotoxy(44,13);
		cout<<"Ingresa nombre del producto: ";
		
		cin.ignore();
        cin.getline(bebidas[nBebidas].nombre, 100);

        for (int i = 0; i < strlen(bebidas[nBebidas].nombre); i++) {
            if (bebidas[nBebidas].nombre[i] == ' ') {
                bebidas[nBebidas].nombre[i] = '-';
            }
        }
		
		gotoxy(43,14);
		cout<<"Ingresa el costo del producto: ";
		cin>>bebidas[nBebidas].costo;
		gotoxy(42,15);
		cout<<"Ingresa la cantidad del producto: ";
		cin>>bebidas[nBebidas].cantidad;
		gotoxy(38,16);
		cout<<"Capacidad en militros (ml) del producto: ";
		cin>>bebidas[nBebidas].ml;
		limpiar();
		nBebidas++;
		idMaxBebidas++;
		gotoxy(43,12);
    	cout << "---------------------------------" <<endl;
    	gotoxy(45,13);
		cout<<"¿Desea agregar otro producto?"<<endl;
		gotoxy(45,14);
		cout<<"1) Sí"<<endl;
		gotoxy(45,15);
		cout<<"2) No"<<endl;
		gotoxy(43,16);
    	cout << "---------------------------------" <<endl;
		gotoxy(45,17);
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
	return make_pair(nBebidas, idMaxBebidas);
}

pair<int, int> insertarSnack(Snack snacks[], int nSnacks, int idMaxSnacks){
	int option;
	bool continuar;
	do{
		snacks[nSnacks].ID = idMaxSnacks + 1;
		gotoxy(37,12);
		cout << "----------------------------------------------" <<endl;
		gotoxy(37,16);
		cout << "----------------------------------------------" <<endl;
		gotoxy(44,13);
		cout<<"Ingresa nombre del producto: ";
		
		cin.ignore();
		cin.getline(snacks[nSnacks].nombre, 100);

        for (int i = 0; i < strlen(snacks[nSnacks].nombre); i++) {
            if (snacks[nSnacks].nombre[i] == ' ') {
                snacks[nSnacks].nombre[i] = '-';
            }
        }
		
		gotoxy(43,14);
		cout<<"Ingresa el costo del producto: ";
		cin>>snacks[nSnacks].costo;
		gotoxy(42,15);
		cout<<"Ingresa la cantidad del producto: ";
		cin>>snacks[nSnacks].cantidad;
		limpiar();
		nSnacks++;
		idMaxSnacks++;
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
	return make_pair(nSnacks, idMaxSnacks);
}

pair<int, int> insertarAbarrote(Abarrote abarrotes[], int nAbarrotes, int idMaxAbarrotes){
	int option;
	bool continuar;
	do{
		abarrotes[nAbarrotes].ID = idMaxAbarrotes + 1;
		gotoxy(37,12);
		cout << "----------------------------------------------" <<endl;
		gotoxy(37,16);
		cout << "----------------------------------------------" <<endl;
		gotoxy(44,13);
		cout<<"Ingresa nombre del producto: ";
		
		cin.ignore();
		cin.getline(abarrotes[nAbarrotes].nombre, 100);

        for (int i = 0; i < strlen(abarrotes[nAbarrotes].nombre); i++) {
            if (abarrotes[nAbarrotes].nombre[i] == ' ') {
                abarrotes[nAbarrotes].nombre[i] = '-';
            }
        }
		
		gotoxy(43,14);
		cout<<"Ingresa el costo del producto:";
		cin>>abarrotes[nAbarrotes].costo;
		gotoxy(42,15);
		cout<<"Ingresa la cantidad del producto:";
		cin>>abarrotes[nAbarrotes].cantidad;
		limpiar();
		nAbarrotes++;
		idMaxAbarrotes++;
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
	return make_pair(nAbarrotes, idMaxAbarrotes);
}

//buscar
void buscarBebidas(Bebida bebidas[], int nBebidas) {
    int ID, inicio = 0, fin = nBebidas - 1;
    bool encontrado = false;
    
    cout << "Digite ID del producto que desea buscar: ";
    cin >> ID;
    
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        
        if (bebidas[medio].ID == ID) {
            cout << "ID     ";
            cout << "NOMBRE     ";
            cout << "COSTO     ";
            cout << "CANTIDAD     ";
            cout << "CAPACIDAD (ml)" << endl;
            cout << bebidas[medio].ID << "     ";
            cout << bebidas[medio].nombre << "     ";
            cout << bebidas[medio].costo << "     ";
            cout << bebidas[medio].cantidad << "     ";
            cout << bebidas[medio].ml << endl;
            cout<<"Precione una tecla para continuar...";
			cin.ignore();
			cin.get();
			limpiar();
            encontrado = true;
            break;
        } else if (bebidas[medio].ID < ID) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    
    if (!encontrado) {
        cout << "No se encontro el elemento" << endl;
    }
}

void buscarSnacks(Snack snacks[], int nSnacks){
	int ID, inicio = 0, fin = nSnacks - 1;
    bool encontrado = false;
    
    cout << "Digite ID del producto que desea buscar: ";
    cin >> ID;
    
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        
        if (snacks[medio].ID == ID) {
            cout << "ID     ";
            cout << "NOMBRE     ";
            cout << "COSTO     ";
            cout << "CANTIDAD"<< endl;
            cout << snacks[medio].ID << "     ";
            cout << snacks[medio].nombre << "     ";
            cout << snacks[medio].costo << "     ";
            cout << snacks[medio].cantidad << endl;
            cout<<"Precione una tecla para continuar...";
			cin.ignore();
			cin.get();
			limpiar();
            encontrado = true;
            break;
        } else if (snacks[medio].ID < ID) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    
    if (!encontrado) {
        cout << "No se encontro el elemento" << endl;
    }
}

void buscarAbarrotes(Abarrote abarrotes[], int nAbarrotes){
	int ID, inicio = 0, fin = nAbarrotes - 1;
    bool encontrado = false;
    
    cout << "Digite ID del producto que desea buscar: ";
    cin >> ID;
    
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        
        if (abarrotes[medio].ID == ID) {
            cout << "ID     ";
            cout << "NOMBRE     ";
            cout << "COSTO     ";
            cout << "CANTIDAD"<< endl;
            cout << abarrotes[medio].ID << "     ";
            cout << abarrotes[medio].nombre << "     ";
            cout << abarrotes[medio].costo << "     ";
            cout << abarrotes[medio].cantidad << endl;
            cout<<"Precione una tecla para continuar...";
			cin.ignore();
			cin.get();
			limpiar();
            encontrado = true;
            break;
        } else if (abarrotes[medio].ID < ID) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    
    if (!encontrado) {
        cout << "No se encontro el elemento" << endl;
    }
}

//actualizar
void actualizarBebida(Bebida bebidas[], int nBebidas){
    int option, ID, a, optionContinuar;
    bool continuar, optinvalida, encontrado;
    do{
        encontrado = false;
        gotoxy(38,13);
    	cout << "----------------------------------------------------"<<endl;
    	gotoxy(38,15);
    	cout << "----------------------------------------------------" <<endl;
    	gotoxy(41,14);
        cout << "Digite ID del producto que desea modificar: ";
        cin >> ID;
        for (int i = 0; i < nBebidas; i++) {
            if (bebidas[i].ID == ID) {
                a = i;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
        	gotoxy(55,16);
            cout << "¡ID no encontrado!" << endl;
            retrasar();
            limpiar();
            continuar = continuarModificar();
            continue;
        }
        gotoxy(55,16);
        cout << "¡ID encontrado!" << endl;
        retrasar();
        limpiar();
        do {
        	gotoxy(38,12);
    		cout << "----------------------------------------------------"<<endl;
    		gotoxy(42,13);
            cout << "¿Que desea modificar en " << bebidas[a].nombre << " de " << bebidas[a].ml << "ml? " << endl;
            gotoxy(42,14);
            cout << "1) Costo" << endl;
            gotoxy(42,15);
            cout << "2) Cantidad" << endl;
            gotoxy(38,16);
    		cout << "----------------------------------------------------" <<endl;
    		gotoxy(42,17);
            cout << "Ingresa tu opción: ";
            cin >> option;
            limpiar();
            if (option == 1) {
            	gotoxy(38,13);
    			cout << "-----------------------------------------------"<<endl;
    			gotoxy(38,15);
    			cout << "-----------------------------------------------"<<endl;
    			gotoxy(43,14);
                cout << "Ingresa el nuevo costo del producto: ";
                cin >> bebidas[a].costo;
                optionContinuar = false;
                limpiar();
            } else if (option == 2) {
            	gotoxy(38,13);
    			cout << "-----------------------------------------------"<<endl;
    			gotoxy(38,15);
    			cout << "-----------------------------------------------"<<endl;
    			gotoxy(43,14);
                cout << "Ingresa la nueva cantidad del producto: ";
                cin >> bebidas[a].cantidad;
                optionContinuar = false;
                limpiar();
            } else {
            	gotoxy(45,14);
                cout << "Opción inválida. Intente de nuevo." << endl;
                optionContinuar = true;
                retrasar();
                limpiar();
            }
        } while (optionContinuar);
        limpiar();
        continuar = continuarModificar();
    } while (continuar);
}

void actualizarSnack(Snack snacks[], int nSnacks){
    int option, ID, a, optionContinuar;
    bool continuar, optinvalida, encontrado;
    do{
        encontrado = false;
        gotoxy(38,13);
    	cout << "----------------------------------------------------"<<endl;
    	gotoxy(38,15);
    	cout << "----------------------------------------------------" <<endl;
    	gotoxy(41,14);
        cout << "Digite ID del producto que desea modificar: ";
        cin >> ID;
        for (int i = 0; i < nSnacks; i++) {
            if (snacks[i].ID == ID) {
                a = i;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
        	gotoxy(55,16);
            cout << "¡ID no encontrado!" << endl;
            retrasar();
            limpiar();
            continuar = continuarModificar();
            continue;
        }
        gotoxy(55,16);
        cout << "¡ID encontrado!" << endl;
        retrasar();
        limpiar();
        do {
        	gotoxy(38,12);
    		cout << "-------------------------------------"<<endl;
    		gotoxy(42,13);
            cout << "¿Que desea modificar en " << snacks[a].nombre << "? " << endl;
            gotoxy(42,14);
            cout << "1) Costo" << endl;
            gotoxy(42,15);
            cout << "2) Cantidad" << endl;
            gotoxy(38,16);
    		cout << "-------------------------------------" <<endl;
    		gotoxy(42,17);
            cout << "Ingresa tu opción: ";
            cin >> option;
            limpiar();
            if (option == 1) {
            	gotoxy(38,13);
    			cout << "-----------------------------------------------"<<endl;
    			gotoxy(38,15);
    			cout << "-----------------------------------------------"<<endl;
    			gotoxy(43,14);
                cout << "Ingresa el nuevo costo del producto:" << endl;
                cin >> snacks[a].costo;
                optionContinuar = false;
                limpiar();
            } else if (option == 2) {
            	gotoxy(38,13);
    			cout << "-----------------------------------------------"<<endl;
    			gotoxy(38,15);
    			cout << "-----------------------------------------------"<<endl;
    			gotoxy(43,14);
                cout << "Ingresa la nueva cantidad del producto:" << endl;
                cin >> snacks[a].cantidad;
                optionContinuar = false;
                limpiar();
            } else {
            	gotoxy(45,14);
                cout << "Opción inválida. Intente de nuevo." << endl;
                optionContinuar = true;
                retrasar();
                limpiar();
            }
        } while (optionContinuar);
        limpiar();
        continuar = continuarModificar();
    } while (continuar);
}

void actualizarAbarrote(Abarrote abarrotes[], int nAbarrotes){
    int option, ID, a, optionContinuar;
    bool continuar, optinvalida, encontrado;
    do{
        encontrado = false;
        gotoxy(38,13);
    	cout << "----------------------------------------------------"<<endl;
    	gotoxy(38,15);
    	cout << "----------------------------------------------------" <<endl;
    	gotoxy(41,14);
        cout << "Digite ID del producto que desea modificar: ";
        cin >> ID;
        for (int i = 0; i < nAbarrotes; i++) {
            if (abarrotes[i].ID == ID) {
                a = i;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "¡ID no encontrado!" << endl;
            retrasar();
            limpiar();
            continuar = continuarModificar();
            continue;
        }
        cout << "¡ID encontrado!" << endl;
        retrasar();
        limpiar();
        do {
        	gotoxy(38,12);
    		cout << "--------------------------------------"<<endl;
    		gotoxy(42,13);
            cout << "¿Que desea modificar en " << abarrotes[a].nombre << "? " << endl;
            gotoxy(42,14);
            cout << "1) Costo" << endl;
            gotoxy(42,15);
            cout << "2) Cantidad" << endl;
            gotoxy(38,16);
    		cout << "-------------------------------------" <<endl;
    		gotoxy(42,17);
            cout << "Ingresa tu opción: ";
            cin >> option;
            limpiar();
            if (option == 1) {
            	gotoxy(38,13);
    			cout << "-----------------------------------------------"<<endl;
    			gotoxy(38,15);
    			cout << "-----------------------------------------------"<<endl;
    			gotoxy(43,14);
                cout << "Ingresa el nuevo costo del producto:" << endl;
                cin >> abarrotes[a].costo;
                optionContinuar = false;
                limpiar();
            } else if (option == 2) {
            	gotoxy(38,13);
    			cout << "-----------------------------------------------"<<endl;
    			gotoxy(38,15);
    			cout << "-----------------------------------------------"<<endl;
    			gotoxy(43,14);
                cout << "Ingresa la nueva cantidad del producto:" << endl;
                cin >> abarrotes[a].cantidad;
                optionContinuar = false;
                limpiar();
            } else {
            	gotoxy(45,14);
                cout << "Opción inválida. Intente de nuevo." << endl;
                optionContinuar = true;
                retrasar();
                limpiar();
            }
        } while (optionContinuar);
        limpiar();
        continuar = continuarModificar();
    } while (continuar);
}


//eliminar
int eliminarBebida(Bebida bebidas[], int nBebidas) {
    int ID;
    bool encontrado = false;
    gotoxy(39,14);
    cout << "----------------------------------------------" <<endl;
    gotoxy(39,16);
    cout << "----------------------------------------------" <<endl;
    gotoxy(41,15);
    cout << "Ingrese el ID del producto a eliminar: ";
    cin >> ID;
    for (int i = 0; i < nBebidas; ++i) {
        if (bebidas[i].ID == ID) {
            bebidas[i] = bebidas[nBebidas - 1];
            nBebidas--;
            encontrado = true;
            gotoxy(50,17);
            cout << "Producto eliminado." << endl;
            retrasar();
        	limpiar();
            return nBebidas;
        }
    }
    if (!encontrado) {
    	gotoxy(50,17);
        cout << "Producto no encontrado." << endl;
        retrasar();
        limpiar();
    }
    return nBebidas;
}

int eliminarSnack(Snack snacks[], int nSnacks) {
    int ID;
    bool encontrado = false;
    gotoxy(39,14);
    cout << "----------------------------------------------" <<endl;
    gotoxy(39,16);
    cout << "----------------------------------------------" <<endl;
    gotoxy(41,15);
    cout << "Ingrese el ID del producto a eliminar: ";
    cin >> ID;
    for (int i = 0; i < nSnacks; ++i) {
        if (snacks[i].ID == ID) {
            snacks[i] = snacks[nSnacks - 1];
            nSnacks--;
            encontrado = true;
            gotoxy(50,17);
            cout << "Producto eliminado." << endl;
            return nSnacks;
        }
    }
    if (!encontrado) {
    	gotoxy(50,17);
        cout << "Producto no encontrado." << endl;
    }
    return nSnacks;
}

int eliminarAbarrote(Abarrote abarrotes[], int nAbarrotes) {
    int ID;
    bool encontrado = false;
    gotoxy(39,14);
    cout << "----------------------------------------------" <<endl;
    gotoxy(39,16);
    cout << "----------------------------------------------" <<endl;
    gotoxy(41,15);
    cout << "Ingrese el ID del producto a eliminar: ";
    cin >> ID;
    for (int i = 0; i < nAbarrotes; ++i) {
        if (abarrotes[i].ID == ID) {
            abarrotes[i] = abarrotes[nAbarrotes - 1];
            nAbarrotes--;
            encontrado = true;
            gotoxy(50,17);
            cout << "Producto eliminado." << endl;
            return nAbarrotes;
        }
    }
    if (!encontrado) {
    	gotoxy(50,17);
        cout << "Producto no encontrado." << endl;
    }
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

void guardarInventario(Bebida bebidas[], int nBebidas, Snack snacks[], int nSnacks, Abarrote abarrotes[], int nAbarrotes){
	FILE *inventario;
	
	inventario = fopen("inventario.csv", "w");
	
	fprintf(inventario, "%s\n", "Inventario de Sistema Integrado;;;;");
	fprintf(inventario, "%s\n", ";;;;");
	
	fprintf(inventario, "%s\n", "Bebidas;;;;");
	fprintf(inventario, "%s\n", "ID;nombre;costo;cantidad;ml");
	for(int i = 0; i<nBebidas; i++){
		fprintf(inventario, "%d;%s;%.2f;%d;%d\n",
		bebidas[i].ID, bebidas[i].nombre, bebidas[i].costo, bebidas[i].cantidad, bebidas[i].ml);
	}
	fprintf(inventario, "%s\n", ";;;;");
	
	fprintf(inventario, "%s\n", "Snacks;;;;");
	fprintf(inventario, "%s\n", "ID;nombre;costo;cantidad");
	for(int i = 0; i<nSnacks; i++){
		fprintf(inventario, "%d;%s;%.2f;%d\n",
		snacks[i].ID, snacks[i].nombre, snacks[i].costo, snacks[i].cantidad);
	}
	fprintf(inventario, "%s\n", ";;;;");
	
	fprintf(inventario, "%s\n", "Abarrotes;;;;");
	fprintf(inventario, "%s\n", "ID;nombre;costo;cantidad");
	for(int i = 0; i<nAbarrotes; i++){
		fprintf(inventario, "%d;%s;%.2f;%d\n",
		abarrotes[i].ID, abarrotes[i].nombre, abarrotes[i].costo, abarrotes[i].cantidad);
	}
	
	fclose(inventario);
}
