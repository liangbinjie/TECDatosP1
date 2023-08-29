#include "nodoMenuRest.h"

NodoMenuRest::NodoMenuRest(int pCodPais, int pCodCiudad, int pCodRest, int pcodMenuRest, string pnombre) {
    codigoPais = pCodPais;
    codCiudad = pCodCiudad;
    codRest = pCodRest;
    codMenuRest = pcodMenuRest;
    nombre = pnombre;
    siguiente = NULL;
    anterior = NULL;
}

NodoMenuRest::NodoMenuRest(int pCodPais, int pCodCiudad, int pCodRest, int pcodMenuRest, string pnombre, NodoMenuRest* sigNodo) {
    codigoPais = pCodPais;
    codCiudad = pCodCiudad;
    codRest = pCodRest;
    codMenuRest = pcodMenuRest;
    nombre = pnombre;
    siguiente = sigNodo;
}