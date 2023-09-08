#include "fila.h"

fila::fila() {
    primero = NULL;
}

bool fila::filaVacia(){return primero == NULL;}    

int fila::largoFila() {
	int cont = 0;
    pNodoFila aux = primero;
    if (filaVacia()) {
        return cont;
    } else {
        while (aux!=NULL) {
            aux=aux->siguiente;
            cont++;
        }
        return cont;
        cout << endl;
    }
}

void fila::encolar(int idCliente) {
    if (filaVacia()) {
		primero = new NodoFila(idCliente);
	} else {
		pNodoFila aux = primero;
		while (aux->siguiente != NULL) {
			aux = aux->siguiente;
		}
		aux->siguiente = new NodoFila(idCliente);
	}
	cout << "Nuevo cliente haciendo fila" << endl;
}

void fila::atender() {
    if (filaVacia()) {
    	cout << "No hay clientes que atender" << endl;
	} else {
		cout << "Atendiendo a cliente: " << primero->idCliente << endl;
		if (primero->siguiente == NULL) {
			pNodoFila temp = primero;
			primero = NULL;
			delete temp;
		} else {
			pNodoFila aux = primero;
			primero = primero->siguiente;
			delete aux;
		}
	}
}

void fila::imprimir() {
    if (filaVacia()) {
    	cout << "No hay clientes en fila" << endl;
	} else {
		pNodoFila aux = primero;
		while (aux) {
			cout << aux->idCliente << " - ";
			aux = aux->siguiente;
		}
	}
}
