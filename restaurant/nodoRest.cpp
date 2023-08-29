#include "nodoRest.h"

NodoRest::NodoRest(int pCodPais, int pCodCiudad, int pCodRest) {
    codigoPais = pCodPais;
    codCiudad = pCodCiudad;
    codRest = pCodRest;
    siguiente = NULL;
    anterior = NULL;
}

NodoRest::NodoRest(int pCodPais, int pCodCiudad, int pCodRest, NodoRest* sigNodo) {
    codigoPais = pCodPais;
    codCiudad = pCodCiudad;
    codRest = pCodRest;
    siguiente = sigNodo;
}