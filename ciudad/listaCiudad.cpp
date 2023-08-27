#include "listaCiudad.h"


ListaCiudad::ListaCiudad() {
    primero = NULL;
}

ListaCiudad::~ListaCiudad() {
    pNodoCiudad aux;
    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
    primero = NULL;
}

bool ListaCiudad::listaVacia() {
    return primero == NULL;
}

void ListaCiudad::insertar(int codPais, int codCiudad, string nombre) {
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

void ListaCiudad::mostrar() {
    NodoCiudad *aux;
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

void ListaCiudad::eliminar(int codPais) {
    if (listaVacia()) {
        cout << "No se puede eliminar, lista vacia" << endl;
    } else {
        pNodoPais aux = primero;
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