#ifndef LISTACIUDAD_H
#define LISTACIUDAD_H

#include <iostream>
using namespace std;

#include "../pais/listaPais.h"

#include "nodoCiudad.h"
#include <sstream>
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
        bool existeCiudad(int codPais, int codCiudad, ListaPais& lPaises);
        void insertar(int codPais, int codCiudad, string nombre, ListaPais& lPaises);
        void borrarInicio();
        NodoCiudad* punteroCiudad(int codCiudad, int codPais);
        void cargarCiudades(ListaPais& lPaises);
        void mostrarDeUnPais(int pais); // funcion para mostrar las ciudades de un pais en especifico
        void eliminarCiudades(int pais);
        void modificarCiudad(int pais, int ciudad, string nombe,ListaPais& lPaises);
        void buscarCiudad(int idPais, int idCiudad);
};

#endif
