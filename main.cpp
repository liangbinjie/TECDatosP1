#include "pais/listaPais.h"
#include "ciudad/listaCiudad.h"
#include "restaurant/listaRest.h"
#include <iostream>
using namespace std;

void clearScreen() {
    cout << string(50, '\n');
}

void menu(ListaPais& lPais, ListaCiudad& lCiudad, ListaRest& lRest) {
    cout << "Bienvenido, que desea realizar?" << endl;
    cout << "1. Insertar" << endl;
    cout << "2. Eliminar" << endl;
    cout << "3. Mostrar" << endl;
    cout << "4. Salir" << endl;
    int opcion;
    cout << "> ";
    cin >> opcion;
    string nombre;
    int codPais, codCiudad, codRest;
    switch(opcion) {
        case 1:
            cout << "Que deseas insertar?" << endl;
            cout << "1. Pais" << endl;
            cout << "2. Ciudad" << endl;
            cout << "3. Restaurante" << endl;
            cout << "> ";
            cin >> opcion;
            switch(opcion) {
                case 1:
                    cout << "Ingrese el codigo del pais: " << endl;
                    cin >> codPais;
                    cout << "Ingrese el nombre del pais: " << endl;
                    cin >> nombre;
                    lPais.insertar(codPais, nombre);
                    break;

                case 2:
                    cout << "Ingres el codigo del pais: " << endl;
                    cin >> codPais;
                    cout << "Ingrese el codigo de la ciudad: " << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el nombre de la ciudad: " << endl;
                    cin >> nombre;
                    lCiudad.insertar(codPais, codCiudad, nombre, lPais);
                    break;
                case 3:
                    cout << "Ingres el codigo del pais: " << endl;
                    cin >> codPais;
                    cout << "Ingrese el codigo de la ciudad: " << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el codigo del rest: " << endl;
                    cin >> codRest;
                    cout << "Ingrese el nombre del restaurante: " << endl;
                    cin >> nombre;
                    lRest.insertar(codPais, codCiudad, codRest, nombre, lPais, lCiudad);
                    break;
            }
            break;
        
        case 2:
            cout << "Que deseas eliminar?" << endl;
            cout << "1. Pais" << endl;
            cout << "2. Ciudad" << endl;
            cout << "> ";
            cin >> opcion;
            switch(opcion) {
                case 1:
                    cout << "Ingrese el codigo del pais que quieres eliminar: ";
                    cin >> codPais;
                    if (lPais.existePais(codPais)) {
                        lPais.eliminar(codPais);
                        cout << "Pais eliminado" << endl;
                    } else {
                        cout << "No se encontro el pais" << endl;
                    }
                    break;
                case 2:
                    cout << "Ingrese el codigo de la ciudad que quieres eliminar :";
                    cin >> codCiudad;
                    if (lCiudad.existeCiudad(codCiudad)) {
                        lCiudad.eliminar(codCiudad);
                        cout << "Ciudad eliminada" << endl;
                    } else {
                        cout << "No se encontro la ciudad" << endl;
                    }
                    break;
                case 3:
                    cout << "Ingrese el codigo del restaurante que quieres eliminar: ";
                    int codRest;
                    cin >> codRest;
                    if (lRest.existeRest(codRest)) {
                        lRest.eliminar(codRest);
                        cout << "Rest eliminado" << endl;
                    } else {
                        cout << "No se encontro el rest" << endl;
                    }
                    break;
            }
            break;
        
        case 3:
            cout << "Que deseas mostrar?" << endl;
            cout << "1. Pais" << endl;
            cout << "2. Ciudad" << endl;
            cout << "3. Restaurantes" << endl;
            cout << "> ";
            cin >> opcion;
            switch(opcion) {
                case 1:
                    lPais.mostrar();
                    break;
                case 2:
                    lCiudad.mostrar();
                    break;
                case 3:
                    lRest.mostrar();
                    break;
            }
            break;
        case 4:
            return;
    }
    menu(lPais, lCiudad, lRest);
}

int main() {
    ListaPais LPaises;
    LPaises.cargarPaises();
    ListaCiudad LCiudad;
    LCiudad.cargarCiudades(LPaises);
    ListaRest LRest;
    LPaises.mostrar();
    // clearScreen();
    menu(LPaises, LCiudad, LRest);
    // menu(LPaises,LCiudad);
    return 0;
}
