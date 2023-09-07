#include "NodoProducto.h"

NodoProducto::NodoProducto(int cp, int cc, int cr, int cm, int cpro, string pNombre, int kc, int p) {
    codPais = cp;
    codCiudad = cc;
    codRest = cr;
    codMenu = cm;
    codProducto = cpro;
    nombre = pNombre;
    kcal = kc;
    precio = p;
    siguiente = NULL;
}

NodoProducto::NodoProducto(int cp, int cc, int cr, int cm, int cpro, string pNombre, int kc, int p, NodoProducto* sigNodo) {
    codPais = cp;
    codCiudad = cc;
    codRest = cr;
    codMenu = cm;
    codProducto = cpro;
    nombre = pNombre;
    kcal = kc;
    precio = p;
    siguiente = sigNodo;
}
