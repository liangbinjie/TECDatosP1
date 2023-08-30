#include "listaRest.h"

ListaRest::ListaRest() {
    primero = NULL;
}

bool ListaRest::listaVacia() {
    return primero == NULL;
}

bool ListaRest::existeRest(int pCodPais, int pCodCiudad, int pCodRest, ListaCiudad& lCiudad, ListaPais& lPais) {
    NodoRest *aux;
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        aux = primero->siguiente;
        while (aux!=primero) {
            if (aux->codRest == pCodRest) {
                lCiudad.existeCiudad(pCodPais, pCodCiudad, lPais);
                return true;
            }
            aux = aux->siguiente;
        }
    }
}

void ListaRest::insertar(int codPais, int codCiudad, int codRest, string nombre, ListaPais& lPaises, ListaCiudad& lCiudades) {
     if ((lPaises.existePais(codPais)) && (lCiudades.existeCiudad(codPais, codCiudad, lPaises))) { // verificar que la ciudad este en el mismo pais
        if (!existeRest(codPais, codCiudad, codRest, lCiudades, lPaises)) {
            if (listaVacia()) {
                primero = new NodoRest(codPais, codCiudad, codRest, nombre);
                primero->anterior=primero;
                primero->siguiente=primero;
            } else {
                pNodoRest nuevo = new NodoRest(codPais, codCiudad, codRest, nombre);
                nuevo->anterior = primero->anterior;
                nuevo->siguiente = primero;
                primero->anterior->siguiente = nuevo;
                primero->anterior = nuevo;
            }
            cout << "Restaurante nuevo insertado" << endl;
        } else {
            cout << "Este restaurante ya existe" << endl;;
        }
    } else {
        cout << "No se puede agregar porque la ciudad o pais estan mal" << endl;
    }
}

void ListaRest::mostrar() {
    pNodoRest aux = primero;
    while (aux->siguiente!=primero) {
        cout << aux->codRest << " : " << aux->nombre << " -> ";
        aux = aux->siguiente;
    }
    cout << aux->codRest << " : " << aux->nombre << " -> " << endl;
}

void ListaRest::borrarInicio() {
    if (listaVacia()) {
        cout << "No hay elementos en la lista";
    } else {
        if (primero->siguiente == primero) {
            pNodoRest temp = primero;
            primero = NULL;
            delete temp;
        } else {
            pNodoRest aux = primero->anterior;
            pNodoRest temp = primero;
            aux->siguiente = primero->siguiente;
            primero = primero->siguiente;
            primero->anterior = aux;
            delete temp;
        }
    }
}

void ListaRest::eliminar(int pCodRest) {
    if (listaVacia()) {
        cout << "Lista vacia" << endl;
    } else {
        pNodoRest aux = primero;
        if (aux->codRest == pCodRest) {
            borrarInicio();
        } else {
            while (aux->siguiente!=primero && aux->codRest != pCodRest) {
                aux = aux->siguiente;
            }
            pNodoRest temp = aux;
            aux->anterior->siguiente = aux->siguiente;
            aux->siguiente->anterior = aux->anterior;
            delete temp;
        }
    }
}

void ListaRest::cargarRests(ListaPais& lPaises, ListaCiudad& lCiudades) {
    string str;
    ifstream archivo;
    archivo.open("Archivos/Restaurantes.txt");
    while (archivo >> str) {
        int cont = 0;
        int idP,idC, idR;
        string name = "", temp;
        for (char& c : str) {
            if (c == ';') {
                if (cont == 0) {
                    idP = stoi(temp);
                } else if (cont == 1) {
                    idC = stoi(temp);
                } else if (cont == 2) {
                    idR = stoi(temp);
                } 
                temp = "";
                cont++;
            } else {
                temp += c;
            }
        }
        name = temp;
        ListaRest::insertar(idP, idC, idR, name, lPaises, lCiudades);
    }
    archivo.close();
    str="";
}