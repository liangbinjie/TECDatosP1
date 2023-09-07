#include "nodoPais.h"

NodoPais::NodoPais(int pCodPais, string pNombre) {
    codigoPais = pCodPais;
    nombre = pNombre;
    siguiente = NULL;
    anterior = NULL;
    ciudadList = NULL;
}

NodoPais::NodoPais(int pCodigoPais, string pNombre, NodoPais *sigNodo) {
    codigoPais = pCodigoPais;
    nombre = pNombre;
    siguiente = sigNodo;
    ciudadList = NULL;
}
