#include <fstream>
#include <iostream>
#include <string>

#include "BibliotecaReportes/BibliotecaReportes.h"
#include "BibliotecaReportes/BibliotecaReportesArboles.h"
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
#include "Menu/MenuFuncionesCliente.h"

static const string DIRECTORIO = "../Archivos/";

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

int main()
{
    TablaHash* TablaAdmins = CargarAdmins("Administradores.txt");
    TablaHash* TablaClientes = CargarAdmins("Clientes.txt");
    
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

    bool Exito;
    bool EsAdmin = MenuFunciones::Login(TablaAdmins, TablaClientes, Exito);
    int opcion, subopcion1;
    
    if (EsAdmin)
    {
        do {
            // Mostrar el menú principal
            cout << "Menu:" << endl;
            cout << "1. Pasillo" << endl;
            cout << "2. Producto" << endl;
            cout << "3. Marca" << endl;
            cout << "4. Inventario" << endl;
            cout << "5. Clientes" << endl;
            cout << "6. Administrador" << endl;
            cout << "7. Ciudad" << endl;
            cout << "8. Reportes" << endl;
            cout << "9. Salir" << endl;
            // Solicitar al usuario que ingrese una opción
            cout << "Ingrese el numero de opcion: ";
            cin >> opcion;
            system("CLS");

            // Realizar acciones según la opción seleccionada
            switch (opcion) {
            case 1:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Pasillo:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "3. Buscar" << endl;
                    cout << "4. Modificar" << endl;
                    cout << "0. Atras" << endl;

                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                    switch (subopcion1) {
                    case 1:
                        //MenuFunciones::InsertarPasillo(ListaPasillos);
                        MenuFunciones::InsertarPasilloABB(ArbolPasillos);
                        break;
                    case 2:
                        //MenuFunciones::EliminarPasillo(ListaPasillos);
                        break;
                    case 3:
                        MenuFunciones::BuscarPasilloABB(ArbolPasillos);
                        //MenuFunciones::BuscarPasillo(ListaPasillos);
                        break;
                    case 4:
                        MenuFunciones::ModificarPasilloABB(ArbolPasillos);
                        //MenuFunciones::ModificarPasillo(ListaPasillos);
                        break;
                    case 5:
                        //BibliotecaReportes::ReportarPasillos(ListaPasillos);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 4." << endl;
                        break;
                    }
                } while (subopcion1 != 0);
                break;
            case 2:
                do {
                    cout << "Producto:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "3. Buscar" << endl;
                    cout << "4. Modificar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");

                    switch (subopcion1)
                    {
                    case 1:
                        MenuFunciones::InsertarProductoAVL(ArbolProds);
                        //MenuFunciones::InsertarProducto(ListaProds, ListaPasillos);
                        break;
                    case 2:
                        //MenuFunciones::EliminarProducto(ListaProds, ListaMarcas);
                        break;
                    case 3:
                        MenuFunciones::BuscarProductoAVL(ArbolProds);
                        //MenuFunciones::BuscarProducto(ListaProds, ListaPasillos);
                        break;
                    case 4:
                        MenuFunciones::ModificarProductoAVL(ArbolProds);
                        //MenuFunciones::ModificarProducto(ListaProds, ListaPasillos);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 4." << endl;
                        break;
                    }
                } while (subopcion1 != 0);
                break;
            case 3:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Marca:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "3. Buscar" << endl;
                    cout << "4. Modificar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                    switch (subopcion1) {
                    case 1:
                        MenuFunciones::InsertarMarcaRN(ArbolMarcas);
                        //MenuFunciones::InsertarMarcaProducto(ListaMarcas, ListaPasillos);
                        break;
                    case 2:
                        //MenuFunciones::EliminarMarcaProducto(ListaMarcas);
                        break;
                    case 3:
                        MenuFunciones::EncontrarMarcaRN(ArbolMarcas);
                        //MenuFunciones::EncontrarMarcaProducto(ListaMarcas);
                        break;
                    case 4:
                        MenuFunciones::ModificarMarcaRN(ArbolMarcas);
                        //MenuFunciones::ModificarMarcaProducto(ListaMarcas);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 4." << endl;
                        break;
                    }
                } while (subopcion1 != 0);
                break;
            case 4:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Inventario:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "3. Buscar" << endl;
                    cout << "4. Modificar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                    switch (subopcion1) {
                    case 1:
                        MenuFunciones::InsertarInventarioAA(ArbolInventario);
                        //MenuFunciones::InsertarInventario(ListaInventario, ListaPasillos, ListaProds, ListaMarcas);
                        break;
                    case 2:
                        //MenuFunciones::EliminarInventario(ListaInventario);
                        break;
                    case 3:
                        MenuFunciones::EncontrarInventarioAA(ArbolInventario);
                        //MenuFunciones::BuscarInventario(ListaInventario);
                        break;
                    case 4:
                        //MenuFunciones::ModificarInventario(ListaInventario);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 4." << endl;
                        break;
                    }
                } while (subopcion1 != 0);
                break;
            case 5:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Cliente:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "3. Buscar" << endl;
                    cout << "4. Modificar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                    switch (subopcion1) {
                    case 1:
                        //MenuFunciones::InsertarClientes(TablaClientes, ListaCiudades, 0);
                        break;
                    case 2:
                        //MenuFunciones::EliminarClientes(TablaClientes, ListaCiudades);
                        break;
                    case 3:
                        //MenuFunciones::EncontrarClientes(TablaClientes, ListaCiudades);
                        break;
                    case 4:
                        //MenuFunciones::ModificarClientes(TablaClientes, ListaCiudades);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 4." << endl;
                        break;
                    }
                } while (subopcion1 != 0);
                break;
            case 6:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Administrador:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "3. Buscar" << endl;
                    cout << "4. Modificar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                    switch (subopcion1) {
                    case 1:
                        //MenuFunciones::InsertarAdministrador(TablaAdmins, ListaCiudades);
                        break;
                    case 2:
                        //MenuFunciones::EliminarAdministrador(TablaAdmins, ListaCiudades);
                        break;
                    case 3:
                        //MenuFunciones::EncontrarAdministrador(TablaAdmins, ListaCiudades);
                        break;
                    case 4:
                        //MenuFunciones::ModificarAdministrador(TablaAdmins, ListaCiudades);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 4." << endl;
                        break;
                    }
                } while (subopcion1 != 0);
                break;
            case 7:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Ciudad:" << endl;
                    cout << "1. Insertar " << endl;
                    cout << "2. Eliminar " << endl;
                    cout << "3. Buscar" << endl;
                    cout << "4. Modificar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                    switch (subopcion1) {
                    case 1:
                        //MenuFunciones:: InsertarCiudad(ListaCiudades);
                        break;
                    case 2:
                        //MenuFunciones:: EliminarCiudad(ListaCiudades);
                        break;
                    case 3:
                        //MenuFunciones::EncontrarCiudad(ListaCiudades);
                        break;
                    case 4:
                        //MenuFunciones::ModificarCiudad(ListaCiudades);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 4." << endl;
                        break;
                    }
                } while (subopcion1 != 0);
                break;
            case 8:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Reportes" << endl;
                    cout << "1. Reporte Pasillos" << endl;
                    cout << "2. Reporte Productos pasillo" << endl;
                    cout << "3. Reporte Marcas Producto" << endl;
                    cout << "4. Reporte Administradores" << endl;
                    cout << "5. Reporte Clientes" << endl;
                    cout << "6. Reporte Ciudades" << endl;
                    cout << "7. Reporte Pasillo mas visitado" << endl;
                    cout << "8. Reporte Pasillo menos visitado" << endl;
                    cout << "9. Reporte Producto mas buscado" << endl;
                    cout << "10. Reporte Marca mas buscada" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                    switch (subopcion1) {
                    case 1:
                        BibliotecaReportesArboles::ReportarPasilloMasVisitado(ArbolPasillos);
                        //BibliotecaReportes::ReportarPasillos(ListaPasillos);
                        break;
                    case 2:
                        //BibliotecaReportes::ReportarProductosPasillo(ListaProds);
                        break;
                    case 3:
                        //BibliotecaReportes::ReportarMarcasProducto(ListaMarcas);
                        break;
                    case 4:
                        //BibliotecaReportes::ReportarAdministradores(TablaAdmins);
                        break;
                    case 5:
                        //BibliotecaReportes::ReportarClientes(TablaClientes);
                        break;
                    case 6:
                        //BibliotecaReportes::ReportarCiudades(ListaCiudades);
                        break;
                    case 7:
                        //BibliotecaReportes::ReportarPasilloMasVisto(ListaPasillos);
                        break;
                    case 8:
                        //BibliotecaReportes::ReportarPasilloMenosVisto(ListaPasillos);
                        break;
                    case 9:
                        //BibliotecaReportes::ReportarProductosMasBuscados(ListaProds);
                        break;
                    case 10:
                        //BibliotecaReportes::ReportarMarcasMasBuscadas(ListaMarcas);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 10." << endl;
                        break;
                    }
                }while (subopcion1 != 0);
                break;
            case 9:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor ingresa un número del 1 al 8." << endl;
                break;
            }
            system("CLS");
        } while (opcion != 9);
    }else
    {
                do {
            // Mostrar el menú principal
            cout << "Menu:" << endl;
            cout << "1. Consultar Precio" << endl;
            cout << "2. Consultar Descuento" << endl;
            cout << "3. Consultar productos" << endl;
            cout << "4. Comprar" << endl;
            cout << "9. Salir" << endl;
            // Solicitar al usuario que ingrese una opción
            cout << "Ingrese el numero de opcion: ";
            cin >> opcion;
            system("CLS");

            // Realizar acciones según la opción seleccionada
            switch (opcion) {
            case 1:
                cout << "Consultar Precio:" << endl;
                MenuFuncionesCliente::ConsultarPrecio(ArbolMarcas);
                break;
            case 2:
                do {
                    cout << "Producto:" << endl;
                    cout << "1. Buscar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");

                    switch (subopcion1)
                    {
                    case 1:
                        //MenuFunciones::BuscarProducto(ListaProds, ListaPasillos);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 4." << endl;
                        break;
                    }
                } while (subopcion1 != 0);
                break;
            case 3:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Marca:" << endl;
                    cout << "1. Buscar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                    switch (subopcion1) {
                    case 1:
                        //MenuFunciones::EncontrarMarcaProducto(ListaMarcas);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 4." << endl;
                        break;
                    }
                } while (subopcion1 != 0);
                break;
            case 4:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Inventario:" << endl;
                    cout << "1. Buscar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                    switch (subopcion1) {
                    case 1:
                        //MenuFunciones::BuscarInventario(ListaInventario);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 4." << endl;
                        break;
                    }
                } while (subopcion1 != 0);
                break;
            case 5:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Cliente:" << endl;
                    cout << "1. Buscar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                    switch (subopcion1) {
                    case 1:
                        //MenuFunciones::EncontrarClientes(TablaClientes, ListaCiudades);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 4." << endl;
                        break;
                    }
                } while (subopcion1 != 0);
                break;
            case 6:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Administrador:" << endl;
                    cout << "1. Buscar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                    switch (subopcion1) {
                    case 1:
                        //MenuFunciones::EncontrarAdministrador(TablaAdmins, ListaCiudades);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 4." << endl;
                        break;
                    }
                } while (subopcion1 != 0);
                break;
            case 7:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Ciudad:" << endl;
                    cout << "1. Buscar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                    switch (subopcion1) {
                    case 1:
                        //MenuFunciones::EncontrarCiudad(ListaCiudades);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 4." << endl;
                        break;
                    }
                } while (subopcion1 != 0);
                break;
            case 8:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Reportes" << endl;
                    cout << "1. Reporte Pasillos" << endl;
                    cout << "2. Reporte Productos pasillo" << endl;
                    cout << "3. Reporte Marcas Producto" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    system("CLS");
                    
                    switch (subopcion1) {
                    case 1:
                        //BibliotecaReportes::ReportarPasillos(ListaPasillos);
                        break;
                    case 2:
                        //BibliotecaReportes::ReportarProductosPasillo(ListaProds);
                        break;
                    case 3:
                        //BibliotecaReportes::ReportarMarcasProducto(ListaMarcas);
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 10." << endl;
                        break;
                    }
                }while (subopcion1 != 0);
                break;
            case 9:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor ingresa un número del 1 al 8." << endl;
                break;
            }
            system("CLS");
        } while (opcion != 9);
    }

    return 0;
    
    //Menu();
    return 0;
}