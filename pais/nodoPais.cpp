#include "nodoPais.h"

NodoPais::NodoPais(int pCodPais, string pNombre) {
    codigoPais = pCodPais;
    nombre = pNombre;
    siguiente = NULL;
    anterior = NULL;
}

NodoPais::NodoPais(int pCodigoPais, string pNombre, NodoPais *sigNodo) {
    codigoPais = pCodigoPais;
    nombre = pNombre;
    siguiente = sigNodo;
}