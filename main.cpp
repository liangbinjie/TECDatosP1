#include "pais/listaPais.h"
#include "ciudad/listaCiudad.h"
#include <iostream>
using namespace std;

void clearScreen() {
    cout << string(50, '\n');
}

void menu(ListaPais& lPais, ListaCiudad lCiudad) {
    cout << "Bienvenido, que desea realizar?" << endl;
    cout << "1. Insertar" << endl;
    cout << "2. Eliminar" << endl;
    cout << "3. Mostrar" << endl;
    cout << "4. Salir" << endl;
    int opcion;
    cout << "> ";
    cin >> opcion;
    string nombre;
    int codPais, codCiudad;
    switch(opcion) {
        case 1:
            cout << "Que deseas insertar?" << endl;
            cout << "1. Pais" << endl;
            cout << "2. Ciudad" << endl;
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
                    int codigo;
                    cin >> codigo;
                    if (lPais.existePais(codigo)) {
                        lPais.eliminar(codigo);
                        cout << "Pais eliminado" << endl;
                    } else {
                        cout << "No se encontro el pais" << endl;
                    }
                    break;
            }
            break;
        
        case 3:
            cout << "Que deseas mostrar?" << endl;
            cout << "1. Pais" << endl;
            cout << "2. Ciudad" << endl;
            cout << "> ";
            cin >> opcion;
            switch(opcion) {
                case 1:
                    lPais.mostrar();
                    break;
                case 2:
                    lCiudad.mostrar();
                    break;
            }
            break;
        case 4:
            return;
    }
    menu(lPais, lCiudad);
}

int main() {
    ListaPais LPaises;
    LPaises.cargarPaises();
    ListaCiudad LCiudad;
    LPaises.mostrar();
    clearScreen();
    menu(LPaises, LCiudad);
    return 0;
}
