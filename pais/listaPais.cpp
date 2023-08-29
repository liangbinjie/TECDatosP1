#include "listaPais.h"
#include <string>


ListaPais::ListaPais() {
    primero = NULL;
}

ListaPais::~ListaPais() {
    pNodoPais aux;
    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
    primero = NULL;
}

bool ListaPais::listaVacia() {
    return primero == NULL;
}

void ListaPais::insertar(int codPais, string nombre) {
    if (listaVacia()) {
        primero = new NodoPais(codPais, nombre);
    } else {
        if (existePais(codPais)) {
            cout << endl;
        } else {
            pNodoPais aux = primero;
            while (aux->siguiente != NULL) {
                aux = aux->siguiente;
            }
            aux->siguiente = new NodoPais(codPais, nombre);
            aux->siguiente->anterior = aux;
        }
    }
}

void ListaPais::mostrar() {
    NodoPais *aux;
    if (primero== NULL)
        cout << "No hay elementos";  
    else {
        aux = primero;
        while(aux) {
        cout << aux->codigoPais << " : " << aux->nombre << " -> ";
        aux = aux->siguiente;
        }
    cout << endl;
    }
}

void ListaPais::borrarInicio() {
    if (listaVacia()) {
        cout << "No hay paises en la lista" << endl;
    } else {
        if (primero->siguiente == NULL) {
            pNodoPais temp = primero;
            primero = NULL;
            delete temp;
        } else {
            pNodoPais aux = primero;
            primero = primero->siguiente;
            primero->anterior = NULL;
            delete aux;
        }
    }
}

void ListaPais::eliminar(int codPais) {
    if (listaVacia()) {
        cout << "No se puede eliminar, lista vacia" << endl;
    } else {
        pNodoPais aux = primero;
        if (aux->codigoPais == codPais) {
            borrarInicio();
        } else {
            while (aux->codigoPais != codPais) {
                aux = aux->siguiente;
            }
            pNodoPais temp = aux;
            aux = aux->anterior;
            aux->siguiente = temp->siguiente;
            delete temp;
        }
    }
}

bool ListaPais::existePais(int codPais) {
    NodoPais *aux;
    if (primero== NULL)
        cout << "No hay elementos";  
    else {
        aux = primero;
        while(aux) {
            if (aux->codigoPais == codPais) {
                // cout << "El pais si existe" << endl;
                return true;
            }
            aux = aux->siguiente;
        }
    }
    // cout << "El pais no existe" << endl;
    return false;
}

void ListaPais::cargarPaises() {
    string str;
    ifstream archivo;
    archivo.open("Archivos/Paises.txt");
    while (archivo >> str) {
        int cont = 0;
        int idP,idC;
        string name = "", temp;
        for (char& c : str) {
            if (c == ';') {
                if (cont == 0) {
                    idP = stoi(temp);
                }
                temp = "";
                cont++;
            } else {
                temp += c;
            }
        }
        // cout << temp << endl;
        name = temp;
        ListaPais::insertar(idP, name);
    }
    archivo.close();
    str="";
}
