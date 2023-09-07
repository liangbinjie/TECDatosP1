#include "nodoCiudad.h"

NodoCiudad::NodoCiudad(int pcodPais, int pCodigoCiudad, string pNombre) {
    codigoPais = pcodPais;
    codigoCiudad= pCodigoCiudad;
    nombre = pNombre;
    siguiente = NULL;
    anterior = NULL;
}

NodoCiudad::NodoCiudad(int pcodPais, int pCodigoCiudad, string pNombre, NodoCiudad *sigNodo) {
    codigoPais = pcodPais;
    codigoCiudad= pCodigoCiudad;
    nombre = pNombre;
    siguiente = sigNodo;
}
