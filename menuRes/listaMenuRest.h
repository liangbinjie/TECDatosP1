#ifndef LISTAMENUREST_H
#define LISTAMENUREST_H

#include <iostream>
using namespace std;

#include "../pais/listaPais.h"
#include "../ciudad/listaCiudad.h"
#include "../restaurant/listaRest.h"

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
        bool existeMenuRest(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenuRest, ListaCiudad& lCiudad, ListaPais& lPais, ListaRest& lRest);
        void insertarMenuRest(int codPais, int codCiudad, int codRest, int codMenuRest, string nombre, ListaPais& lPaises, ListaCiudad& lCiudad, ListaRest& lRest);
        void borrarInicio();
        void cargarMenuRest(ListaPais& lPais, ListaCiudad& lCiudad, ListaRest& lRest);
};

#endif