#include "nodoCompra.h"

NodoCompra::NodoCompra(int idCliente, int cp, int cc, int cr, int cm, string pp) {
	this->idCliente = idCliente;
	idPais = cp;
	idCiudad = cc;
	idRest = cr;
	idMenu = cm;
	productos = pp;
	siguiente = NULL;
}

