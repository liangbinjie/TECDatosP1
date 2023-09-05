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
        void insertar(int codPais, string nombre);
        void mostrar();
        void eliminar(int codPais);
        bool existePais(int codPais);
        void borrarInicio();
        NodoPais* punteroPais(int codPais);
        ListaCiudad* obtenerListaCiudades(int codPais);
        pNodoPais obtenerPrimerNodo();
        void modificarPais(int pCodPaisOriginal, string nombre);
        bool buscarPais(int id);
        void modificarNombre(int id, string nombre);
};

#endif
