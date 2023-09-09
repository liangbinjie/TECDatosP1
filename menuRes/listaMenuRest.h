#ifndef LISTAMENUREST_H
#define LISTAMENUREST_H

#include <iostream>
using namespace std;

#include "../pais/listaPais.h"
#include "../ciudad/listaCiudad.h"
#include "../restaurant/listaRest.h"

#include "nodoMenuRest.h"
#include <sstream>
typedef NodoMenuRest* pNodoMenuRest;
class ListaMenuRest {
    private:
        pNodoMenuRest primero;
        friend class ListaPais;

    public:
        ListaMenuRest();

        bool listaVacia();
        void mostrar();
        void eliminar(int codMenu, int codPais, int codCiudad, int codRest);
        bool existeMenuRest(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenuRest, ListaPais& lPais, ListaCiudad& lCiudad, ListaRest& lRest);
        void insertarMenuRest(int codPais, int codCiudad, int codRest, int codMenuRest, string nombre, ListaPais& lPais, ListaCiudad& lCiudad, ListaRest& lRest);
        void borrarInicio();
        NodoMenuRest* punteroMenu(int pcodMenu);
        void buscarMenuRest(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRest);
        void cargarMenuRest(ListaPais& lPais, ListaCiudad& lCiudad, ListaRest& lRest);
        void modificarMenu(int codPais, int codCiudad, int codRest, string name, int codMenu);
};

#endif
