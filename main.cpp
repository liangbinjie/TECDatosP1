#include "pais/listaPais.h"
#include <iostream>
using namespace std;

void clearScreen() {
    cout << string(50, '\n');
}

void menu(ListaPais& lPais) {
    cout << "Bienvenido, que desea realizar?" << endl;
    cout << "1. Insertar" << endl;
    cout << "2. Eliminar" << endl;
    cout << "3. Mostrar" << endl;
    cout << "4. Salir" << endl;
    int opcion;
    cout << "> ";
    cin >> opcion;
    switch(opcion) {
        case 1:
            cout << "Que deseas insertar?" << endl;
            cout << "1. Pais" << endl;
            cout << "2. Ciudad" << endl;
            cout << "> ";
            cin >> opcion;
            switch(opcion) {
                case 1:
                    string nombre;
                    int codigo;
                    cout << "Ingrese el codigo del pais: " << endl;
                    cin >> codigo;
                    cout << "Ingrese el nombre del pais: " << endl;
                    cin >> nombre;
                    lPais.insertar(codigo, nombre);
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
                        cout << "No se encontro el pais";
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
            }
            break;
        case 4:
            return;
    }
    menu(lPais);
}

int main() {
    ListaPais LPaises;
    LPaises.cargarPaises();
    LPaises.mostrar();
    clearScreen();
    menu(LPaises);


    return 0;
}
