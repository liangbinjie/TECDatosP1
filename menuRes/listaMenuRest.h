#ifndef LISTAMENUREST_H
#define LISTAMENUREST_H

#include <iostream>
using namespace std;

#include "../pais/listaPais.h"

#include "nodoMenuRest.h"
typedef NodoMenuRest* pNodoMenuRest;
class ListaMenuRest {
    private:
        pNodoMenuRest primero;
        friend class ListaPais;

    public:
        ListaMenuRest();

        bool listaVacia();
        void mostrar();
        void eliminar(int codCiudad);
        bool existeMenuRest(int codMenuRest);
        void insertarRest(int codPais, int codCiudad, int codRest, int codMenuRest, string nombre, ListaPais& lPaises);
        void borrarInicio();
        void cargarCiudades(ListaPais& lPaises);
};

#endif