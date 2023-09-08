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
        if(primero->codRest == pCodRest){
            if (lCiudad.existeCiudad(pCodPais, pCodCiudad, lPais)){
            return true;
            }
        }
        aux = primero->siguiente;
        while (aux!=primero) {
            if (aux->codRest == pCodRest) {
                if(lCiudad.existeCiudad(pCodPais, pCodCiudad, lPais)==true){
                return true;
                }
            }
            aux = aux->siguiente;
        }
    }
    return false;
}

NodoRest* ListaRest::punteroRest(int pcodRest) {
    NodoRest *auxRest;
    if (primero== NULL)
        cout << "No hay elementos";  
    else {
        auxRest = primero;
        while(auxRest) {
            if (auxRest->codRest == pcodRest) {
                return auxRest;
            }
            auxRest = auxRest->siguiente;
        }
    }
    return 0;
}

void ListaRest::insertar(int codPais, int codCiudad, int codRest, string nombre, ListaPais& lPaises, ListaCiudad& lCiudades) {
     if ((lPaises.existePais(codPais)) && (lCiudades.existeCiudad(codPais, codCiudad, lPaises))) { // verificar que la ciudad este en el mismo pais
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
    bool flag=false;
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        if(primero->codRest == pCodRest){
            if(existeRest(pCodPais,pCodCiudad,pCodRest,lPaises,lCiudades)){
                NodoPais* auxPais = lPaises.punteroPais(pCodPais);
                NodoCiudad* auxCiudad = lCiudades.punteroCiudad(pCodCiudad);
                cout << "Datos del restaurante"<<endl;
                cout << "Nombre y codigo del pais: "<< auxPais->nombre<< "  " << auxPais->codigoPais<<endl;
                cout << "Nombre y codigo de la ciudad: "<<auxCiudad->nombre<< "  "<< aux->codCiudad<<endl;
                cout << "Nombre y codigo del restaurante: "<< aux->nombre<< "  "<< aux->codRest<<endl;  
                flag=true;
        }
        }
        aux = primero->siguiente;
        while (aux!=primero) {
            if (aux->codRest == pCodRest) {
                if(existeRest(pCodPais,pCodCiudad,pCodRest,lPaises,lCiudades)){
                NodoPais* auxPais = lPaises.punteroPais(pCodPais);
                NodoCiudad* auxCiudad = lCiudades.punteroCiudad(pCodCiudad);
                cout << "Datos del restaurante"<<endl;
                cout << "Nombre y codigo del pais: "<< auxPais->nombre<< "  " << auxPais->codigoPais<<endl;
                cout << "Nombre y codigo de la ciudad: "<<auxCiudad->nombre<< "  "<< aux->codCiudad<<endl;
                cout << "Nombre y codigo del restaurante: "<< aux->nombre<< "  "<< aux->codRest<<endl;    
                flag=true;
                }
            }
            aux = aux->siguiente;
        }
        if(flag==false){
        	cout<<"Restaurante no encontrado"<<endl;
		}
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

void ListaRest::modificarRest(int pCodPais, int pCodCiudad, int pCodRest, ListaPais& lPais, ListaCiudad& lCiudad, string nombre) {
    NodoRest *aux;
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        if(primero->codRest == pCodRest){
            if (lCiudad.existeCiudad(pCodPais, pCodCiudad, lPais)){
                primero->nombre = nombre;
                return;
            }
        }
        aux = primero->siguiente;
        while (aux!=primero) {
            if (aux->codRest == pCodRest) {
                if(lCiudad.existeCiudad(pCodPais, pCodCiudad, lPais)==true){
                    aux->nombre = nombre;
                    return;
                }
            }
            aux = aux->siguiente;
        }
    }
    return;
}

