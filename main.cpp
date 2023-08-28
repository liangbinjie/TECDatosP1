#include "pais/listaPais.h"
#include "ciudad/listaCiudad.h"
#include <iostream>
using namespace std;

int main() {


    ListaPais L1;
    L1.cargarPaises();
    L1.insertarP(12,"CR");
    L1.insertarP(13,"EEUU");
    L1.insertarP(14,"PNA");
    L1.mostrar();
    L1.eliminar(14);
    L1.mostrar();

    ListaCiudad L1C(L1);

    L1C.insertarEnLista(12, 3, "cartago");
    L1C.mostrar();

    return 0;
}
