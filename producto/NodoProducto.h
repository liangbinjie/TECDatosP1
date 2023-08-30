#ifndef NODOPRODUCTO_H
#define NODOPRODUCTO_H

#include <iostream>
#include <string>
using namespace std;

class NodoProducto {
private:
    int codPais;
    int codCiudad;
    int codRest;
    int codMenu;
    int codProducto;
    string nombre;
    int kcal;
    int precio;
    NodoProducto* siguiente;
    friend class ListaProducto;

public:
    NodoProducto(int cp, int cc, int cr, int cm, int cpr, string n, int k, int p);
    
};

#endif
