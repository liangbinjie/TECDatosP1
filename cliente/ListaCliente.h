#ifndef LISTACLIENTE_H
#define LISTACLIENTE_H

#include "NodoCliente.h"

class ListaCliente {
private:
    NodoCliente* primero;

public:
    ListaCliente();

    void insertar(int id, std::string nombre);
    bool existeCliente(int id);
    void mostrar();
    bool eliminar(int id);
};

#endif
