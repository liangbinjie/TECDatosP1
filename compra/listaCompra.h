#ifndef LISTACOMPRA_H
#define LISTACOMPRA_H

#include <iostream>
#include "nodoCompra.h"
using namespace std;

typedef NodoCompra* pNodoCompra;

class ListaCompra {
   private:
	   pNodoCompra primero;
	   
	public:
	    ListaCompra();
		void agregar(int idCliente, int cp, int cc, int cr, int cm, string compra);
		void mostrar();
	    
};

#endif
