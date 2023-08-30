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
        bool existeCiudad(int codPais, int codCiudad, ListaPais& lPaises);
        void insertar(int codPais, int codCiudad, string nombre, ListaPais& lPaises);
        void borrarInicio();
        void cargarCiudades(ListaPais& lPaises);
        void mostrarDeUnPais(int pais); // funcion para mostrar las ciudades de un pais en especifico
        void eliminarCiudades(int pais);
};

#endif