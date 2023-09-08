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
/*
            if (lRest.existeRest(pCodPais, pCodCiudad, pCodRest, lCiudad ,lPais)==true){;
            return true;}
*/
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
                NodoCiudad* auxCiudad = lCiudades.punteroCiudad(pCodCiudad);
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
                NodoCiudad* auxCiudad = lCiudades.punteroCiudad(pCodCiudad);
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
/*
    if (lRest.existeRest(codPais,codCiudad, codRest, lCiudad, lPaises)) {
        if (listaVacia()) {
            primero = new NodoMenuRest(codPais, codCiudad, codRest, codMenuRest, nombre);
        } else {
            if (existeMenuRest(codPais, codCiudad, codRest, codMenuRest, lCiudad, lPaises, lRest)) {
*/
                cout << "Este menu ya existe, no se puede insertar" << endl;
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




/*void ListaCiudad::borrarInicio() {
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
                    cout << aux->codigoCiudad << endl;
                    break;

                }

void ListaMenuRest::eliminar(int codMenu) {
    if (listaVacia()) {
        cout << "No se puede eliminar, lista vacia" << endl;
    } else {
        pNodoMenuRest aux = primero;
        if (aux->codMenuRest == codMenu) {
            borrarInicio();
        } else {
            while (aux->codigoPais != codMenu) {
                aux = aux->siguiente;
            }
            pNodoCiudad temp = aux;
            aux = aux->anterior;
            aux->siguiente = aux->siguiente;
            delete temp;
        }
    }
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
