#ifndef LISTAPRODUCTO_H
#define LISTAPRODUCTO_H

#include <iostream>
using namespace std;

#include "../pais/listaPais.h"
#include "../ciudad/listaCiudad.h"
#include "../restaurant/listaRest.h"
#include "../menuRes/listaMenuRest.h"


#include "NodoProducto.h"
typedef NodoProducto* pNodoProducto;

class ListaProducto {
private:
    ListaProducto* primero;

public:
    ListaProducto();

    void insertar(int codPais, int codCiudad, int codRest, int codMenu, int id, std::string nombre, ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRests, ListaMenuRest& lMenus);
    bool existeProducto(int id);
    void mostrar();
    bool eliminar(int id);
    bool listaVacia();
};

#endif