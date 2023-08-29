#include "listaRest.h"

ListaRest::ListaRest() {
    primero = NULL;
}

bool ListaRest::listaVacia() {
    return primero == NULL;
}

bool ListaRest::existeRest(int pCodRest) {
    NodoRest *aux;
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        aux = primero->siguiente;
        while (aux!=primero) {
            if (aux->codRest == pCodRest) {
                return true;
            }
            aux = aux->siguiente;
        }
    }
    return false;
}

void ListaRest::insertar(int codPais, int codCiudad, int codRest, string nombre, ListaPais& lPaises, ListaCiudad& lCiudades) {
    if ((lPaises.existePais(codPais)) && (lCiudades.existeCiudad(codCiudad))) { // verificar que la ciudad este en el mismo pais
        if (!existeRest(codRest)) {
            if (listaVacia()) {
                primero = new NodoRest(codPais, codCiudad, codRest, nombre);
                primero->anterior=primero;
                primero->siguiente=primero;
            } else {
                pNodoRest nuevo = new NodoRest(codPais, codCiudad, codRest, nombre);
                nuevo->anterior = primero->anterior;
                nuevo->siguiente = primero;
                primero->anterior->siguiente = nuevo;
                primero->anterior = nuevo;
            }
            cout << "Restaurante nuevo insertado" << endl;
        } else {
            cout << "Este restaurante ya existe" << endl;;
        }
    } else {
        cout << "No se puede agregar porque la ciudad o pais estan mal" << endl;
    }
}

void ListaRest::mostrar() {
    pNodoRest aux = primero;
    while (aux->siguiente!=primero) {
        cout << aux->codRest << " : " << aux->nombre << " -> ";
        aux = aux->siguiente;
    }
    cout << aux->codRest << " : " << aux->nombre << " -> " << endl;
}

void ListaRest::borrarInicio() {
    if (listaVacia()) {
        cout << "No hay elementos en la lista";
    } else {
        if (primero->siguiente == primero) {
            pNodoRest temp = primero;
            primero = NULL;
            delete temp;
        } else {
            pNodoRest aux = primero->anterior;
            pNodoRest temp = primero;
            aux->siguiente = primero->siguiente;
            primero = primero->siguiente;
            primero->anterior = aux;
            delete temp;
        }
    }
}

void ListaRest::eliminar(int pCodRest) {
    if (listaVacia()) {
        cout << "Lista vacia" << endl;
    } else {
        pNodoRest aux = primero;
        if (aux->codRest == pCodRest) {
            borrarInicio();
        } else {
            while (aux->siguiente!=primero && aux->codRest != pCodRest) {
                aux = aux->siguiente;
            }
            pNodoRest temp = aux;
            aux->anterior->siguiente = aux->siguiente;
            aux->siguiente->anterior = aux->anterior;
            delete temp;
        }
    }
}

// void ListaRest::cargarRests() {

// }