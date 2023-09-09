#include "listaProducto.h"

ListaProducto::ListaProducto() {
    primero = NULL;
}

bool ListaProducto::listaVacia() {
    return primero == NULL;
}

void ListaProducto::buscarProducto(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, int pCodProducto, ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRest, ListaMenuRest& lMenu){
    NodoProducto *aux;
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        aux = primero;
        while (aux) {
            if (aux->codMenu == pCodMenu && aux->codPais == pCodPais && aux->codCiudad == pCodCiudad && aux->codRest == pCodRest && aux->codProducto==pCodProducto) {
                cout << "Datos del producto"<<endl;
                cout << "Nombre y codigo del pais: "<< lPaises.punteroPais(pCodPais)->nombre<< "  " << lPaises.punteroPais(pCodPais)->codigoPais<<endl;
                cout << "Nombre y codigo de la ciudad: "<< lCiudades.punteroCiudad(pCodCiudad, pCodPais)->nombre<< "  "<< lCiudades.punteroCiudad(pCodCiudad, pCodPais)->codigoCiudad<<endl;
                cout << "Nombre y codigo del restaurante: "<< lRest.punteroRest(pCodRest, pCodCiudad, pCodPais)->nombre<< "  "<< lRest.punteroRest(pCodRest, pCodCiudad, pCodPais)->codRest<<endl; 
                cout << "Nombre y codigo del producto: "<< aux->nombre<< "  "<< aux->codProducto<<endl; 
                cout << "Kcal del producto: "<< aux->kcal<<endl;
                cout << "Precio del producto: "<< aux->precio<<endl;
                return;
            }
            aux = aux->siguiente;
        }
        cout << "No se encontro el producto" << endl;
    }
}
    


bool ListaProducto::existeProducto(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, int pCodProducto, ListaPais& lPais, ListaCiudad& lCiudad, ListaRest& lRest, ListaMenuRest& lMenuRest ) {
    NodoProducto* aux = primero;
    if (primero==NULL){
        cout << "No hay elementos" << endl;
    }else{
        aux = primero;
        while(aux!=NULL) {
            if (aux->codProducto==pCodProducto) {
                if (aux->codPais == pCodPais && aux->codCiudad == pCodCiudad && aux->codRest == pCodRest && aux->codMenu==pCodMenu) {
                    return true;
                }
            }
            aux = aux->siguiente;
        }
    }
    return false;
}

void ListaProducto::insertarProducto(int codPais, int codCiudad, int codRest, int codMenu, int codProducto, string nombre, int kcal, int precio, ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRests, ListaMenuRest& lMenu) {
    if (lMenu.existeMenuRest(codPais, codCiudad, codRest, codMenu, lPaises, lCiudades, lRests)) {
      
        if (listaVacia()) {
            primero = new NodoProducto( codPais,  codCiudad,  codRest,  codMenu,  codProducto,  nombre,  kcal,  precio);
        } else {
            if(existeProducto(codPais, codCiudad, codRest, codMenu, codProducto, lPaises, lCiudades, lRests, lMenu)){
                cout <<"Este producto ya existe en el menu, no se puede insertar" << endl;
            } else {
                NodoProducto* aux = primero;
                while (aux->siguiente!=NULL) {
                aux = aux->siguiente;
                }
                aux->siguiente = new NodoProducto(codPais, codCiudad, codRest, codMenu, codProducto,  nombre,  kcal,  precio);
                aux->siguiente->anterior = aux;
            }
        }
    } else {
        cout << "Incongruencias con la ubicacion" << endl;
    }
}


void ListaProducto::eliminar(int id) {
    if (listaVacia()) {
        cout << "Lista vacia" << endl; 
    } else {
        if (primero->codProducto == id) {
            NodoProducto* temp = primero;
            primero = primero->siguiente;
            delete temp;
        } else {
            NodoProducto* temp = primero;
            while (temp->siguiente && temp->siguiente->codProducto != id) {
                temp = temp->siguiente;
            }
            if (temp->siguiente) {
                NodoProducto* nodoEliminar = temp->siguiente;
                temp->siguiente = nodoEliminar->siguiente;
                delete nodoEliminar;
            }
        }
        cout << "Se elimino el producto" << endl;
    }
}

void ListaProducto::cargarProductos(ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRests, ListaMenuRest& lMenus) {
    ifstream archivo("Archivos/Productos.txt");
    string line;
    
    while (getline(archivo, line)) {
        stringstream ss(line);
        string temp;
        int idP, idC, idR, idM, id, kcal, precio;
        string name;

        getline(ss, temp, ';');
        idP = stoi(temp);

        getline(ss, temp, ';');
        idC = stoi(temp);

        getline(ss, temp, ';');
        idR = stoi(temp);

        getline(ss, temp, ';');
        idM = stoi(temp);

        getline(ss, temp, ';');
        id = stoi(temp);

        getline(ss, name, ';');

        getline(ss, temp, ';');
        kcal = stoi(temp);

        getline(ss, temp, ';');
        precio = stoi(temp);

        ListaProducto::insertarProducto(idP, idC, idR, idM, id, name, kcal, precio, lPaises, lCiudades, lRests, lMenus);
    }

    archivo.close();
}

void ListaProducto::mostrar() {
    NodoProducto *aux;
    if (primero==NULL)
        cout << "No hay elementos";  
    else {
        cout << endl;
        aux = primero;
        while(aux) {
        std::cout << "ID PRODUCTO: " << aux->codProducto << ", Nombre: " << aux->nombre<< " -> ";
        aux = aux->siguiente;
        }
         cout << endl;
    }
}

void ListaProducto::modificarProducto(int codPais, int codCiudad, int codRest, int codMenu, int codProducto, string nombre, int kcal, int precio, ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRests, ListaMenuRest& lMenus) {
    NodoProducto *aux = primero;
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        while (aux!=NULL) {
            cout << aux->codMenu;
            if (aux->codPais == codPais && aux->codCiudad == codCiudad && aux->codRest == codRest && aux->codMenu && aux->codMenu == codMenu) {
                aux->nombre = nombre;
                aux->kcal = kcal;
                aux->precio = precio;
                cout << "Producto modificado" << endl;
                return;
            }
            aux = aux->siguiente;
        }
    }
    cout << "No se encontro el producto" << endl;
    return;
}

void ListaProducto::mostrarProductosMenu(int codPais, int codCiudad, int codRest, int codMenu) {
    if (primero==NULL) {
        cout << "No hay productos en la base de datos" << endl;
    } else {
        pNodoProducto aux = primero;
        while (aux) {
            if (aux->codCiudad == codCiudad && aux->codPais == codPais && aux->codRest == codRest && aux->codMenu == codMenu) {
                cout << "- " << aux->codProducto << ". " << aux->nombre << endl;
            }
            aux = aux->siguiente;
        }
    }
}
