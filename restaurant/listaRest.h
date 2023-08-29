#ifndef LISTAREST_H
#define LISTAREST_H

#include <iostream>

#include "../pais/listaPais.h"
#include "../ciudad/listaCiudad.h"

#include "nodoRest.h"
typedef NodoRest* pNodoRest;

class ListaRest {

    private:
        pNodoRest primero; 
    public:
        ListaRest();

        void insertar(int codPais, int codCiudad, int codRest, string nombre, ListaPais& lPaises, ListaCiudad& lCiudades);
        bool listaVacia();
        void mostrar();
        bool existeRest(int pCodRest);
        void eliminar(int codRest);
        void borrarInicio();
        void cargarRests();
};

#endif