#include <fstream>
#include <iostream>
#include <string>

#include "BibliotecaReportes/BibliotecaReportes.h"
#include "BibliotecaReportes/BibliotecaReportesArboles.h"
#include "Estructuras/Arboles/ArbolB.h"
#include "Estructuras/Arboles/ArbolAA/ArbolAA.h"
#include "Estructuras/Arboles/ArbolAVL/ArbolAVL.h"
#include "Estructuras/Arboles/ArbolBinario/ArbolBinario.h"
#include "Estructuras/Arboles/ArbolRN/ArbolRN.h"
#include "Estructuras/ListaDoble/ListaDoble.h"
#include "Estructuras/ListaSimple/ListaSimple.h"
#include "Estructuras/ListaDobleCircular/ListaDobleCircular.h"
#include "Estructuras/ListaCircular/ListaCircular.h"
#include "Estructuras/Nodos/NodosDerivados/Administrador/NodoAdmin.h"
#include "Estructuras/Nodos/NodosDerivados/Inventario/NodoInventario.h"
#include "Estructuras/Nodos/NodosDerivados/Pasillo/NodoPasillo.h"
#include "Estructuras/Nodos/NodosDerivados/Producto/NodoProducto.h"
#include "Estructuras/Nodos/NodosDerivados/Marca/NodoMarca.h"
#include "Estructuras/Nodos/NodosDerivados/Ciudad/NodoCiudad.h"
#include "Estructuras/Nodos/NodosDerivados/Clientes/NodoCliente.h"
#include "Estructuras/TablaHash/TablaHash.h"
#include "Menu/MenuFunciones.h"
#include "Menu/MenuFuncionesAdmin.h"
#include "Menu/MenuFuncionesCliente.h"

static const string DIRECTORIO = "../Archivos/";
#pragma region CargaListas
ListaSimple* CargarPasillos(string NombreArchivo)
{
    ifstream Archivo;
    ListaSimple* ListaArchivo = new ListaSimple();
    const string Directorio = DIRECTORIO+NombreArchivo;
    cout<<Directorio<<endl;
    Archivo.open(Directorio);
    for(string Linea; getline(Archivo, Linea);)
    {
        ListaArchivo->InsertarFinal(new NodoPasillo(Linea));
    }
    return ListaArchivo;
}
ListaDoble* CargarProductosPasillo(string NombreArchivo)
{
    ifstream Archivo;
    ListaDoble* ListaArchivo = new ListaDoble();
    const string Directorio = DIRECTORIO+NombreArchivo;
    cout<<Directorio<<endl;
    Archivo.open(Directorio);
    for(string Linea; getline(Archivo, Linea);)
    {
        ListaArchivo->InsertarFinal(new NodoProducto(Linea));
    }
    return ListaArchivo;
}
ListaDoble* CargarInventario(string NombreArchivo)
{
    ifstream Archivo;
    ListaDoble* ListaArchivo = new ListaDoble();
    const string Directorio = DIRECTORIO+NombreArchivo;
    cout<<Directorio<<endl;
    Archivo.open(Directorio);
    for(string Linea; getline(Archivo, Linea);)
    {
        if (Linea.empty()) continue;
        ListaArchivo->InsertarFinal(new NodoInventario(Linea));
    }
    return ListaArchivo;
}
ListaDobleCircular* CargarMarcaProductos(string NombreArchivo){
    ifstream Archivo;
    ListaDobleCircular* ListaArchivo = new ListaDobleCircular();
    const string Directorio = DIRECTORIO+NombreArchivo;
    cout<<Directorio<<endl;
    Archivo.open(Directorio);
    for(string Linea; getline(Archivo, Linea);)
    {
        if (Linea.empty()) continue;
        ListaArchivo->InsertarFinal(new NodoMarca(Linea));
    }
    return ListaArchivo;
}
ListaCircular* CargarCiudad(string NombreArchivo){
    ifstream Archivo;
    ListaCircular* ListaArchivo = new ListaCircular();
    const string Directorio = DIRECTORIO+NombreArchivo;
    cout<<Directorio<<endl;
    Archivo.open(Directorio);
    for(string Linea; getline(Archivo, Linea);)
    {
        if (Linea.empty()) continue;
        ListaArchivo->InsertarFinal(new NodoCiudad(Linea));
    }
    return ListaArchivo;
}
TablaHash* CargarAdmins(string NombreArchivo)
{
    ifstream Archivo;
    TablaHash* ListaArchivo = new TablaHash();
    const string Directorio = DIRECTORIO+NombreArchivo;
    cout<<Directorio<<endl;
    Archivo.open(Directorio);
    for(string Linea; getline(Archivo, Linea);)
    {
        if (Linea.empty()) continue;
        NodoAdmin* NuevoNodo = new NodoAdmin(Linea);
        ListaArchivo->InsertarNodo(NuevoNodo, NuevoNodo->CodAministrador);
    }
    return ListaArchivo;
}
TablaHash* CargarClientes(string NombreArchivo)
{
    ifstream Archivo;
    TablaHash* ListaArchivo = new TablaHash();
    const string Directorio = DIRECTORIO+NombreArchivo;
    cout<<Directorio<<endl;
    Archivo.open(Directorio);
    //string Basura;
    //getline(Archivo, Basura);
    for(string Linea; getline(Archivo, Linea);)
    {
        if (Linea.empty()) continue;
        NodoCliente* NuevoNodo = new NodoCliente(Linea);
        ListaArchivo->InsertarNodo(NuevoNodo, NuevoNodo->Cedula);
    }
    return ListaArchivo;
}
#pragma endregion

ArbolAVL* CargarProductosPasillos(string NombreArchivo)
{
    ifstream Archivo;
    ArbolAVL* ArbolArchivo = new ArbolAVL();
    const string Directorio = DIRECTORIO+NombreArchivo;
    cout<<Directorio<<endl;
    Archivo.open(Directorio);
    for(string Linea; getline(Archivo, Linea);)
    {
        if (Linea.empty()) continue;
        NodoProducto* NuevoNodo = new NodoProducto(Linea);
        ArbolArchivo->InsertarNodo(ArbolArchivo->Raiz, false, NuevoNodo);
    }
    return ArbolArchivo;
}

ArbolBinario* CargarPasillosABB(string NombreArchivo)
{
    ifstream Archivo;
    ArbolBinario* ArbolArchivo = new ArbolBinario();
    const string Directorio = DIRECTORIO+NombreArchivo;
    cout<<Directorio<<endl;
    Archivo.open(Directorio);
    for(string Linea; getline(Archivo, Linea);)
    {
        if (Linea.empty()) continue;
        NodoPasillo* NuevoNodo = new NodoPasillo(Linea);
        ArbolArchivo->InsertarNodo(NuevoNodo);
    }
    return ArbolArchivo;
}

ArbolRN* CargarMarcasARN(string NombreArchivo)
{
    ifstream Archivo;
    ArbolRN* ArbolArchivo = new ArbolRN();
    const string Directorio = DIRECTORIO+NombreArchivo;
    cout<<Directorio<<endl;
    Archivo.open(Directorio);
    for(string Linea; getline(Archivo, Linea);)
    {
        if (Linea.empty()) continue;
        NodoMarca* NuevoNodo = new NodoMarca(Linea);
        ArbolArchivo->insertar(NuevoNodo);
    }
    return ArbolArchivo;
}

ArbolAA* CargarInvetarioAA(string NombreArchivo)
{
    ifstream Archivo;
    ArbolAA* ArbolArchivo = new ArbolAA();
    const string Directorio = DIRECTORIO+NombreArchivo;
    cout<<Directorio<<endl;
    Archivo.open(Directorio);
    for(string Linea; getline(Archivo, Linea);)
    {
        if (Linea.empty()) continue;
        NodoInventario* NuevoNodo = new NodoInventario(Linea);
        ArbolArchivo->insert(NuevoNodo);
    }
    return ArbolArchivo;
}

ArbolBinario* CargarCiudadesABB(string NombreArchivo)
{
    ifstream Archivo;
    ArbolBinario* ArbolArchivo = new ArbolBinario();
    const string Directorio = DIRECTORIO+NombreArchivo;
    cout<<Directorio<<endl;
    Archivo.open(Directorio);
    for(string Linea; getline(Archivo, Linea);)
    {
        if (Linea.empty()) continue;
        NodoCiudad* NuevoNodo = new NodoCiudad(Linea);
        ArbolArchivo->InsertarNodo(NuevoNodo);
    }
    return ArbolArchivo;
}

ArbolB* CargarAdminsB(string NombreArchivo)
{
    ifstream Archivo;
    ArbolB* ArbolAdmins = new ArbolB();
    const string Directorio = DIRECTORIO + NombreArchivo;
    cout << Directorio << endl;
    Archivo.open(Directorio);
    for (string Linea; getline(Archivo, Linea);)
    {
        if (Linea.empty()) continue;
        NodoAdmin* NuevoAdmin = new NodoAdmin(Linea);
        //NuevoAdmin->Mostrar();
        ArbolAdmins->Insertar(NuevoAdmin);
    }
    return ArbolAdmins;
}

ArbolB* CargarClientesB(string NombreArchivo)
{
    ifstream Archivo;
    ArbolB* ArbolClientes = new ArbolB();
    const string Directorio = DIRECTORIO + NombreArchivo;
    cout << Directorio << endl;
    Archivo.open(Directorio);
    for (string Linea; getline(Archivo, Linea);)
    {
        if (Linea.empty()) continue;
        NodoCliente* NuevoCliente = new NodoCliente(Linea);
        ArbolClientes->Insertar(NuevoCliente);
    }
    return ArbolClientes;
}

int main()
{
    ListaSimple* ListaCompras = new ListaSimple();
    ListaSimple* HistorialCompras = new ListaSimple();
    
    TablaHash* TablaAdmins = CargarAdmins("Administradores.txt");
    TablaHash* TablaClientes = CargarClientes("Clientes.txt");
    
    ArbolBinario* ArbolPasillos = CargarPasillosABB("Pasillos.txt");
    ArbolPasillos->Infijo(ArbolPasillos->Raiz);
    
    ArbolAVL* ArbolProds = CargarProductosPasillos("ProductosPasillos.txt");
    ArbolProds->Infijo(ArbolProds->Raiz);
    
    ArbolRN* ArbolMarcas = CargarMarcasARN("MarcasProductos.txt");
    ArbolMarcas->inordenM();
    
    ArbolAA* ArbolInventario = CargarInvetarioAA("Inventario.txt");
    ArbolInventario->Infijo(ArbolInventario->root);

    ArbolBinario* ArbolCiudades = CargarCiudadesABB("Ciudades.txt");
    ArbolCiudades->Infijo(ArbolCiudades->Raiz);

    ArbolB* ArbolAdmin = CargarAdminsB("Administradores.txt");
    ArbolB* ArbolClientes = CargarClientesB("Clientes.txt");

    ArbolAdmin->Recorrer();

Inicio:
    
    bool Exito;
    bool EsAdmin = MenuFunciones::Login(ArbolAdmin, ArbolClientes, Exito);
    int opcion, subopcion1;
    
    if (EsAdmin)
    {
        do {
            // Mostrar el menú principal
            cout << " ===== Menu Administrador =====" << endl;
            cout << "1. Mantenimiento de Bases de datos" << endl;
            cout << "2. Facturar" << endl;
            cout << "3. Revisar Gondolas" << endl;
            cout << "4. Verificar inventario" << endl;
            cout << "5. Reportes" << endl;
            cout << "0. Salir" << endl;
            // Solicitar al usuario que ingrese una opción
            cout << "Ingrese el numero de opcion: ";
            cin >> opcion;
            system("CLS");

            // Realizar acciones según la opción seleccionada
            switch (opcion) {
            case 1:
                do {
                    cout << "===== Mantenimiento de la Base de Datos ======" << endl;
                    cout << "1. Insercion" << endl;
                    cout << "2. Busqueda" << endl;
                    cout << "3. Modificar" << endl;
                    cout << "0. Atras" << endl;
                    cout << "Ingrese el numero de opcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    switch (subopcion1) {
                    case 1:
                        do {
                            cout << "===== Inserciones ======" << endl;
                            cout << "1. Pasillo" << endl;
                            cout << "2. Producto" << endl;
                            cout << "3. Marca" << endl;
                            cout << "4. Inventario" << endl;
                            cout << "5. Clientes" << endl;
                            cout << "6. Administrador" << endl;
                            cout << "7. Ciudad" << endl;
                            cout << "0. Atras" << endl;
                            cout << "Ingrese el numero de opcion: ";
                            cin >> subopcion1;
                            system("CLS");
                            switch (subopcion1) {
                            case 1:
                                MenuFunciones::InsertarPasilloABB(ArbolPasillos);
                                break;
                            case 2:
                                MenuFunciones::InsertarProductoAVL(ArbolProds);
                                break;
                            case 3:
                                MenuFunciones::InsertarMarcaRN(ArbolMarcas);
                                break;
                            case 4:
                                MenuFunciones::InsertarInventarioAA(ArbolInventario);
                                break;
                            case 5:                                
                                MenuFunciones::InsertarClienteB(ArbolClientes);
                                break;
                            case 6:                               
                                MenuFunciones::InsertarAdministradorB(ArbolAdmin, nullptr);
                                break;
                            case 7:
                                MenuFunciones::InsertarCiudadABB(ArbolCiudades);
                                break;
                            case 0:
                                cout << "Volviendo al menu principal..." << endl;
                                break;
                            default:
                                cout << "Subopcion no válida. Por favor ingresa un número del 1 al 7." << endl;
                                break;
                            }
                        } while (subopcion1 != 0);
                        break;
                    case 2:
                        do {
                            cout << "===== Busqueda ======" << endl;
                            cout << "1. Pasillo" << endl;
                            cout << "2. Producto" << endl;
                            cout << "3. Marca" << endl;
                            cout << "4. Inventario" << endl;
                            cout << "5. Clientes" << endl;
                            cout << "6. Administrador" << endl;
                            cout << "7. Ciudad" << endl;
                            cout << "0. Atras" << endl;
                            cout << "Ingrese el numero de opcion: ";
                            cin >> subopcion1;
                            system("CLS");
                            switch (subopcion1) {
                            case 1:
                                MenuFunciones::BuscarPasilloABB(ArbolPasillos);
                                break;
                            case 2:
                                MenuFunciones::BuscarProductoAVL(ArbolProds);
                                break;
                            case 3:
                                MenuFunciones::EncontrarMarcaRN(ArbolMarcas);
                                break;
                            case 4:
                                MenuFunciones::EncontrarInventarioAA(ArbolInventario);
                                break;
                            case 5:                                
                                MenuFunciones::EncontrarClienteB(ArbolClientes, nullptr);
                                break;
                            case 6:                                
                                MenuFunciones::EncontrarAdministradorB(ArbolAdmin, nullptr);
                                break;
                            case 7:
                                MenuFunciones::EncontrarCiudadABB(ArbolCiudades);
                                break;
                            case 0:
                                cout << "Volviendo al menu principal..." << endl;
                                break;
                            default:
                                cout << "Subopcion no válida. Por favor ingresa un número del 1 al 7." << endl;
                                break;
                            }
                        } while (subopcion1 != 0);
                        break;
                    case 3:
                        do {
                            cout << "===== Modificaciones ======" << endl;
                            cout << "1. Pasillo" << endl;
                            cout << "2. Producto" << endl;
                            cout << "3. Marca" << endl;
                            cout << "4. Inventario" << endl;
                            cout << "5. Clientes" << endl;
                            cout << "6. Administrador" << endl;
                            cout << "7. Ciudad" << endl;
                            cout << "0. Atras" << endl;
                            cout << "Ingrese el numero de opcion: ";
                            cin >> subopcion1;
                            system("CLS");
                            switch (subopcion1) {
                            case 1:
                                MenuFunciones::ModificarPasilloABB(ArbolPasillos);
                                break;
                            case 2:
                                MenuFunciones::ModificarProductoAVL(ArbolProds);
                                break;
                            case 3:
                                MenuFunciones::ModificarMarcaRN(ArbolMarcas);
                                break;
                            case 4:
                                MenuFunciones::ModificarInventarioAA(ArbolInventario);
                                break;
                            case 5:                               
                                MenuFunciones::ModificarClienteB(ArbolClientes, nullptr);
                                break;
                            case 6:
                                MenuFunciones::ModificarAdministradorB(ArbolAdmin, nullptr);
                                break;
                            case 7:
                                MenuFunciones::ModificarCiudadABB(ArbolCiudades);
                                break;
                            case 0:
                                cout << "Volviendo al menu principal..." << endl;
                                break;
                            default:
                                cout << "Subopcion no válida. Por favor ingresa un número del 1 al 7." << endl;
                                break;
                            }
                        } while (subopcion1 != 0);
                        break;
                    case 0:
                        cout << "Saliendo del programa..." << endl;
                        break;
                    default:
                        cout << "Opción no válida. Por favor ingresa un número del 1 al 8." << endl;
                        break;
                    }
                    system("CLS");
                }while (subopcion1 != 0);
                break;
            case 2:
                MenuFuncionesAdmin::Facturar(ListaCompras, HistorialCompras);
                break;
            case 3:
                MenuFuncionesAdmin::RevisarGondolas(ListaCompras,ArbolInventario);
                break;
            case 4:
                MenuFuncionesAdmin::VerificarIventario(ArbolInventario, ListaCompras);
                break;
            case 5:
                do {
                    cout << "===== Reportes =====" << endl;
                    cout << "1. Pasillos mas visitado" << endl;
                    cout << "2. Pasillo menos visitado" << endl;
                    cout << "3. Producto por pasillo mas vendidos" << endl;
                    cout << "4. Marcas mas vendidas" << endl;
                    cout << "5. Cliente que mas compro" << endl;
                    cout << "6. Cliente que menos compro" << endl;
                    cout << "7. Producto mas cargado en Gondolas" << endl;
                    cout << "8. Cliente que mas facturo" << endl;
                    cout << "9. Marcas de un producto" << endl;
                    cout << "10. Factura de mayor monto" << endl;
                    cout << "11. Productos de un pasillo" << endl;
                    cout << "12. Clientes del supermercado" << endl;
                    cout << "13. Pasillo del supermercado" << endl;
                    cout << "14. Inverntario del supermercado" << endl;
                    cout << "0. Atras" << endl;

                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");

                    switch (subopcion1) {
                    case 1:
                        BibliotecaReportesArboles::ReportarPasilloMasVisitado(ArbolPasillos);
                        break;
                    case 2:
                        BibliotecaReportesArboles::ReportarPasilloMenosVisitado(ArbolPasillos);
                        break;
                    case 3:
                        BibliotecaReportesArboles::ReportarProductoMasVendido(ArbolInventario);
                        break;
                    case 4:
                        BibliotecaReportesArboles::ReportarMarcaMasVendida(ArbolMarcas);
                        break;
                    case 5:
                        //BibliotecaReportesArboles::ReportarClienteMayorCompra(TablaClientes);
                        break;
                    case 6:
                        //BibliotecaReportesArboles::ReportarClienteMenorCompra(TablaClientes);
                        break;
                    case 7:
                        //BibliotecaReportesArboles::ReportarProductoGondola(ArbolInventario);
                        break;
                    case 8:
                        //BibliotecaReportesArboles::ReportarClienteMasFacturo(ArbolInventario);
                        break;
                    case 9:
                        BibliotecaReportesArboles::ReportarMarcasPorProducto(ArbolMarcas);
                        break;
                    case 10:
                        //BibliotecaReportesArboles::ReportarFacturaMayor( por determinar, no se);
                        break;
                    case 11:
                        BibliotecaReportesArboles::ReportarProductosDePasillo(ArbolPasillos, ArbolProds);
                        break;
                    case 12:
                        BibliotecaReportesArboles::ReportarClientes(ArbolClientes);
                        break;
                    case 13:
                        BibliotecaReportesArboles::ReportarPasillos(ArbolPasillos);
                        break;
                    case 14:
                        BibliotecaReportesArboles::ReportarInventario(ArbolInventario);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 14." << endl;
                        break;
                    }
                } while (subopcion1 != 0);
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor ingresa un número del 1 al 5." << endl;
                break;
            }
            system("CLS");
        } while (opcion != 0);
    }else
    {
        do
        {
            // Mostrar el menú principal
            cout << "===== Menu Clientes =====" << endl;
            cout << "1. Consultar Precio" << endl;
            cout << "2. Consultar Descuento" << endl;
            cout << "3. Consultar productos" << endl;
            cout << "4. Comprar" << endl;
            cout << "0. Salir" << endl;
            // Solicitar al usuario que ingrese una opción
            cout << "Ingrese el numero de opcion: ";
            cin >> opcion;
            system("CLS");

            // Realizar acciones según la opción seleccionada
            switch (opcion)
            {
            case 1:
                cout << "Consultar Precio:" << endl;
                MenuFuncionesCliente::ConsultarPrecio(ArbolMarcas);
                break;
            case 2:
                cout << "Consultar Descuento:" << endl;
                if (Exito)
                {
                    MenuFuncionesCliente::ConsultarDescuento();    
                }else
                {
                    cout<<"Debe estar logueado para usar esta opcion\n";
                }
                
                break;
            case 3:
                cout << "Consultar Productos: " << endl;
                MenuFuncionesCliente::ConsultarProductos(ArbolProds);
                break;
            case 4:
                cout << "Comprar: " << endl;
                if (Exito)
                {
                    MenuFuncionesCliente::Comprar(ListaCompras, HistorialCompras, ArbolPasillos, ArbolProds, ArbolMarcas,
                                                  ArbolInventario, ArbolClientes);    
                }else
                {
                    cout<<"Debe estar logueado para usar esta opcion\n";
                }
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor ingresa un número del 1 al 4." << endl;
                break;
            }
            system("CLS");
        }
        while (opcion != 0);
    }
    int Reingresar = 0;
    cout<<"Desea reingresar al sistema? (1: Sí, 2: No): ";
    cin>>Reingresar;
    if (Reingresar == 1)
    {
        goto Inicio;    
    }
    
    cout<<"Adios!\n";
    return 0;
    
    //Menu();
    return 0;
}