#include "listaPais.h"
#include <string>
#include <stdlib.h>
#include <fstream>
#include <cstdio>



ListaPais::ListaPais() {
    primero = NULL;
}

ListaPais::~ListaPais() {
    pNodoPais aux;
    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
    primero = NULL;
}

bool ListaPais::listaVacia() {
    return primero == NULL;
}

void ListaPais::insertar(int codPais, string nombre) {
    if (listaVacia()) {
        primero = new NodoPais(codPais, nombre);
    } else {
        if (existePais(codPais)) {
            cout << "Este pais ya existe" << endl;
        } else {
            pNodoPais aux = primero;
            while (aux->siguiente != NULL) {
                aux = aux->siguiente;
            }
            aux->siguiente = new NodoPais(codPais, nombre);
            aux->siguiente->anterior = aux;
            cout << "Nuevo pais insertado" << endl;
        }
    }
}

void ListaPais::modificarPais(int pCodPaisOriginal, string pnombre){
    NodoPais* auxPais = punteroPais(pCodPaisOriginal);
    auxPais->nombre = pnombre;
}

void ListaPais::mostrar() {
    NodoPais *aux;
    if (primero== NULL)
        cout << "No hay elementos";  
    else {
        aux = primero;
        while(aux) {
        cout << aux->codigoPais << " : " << aux->nombre << " -> ";
        aux = aux->siguiente;
        }
    cout << endl;
    }
}

void ListaPais::borrarInicio() {
    if (listaVacia()) {
        cout << "No hay paises en la lista" << endl;
    } else {
        if (primero->siguiente == NULL) {
            pNodoPais temp = primero;
            primero = NULL;
            delete temp;
        } else {
            pNodoPais aux = primero;
            primero = primero->siguiente;
            primero->anterior = NULL;
            delete aux;
        }
    }
}

void ListaPais::eliminar(int codPais) {
    if (listaVacia()) {
        cout << "No se puede eliminar, lista vacia" << endl;
    } else {
        pNodoPais aux = primero;
        if (aux->codigoPais == codPais) {
            borrarInicio();
        } else {
            while (aux->codigoPais != codPais) {
                aux = aux->siguiente;
            }
            pNodoPais temp = aux;
            aux = aux->anterior;
            aux->siguiente = temp->siguiente;
            delete temp;
        }
    }
}

bool ListaPais::existePais(int codPais) {
    NodoPais *aux;
    if (primero== NULL)
        cout << "No hay elementos";  
    else {
        aux = primero;
        while(aux) {
            if (aux->codigoPais == codPais) {
                // cout << "El pais si existe" << endl;
                return true;
            }
            aux = aux->siguiente;
        }
    }
    // cout << "El pais no existe" << endl;
    return false;
}

NodoPais* ListaPais::punteroPais(int codPais) {
    NodoPais *auxPais;
    if (primero== NULL)
        cout << "No hay elementos";  
    else {
        auxPais = primero;
        while(auxPais) {
            if (auxPais->codigoPais == codPais) {
                return auxPais;
            }
            auxPais = auxPais->siguiente;
        }
    }
    return 0;
}


void ListaPais::reportePaises() {
    NodoPais *aux = primero; // Supongo que primerNodo es el puntero al primer elemento de tu lista
    ofstream archivo;
    archivo.open("reportes/Paises.txt", ios::out);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }

    while (aux) {
        archivo << aux->nombre << endl;
        aux = aux->siguiente;
    }

    archivo.close();
}


void ListaPais::cargarPaises() {
    ifstream archivo("Archivos/Paises.txt");
    string line;
    
    while (getline(archivo, line)) {
        stringstream ss(line);
        string temp;
        int idP;
        string name;

        getline(ss, temp, ';');
        idP = stoi(temp);

        getline(ss, name, ';');

        ListaPais::insertar(idP, name);
    }
    archivo.close();
}


bool ListaPais::buscarPais(int id) {
    NodoPais *aux;
    if (primero== NULL)
        cout << "No hay elementos";  
    else {
        aux = primero;
        while(aux) {
            if (aux->codigoPais == id) {
                cout << "Codigo de pais: " << aux->codigoPais << endl;
                cout << "Nombre Pais: " << aux->nombre << endl;
                return true;
            }
            aux = aux->siguiente;
        }
    }
    cout << "El pais no existe" << endl;
    return false;
}

void ListaPais::modificarNombre(int id, string nombre) {
    NodoPais *aux;
    if (primero== NULL)
        cout << "No hay elementos";  
    else {
        aux = primero;
        while(aux) {
            if (aux->codigoPais == id) {
                aux->nombre = nombre;
                cout << "Nombre de pais modificado a: " << nombre << endl;
                return;
            }
            aux = aux->siguiente;
        }
    }
    cout << "El pais no existe" << endl;
    return;
}
