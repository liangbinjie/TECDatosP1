#ifndef NODOCLIENTE_H
#define NODOCLIENTE_H

#include <string>
#include <iostream>
using namespace std;

class NodoCliente {
private:
    int identificacion;
    string nombre;
    NodoCliente* siguiente;

    friend class ListaCliente;

public:
    NodoCliente(int id, string nom);
};

#endif
