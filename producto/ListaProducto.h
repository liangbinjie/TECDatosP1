#ifndef LISTAPRODUCTO_H
#define LISTAPRODUCTO_H

#include <iostream>
#include "NodoProducto.h"
#include "../pais/listaPais.h"
#include "../ciudad/listaCiudad.h"
#include "../restaurant/listaRest.h"
#include "../menuRes/listaMenuRest.h"
using namespace std;
#include <fstream>

typedef NodoProducto *pNodoProducto;

class ListaProducto {
    private:
        pNodoProducto primero;
    
    public:
        ListaProducto();
        // ListaProducto()

        bool listaVacia();
        void insertar(int codPais, int codCiudad, int codRest, int codMenu, int codProducto, string nombre, int kcal, int precio, ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRests, ListaMenuRest& lMenus);
        bool existeProducto(int id);
        void eliminar(int id);
        void mostrar();
        void cargarProductos(ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRests, ListaMenuRest& lMenus);
};

#endif