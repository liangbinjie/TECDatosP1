#include "pais/ListaPais.h"
#include <iostream>
using namespace std;

int main() {
    ListaPais L1;
    L1.insertar(12,"CR");
    L1.insertar(13,"EEUU");
    L1.mostrar();

    return 0;
}