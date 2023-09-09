#include "listaMenuRest.h"
#include "../pais/listaPais.h"
#include "../ciudad/listaCiudad.h"
#include "../menuRes/listaMenuRest.h"

ListaMenuRest::ListaMenuRest() {
	primero = NULL;
}
bool ListaMenuRest::listaVacia() {
    return primero == NULL;
}


bool ListaMenuRest::existeMenuRest(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenuRest, ListaPais& lPais, ListaCiudad& lCiudad, ListaRest& lRest) {
    NodoMenuRest *aux;
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        aux = primero;
        while (aux!=NULL) {
            if (aux->codMenuRest == pCodMenuRest) {
                if (aux->codigoPais == pCodPais && aux->codCiudad == pCodCiudad && aux->codRest == pCodRest) {
                    return true;
                }
            }
            aux = aux->siguiente;
        }
    }
    return false;
}

NodoMenuRest* ListaMenuRest::punteroMenu(int pcodMenu) {
    NodoMenuRest *auxMenu;
    if (primero== NULL)
        cout << "No hay elementos";  
    else {
        auxMenu = primero;
        while(auxMenu) {
            if (auxMenu->codMenuRest == pcodMenu) {
                return auxMenu;
            }
            auxMenu = auxMenu->siguiente;
        }
    }
    return 0;
}

void ListaMenuRest::buscarMenuRest(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRest){
    NodoMenuRest *aux;
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        aux = primero;
        while (aux) {
            if (aux->codMenuRest == pCodMenu && aux->codigoPais == pCodPais && aux->codCiudad == pCodCiudad && aux->codRest == pCodRest) {
                cout << "Datos del menu" << endl;
                cout << "Codigo Pais y nombre: " << pCodPais << " | " << lPaises.punteroPais(pCodPais)->nombre << endl;
                cout << "Codigo ciudad y nombre: " << pCodCiudad << " | " << lCiudades.punteroCiudad(pCodCiudad, pCodPais)->nombre << endl;
                cout << "Codigo restaurante y nombre: " << pCodRest << " | " << lRest.punteroRest(pCodRest, pCodCiudad, pCodPais)->nombre << endl;
                cout << "Codigo menu y nombre: " << pCodMenu << " | " << aux->nombre << endl; 
                return;
            }
            aux = aux->siguiente;
        }
    }
}

void ListaMenuRest::insertarMenuRest(int codPais, int codCiudad, int codRest, int codMenuRest, string nombre, ListaPais& lPaises, ListaCiudad& lCiudad, ListaRest& lRest) {
    if (lRest.existeRest(codPais,codCiudad, codRest, lPaises, lCiudad)) {
        if (listaVacia()) {
            primero = new NodoMenuRest(codPais, codCiudad, codRest, codMenuRest, nombre);
        } else {
            if (existeMenuRest(codPais, codCiudad, codRest, codMenuRest, lPaises, lCiudad, lRest)) {
                cout << "Este menu ya existe, no se puede insertar" << endl;
            } else {
                pNodoMenuRest aux = primero;
                while (aux->siguiente!=NULL) {
                    aux = aux->siguiente;
                }
                aux->siguiente = new NodoMenuRest(codPais, codCiudad, codRest, codMenuRest, nombre);
                aux->siguiente->anterior = aux;
                cout << "Nuevo menu insertado" << endl;
            }
        }
    } else {
        cout << "Los datos proporcionados no coinciden" << endl;
    }
}
    
void ListaMenuRest::mostrar() {
    NodoMenuRest *aux;
    if (primero==NULL)
        cout << "No hay elementos";  
    else {
        aux = primero;
        while(aux) {
        cout << aux->codMenuRest << " : " << aux->nombre << " -> ";
        aux = aux->siguiente;
        }
    cout << endl;
    }
}

void ListaMenuRest::cargarMenuRest(ListaPais& lPais, ListaCiudad& lCiudad, ListaRest& lRest) {
    ifstream archivo("Archivos/Menu.txt");
    string line;
    
    while (getline(archivo, line)) {
        stringstream ss(line);
        string temp;
        int idP, idC, idR, idM;
        string name;

        getline(ss, temp, ';');
        idP = stoi(temp);

        getline(ss, temp, ';');
        idC = stoi(temp);

        getline(ss, temp, ';');
        idR = stoi(temp);

        getline(ss, temp, ';');
        idM = stoi(temp);

        getline(ss, name, ';');

        ListaMenuRest::insertarMenuRest(idP, idC, idR, idM, name, lPais, lCiudad, lRest);
    }

    archivo.close();
}
