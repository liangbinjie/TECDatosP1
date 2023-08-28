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
/*
   void ListaCiudad::insertar(int codPais, int codCiudad, string nombre) {
    pNodoPais auxP = primero;
    while (auxP->siguiente != NULL) {
        if (auxP->codigoPais == codPais) {

            if (listaVacia()) {
                primero = new NodoCiudad(codPais, codCiudad, nombre);
            } else {
                pNodoCiudad auxC = primero;
                 while (auxC->siguiente != NULL) {
                    if (auxC->codigoCiudad == codCiudad) {
                        cout << "La ciudad ya existe" ;
                        break;
                    }
                    else{
                     auxC = auxC->siguiente;
                 }
                 }
                 auxC->siguiente = new NodoCiudad(codPais, codCiudad, nombre);\
                 auxC->siguiente->anterior = auxC;
                    
    }


            return aux; // Se encontró el país con el código especificado
        }
        aux = aux->siguiente;



    aux = aux->siguiente;
    }
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

*/

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