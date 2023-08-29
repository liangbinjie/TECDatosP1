#include "listaMenuRest.h"
#include "../pais/listaPais.h"
#include "../ciudad/listaCiudad.h"
#include "../menuRes/listaMenuRest.h"

ListaMenuRest::ListaMenuRest(ListaPais& listaPaises): primero(NULL), listaPaises(listaPaises) {
  
}

bool ListaMenuRest::listaVacia() {
    return primero == NULL;
}

bool ListaMenuRest::existeMenuRest(int pcodMenuRest) {
    NodoMenuRest* aux;
    if (primero == NULL) {
        cout << "No hay elementos";
    } else {
        aux = primero;
        while (aux) {
            if (aux->codMenuRest == pcodMenuRest) {
                return true;
            }
            aux = aux->siguiente;
        }
    }
    return false;
}

void ListaMenuRest::insertarRest(int codPais, int codCiudad, int codRest, int codMenuRest, string nombre, ListaPais& lPaises) {
    if (lPaises.existePais(codPais)) {
        if (lPaises.existeCiudad(codPais)) {
            if (lPaises.existeRest(codRest)) {
        if (listaVacia()) {
            primero = new NodoMenuRest(codPais, codCiudad, codRest, codMenuRest, nombre);
        } else {
            if (existeMenuRest(codMenuRest)) {
                cout << "Este menu ya existe en este restaurante, no se puede insertar" << endl;
            } else {
                pNodoMenuRest aux = primero;
                while (aux->siguiente!=NULL) {
                    aux = aux->siguiente;
                }
                aux->siguiente = new NodoMenuRest(codPais, codCiudad, codRest, codMenuRest, nombre);
                aux->siguiente->anterior = aux;
            }
        }
     } else {
        cout << "Este restaurante no existe" << endl;
    }   
    } else {
        cout << "Esta ciudad no existe" << endl;
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
        cout << aux->codMenuRest << " : " << aux->nombre << " -> ";
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
