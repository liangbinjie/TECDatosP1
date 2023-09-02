#include "listaProducto.h"

ListaProducto::ListaProducto() {
    primero = NULL;
}

bool ListaProducto::listaVacia() {
    return primero == NULL;
}


void ListaProducto::buscarProducto(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, int pCodProducto, ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRest, ListaMenuRest& lMenu){
    NodoProducto *auxProducto;
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        if(primero->codProducto == pCodProducto){
            if(existeProducto(pCodPais,pCodCiudad,pCodRest,pCodMenu,pCodProducto,lPaises,lCiudades,lRest,lMenu)){
                NodoPais* auxPais = lPaises.punteroPais(pCodPais);
                NodoCiudad* auxCiudad = lCiudades.punteroCiudad(pCodCiudad);
                NodoRest* auxRest = lRest.punteroRest(pCodRest);
                NodoMenuRest* auxMenu = lMenu.punteroMenu(pCodMenu);
                cout << "Datos del producto"<<endl;
                cout << "Nombre y codigo del pais: "<< auxPais->nombre<< "  " << auxPais->codigoPais<<endl;
                cout << "Nombre y codigo de la ciudad: "<<auxCiudad->nombre<< "  "<< auxCiudad->codigoCiudad<<endl;
                cout << "Nombre y codigo del restaurante: "<< auxRest->nombre<< "  "<< auxRest->codRest<<endl; 
                cout << "Nombre y codigo del producto: "<< auxProducto->nombre<< "  "<< auxProducto->codProducto<<endl;  
                cout << "Nombre y codigo del producto: "<< auxProducto->nombre<< "  "<< auxProducto->codProducto<<endl; 
                cout << "Kcal del producto: "<< auxProducto->kcal<<endl;
                cout << "Precio del producto: "<< auxProducto->precio<<endl;
        }
        }
        auxProducto = primero->siguiente;
        while (auxProducto!=NULL) {
            if (auxProducto->codProducto == pCodProducto) {
                if(existeProducto(pCodPais,pCodCiudad,pCodRest,pCodMenu,pCodProducto,lPaises,lCiudades,lRest,lMenu)){
                NodoPais* auxPais = lPaises.punteroPais(pCodPais);
                NodoCiudad* auxCiudad = lCiudades.punteroCiudad(pCodCiudad);
                NodoRest* auxRest = lRest.punteroRest(pCodRest);
                NodoMenuRest* auxMenu = lMenu.punteroMenu(pCodMenu);
                cout << "Datos del producto"<<endl;
                cout << "Nombre y codigo del pais: "<< auxPais->nombre<< "  " << auxPais->codigoPais<<endl;
                cout << "Nombre y codigo de la ciudad: "<<auxCiudad->nombre<< "  "<< auxCiudad->codigoCiudad<<endl;
                cout << "Nombre y codigo del restaurante: "<< auxRest->nombre<< "  "<< auxRest->codRest<<endl; 
                cout << "Nombre y codigo del menu: "<< auxMenu->nombre<< "  "<< auxMenu->codMenuRest<<endl;  
                cout << "Nombre y codigo del producto: "<< auxProducto->nombre<< "  "<< auxProducto->codProducto<<endl; 
                cout << "Kcal del producto: "<< auxProducto->kcal<<endl;
                cout << "Precio del producto: "<< auxProducto->precio<<endl;    
                }
            }
            auxProducto = auxProducto->siguiente;
        }
    }
    }
    


bool ListaProducto::existeProducto(int pCodPais, int pCodCiudad, int pCodRes, int pCodMenu, int pCodProducto, ListaPais& lPais, ListaCiudad& lCiudad, ListaRest& lRest, ListaMenuRest& lMenuRest ) {
    NodoProducto* aux = primero;
    if (primero==NULL){
        cout << "No hay elementos";
    }else{
        if (primero->codProducto==pCodProducto){
            if(lMenuRest.existeMenuRest(pCodPais,pCodCiudad,pCodRes,pCodMenu,lPais, lCiudad, lRest)==true){
                cout<<"si existe";
                return true;
            }
        }
        aux = primero->siguiente;
        while(aux!=NULL){
            if (aux->codProducto==pCodProducto){
                if(lMenuRest.existeMenuRest(pCodPais,pCodCiudad,pCodRes,pCodMenu,lPais, lCiudad, lRest)==true){
                    cout<<"si existe";
                    return true;
            }
        }
        aux = aux->siguiente;
    }
return false;
}
}

void ListaProducto::insertarProducto(int codPais, int codCiudad, int codRest, int codMenu, int codProducto, string nombre, int kcal, int precio, ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRests, ListaMenuRest& lMenu) {
    if (lMenu.existeMenuRest(codPais, codCiudad, codRest, codMenu, lPaises, lCiudades, lRests)) {
        if (listaVacia()) {
            primero = new NodoProducto( codPais,  codCiudad,  codRest,  codMenu,  codProducto,  nombre,  kcal,  precio);
        } else {
            if(existeProducto(codPais, codCiudad, codRest, codMenu, codProducto, lPaises, lCiudades, lRests, lMenu)){
                cout <<"Este producto ya existe en el menu, no se puede insertar";
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
    }
}

void ListaProducto::cargarProductos(ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRests, ListaMenuRest& lMenus) {
    string str;
    ifstream archivo;
    archivo.open("Archivos/Productos.txt");
    while (archivo >> str) {
        int cont = 0;
        int idP, idC, idR, idM, id, kcal, precio;
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
                    idM = stoi(temp);
                } else if (cont == 4) {
                    id = stoi(temp);
                } else if (cont == 5) {
                    name = temp;
                } else if (cont == 6) {
                    kcal = stoi(temp);
                }
                temp = "";
                cont++;
            } else {
                temp += c;
            }
        }
        precio = stoi(temp);
        ListaProducto::insertarProducto(idP, idC, idR, idM, id, name, kcal, precio, lPaises, lCiudades, lRests, lMenus);
    }
    archivo.close();
    str = "";
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
