#ifndef NODOPAIS_H
#define NODOPAIS_H

#include <iostream>
using namespace std;
class ListaCiudad;
class NodoPais {
    private:
        int codigoPais;
        string nombre;
        NodoPais *siguiente;
        NodoPais *anterior;
        ListaCiudad *ciudadList;
        friend class ListaPais;
        friend class ListaCiudad;
        
    public:
        NodoPais(int codigo, string nombre);
        NodoPais(int codigo, string nombre, NodoPais *sigNodo);
};

#endif