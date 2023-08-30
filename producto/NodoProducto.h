#ifndef NODOPRODUCTO_H
#define NODOPRODUCTO_H

#include <iostream>
using namespace std;

class NodoProducto {
    private:
        NodoProducto* siguiente;
        int codPais;
        int codCiudad;
        int codRest;
        int codMenu;
        int codProducto;
        string nombre;
        int kcal;
        int precio;

        friend class ListaProducto;
    
    public:
        NodoProducto(int cp, int cc, int cr, int cm, int cpro, string nombre, int kc, int p);
        NodoProducto(int cp, int cc, int cr, int cm, int cpro, string nombre, int kc, int p, NodoProducto* sigNodo);
};

#endif