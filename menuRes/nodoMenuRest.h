#ifndef NODOMENUREST_H
#define NODOMENUREST_H

#include <iostream>
using namespace std;

class NodoMenuRest {
    private:
        int codigoPais;
        int codCiudad;
        int codRest;
        int codMenuRest;
        int contador;
        string nombre;
        NodoMenuRest *siguiente;
        NodoMenuRest *anterior;
        
        friend class ListaMenuRest;
        friend class ListaProducto;
        

    public:
        NodoMenuRest(int pCodPais, int pCodCiudad, int pCodRest, int codMenuRest, string nombre);
        NodoMenuRest(int pCodPais, int pCodCiudad, int pCodRest, int codMenuRest, string nombre, NodoMenuRest* sigNodo);
};

#endif
