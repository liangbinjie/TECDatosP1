#ifndef NODOCIUDAD_H
#define NODOCIUDAD_H

#include <iostream>
using namespace std;

class NodoCiudad {
    private:
        int codigoPais;
        int codigoCiudad;
        string nombre;
        NodoCiudad *siguiente;
        NodoCiudad *anterior;
        friend class ListaCiudad;
        
    public:
        NodoCiudad(int codPais, int pCodCiudad, string nombre);
        NodoCiudad(int codPais, int codigoCiudad, string nombre, NodoCiudad *sigNodo);
};

#endif