#ifndef NODOREST_H
#define NODOREST_H

#include <iostream>
using namespace std;

class NodoRest {
    private:
        int codigoPais;
        int codCiudad;
        int codRest;
        int contador;
        string nombre;
        NodoRest *siguiente;
        NodoRest *anterior;
        
        friend class ListaRest;
        friend class ListaMenuRest;
        friend class ListaProducto;

    public:
        NodoRest(int pCodPais, int pCodCiudad, int pCodRest, string nombre);
        NodoRest(int pCodPais, int pCodCiudad, int pCodRest, string nombre, NodoRest* sigNodo);
};

#endif
