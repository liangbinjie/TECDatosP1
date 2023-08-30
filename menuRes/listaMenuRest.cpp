#include "listaMenuRest.h"
#include "../pais/listaPais.h"
#include "../ciudad/listaCiudad.h"
#include "../menuRes/listaMenuRest.h"

ListaMenuRest::ListaMenuRest() {
	primero = NULL;
}
bool ListaMenuRest::listaVacia() {
    return primero == NULL;
}


bool ListaMenuRest::existeMenuRest(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenuRest, ListaCiudad& lCiudad, ListaPais& lPais, ListaRest& lRest) {
    NodoMenuRest *aux;
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        if(primero->codMenuRest == pCodMenuRest){
            if (lRest.existeRest(pCodPais, pCodCiudad, pCodRest, lCiudad ,lPais)==true){;
            return true;}
        }
        aux = primero->siguiente;
        while (aux!=primero) {
            if (aux->codMenuRest == pCodMenuRest) {
                if(lRest.existeRest(pCodPais, pCodCiudad, pCodRest, lCiudad ,lPais)==true){;
                return true;}
            }
            aux = aux->siguiente;
        }
    }
    return false;
}

void ListaMenuRest::insertarMenuRest(int codPais, int codCiudad, int codRest, int codMenuRest, string nombre, ListaPais& lPaises, ListaCiudad& lCiudad, ListaRest& lRest) {
    if (lRest.existeRest(codPais,codCiudad, codRest, lCiudad, lPaises)) {
        if (listaVacia()) {
            primero = new NodoMenuRest(codPais, codCiudad, codRest, codMenuRest, nombre);
        } else {
            if (existeMenuRest(codPais, codCiudad, codRest, codMenuRest, lCiudad, lPaises, lRest)) {
                cout << "Esta ciudad ya existe, no se puede insertar" << endl;
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
        cout << "Este pais no existe" << endl;
    }
}
    
    
    /*if (existeMenuRest(codPais, codCiudad, codRest, codMenuRest, lCiudad, lPaises, lRest)==false) {
        if (listaVacia()) {
            primero = new NodoMenuRest(codPais, codCiudad, codRest, codMenuRest, nombre);
            cout << "";
        } else {
            cout <<"Aca";
            pNodoMenuRest aux = primero;
            while (aux->siguiente != NULL) {
                aux = aux->siguiente;
            }
            cout << "Hp";
            pNodoMenuRest nuevoNodo = new NodoMenuRest(codPais, codCiudad, codRest, codMenuRest, nombre);
            aux->siguiente = nuevoNodo;
            nuevoNodo->anterior = aux;
        }
    } else {
        cout << "ABC";
    }
}
*/
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

/*void ListaMenuRest::eliminar(int codCiudad) {
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
*/
/*void ListaMenuRest::cargarCiudades(ListaPais& lPais) {
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
*/

void ListaMenuRest::cargarMenuRest(ListaPais& lPais, ListaCiudad& lCiudad, ListaRest& lRest) {
    string str;
    ifstream archivo;
    archivo.open("Archivos/Menu.txt");
    while (archivo >> str) {
        int cont = 0;
        int idP,idC,idR,idMR;
        string name = "", temp;
        for (char& c : str) {
            if (c == ';') {
                if (cont == 0) {
                    idP = stoi(temp);
                } else if (cont == 1) {
                    idC = stoi(temp);
                } else if (cont == 2) {
                    idR = stoi(temp);
                } else if (cont == 3) {
                    idMR = stoi(temp);
                } 
                temp = "";
                cont++;
            } else {
                temp += c;
            }
        }
        name = temp;
        ListaMenuRest::insertarMenuRest(idP, idC, idR, idMR, name, lPais, lCiudad, lRest);
    }
    archivo.close();
    str="";
}