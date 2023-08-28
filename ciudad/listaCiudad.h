#ifndef LISTACIUDAD_H
#define LISTACIUDAD_H

#include <iostream>
using namespace std;

#include "nodoCiudad.h"
typedef NodoCiudad* pNodoCiudad;
class ListaPais;
class ListaCiudad {
    private:
        pNodoCiudad primero;
        ListaPais& listaPaises;
        friend class ListaPais;

    public:
        ListaCiudad(ListaPais& listaPaises);
        ~ListaCiudad();

        bool listaVacia();
        void insertarEnLista(int codPais, int codCiudad, string nombre);
        void mostrar();
        void eliminar(int codPais);
        bool existePais(int codPais);
        void insertarCiudad(int codCiudad, string nombre);
};

#endif