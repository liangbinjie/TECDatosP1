#include "nodoCiudad.h"

NodoCiudad::NodoCiudad(int pCodigoCiudad, string pNombre) {
    codigoCiudad= pCodigoCiudad;
    nombre = pNombre;
    siguiente = NULL;
    anterior = NULL;
}

NodoCiudad::NodoCiudad(int pCodigoCiudad, string pNombre, NodoCiudad *sigNodo) {
    codigoCiudad= pCodigoCiudad;
    nombre = pNombre;
    siguiente = sigNodo;
}