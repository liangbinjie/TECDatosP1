#ifndef NODOPAIS_H
#define NODOPAIS_H

#include <iostream>
using namespace std;

class NodoPais {
    private:
        int codigoPais;
        string nombre;
        NodoPais *siguiente;
        NodoPais *anterior;
        friend class ListaPais;
        
    public:
        NodoPais(int codigo, string nombre);
        NodoPais(int codigo, string nombre, NodoPais *sigNodo);
};

#endif