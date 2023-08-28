#include "listaPais.h"


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
        pNodoPais aux = primero;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = new NodoPais(codPais, nombre);
        aux->siguiente->anterior = aux;
    }
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
        }
        cout << aux->codigoPais;
        while (aux->codigoPais != codPais) {
            aux = aux->siguiente;
        }
        pNodoPais temp = aux;
        aux = aux->siguiente;
        aux->siguiente->anterior = aux->anterior;
        delete temp;
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
                cout << "El pais si existe" << endl;
                return true;
            }
            aux = aux->siguiente;
        }
        
    }
    cout << "El pais no existe";
    return false;
}
