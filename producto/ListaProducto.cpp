#include "listaProducto.h"

ListaProducto::ListaProducto() {
    primero = NULL;
}

bool ListaProducto::listaVacia() {
    return primero == NULL;
}

void ListaProducto::insertar(int codPais, int codCiudad, int codRest, int codMenu, int codProducto, string nombre, int kcal, int precio, ListaPais& lPaises, ListaCiudad& lCiudades, ListaRest& lRests, ListaMenuRest& lMenus) {
    if (lCiudades.existeCiudad(codPais, codCiudad, lPaises)) {
        if (listaVacia()) {
            primero = new NodoProducto( codPais,  codCiudad,  codRest,  codMenu,  codProducto,  nombre,  kcal,  precio);
        } else {
            NodoProducto* aux = primero;
            while (aux->siguiente) {
                aux = aux->siguiente;
            }
            aux->siguiente = new NodoProducto(codPais, codCiudad, codRest, codMenu, codProducto,  nombre,  kcal,  precio);
        }
    } else {
        cout << "Incongruencias con la ubicacion" << endl;
    }
}

bool ListaProducto::existeProducto(int id) {
    NodoProducto* aux = primero;
    while (aux) {
        if (aux->codProducto == id) {
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
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
                }else if (cont == 4) {
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
        ListaProducto::insertar(idP, idC, idR, idM, id, name, kcal, precio, lPaises, lCiudades, lRests, lMenus);
    }
    archivo.close();
    str="";
}

void ListaProducto::mostrar() {
    NodoProducto* temp = primero;
    while (temp) {
        std::cout << "ID PRODUCTO: " << temp->codProducto << ", Nombre: " << temp->nombre << std::endl;
        temp = temp->siguiente;
    }
}