#include "listaCiudad.h"
#include "../pais/listaPais.h"

ListaCiudad::ListaCiudad() {
    primero = NULL;
}


bool ListaCiudad::listaVacia() {
    return primero == NULL;
}

bool ListaCiudad::existeCiudad(int codPais, int codCiudad, ListaPais& lPaises) {
    NodoCiudad* aux;
    if (primero == NULL) {
        cout << "No hay elementos";
    } else {
        aux = primero;
        while (aux) {
            if ((aux->codigoCiudad == codCiudad) && (aux->codigoPais == codPais)) {
                if (lPaises.existePais(aux->codigoPais)){
                    return true;
                }
            }
            aux = aux->siguiente;
        }
    return false; }
    return false;
}

void ListaCiudad::insertar(int codPais, int codCiudad, string nombre, ListaPais& lPaises) {
    if (lPaises.existePais(codPais)) {
        if (listaVacia()) {
            primero = new NodoCiudad(codPais, codCiudad, nombre);
        } else {
            if (existeCiudad(codPais, codCiudad, lPaises)) {
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


void ListaCiudad::mostrar(int ciudad) { // muestra las ciudades de la lista
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

void ListaCiudad::mostrarDeUnPais(int pais) { // muestra las ciudades de un pais en especifico
    NodoCiudad *aux;
    if (primero==NULL)
        cout << "No hay elementos";  
    else {
        aux = primero;
        while(aux) {
            if(aux->codigoPais== pais){
                cout << aux->codigoCiudad << " : " << aux->nombre << " -> ";
            }
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
        int cont = 0;
        int idP,idC;
        string name = "", temp;
        for (char& c : str) {
            if (c == ';') {
                if (cont == 0) {
                    idP = stoi(temp);
                } else if (cont == 1) {
                    idC = stoi(temp);
                }
                temp = "";
                cont++;
            } else {
                temp += c;
            }
        }
        name = temp;
        ListaCiudad::insertar(idP, idC, name, lPais);
    }
    archivo.close();
    str="";
}