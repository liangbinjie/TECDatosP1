#ifndef LISTACLIENTE_H
#define LISTACLIENTE_H

#include <fstream>

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
    void cargarCliente();
    bool buscarCliente(int id);
    void modificarNombre(int id, string nombre);
};

#endif

