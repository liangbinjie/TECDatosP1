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
        return false; 
        }
    return false;
}

NodoCiudad* ListaCiudad::punteroCiudad(int codCiudad, int codPais) {
    NodoCiudad *auxCiudad;
    if (primero== NULL)
        cout << "No hay elementos";  
    else {
        auxCiudad = primero;
        while(auxCiudad) {
            if (auxCiudad->codigoCiudad == codCiudad && auxCiudad->codigoPais == codPais) {
                return auxCiudad;
            }
            auxCiudad = auxCiudad->siguiente;
        }
    }
    return 0;
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
                cout << "Nueva ciudad insertada" << endl;
            }
        }
    } else {
        cout << "Este pais no existe" << endl;
    }
}


void ListaCiudad::mostrar() { // muestra las ciudades de la lista
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
            if(aux->codigoPais==pais){
                cout << aux->codigoCiudad << " : " << aux->nombre << " -> ";
            }
        aux = aux->siguiente;
        }
        cout << endl;
    return;
    }
}

void ListaCiudad::modificarCiudad(int pCodPais, int pCodCiudad, string pnombre, ListaPais& LPais){
    if(existeCiudad(pCodPais,pCodCiudad,LPais)){
       NodoCiudad* auxCiudad = punteroCiudad(pCodCiudad, pCodPais);
       auxCiudad->nombre = pnombre; 
       cout <<"Cambio realizado con exito";
    }else{
        cout <<"Incongruencias con la ubicacion";
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
    cout << codCiudad << endl;
    if (listaVacia()) {
        cout << "No se puede eliminar, lista vacia" << endl;
    } else {
        pNodoCiudad aux = primero;
        if (aux->codigoCiudad == codCiudad) {
            borrarInicio();
        } else {
            while (aux->codigoPais != codCiudad) {
                if (aux->codigoCiudad == codCiudad) {
                    // cout << aux->codigoCiudad << endl;
                    break;

                }
                aux = aux->siguiente;
            }
            pNodoCiudad temp = aux;
            aux = aux->anterior;
            aux->siguiente = temp->siguiente;
            delete temp;
        }
    }
}

void ListaCiudad::reporteCiudades(int pais) {
 ofstream archivo;
    archivo.open("reportes/Ciudades.txt", ios::out);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
 NodoCiudad *aux;
    if (primero==NULL)
        cout << "No hay elementos";  
    else {
        aux = primero;
        while(aux) {
            if(aux->codigoPais==pais){
                archivo << aux->nombre <<endl;
            }
        aux = aux->siguiente;
        }
    } archivo.close();
}

void ListaCiudad::cargarCiudades(ListaPais& lPais) {
    ifstream archivo("Archivos/Ciudades.txt");
    string line;
    
    while (getline(archivo, line)) {
        stringstream ss(line);
        string temp;
        int idP, idC;
        string name;

        getline(ss, temp, ';');
        idP = stoi(temp);

        getline(ss, temp, ';');
        idC = stoi(temp);

        getline(ss, name, ';');

        ListaCiudad::insertar(idP, idC, name, lPais);
    }

    archivo.close();
}

void ListaCiudad::eliminarCiudades(int pais) {
    NodoCiudad *aux;
    if (primero==NULL)
        cout << "No hay elementos";  
    else {
        aux = primero;
        while(aux) {
            if(aux->codigoPais==pais){
                cout << aux->codigoCiudad;
                ListaCiudad::eliminar(aux->codigoCiudad);
            }
            aux = aux->siguiente;
        }
        cout << endl;
    }
}


void ListaCiudad::buscarCiudad(int codPais, int codCiudad) {
    NodoCiudad *aux;
    if (primero==NULL) {
        cout << "No hay ciudades" << endl;
    } else {
        aux = primero;
        while (aux) {
            if (aux->codigoPais == codPais && aux->codigoCiudad == codCiudad) {
                cout << "Codigo pais: " << aux->codigoPais << endl;
                cout << "Codigo ciudad: " << aux->codigoCiudad << endl;
                cout << "Nombre: " << aux->nombre << endl;
                return;
            }
            aux = aux->siguiente;
        }
        cout << "No existe esta ciudad" << endl;
    }
}
