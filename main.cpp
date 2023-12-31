#include "pais/listaPais.h"
#include "ciudad/listaCiudad.h"
#include "restaurant/listaRest.h"
#include "menuRes/listaMenuRest.h"
#include "producto/listaProducto.h"
#include "cliente/listaCliente.h"
#include "compra/fila.h"
#include "compra/listaCompra.h"
#include <iostream>
using namespace std;

void clearScreen() {
    cout << string(50, '\n');
}

void menu(ListaPais& lPais, ListaCiudad& lCiudad, ListaRest& lRest, ListaMenuRest& lMenu, ListaProducto& lProducto, ListaCliente& lCliente, fila& Fila, ListaCompra& lCompra) {
    cout << endl;
	cout << "Bienvenido, que desea realizar?" << endl;
	cout << endl;
    cout << "1. Insertar" << endl;
    cout << "2. Eliminar" << endl;
    cout << "3. Mostrar" << endl;
    cout << "4. Modificar" << endl;
    cout << "5. Buscar" << endl;
    cout << "6. Comprar" << endl;
    cout << "7. Reportes" << endl;
    cout << "8. Salir" << endl;
    int numPais;
    int opcion;
    cout << "> ";
    cin >> opcion;
    string nombre;
    int codPais, codCiudad, codRest, codMenu, codProducto, codCliente, calorias, precio;
    switch(opcion) {
        case 1:
        	cout << endl;
            cout << "Que deseas insertar?" << endl;
            cout << endl;
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
                	cout << endl;
                    cout << "Ingrese el codigo del pais: " << endl;
                    cin >> codPais;
                    cout << "Ingrese el nombre del pais: " << endl;
                    cin.ignore();
                    getline(cin,nombre);
                    lPais.insertar(codPais, nombre);
                    break;

                case 2:
                	cout << endl;
                    cout << "Ingrese el codigo del pais: " << endl;
                    cin >> codPais;
                    cout << "Ingrese el codigo de la ciudad: " << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el nombre de la ciudad: " << endl;
                    cin.ignore();
                    getline(cin,nombre);
                    lCiudad.insertar(codPais, codCiudad, nombre, lPais);
                    break;

                case 3:
                	cout << endl;
                    cout << "Ingrese el codigo del pais: " << endl;
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
                	cout << endl;
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
                    lMenu.insertarMenuRest(codPais, codCiudad, codRest,codMenu,nombre,lPais,lCiudad,lRest);
                    break;
                
                case 5:
                	cout << endl;
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
                    lProducto.insertarProducto(codPais, codCiudad, codRest, codMenu, codProducto, nombre, calorias, precio, lPais, lCiudad, lRest, lMenu);
                    break;

                case 6:
                	cout << endl;
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
        	cout << endl;
            cout << "Que deseas eliminar?" << endl;
            cout << endl;
            cout << "1. Pais" << endl;
            cout << "2. Ciudad" << endl;
            cout << "3. Restaurante" << endl;
            cout << "4. Menu" << endl;
            cout << "5. Producto" << endl;
            cout << "6. Clientes" << endl;
            cout << "> ";
            cin >> opcion;
            switch(opcion) {
                case 1:cout << endl;
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
                	cout << endl;
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
                	cout << endl;
                    cout << "Ingrese el codigo del restaurante que quieres eliminar: ";
                    cin >> codRest;
                    cout << "Ingrese el codigo del pais del restaurante: ";
                    cin >> codPais;
                    cout << "Ingrese el codigo de ciudad del restaurante: ";
                    cin >> codCiudad;
                    if (lRest.existeRest(codPais, codCiudad, codRest, lPais, lCiudad)) {
                        lRest.eliminar(codRest);
                        cout << "Rest eliminado" << endl;
                    } else {
                        cout << "No se encontro el rest" << endl;
                    }
                    break;

                case 4:
                	cout << endl;
                    cout << "Ingrese el codigo del menu que quieres eliminar: ";
                    cin >> codMenu;
                    cout << "Ingrese el codigo del restaurante del menu: ";
                    cin >> codRest;
                    cout << "Ingrese el codigo de la ciudad del menu: ";
                    cin >> codCiudad;
                    cout << "Ingrese el codigo del pais del menu: ";
                    cin >> codPais;
                    lMenu.eliminar(codMenu, codPais, codCiudad, codRest);
                    break;
                case 5:
                	cout << endl;
                   cout << "Ingrese el codigo del producto que quieres eliminar :";
                   cin >> codProducto;
                   cout << "Ingrese el codigo del menu del producto que quieres eliminar :";
                   cin >> codMenu;
                   cout << "Ingrese el codigo del restaurante que tiene el producto que quieres eliminar: ";
                    cin >> codRest;
                    cout << "Ingrese el codigo de ciudad del producto: ";
                    cin >> codCiudad;
                    cout << "Ingrese el codigo del pais que tiene el producto: ";
                    cin >> codPais;
                   if (lProducto.existeProducto(codPais, codCiudad,codRest,codMenu, codProducto, lPais, lCiudad,lRest,lMenu)) {
                       lProducto.eliminar(codProducto);
                   } else {
                       cout << "No se pudo encontrar el producto" << endl;
                   }
                    break;
                
                case 6:
                	cout << endl;
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
        	cout << endl;
            cout << "Que deseas mostrar?" << endl;
            cout << endl;
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
                	cout << endl;
                    lPais.mostrar();
                    break;
                case 2:
                	cout << endl;
                    lCiudad.mostrar();
                    break;
                case 3:
                	cout << endl;
                    lRest.mostrar();
                    break;

                case 4:
                	cout << endl;
                    lMenu.mostrar();
                    break;
                
                case 5:
                	cout << endl;
                    lProducto.mostrar();
                    break;

                case 6:
                	cout << endl;
                    lCliente.mostrar();
                    break; 
            }
            break;

        case 4:
        	cout << endl;
            cout << "Que deseas MODIFICAR?" << endl;
            cout << endl;
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
                	cout << endl;
                    cout << "Ingrese el numero del pais que quiere MODIFICAR: ";
                    cin >> numPais;
                    cout << "Ingrese el nuevo nombre que quiere MODIFICAR: ";
                    cin.ignore();
                    getline(cin,nombre);
                    lPais.modificarNombre(numPais, nombre);
                    break;
                case 2:
                	cout << endl;
                    cout << "Ingrese el codigo del pais al que pertenece la ciudad: ";
                    cin >> codPais;
                    cout << "Ingrese el codigo de la ciudad: ";
                    cin >> codCiudad;
                    cout << "Ingrese el nuevo nombre que quiere MODIFICAR: ";
                    cin.ignore();
                    getline(cin,nombre);
                	lCiudad.modificarCiudad(codPais, codCiudad, nombre, lPais);
                    break;
                case 3:
                	cout << endl;
                    cout << "Ingres el codigo del pais: ";
                    cin >> codPais;
                    cout << "Ingrese el codigo de la ciudad: ";
                    cin >> codCiudad;
                    cout << "Ingrese el codigo del rest: ";
                    cin >> codRest;
                    cout << "Ingrese el nuevo nombre del restaurante: ";
                    cin.ignore();
                    getline(cin,nombre);
                    if (lRest.existeRest(codPais, codCiudad, codRest, lPais, lCiudad)) {
                        lRest.modificarRest(codPais, codCiudad, codRest, lPais, lCiudad, nombre);
                        cout << "Nombre del restaurante modificado a: " << nombre << endl;
                    } else {
                        cout << "No se encontro el restaurante en la base d datos" << endl;
                    }
                    break;

                case 4:
                	cout << endl;
                    cout << "Ingres el codigo del pais: ";
                    cin >> codPais;
                    cout << "Ingrese el codigo de la ciudad: ";
                    cin >> codCiudad;
                    cout << "Ingrese el codigo del rest: ";
                    cin >> codRest;
                    cout << "Ingrese el codigo del menu: ";
                    cin >> codMenu;
                    cout << "Ingrese el nuevo nombre del menu: ";
                    cin.ignore();
                    getline(cin,nombre);
                    lMenu.modificarMenu(codPais,codCiudad, codRest, nombre, codMenu);
                    break;
                
                case 5:
                	cout << endl;
                    cout << "Ingres el codigo del pais: ";
                    cin >> codPais;
                    cout << "Ingrese el codigo de la ciudad: ";
                    cin >> codCiudad;
                    cout << "Ingrese el codigo del rest: ";
                    cin >> codRest;
                    cout << "Ingrese el codigo del menu: ";
                    cin >> codMenu;
                    cout << "Ingrese el codigo del producto: ";
                    cin >> codProducto;
                    cout << "Ingrese el nuevo nombre del producto: ";
                    cin.ignore();
                    getline(cin,nombre);
                    cout << "Ingrese el monto de calorias a modificar: ";
                    cin >> calorias;
                    cout << "Ingrese el precio a modificar: ";
                    cin >> precio;
                    lProducto.modificarProducto(codPais, codCiudad, codRest, codMenu, codProducto, nombre, calorias, precio, lPais, lCiudad, lRest, lMenu);
                    break;

                case 6:
                	cout << endl;
                    cout << "Ingrese la identificacion del cliente que desea modificar: ";
                    cin >> codCliente;
                    cout << "Ingrese el nuevo nombre: ";
                    cin >> nombre;
                    lCliente.modificarNombre(codCliente, nombre);
                    break; 
            }
            break;
        
        case 5:
        	cout << endl;
            cout << "Que deseas BUSCAR?" << endl;
            cout << endl;
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
                	cout << endl;
                    cout << "Ingrese el numero del pais que quiere mostrar: " << endl;
                    cin >> numPais;
                    lPais.buscarPais(numPais);
                    break;
                case 2:
                	cout << endl;
                    cout << "Ingrese el codigo de pais de la ciudad que quieres buscar: " << endl;
                    cin >> numPais;
                    cout << "Ingrese el codigo de ciudad que deseas buscar: " << endl;
                    cin >> codCiudad;
                    lCiudad.buscarCiudad(numPais, codCiudad);
                    break;
                case 3:
                	cout << endl;
                    cout << "Ingrese el numero del pais del que quiere ver el restaurante" << endl;
                    cin >> codPais;
                    cout << "Ingrese el numero de la ciudad del que quiere ver el restaurante" << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el numero del restaurante" << endl;
                    cin >> codRest;
                    lRest.buscarRest(codPais, codCiudad, codRest, lPais, lCiudad);
                    break;
                case 4:
                	cout << endl;
                    cout << "Ingrese el numero del pais del que quiere ver el menu" << endl;
                    cin >> codPais;
                    cout << "Ingrese el numero de la ciudad del que quiere ver el menu" << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el numero del restaurante del que quiere ver el menu" << endl;
                    cin >> codRest;
                    cout << "Ingrese el numero del menu" << endl;
                    cin >> codMenu;
                    lMenu.buscarMenuRest(codPais, codCiudad, codRest, codMenu, lPais, lCiudad, lRest);
                    break;
                case 5:
                	cout << endl;
                    cout << "Ingrese el numero del pais del que quiere ver el producto" << endl;
                    cin >> codPais;
                    cout << "Ingrese el numero de la ciudad del que quiere ver el producto" << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el numero del restaurante del que quiere ver el producto" << endl;
                    cin >> codRest;
                    cout << "Ingrese el numero del menu del que quiere ver el producto" << endl;
                    cin >> codMenu;
                    cout << "Ingrese el numero del producto" << endl;
                    cin >> codProducto;
                    lProducto.buscarProducto(codPais, codCiudad, codRest, codMenu, codProducto, lPais, lCiudad, lRest, lMenu);
                    break;
                case 6:
                	cout << endl;
                    cout << "Ingrese la identificacion del cliente: ";
                    cin >> codCliente;
                    lCliente.buscarCliente(codCliente);
                    break; 
            }
            break;


        case 6:
        	cout << endl;
        	cout << "Que deseas hacer?" << endl;
        	cout << endl;
        	cout << "1. Hacer fila para comprar" << endl;
        	cout << "2. Atender a cliente" << endl;
        	cin >> opcion;
        	switch(opcion) {
        		case 1:
        			cout << endl;
        			if (Fila.largoFila() == 5) {
        				cout << "No se puede hacer mas fila, porque ya esta lleno" << endl;
					} else {
						cout << "Ingrese su identificacion: ";
						cin >> codCliente;
						if (lCliente.existeCliente(codCliente)) {
							Fila.encolar(codCliente);
							Fila.imprimir();
						} else {
							cout << "Esta identificacion no existe en la base de datos" << endl;
						}
 					}
 					break;

				case 2:
					cout << endl;
					if (Fila.filaVacia()) {
						cout << "No hay clientes que atender" << endl;
					} else {
						codCliente = Fila.atender();
                        cout << "Ingrese el pais donde se encuentra el restaurante: ";
                        cin >> codPais;
                        cout << "Ingrese la ciudad donde se encuentra el restaurante: ";
                        cin >> codCiudad;
                        cout << "Ingrese el codigo del restaurante: ";
                        cin >> codRest;
                        cout << "Ingrese el id menu que quieres comprar: ";
                        cin >> codMenu;
                        if (lMenu.existeMenuRest(codPais, codCiudad, codRest, codMenu, lPais, lCiudad, lRest)) {
                            // while (true)
                            while (true) {
                                lProducto.mostrarProductosMenu(codPais, codCiudad, codRest, codMenu);
                                int codProd;
                                string compra = "";
                                cout << "Que desea comprar?: ";
                                cin >> codProd;
                                if (lProducto.existeProducto(codPais, codCiudad, codRest, codMenu, codProd, lPais, lCiudad, lRest, lMenu)) {
                                    compra += codProd + ";";
                                    lProducto.aumentarCompra(codPais, codCiudad, codRest, codMenu, codProd, lPais, lCiudad, lRest, lMenu);
                                    cout << "Producto agregado a la compra" << endl;
                                } else {
                                    cout << "Ingrese un producto valido" << endl;
                                }
                                cout << "Desea seguir comprando? y/n" << endl;
                                char seguir;
                                cin >> seguir;
                                if (seguir == 'n') {
                                    //cout << compra << endl;
                                    lCompra.agregar(codCliente, codPais, codCiudad, codRest, codMenu, compra);
                                    cout << "Por favor espere en la fila de pagar" << endl;
                                    //lCompra.mostrar();
                                    break;
                                }
                            }

                        } else {
                            cout << "No existe este menu" << endl;
                        }
					}
					break;			
			}
			
			break;
            

        case 7:
            cout << endl;
            cout << "Reportes" << endl;
            cout << endl;
            cout << "1. Paises" << endl;
            cout << "2. Ciudades" << endl;
            cout << "3. Restaurantes" << endl;
            cout << "4. Clientes" << endl;
            cout << "5. Restaurante mas buscado" << endl;
            cout << "6. Menu mas buscado" << endl;
            cout << "7. Producto mas comprado" << endl;
            cout << "8. Consultar el precio de un producto" << endl;
            cout << "> ";
            cin >> opcion;
            switch(opcion) {
                case 1:
                	cout << endl;
                    cout << "Reporte del pais: " << endl;
                    lPais.reportePaises();
                    cout << "Proceso finalizado" << endl;
                    break;
                case 2:
                    cout << endl;
                    cout << "Ingrese el codigo del pais del que quiere ver las ciudades" << endl;
                    cin >> codPais;
                    lCiudad.reporteCiudades(codPais);
                    cout << "Proceso finalizado" << endl;
                    break;
                case 3:
                	cout << endl;
                    cout << "Ingrese el numero del pais del que quiere ver el restaurante" << endl;
                    cin >> codPais;
                    cout << "Ingrese el numero de la ciudad del que quiere ver el restaurante" << endl;
                    cin >> codCiudad;
                    lRest.restPaisCiudad(codPais, codCiudad, lPais, lCiudad);
                    cout << "Proceso finalizado" << endl;
                    break;
                case 4:
                	lCliente.reporteClientes();
                    cout << "Proceso finalizado" << endl;
                    break;
                case 5:
                	cout << endl;
                    lRest.reporteRestBuscado();
                    cout << "Proceso finalizado" << endl;
                    break;
                case 6:
                	cout << endl;
                    lMenu.menuMasBuscado();
                    cout << "Proceso finalizado" << endl;
                    break; 
                case 7:
                    cout << endl;
                    lProducto.productoMasComprado();
                    cout << "Proceso finalizado" << endl;
                    break;

                case 8:
                    cout << endl;
                    cout << "Ingrese el numero del pais del que quiere ver el producto" << endl;
                    cin >> codPais;
                    cout << "Ingrese el numero de la ciudad del que quiere ver el producto" << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el numero del restaurante del que quiere ver el producto" << endl;
                    cin >> codRest;
                    cout << "Ingrese el numero del menu del que quiere ver el producto" << endl;
                    cin >> codMenu;
                    cout << "Ingrese el numero del producto" << endl;
                    cin >> codProducto;
                    lProducto.precio(codPais, codCiudad, codRest, codMenu, codProducto, lPais, lCiudad, lRest, lMenu);
                    cout << "Proceso finalizado" << endl;
                    break;
            }
            break;

            
    	case 8:
            return;
    }
    menu(lPais, lCiudad, lRest, lMenu, lProducto, lCliente, Fila, lCompra);
}

int main() {
    ListaPais LPaises;
    LPaises.cargarPaises();

    ListaCiudad LCiudad;
    LCiudad.cargarCiudades(LPaises);

    ListaRest LRest;
    LRest.cargarRests(LPaises, LCiudad);

    ListaMenuRest LMenu;
    LMenu.cargarMenuRest(LPaises, LCiudad, LRest);

    ListaProducto LProducto;
    LProducto.cargarProductos(LPaises, LCiudad, LRest, LMenu);

    ListaCliente LCliente;
    LCliente.cargarCliente();
    
    fila Fila;

    ListaCompra lCompra;
    
    clearScreen();
    menu(LPaises, LCiudad, LRest, LMenu, LProducto, LCliente, Fila, lCompra);
  
    return 0;
}

