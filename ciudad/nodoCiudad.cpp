#include "nodoCiudad.h"

NodoCiudad::NodoCiudad(int pCodPais, int pCodigoCiudad, string pNombre) {
    codigoPais = pCodPais;
    codigoCiudad= pCodigoCiudad;
    nombre = pNombre;
    siguiente = NULL;
    anterior = NULL;
}

NodoCiudad::NodoCiudad(int pCodigoPais, int pCodigoCiudad, string pNombre, NodoCiudad *sigNodo) {
    codigoPais = pCodigoPais;
    codigoCiudad= pCodigoCiudad;
    nombre = pNombre;
    siguiente = sigNodo;
}