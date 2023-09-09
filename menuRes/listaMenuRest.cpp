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


bool ListaMenuRest::existeMenuRest(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenuRest, ListaPais& lPais, ListaCiudad& lCiudad, ListaRest& lRest) {
    NodoMenuRest *aux;
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        if(primero->codMenuRest == pCodMenuRest){
            if (lRest.existeRest(pCodPais, pCodCiudad, pCodRest, lPais, lCiudad)==true){
            cout<<"si existe";
            return true;
            }
        }
        aux = primero->siguiente;
        while (aux!=NULL) {
            if (aux->codMenuRest == pCodMenuRest) {
                if(lRest.existeRest(pCodPais, pCodCiudad, pCodRest, lPais, lCiudad)==true){
                    cout<<"si existe";
                return true;
                }
            }
            aux = aux->siguiente;
        }
    }
    return false;
}

NodoMenuRest* ListaMenuRest::punteroMenu(int pcodMenu) {
    NodoMenuRest *auxMenu;
    if (primero== NULL)
        cout << "No hay elementos";  
    else {
        auxMenu = primero;
        while(auxMenu) {
            if (auxMenu->codMenuRest == pcodMenu) {
                return auxMenu;
            }
            auxMenu = auxMenu->siguiente;
        }
    }
    return 0;
}

void ListaMenuRest::buscarMenuRest(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRest){
    NodoMenuRest *aux;
    bool flag=false;
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        if(primero->codMenuRest == pCodMenu){
            if(existeMenuRest(pCodPais,pCodCiudad,pCodRest,pCodMenu,lPaises,lCiudades,lRest)){
                NodoPais* auxPais = lPaises.punteroPais(pCodPais);
                NodoCiudad* auxCiudad = lCiudades.punteroCiudad(pCodCiudad, pCodPais);
                NodoRest* auxRest = lRest.punteroRest(pCodRest);
                cout << "Datos del menu"<<endl;
                cout << "Nombre y codigo del pais: "<< auxPais->nombre<< "  " << auxPais->codigoPais<<endl;
                cout << "Nombre y codigo de la ciudad: "<<auxCiudad->nombre<< "  "<< auxCiudad->codigoCiudad<<endl;
                cout << "Nombre y codigo del restaurante: "<< auxRest->nombre<< "  "<< auxRest->codRest<<endl; 
                cout << "Nombre y codigo del menu: "<< aux->nombre<< "  "<< aux->codMenuRest<<endl; 
                flag=true;  
            }
        }
        aux = primero->siguiente;
        while (aux!=NULL) {
            if (aux->codMenuRest == pCodMenu) {
                if(existeMenuRest(pCodPais,pCodCiudad,pCodRest,pCodMenu,lPaises,lCiudades,lRest)){
                NodoPais* auxPais = lPaises.punteroPais(pCodPais);
                NodoCiudad* auxCiudad = lCiudades.punteroCiudad(pCodCiudad, pCodPais);
                NodoRest* auxRest = lRest.punteroRest(pCodRest);
                cout << "Datos del menu"<<endl;
                cout << "Nombre y codigo del pais: "<< auxPais->nombre<< "  " << auxPais->codigoPais<<endl;
                cout << "Nombre y codigo de la ciudad: "<<auxCiudad->nombre<< "  "<< auxCiudad->codigoCiudad<<endl;
                cout << "Nombre y codigo del restaurante: "<< auxRest->nombre<< "  "<< auxRest->codRest<<endl; 
                cout << "Nombre y codigo del menu: "<< aux->nombre<< "  "<< aux->codMenuRest<<endl;    
                flag=true;
                }
            }
            aux = aux->siguiente;  
        }
        if (flag==false){
            cout<<"Menu no encontrado"<<endl;
        }
    }
}
    

void ListaMenuRest::insertarMenuRest(int codPais, int codCiudad, int codRest, int codMenuRest, string nombre, ListaPais& lPaises, ListaCiudad& lCiudad, ListaRest& lRest) {
    if (lRest.existeRest(codPais,codCiudad, codRest, lPaises, lCiudad)) {
        if (listaVacia()) {
            primero = new NodoMenuRest(codPais, codCiudad, codRest, codMenuRest, nombre);
        } else {
            if (existeMenuRest(codPais, codCiudad, codRest, codMenuRest, lPaises, lCiudad, lRest)) {
                cout << "Este menu ya existe, no se puede insertar" << endl;
            } else {
                pNodoMenuRest aux = primero;
                while (aux->siguiente!=NULL) {
                    aux = aux->siguiente;
                }
                aux->siguiente = new NodoMenuRest(codPais, codCiudad, codRest, codMenuRest, nombre);
                aux->siguiente->anterior = aux;
                cout << "Nuevo menu insertado" << endl;
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
        cout << aux->codMenuRest << " : " << aux->nombre << " -> ";
        aux = aux->siguiente;
        }
    cout << endl;
    }
}

void ListaMenuRest::cargarMenuRest(ListaPais& lPais, ListaCiudad& lCiudad, ListaRest& lRest) {
    ifstream archivo("Archivos/Menu.txt");
    string line;
    
    while (getline(archivo, line)) {
        stringstream ss(line);
        string temp;
        int idP, idC, idR, idM;
        string name;

        getline(ss, temp, ';');
        idP = stoi(temp);

        getline(ss, temp, ';');
        idC = stoi(temp);

        getline(ss, temp, ';');
        idR = stoi(temp);

        getline(ss, temp, ';');
        idM = stoi(temp);

        getline(ss, name, ';');

        ListaMenuRest::insertarMenuRest(idP, idC, idR, idM, name, lPais, lCiudad, lRest);
    }

    archivo.close();
}
