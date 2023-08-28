#include "pais/listaPais.h"
#include "ciudad/listaCiudad.h"
#include <iostream>
using namespace std;

int main() {
    ListaPais L1;
    L1.cargarPaises();
    L1.insertar(12,"CR");
    L1.insertar(13,"EEUU");
    L1.insertar(14,"PNA");
    L1.mostrar();
    L1.eliminar(14);
    L1.mostrar();

    return 0;
}
