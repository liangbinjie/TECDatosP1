#include "nodoRest.h"

NodoRest::NodoRest(int pCodPais, int pCodCiudad, int pCodRest, string pNombre) {
    codigoPais = pCodPais;
    codCiudad = pCodCiudad;
    codRest = pCodRest;
    nombre = pNombre;
    siguiente = NULL;
    anterior = NULL;
    contador = 0;
}

NodoRest::NodoRest(int pCodPais, int pCodCiudad, int pCodRest, string pNombre, NodoRest* sigNodo) {
    codigoPais = pCodPais;
    codCiudad = pCodCiudad;
    codRest = pCodRest;
    nombre = pNombre;
    contador = 0;
    siguiente = sigNodo;
}
