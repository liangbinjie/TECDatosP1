#include "nodoRest.h"

NodoRest::NodoRest(int pCodPais, int pCodCiudad, int pCodRest, string pNombre) {
    codigoPais = pCodPais;
    codCiudad = pCodCiudad;
    codRest = pCodRest;
    nombre = pNombre;
    siguiente = NULL;
    anterior = NULL;
}

NodoRest::NodoRest(int pCodPais, int pCodCiudad, int pCodRest, string pNombre, NodoRest* sigNodo) {
    codigoPais = pCodPais;
    codCiudad = pCodCiudad;
    codRest = pCodRest;
    nombre = pNombre;
    siguiente = sigNodo;
}