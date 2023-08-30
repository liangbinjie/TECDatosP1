#include "ListaCliente.h"
#include <iostream>

ListaCliente::ListaCliente() {
    primero = NULL;
}

void ListaCliente::insertar(int id, std::string nombre) {
    if (existeCliente(id)) {
        std::cout << "Cliente con identificacion " << id << " ya existe. No se ha insertado." << std::endl;
        return;
    }

    NodoCliente* nuevoNodo = new NodoCliente(id, nombre);
    if (!primero) {
        primero = nuevoNodo;
    } else {
        NodoCliente* temp = primero;
        while (temp->siguiente) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

bool ListaCliente::existeCliente(int id) {
    NodoCliente* temp = primero;
    while (temp) {
        if (temp->identificacion == id) {
            return true;
        }
        temp = temp->siguiente;
    }
    return false;
}

void ListaCliente::mostrar() {
    NodoCliente* temp = primero;
    while (temp) {
        std::cout << "Identificacion: " << temp->identificacion << ", Nombre: " << temp->nombre << std::endl;
        temp = temp->siguiente;
    }
}

bool ListaCliente::eliminar(int id) {
    if (!primero) {
        return false;
    }
    
    if (primero->identificacion == id) {
        NodoCliente* temp = primero;
        primero = primero->siguiente;
        delete temp;
        return true;
    }

    NodoCliente* temp = primero;
    while (temp->siguiente && temp->siguiente->identificacion != id) {
        temp = temp->siguiente;
    }

    if (temp->siguiente) {
        NodoCliente* nodoEliminar = temp->siguiente;
        temp->siguiente = nodoEliminar->siguiente;
        delete nodoEliminar;
        return true;
    }

    return false;
}
