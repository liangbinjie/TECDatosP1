#ifndef FILA_H
#define FILA_H

#include <iostream>
#include "nodoFila.h"
using namespace std;

typedef NodoFila* pNodoFila;

class fila {
   private:
	   pNodoFila primero;
	   
	public:
	    fila();
	    int largoFila();
	    bool filaVacia();        
	    void encolar(int id); 
	    int atender ();
	    void imprimir();
};

#endif
