#ifndef LISTACIUDAD_H
#define LISTACIUDAD_H

#include <iostream>
using namespace std;

#include "../pais/listaPais.h"

#include "nodoCiudad.h"
typedef NodoCiudad* pNodoCiudad;
class ListaCiudad {
    private:
        pNodoCiudad primero;
        friend class ListaPais;

    public:
        ListaCiudad();
        ~ListaCiudad();

        bool listaVacia();
        void mostrar();
        void eliminar(int codPais); // cambiar a ciudad
        bool existePais(int codPais); // cambiar a ciudad
        void insertar(int codPais, int codCiudad, string nombre, ListaPais& lPaises);
};

#endif