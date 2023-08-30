#include "NodoProducto.h"

NodoProducto::NodoProducto(int cp, int cc, int cr, int cm, int cpr, string n, int k, int p) {
    codPais = cp;
    codCiudad = cc;
    codRest = cr;
    codMenu = cm;
    codProducto = cpr;
    nombre = n;
    kcal = k;
    precio = p;
    siguiente = NULL;
}
    
