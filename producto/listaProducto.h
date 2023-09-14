#ifndef LISTAPRODUCTO_H
#define LISTAPRODUCTO_H

#include <iostream>
#include "NodoProducto.h"
#include "../pais/listaPais.h"
#include "../ciudad/listaCiudad.h"
#include "../restaurant/listaRest.h"
#include "../menuRes/listaMenuRest.h"
#include <sstream>
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
        void insertarProducto(int codPais, int codCiudad, int codRest, int codMenu, int codProducto, string nombre, int kcal, int precio, ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRests, ListaMenuRest& lMenus);
        bool existeProducto(int pCodPais, int pCodCiudad, int pCodRes, int pCodMenu, int pCodProducto, ListaPais& lPais, ListaCiudad& lCiudad, ListaRest& lRest, ListaMenuRest& lMenuRest);
        void eliminar(int id);
        void buscarProducto(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, int pCodProducto, ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRest, ListaMenuRest& lMenuRest);
        void mostrar();
        void cargarProductos(ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRests, ListaMenuRest& lMenus);
        void modificarProducto(int codPais, int codCiudad, int codRest, int codMenu, int codProducto, string nombre, int kcal, int precio, ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRests, ListaMenuRest& lMenus);
        void mostrarProductosMenu(int codPais, int codCiudad, int codRest, int codMenu);
        void precio(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, int pCodProducto, ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRest, ListaMenuRest& lMenuRest);
        void productoMasComprado();
        void aumentarCompra(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, int pCodProducto, ListaPais& lPais, ListaCiudad& lCiudad, ListaRest& lRest, ListaMenuRest& lMenuRest );
};

#endif
