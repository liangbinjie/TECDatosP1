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
        void mostrar(int pais);
        void eliminar(int codCiudad);
        bool existeCiudad(int codCiudad);
        void insertar(int codPais, int codCiudad, string nombre, ListaPais& lPaises);
        void borrarInicio();
        void cargarCiudades(ListaPais& lPaises);
};

#endif