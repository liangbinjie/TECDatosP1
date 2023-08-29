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
        // ~ListaCiudad();

        bool listaVacia();
        void mostrar();
        void eliminar(int codCiudad);
        bool existeCiudad(int codCiudad);
        void insertar(int codPais, int codCiudad, string nombre, ListaPais& lPaises);
};

#endif