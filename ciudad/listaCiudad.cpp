#include "listaCiudad.h"
#include "../pais/listaPais.h"


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

void ListaCiudad::insertar(int codPais, int codCiudad, string nombre, ListaPais& lPaises) {
    if (lPaises.existePais(codPais)) {
        cout << "insertando";
        // falta validar si la ciudad existe
        // si existe, no insertar
        // if ....
        pNodoCiudad nuevoNodo = new NodoCiudad(codCiudad, nombre);

        if (listaVacia()) {
            primero = nuevoNodo;
        } else {
            pNodoCiudad aux = primero;
            while (aux->siguiente != NULL) {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevoNodo;
            nuevoNodo->anterior = aux;
        }
        cout << "Nueva ciudad insertada en la lista." << endl;
    } else {
        cout << "No se encontro el pais";
    }
}

void ListaCiudad::mostrar() {
    NodoCiudad *aux;
    if (primero==NULL)
        cout << "No hay elementos";  
    else {
        aux = primero;
        while(aux) {
        cout << aux->codigoCiudad << " : " << aux->nombre << " -> ";
        aux = aux->siguiente;
        }
    cout << endl;
    }
}
/*
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
*/