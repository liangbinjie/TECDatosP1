#ifndef LISTAPAIS_H
#define LISTAPAIS_H

#include <iostream>
#include <fstream>
using namespace std;

#include "nodoPais.h"
typedef NodoPais* pNodoPais;

class ListaPais {
    private:
        pNodoPais primero;

    public:
        ListaPais();
        ~ListaPais();

        void cargarPaises();
        bool listaVacia();
        void insertar(int codPais, string nombre);
        void mostrar();
        void eliminar(int codPais);
        bool existePais(int codPais);
        void borrarInicio();
};

#endif
