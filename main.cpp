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
    int numPais;
    int opcion;
    cout << "> ";
    cin >> opcion;
    string nombre;
    int codPais, codCiudad, codRest, codMenu, codProducto, codCliente, calorias, precio;
    switch(opcion) {
        case 1:
            cout << "Que deseas insertar?" << endl;
            cout << "1. Pais" << endl;
            cout << "2. Ciudad" << endl;
            cout << "3. Restaurante" << endl;
            cout << "4. Menu" << endl;
            cout << "5. Producto" << endl;
            cout << "6. Clientes" << endl;
            cout << "> ";
            cin >> opcion;
            switch(opcion) {
                case 1:
                    cout << "Ingrese el codigo del pais: " << endl;
                    cin >> codPais;
                    cout << "Ingrese el nombre del pais: " << endl;
                    cin.ignore();
                    getline(cin,nombre);
                    lPais.insertar(codPais, nombre);
                    break;

                case 2:
                    cout << "Ingres el codigo del pais: " << endl;
                    cin >> codPais;
                    cout << "Ingrese el codigo de la ciudad: " << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el nombre de la ciudad: " << endl;
                    cin.ignore();
                    getline(cin,nombre);
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
                    cin.ignore();
                    getline(cin,nombre);
                    lRest.insertar(codPais, codCiudad, codRest, nombre, lPais, lCiudad);
                    break;
                
                case 4:
                    //Menu
                    break;
                
                case 5:
                    cout << "Ingres el codigo del pais: " << endl;
                    cin >> codPais;
                    cout << "Ingrese el codigo de la ciudad: " << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el codigo del rest: " << endl;
                    cin >> codRest;
                    cout << "Ingrese el codigo del menu: " << endl;
                    cin >> codMenu;
                    cout << "Ingrese el codigo del producto: " << endl;
                    cin >> codProducto;
                    cout << "Ingrese el nombre del producto: " << endl;
                    cin.ignore();
                    getline(cin,nombre);
                    cout << "Ingrese la cantidad de caloria del producto: " << endl;
                    cin >> calorias;
                    cout << "Ingrese el precio del producto: " << endl;
                    cin >> precio;
                    // lProductos.insertar(codPais, codCiudad, codRest, codMenu, codProducto, nombre, calorias, precio, lPais, lCiudad, lRest, lMenu);
                    break;

                case 6:
                    cout << "Ingres la identificacion del cliente: " << endl;
                    cin >> codCliente;
                    cout << "Ingrese el nombre del cliente: " << endl;
                    cin.ignore();
                    getline(cin,nombre);
                    // lClientes.insertar(codCliente, nombre);
                    break;
            }
            break;
        
        case 2:
            cout << "Que deseas eliminar?" << endl;
            cout << "1. Pais" << endl;
            cout << "2. Ciudad" << endl;
            cout << "3. Restaurante" << endl;
            cout << "4. Menu" << endl;
            cout << "5. Producto" << endl;
            cout << "6. Clientes" << endl;
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

                //agregar los demas cases
            }
            break;
        
        case 3:
            cout << "Que deseas mostrar?" << endl;
            cout << "1. Pais" << endl;
            cout << "2. Ciudad" << endl;
            cout << "3. Restaurante" << endl;
            cout << "4. Menu" << endl;
            cout << "5. Producto" << endl;
            cout << "6. Clientes" << endl;
            cout << "> ";
            cin >> opcion;
            switch(opcion) {
                case 1:
                    lPais.mostrar();
                    break;
                case 2:
                cout << "Ingrese el numero del pais del que quiere ver las ciudades" << endl;
                    cin >> numPais;
                    lCiudad.mostrar(numPais);
                    break;
                case 3:
                    lRest.mostrar();
                    break;

                // case 4:
                //     lMenu.mostrar();
                //     break;
                
                // case 5:
                //     lProducto.mostrar();
                //     break;

                // case 6:
                //     lCliente.mostrar();
                //     break;
                

            }
            break;
        case 4:
            return;
    }
    menu(lPais, lCiudad, lRest);
}

int main() {
    cout << "hopa";
    ListaPais LPaises;
    LPaises.cargarPaises();
    ListaCiudad LCiudad;
    LCiudad.cargarCiudades(LPaises);
    ListaRest LRest;
    // LRest.insertar(123,345,456,"mac", LPaises, LCiudad);
    // LRest.insertar(123,345,876,"qwe", LPaises, LCiudad);
    // LRest.insertar(123,345,4563,"kfc", LPaises, LCiudad);
    // LRest.insertar(123,345,687,"pollo", LPaises, LCiudad);
    LPaises.mostrar();
    // clearScreen();
    menu(LPaises, LCiudad, LRest);
    // menu(LPaises,LCiudad);
    return 0;
}
