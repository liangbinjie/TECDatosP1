#include "listaCiudad.h"
#include "../pais/listaPais.h"


ListaCiudad::ListaCiudad(ListaPais& listaPaises) : primero(NULL), listaPaises(listaPaises) {
  
}

ListaCiudad::~ListaCiudad() {
    pNodoCiudad aux;
    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
    primero = NULL;
}

bool ListaCiudad::listaVacia() {
    return primero == NULL;
}

void ListaCiudad::insertarCiudad(int codCiudad, string nombre) {
    pNodoCiudad nuevoNodo = new NodoCiudad(codCiudad, nombre);

    if (listaVacia()) {
        primero = nuevoNodo;
    } else {
        pNodoCiudad aux = primero;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevoNodo;
        nuevoNodo->anterior = aux;
    }
    cout << "Nueva ciudad insertada en la lista." << endl;
}


void ListaCiudad::insertarEnLista(int codPais, int codCiudad, string nombre) {
   pNodoPais auxP = listaPaises.primero; // Accede al primer nodo de la lista de países
    while (auxP != NULL) {
        if (auxP->codigoPais == codPais) {
            if (auxP->ciudadList == NULL) {
                auxP->ciudadList = new ListaCiudad(listaPaises); // Crea una nueva lista de ciudades si aún no existe
            }
            auxP->ciudadList->insertarCiudad(codCiudad, nombre); // Llama al método insertar de la lista de ciudades
            return; // Sale del método luego de realizar la inserción
        }
        auxP = auxP->siguiente;
    }
    // Resto del código de inserción de ciudades si no se encuentra el país
}


/*
   void ListaCiudad::insertar(int codPais, int codCiudad, string nombre) {
    pNodoPais auxP = primero;
    while (auxP->siguiente != NULL) {
        if (auxP->codigoPais == codPais) {

            if (listaVacia()) {
                primero = new NodoCiudad(codPais, codCiudad, nombre);
            } else {
                pNodoCiudad auxC = primero;
                 while (auxC->siguiente != NULL) {
                    if (auxC->codigoCiudad == codCiudad) {
                        cout << "La ciudad ya existe" ;
                        break;
                    }
                    else{
                     auxC = auxC->siguiente;
                 }
                 }
                 auxC->siguiente = new NodoCiudad(codPais, codCiudad, nombre);\
                 auxC->siguiente->anterior = auxC;
                    
    }


            return aux; // Se encontró el país con el código especificado
        }
        aux = aux->siguiente;



    aux = aux->siguiente;
    }
    if (listaVacia()) {
        primero = new NodoPais(codPais, nombre);
    } else {
        pNodoPais aux = primero;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = new NodoPais(codPais, nombre);
        aux->siguiente->anterior = aux;
    }
}

*/

void ListaCiudad::mostrar() {
    NodoCiudad *aux;
    if (primero== NULL)
        cout << "No hay elementos";  
    else {
        aux = primero;
        while(aux) {
        cout << aux->codigoCiudad << " : " << aux->nombre << " -> ";
        aux = aux->siguiente;
        }
    cout << endl;
    }
}
/*
void ListaCiudad::eliminar(int codPais) {
    if (listaVacia()) {
        cout << "No se puede eliminar, lista vacia" << endl;
    } else {
        pNodoPais aux = primero;
        cout << aux->codigoPais;
        while (aux->codigoPais != codPais) {
            aux = aux->siguiente;
        }
        pNodoPais temp = aux;
        aux = aux->siguiente;
        aux->siguiente->anterior = aux->anterior;
        delete temp;
    }
}
*/