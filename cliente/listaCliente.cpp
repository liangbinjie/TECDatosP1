#include "listaCliente.h"
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
        cout << "Se elimino el cliente" << endl; 
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
        cout << "Se elimino el cliente" << endl; 
        return true;
    }

    cout << "No se pudo eliminar el cliente" << endl;
    return false;
}

void ListaCliente::cargarCliente() {
    string str;
    ifstream archivo;
    archivo.open("Archivos/Clientes.txt");
    while (archivo >> str) {
        int cont = 0;
        int id;
        string name = "", temp;
        for (char& c : str) {
            if (c == ';') {
                if (cont == 0) {
                    id = stoi(temp);
                }
                temp = "";
                cont++;
            } else {
                temp += c;
            }
        }
        name = temp;
        ListaCliente::insertar(id, name);
    }
    archivo.close();
    str="";
}

bool ListaCliente::buscarCliente(int id) {
    NodoCliente* temp = primero;
    while (temp) {
        if (temp->identificacion == id) {
            cout << "Nombre: " << temp->nombre << endl;
            return true;
        }
        temp = temp->siguiente;
    }
    cout << "No se encontro el cliente" << endl;
    return false;
}

void ListaCliente::modificarNombre(int id, string nombre) {
    NodoCliente* temp = primero;
    while (temp) {
        if (temp->identificacion == id) {
            temp->nombre = nombre;
            cout << "Nombre modificado a " << nombre;
            return;
        }
        temp = temp->siguiente;
    }
    cout << "No se encontro el cliente" << endl;
}
