#ifndef LISTACIUDAD_H
#define LISTACIUDAD_H

#include <iostream>
using namespace std;

#include "nodoCiudad.h"
typedef NodoCiudad* pNodoCiudad;

class ListaCiudad {
    private:
        pNodoCiudad primero;

    public:
        ListaCiudad();
        ~ListaCiudad();

        bool listaVacia();
        void insertar(int codPais, int codCiudad, string nombre);
        void mostrar();
        void eliminar(int codPais);
        bool existePais(int codPais);
};

#endif