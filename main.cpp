#include "pais/listaPais.h"
#include "ciudad/listaCiudad.h"
#include "restaurant/listaRest.h"
#include "menuRes/listaMenuRest.h"
#include "producto/listaProducto.h"
#include "cliente/listaCliente.h"
#include <iostream>
using namespace std;

void clearScreen() {
    cout << string(50, '\n');
}

void menu(ListaPais& lPais, ListaCiudad& lCiudad, ListaRest& lRest, ListaMenuRest& lMenu, ListaProducto& lProducto, ListaCliente& lCliente) {
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
                    cout << "Ingrese el codigo del pais: " << endl;
                    cin >> codPais;
                    cout << "Ingrese el codigo de la ciudad: " << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el codigo del rest: " << endl;
                    cin >> codRest;
                    cout << "Ingrese el codigo del menu: " << endl;
                    cin >> codMenu;
                    cout << "Ingrese el nombre del menu " << endl;
                    cin.ignore();
                    getline(cin,nombre);
                    lMenu.insertarMenuRest(codPais, codMenu,codRest,codMenu,nombre,lPais,lCiudad,lRest);
                    break;
                
                case 5:
                    cout << "Ingrese el codigo del pais: " << endl;
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
                    lProducto.insertar(codPais, codCiudad, codRest, codMenu, codProducto, nombre, calorias, precio, lPais, lCiudad, lRest, lMenu);
                    break;

                case 6:
                    cout << "Ingrese la identificacion del cliente: " << endl;
                    cin >> codCliente;
                    cout << "Ingrese el nombre del cliente: " << endl;
                    cin.ignore();
                    getline(cin,nombre);
                    lCliente.insertar(codCliente, nombre);
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
                        lCiudad.eliminarCiudades(codPais);
                        cout << "Pais eliminado" << endl;
                    } else {
                        cout << "No se encontro el pais" << endl;
                    }
                    break;
                case 2:
                    cout << "Ingrese el codigo de la ciudad que quieres eliminar :";
                    cin >> codCiudad;
                    cout << "Ingrese el codigo del pais de la ciudad: ";
                    cin >> codPais;
                    if (lCiudad.existeCiudad(codPais, codCiudad, lPais)) {
                        lCiudad.eliminar(codCiudad);
                        cout << "Ciudad eliminada" << endl;
                    } else {
                        cout << "No se encontro la ciudad" << endl;
                    }
                    break;

                case 3:
                    cout << "Ingrese el codigo del restaurante que quieres eliminar: ";
                    cin >> codRest;
                    cout << "Ingrese el codigo del pais del restaurante: ";
                    cin >> codPais;
                    cout << "Ingrese el codigo de ciudad del restaurante: ";
                    cin >> codCiudad;
                    if (lRest.existeRest(codPais, codCiudad, codRest, lCiudad, lPais)) {
                        lRest.eliminar(codRest);
                        cout << "Rest eliminado" << endl;
                    } else {
                        cout << "No se encontro el rest" << endl;
                    }
                    break;

                case 4:
                     cout << "Ingrese el codigo del menu que quieres eliminar: ";
                    cin >> codMenu;
                    cout << "Ingrese el codigo del restaurante del menu: ";
                    cin >> codRest;
                    cout << "Ingrese el codigo de la ciudad del menu: ";
                    cin >> codCiudad;
                    cout << "Ingrese el codigo del pais del menu: ";
                    cin >> codPais;
                    if (lMenu.existeMenuRest(codPais, codCiudad, codRest, codMenu, lCiudad, lPais, lRest)) {
                        lMenu.eliminar(codMenu);
                        cout << "Menu eliminado" << endl;
                    } else {
                        cout << "No se encontro el menu" << endl;
                    }
                    break;
                
                case 5:
                   cout << "Ingrese el codigo del producto que quieres eliminar :";
                   cin >> codProducto;
                   if (lProducto.existeProducto(codProducto)) {
                       lProducto.eliminar(codProducto);
                   } else {
                       cout << "No se pudo encontrar el producto" << endl;
                   }
                    break;
                
                case 6:
                    cout << "Ingrese la identificacion del cliente que quieres eliminar :";
                    cin >> codCliente;
                    if (lCliente.existeCliente(codCliente)) {
                        lCliente.eliminar(codCliente);
                    } else {
                        cout << "No se pudo encontrar el cliente" << endl;
                    }
                    break;

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
                    lCiudad.mostrarDeUnPais(numPais);
                    break;
                case 3:
                    lRest.mostrar();
                    break;

                case 4:
                    // lMenu.mostrar();
                    break;
                
                case 5:
                    lProducto.mostrar();
                    break;

                case 6:
                    lCliente.mostrar();
                    break;
                

            }
            break;
        case 4:
            return;
    }
    menu(lPais, lCiudad, lRest, lMenu, lProducto, lCliente);
}

int main() {
    ListaPais LPaises;
    LPaises.cargarPaises();
    ListaCiudad LCiudad;
    
    LCiudad.cargarCiudades(LPaises);
    ListaRest LRest;
    LRest.cargarRests(LPaises, LCiudad);
    LRest.existeRest(123, 346, 34, LCiudad, LPaises);
    LRest.mostrar();

    ListaMenuRest LMenu;
    cout << "hols";
    //LMenu.insertarMenuRest(123,345,34,1,"mcpollo",LPaises, LCiudad, LRest);
    LPaises.mostrar();
    LMenu.insertarMenuRest(345,987,456,90,"mcpo",LPaises, LCiudad, LRest);
    LMenu.mostrar();
    LMenu.insertarMenuRest(4567,234,876,100,"mcpohh",LPaises, LCiudad, LRest);
    LMenu.mostrar();
    LMenu.insertarMenuRest(123,345,2341,2,"llo",LPaises, LCiudad, LRest);
    LMenu.mostrar();
    cout << "sss" << endl;
    LMenu.mostrar();
    //LMenu.cargarMenuRest(LPaises, LCiudad, LRest);
    //cout << "sss" << endl;
    //LMenu.mostrar();
    ListaProducto LProducto;
    LProducto.cargarProductos(LPaises, LCiudad, LRest, LMenu);
    ListaCliente LCliente;
    LCliente.cargarCliente();
    clearScreen();
    menu(LPaises, LCiudad, LRest, LMenu, LProducto, LCliente);
    return 0;
}
