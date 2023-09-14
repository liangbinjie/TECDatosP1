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
    cout << endl;
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
    ifstream archivo("Archivos/Clientes.txt");
    string line;
    
    while (getline(archivo, line)) {
        stringstream ss(line);
        string temp;
        int id;
        string name;

        getline(ss, temp, ';');
        id = stoi(temp);

        getline(ss, name, ';');

        ListaCliente::insertar(id, name);
    }
    archivo.close();
}

bool ListaCliente::buscarCliente(int id) {
    NodoCliente* temp = primero;
    while (temp) {
        if (temp->identificacion == id) {
            cout << "Identificacion: " << temp->identificacion << endl;
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
            cout << "Nombre modificado a " << nombre << endl;
            return;
        }
        temp = temp->siguiente;
    }
    cout << "No se encontro el cliente" << endl;
}

void ListaCliente::reporteClientes() {
    ofstream archivo;
    archivo.open ("reportes/clientes.txt");
    NodoCliente* temp = primero;
    while (temp) {
        archivo << "Identificacion: " << temp->identificacion << endl;
        archivo << "Nombre: " << temp->nombre << endl;
        archivo << "----------------\n"; 
        temp = temp->siguiente;
    }
    archivo.close();
}