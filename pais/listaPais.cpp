#include "listaPais.h"
#include "../ciudad/listaCiudad.h"


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

pNodoPais ListaPais::obtenerPrimerNodo() {
    return primero;
}

void ListaPais::insertarP(int codPais, string nombre) {
    if (listaVacia()) {
        primero = new NodoPais(codPais, nombre);
    } else {
        if (existePais(codPais)) {
            cout << "Este pais ya existe" << endl;
        } else {
            pNodoPais aux = primero;
            while (aux->siguiente != NULL) {
                aux = aux->siguiente;
            }
            aux->siguiente = new NodoPais(codPais, nombre);
            aux->siguiente->anterior = aux;
            cout << "Nuevo pais insertado" << endl;
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

ListaCiudad* ListaPais::obtenerListaCiudades(int codPais) {
    pNodoPais aux = primero;
    while (aux != nullptr) {
        if (aux->codigoPais == codPais) {
            return aux->ciudadList; // Devuelve el puntero a la lista de ciudades
        }
        aux = aux->siguiente;
    }
    return nullptr; // Si no se encuentra el país
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
        size_t pos = str.find(';');
        if (pos != string::npos) {
            int id = std::stoi(str.substr(0, pos));
            string name = str.substr(pos + 1);

            ListaPais::insertarP(id,name);
        }
    }
    archivo.close();
    str="";
}
