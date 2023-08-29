#include "listaCiudad.h"
#include "../pais/listaPais.h"


ListaCiudad::ListaCiudad() {
    primero = NULL;
}

bool ListaCiudad::listaVacia() {
    return primero == NULL;
}

bool ListaCiudad::existeCiudad(int codCiudad) {
    NodoCiudad* aux;
    if (primero == NULL) {
        cout << "No hay elementos";
    } else {
        aux = primero;
        while (aux) {
            if (aux->codigoCiudad == codCiudad) {
                return true;
            }
        }
    }
    return false;
}

void ListaCiudad::insertar(int codPais, int codCiudad, string nombre, ListaPais& lPaises) {
    if (lPaises.existePais(codPais)) {
        if (listaVacia()) {
            primero = new NodoCiudad(codPais, codCiudad, nombre);
        } else {
            if (existeCiudad(codCiudad)) {
                cout << "Esta ciudad ya existe, no se puede insertar";
            } else {
                pNodoCiudad aux = primero;
                while (aux->siguiente!=NULL) {
                    aux = aux->siguiente;
                }
                aux->siguiente = new NodoCiudad(codPais, codCiudad, nombre);
                aux->siguiente->anterior = aux;
            }
        }
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