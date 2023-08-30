#include "ListaProducto.h"
#include "../pais/ListaPais.h"
#include "../ciudad/ListaCiudad.h"
#include "../restaurant/ListaRest.h"
#include "../menuRes/listaMenuRest.h"
#include <iostream>

ListaProducto::ListaProducto() {
    primero = NULL;
}

bool ListaProducto::existeProducto(int id) {
    cout << "Hola";
    pNodoProducto aux = primero;
    while (aux) {
        if (aux->codProducto == id) {
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
}