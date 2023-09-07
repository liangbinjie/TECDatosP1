#include "NodoCliente.h"

NodoCliente::NodoCliente(int id, string nom) {
    identificacion = id;
    nombre = nom;
    siguiente = NULL;
}

