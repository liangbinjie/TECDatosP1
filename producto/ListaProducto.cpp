#include "ListaProducto.h"
#include <iostream>

ListaProducto::ListaProducto() {
    primero = NULL;
}

void ListaProducto::insertar(int codPais, int codCiudad, int codRest, int codMenu, int id, std::string nombre, ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRests, ListaMenuRes& lMenus) {
    // if lPaises.existePais(codPais) && lCiudades.existeCiudad(codCiudad)
    // if lRests.existeRest(codRest) && lMenus.existeMenu(codMenu)
    if (listaVacia()) {
        primero = new NodoProducto(codPais, codCiudad, codRest, codMenu, id, nombre);
    } else {

    }
}

bool ListaProducto::existeProducto(int id) {
    if (listaVacia()) {
        cout << "Lista vacia";
    } else {
        NodoProducto* aux = primero;
        while (aux) {
            if (aux->codProducto == id) {
                return true;
            }
            aux = aux->siguiente;
        }
    }
    return false;
}

bool ListaProducto::listaVacia() {
    return primero == NULL;
}

void ListaProducto::mostrar() {
    NodoProducto* aux;
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        aux = primero;
        while (aux) {
            cout << aux->codProducto << " : " << aux->nombre << " : " aux->kcal " : $" << aux->precio << endl;
            aux = aux->siguiente;
        }
        cout << endl;
    }
}

ListaProducto::eliminar(int id) {
    if (listaVacia()) {
        cout << "Lista vacia";
    } else {
        NodoProducto* aux = primero;
        if (aux->codProducto == id) {
            pNodoProducto temp = primero;
            primero = primero->siguiente;
            delete temp;
        } else {
            aux = aux->siguiente;
            while(aux && aux->codProducto!=id) {
                aux = aux->siguiente;
            }
            pNodoProducto temp = aux->siguiente;
            aux->siguiente = aux->siguiente->siguiente;
            delete temp;
        }
    }
}

