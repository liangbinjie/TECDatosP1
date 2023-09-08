#ifndef NODOFILA_H
#define NODOFILA_H

#include <iostream>
using namespace std;

class NodoFila {
	private:
		int idCliente;
		NodoFila *siguiente;
		
		friend class fila;
		
	public:
		NodoFila(int idCliente);
	
};

#endif
