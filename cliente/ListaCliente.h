#ifndef LISTACLIENTE_H
#define LISTACLIENTE_H

#include "NodoCliente.h"
#include <fstream>

class ListaCliente {
private:
    NodoCliente* primero;

public:
    ListaCliente();

    void insertar(int id, std::string nombre);
    bool existeCliente(int id);
    void mostrar();
    bool eliminar(int id);
    void cargarCliente();
};

#endif
