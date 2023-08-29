#include "listaMenuRest.h"
#include "../pais/listaPais.h"


ListaMenuRest::ListaMenuRest(ListaPais& listaPaises): primero(NULL), listaPaises(listaPaises) {
  
}

bool ListaMenuRest::listaVacia() {
    return primero == NULL;
}

bool ListaMenuRest::existeCiudad(int codCiudad) {
    NodoMenuRest* aux;
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

void ListaMenuRest::insertar(int codPais, int codCiudad, codRest, codMenuRest, string nombre, ListaPais& lPaises) {
    if (lPaises.existePais(codPais)) {
        if (listaVacia()) {
            primero = new NodoMenuRest(codPais, codCiudad, codRest, codMenuRest, nombre);
        } else {
            if (existeCiudad(codCiudad)) {
                cout << "Esta ciudad ya existe, no se puede insertar" << endl;
            } else {
                pNodoMenuRest aux = primero;
                while (aux->siguiente!=NULL) {
                    aux = aux->siguiente;
                }
                aux->siguiente = new NodoMenuRest(codPais, codCiudad, nombre);
                aux->siguiente->anterior = aux;
            }
        }
    } else {
        cout << "Este pais no existe" << endl;
    }
}


void ListaMenuRest::mostrar() {
    NodoMenuRest *aux;
    if (primero==NULL)
        cout << "No hay elementos";  
    else {
        aux = primero;
        while(aux) {
        cout << aux->codigoCiudad << " : " << aux->nombre << " -> ";
        aux = aux->siguiente;
        }
    cout << endl;
    }
}

void ListaMenuRest::borrarInicio() {
    if (listaVacia()) {
        cout << "Lista vacia" << endl;
    } else {
        if (primero->siguiente == NULL) {
            pNodoMenuRest temp = primero;
            primero = NULL;
            delete temp;
        } else {
            pNodoMenuRest aux = primero;
            primero = primero->siguiente;
            primero->anterior = NULL;
            delete aux;
        }
    }
}

void ListaMenuRest::eliminar(int codCiudad) {
    if (listaVacia()) {
        cout << "No se puede eliminar, lista vacia" << endl;
    } else {
        pNodoMenuRest aux = primero;
        if (aux->codigoCiudad == codCiudad) {
            borrarInicio();
        } else {
            while (aux->codigoPais != codCiudad) {
                aux = aux->siguiente;
            }
            pNodoMenuRest temp = aux;
            aux = aux->siguiente;
            aux->siguiente->anterior = aux->anterior;
            delete temp;
        }
    }
}

void ListaMenuRest::cargarCiudades(ListaPais& lPais) {
    string str;
    ifstream archivo;
    archivo.open("Archivos/Ciudades.txt");
    while (archivo >> str) {
        size_t pos = str.find(';');
        if (pos != string::npos) {
            int idP = std::stoi(str.substr(0, pos));
            int idC = std::stoi(str.substr(1, pos));
            string name = str.substr(pos + 2);

            ListaMenuRest::insertar(idP, idC, name, lPais);
        }
    }
    archivo.close();
    str="";
}
