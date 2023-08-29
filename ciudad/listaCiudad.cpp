#include "listaCiudad.h"
#include "../pais/listaPais.h"


ListaCiudad::ListaCiudad() {
    primero = NULL;
}

bool ListaCiudad::listaVacia() {
    return primero == NULL;
}

bool ListaCiudad::existeCiudad(int codCiudad) {
    NodoCiudad* aux;
    if (primero == NULL) {
        cout << "No hay elementos";
    } else {
        aux = primero;
        while (aux) {
            if (aux->codigoCiudad == codCiudad) {
                return true;
            }
            aux = aux->siguiente;
        }
    }
    return false;
}

void ListaCiudad::insertar(int codPais, int codCiudad, string nombre, ListaPais& lPaises) {
    if (lPaises.existePais(codPais)) {
        if (listaVacia()) {
            primero = new NodoCiudad(codPais, codCiudad, nombre);
        } else {
            if (existeCiudad(codCiudad)) {
                cout << "Esta ciudad ya existe, no se puede insertar" << endl;
            } else {
                pNodoCiudad aux = primero;
                while (aux->siguiente!=NULL) {
                    aux = aux->siguiente;
                }
                aux->siguiente = new NodoCiudad(codPais, codCiudad, nombre);
                aux->siguiente->anterior = aux;
            }
        }
    } else {
        cout << "Este pais no existe" << endl;
    }
}


void ListaCiudad::mostrar() {
    NodoCiudad *aux;
    if (primero==NULL)
        cout << "No hay elementos";  
    else {
        aux = primero;
        while(aux) {
            cout << aux->codigoPais << " : " << aux->codigoCiudad << " : " << aux->nombre << " -> ";
            aux = aux->siguiente;
        }
    cout << endl;
    }
}

void ListaCiudad::borrarInicio() {
    if (listaVacia()) {
        cout << "Lista vacia" << endl;
    } else {
        if (primero->siguiente == NULL) {
            pNodoCiudad temp = primero;
            primero = NULL;
            delete temp;
        } else {
            pNodoCiudad aux = primero;
            primero = primero->siguiente;
            primero->anterior = NULL;
            delete aux;
        }
    }
}

void ListaCiudad::eliminar(int codCiudad) {
    if (listaVacia()) {
        cout << "No se puede eliminar, lista vacia" << endl;
    } else {
        pNodoCiudad aux = primero;
        if (aux->codigoCiudad == codCiudad) {
            borrarInicio();
        } else {
            while (aux->codigoPais != codCiudad) {
                aux = aux->siguiente;
            }
            pNodoCiudad temp = aux;
            aux = aux->siguiente;
            aux->siguiente->anterior = aux->anterior;
            delete temp;
        }
    }
}

void ListaCiudad::cargarCiudades(ListaPais& lPais) {
    string str;
    ifstream archivo;
    archivo.open("Archivos/Ciudades.txt");
    while (archivo >> str) {
        size_t pos = str.find(';');
        if (pos != string::npos) {
            int idP = std::stoi(str.substr(0, pos));
            int idC = std::stoi(str.substr(pos + 1));
            cout << idP << endl;
            cout << idC << endl;;
            string name = str.substr(pos + 3);
            cout << name << endl;

            ListaCiudad::insertar(idP, idC, name, lPais);
        }
    }
    archivo.close();
    str="";
}