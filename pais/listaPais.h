#ifndef LISTAPAIS_H
#define LISTAPAIS_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "nodoPais.h"
typedef NodoPais* pNodoPais;

class ListaPais {
    private:
        pNodoPais primero;
        friend class ListaCiudad;

    public:
        ListaPais();
        ~ListaPais();

        void cargarPaises();
        bool listaVacia();
        void insertarP(int codPais, string nombre);
        void mostrar();
        void eliminar(int codPais);
        bool existePais(int codPais);
        void borrarInicio();
        ListaCiudad* obtenerListaCiudades(int codPais);
        pNodoPais obtenerPrimerNodo();
};

#endif
