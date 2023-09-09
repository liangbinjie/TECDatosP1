#include "listaRest.h"

ListaRest::ListaRest() {
    primero = NULL;
}

bool ListaRest::listaVacia() {
    return primero == NULL;
}

bool ListaRest::existeRest(int pCodPais, int pCodCiudad, int pCodRest, ListaPais& lPais, ListaCiudad& lCiudad) {
    NodoRest *aux;
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        if(primero->codigoPais == pCodPais && primero->codCiudad == pCodCiudad && primero->codRest == pCodRest){
                return true;
        } else {
            aux = primero->siguiente;
            while (aux!=primero) {
                if (aux->codigoPais == pCodPais && aux->codCiudad == pCodCiudad && aux->codRest == pCodRest){
                    // cout << aux->nombre;
                    return true;
                }
                aux = aux->siguiente;
            }
        }
    }
    return false;
}

NodoRest* ListaRest::punteroRest(int pcodRest, int codCiudad, int codPais) {
    NodoRest *auxRest;
    if (primero== NULL)
        cout << "No hay elementos";  
    else {
        auxRest = primero;
        while(auxRest) {
            if (auxRest->codRest == pcodRest && auxRest->codCiudad == codCiudad && auxRest->codigoPais==codPais) {
                return auxRest;
            }
            auxRest = auxRest->siguiente;
        }
    }
    return 0;
}

void ListaRest::insertar(int codPais, int codCiudad, int codRest, string nombre, ListaPais& lPaises, ListaCiudad& lCiudades) {
     if (lCiudades.existeCiudad(codPais, codCiudad, lPaises)) { // verificar que la ciudad este en el mismo pais
        if (!existeRest(codPais, codCiudad, codRest, lPaises, lCiudades)) {
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
            cout << "Este restaurante ya existe" << endl;
        }
    } else {
        cout << "No se puede agregar porque la ciudad o pais estan mal" << endl;
    }
}

void ListaRest::buscarRest(int pCodPais, int pCodCiudad, int pCodRest, ListaPais& lPaises, ListaCiudad& lCiudades){
    NodoRest *aux;
    if (primero == NULL) {
        cout << "No hay restaurantes" << endl;
    } else {
        if (primero->codRest == pCodRest && primero->codigoPais == pCodPais && primero->codCiudad == pCodCiudad) {
            cout << "Datos del restaurante" << endl;
            cout << "Codigo Pais y nombre: " << pCodPais << " | " << lPaises.punteroPais(pCodPais)->nombre << endl;
            cout << "Codigo ciudad y nombre: " << pCodCiudad << " | " << lCiudades.punteroCiudad(pCodCiudad, pCodPais)->nombre << endl;
            cout << "Codigo restaurante y nombre: " << pCodRest << " | " << primero->nombre << endl;
            return;
        } else {
            aux = primero->siguiente;
            while (aux!=primero) {
                if (aux->codRest == pCodRest && aux->codigoPais == pCodPais && aux->codCiudad == pCodCiudad) {
                    cout << "Datos del restaurante" << endl;
                    cout << "Codigo Pais y nombre: " << pCodPais << " | " << lPaises.punteroPais(pCodPais)->nombre << endl;
                    cout << "Codigo ciudad y nombre: " << pCodCiudad << " | " << lCiudades.punteroCiudad(pCodCiudad, pCodPais)->nombre << endl;
                    cout << "Codigo restaurante y nombre: " << pCodRest << " | " << aux->nombre << endl;
                    return;
                }
                aux = aux->siguiente;
            }
        }
        cout << "No se encontro el restaraunte" << endl;
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
    ifstream archivo("Archivos/Restaurantes.txt");
    string line;
    
    while (getline(archivo, line)) {
        stringstream ss(line);
        string temp;
        int idP, idC, idR;
        string name;

        getline(ss, temp, ';');
        idP = stoi(temp);

        getline(ss, temp, ';');
        idC = stoi(temp);

        getline(ss, temp, ';');
        idR = stoi(temp);

        getline(ss, name, ';');

        ListaRest::insertar(idP, idC, idR, name, lPaises, lCiudades);
    }

    archivo.close();
}

void ListaRest::modificarRest(int pCodPais, int pCodCiudad, int pCodRest, ListaPais& lPais, ListaCiudad& lCiudad, string pnombre) {
    NodoRest *aux;
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        if(primero->codRest == pCodRest && primero->codigoPais == pCodPais && primero->codCiudad == pCodCiudad){
            primero->nombre = pnombre;
            return;
        } else {
            aux = primero->siguiente;
            while (aux!=primero) {
                if (aux->codRest == pCodRest && aux->codigoPais == pCodPais && aux->codCiudad == pCodCiudad) {
                    aux->nombre = pnombre;
                    return;
                }
                aux = aux->siguiente;
            }
        }
    }
    return;
}

