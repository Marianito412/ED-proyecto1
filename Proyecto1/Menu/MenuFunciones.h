#pragma once
#include "../Estructuras/Arboles/ArbolAA/ArbolAA.h"
#include "../Estructuras/Arboles/ArbolAVL/ArbolAVL.h"
#include "../Estructuras/Arboles/ArbolBinario/ArbolBinario.h"
#include "../Estructuras/Arboles/ArbolRN/ArbolRN.h"
#include "../Estructuras/Arboles/ArbolB.h"
#include "../Estructuras/ListaCircular/ListaCircular.h"
#include "../Estructuras/ListaDoble/ListaDoble.h"
#include "../Estructuras/ListaDobleCircular/ListaDobleCircular.h"
#include "../Estructuras/ListaSimple/ListaSimple.h"
#include "../Estructuras/TablaHash/TablaHash.h"



class MenuFunciones
{
public:

#pragma region Login
    static bool Login(TablaHash* TablaAdmins, TablaHash* TablaClientes, bool& Exitoso);
#pragma endregion 

#pragma region Pasillo
    static void InsertarPasillo(ListaSimple* Lista);
    static void EliminarPasillo(ListaSimple* Lista);
    static void BuscarPasillo(ListaSimple* Lista);
    static void ModificarPasillo(ListaSimple* Lista);

    static void InsertarPasilloABB(ArbolBinario* Arbol);
    static void BuscarPasilloABB(ArbolBinario* Arbol);
    static void ModificarPasilloABB(ArbolBinario* Arbol);
#pragma endregion

#pragma region Producto
    static void InsertarProducto(ListaDoble* Lista, ListaSimple* ListaPasillo);
    static void EliminarProducto(ListaDoble* Lista, ListaDobleCircular* ListaMarcas);
    static void BuscarProducto(ListaDoble* Lista, ListaSimple* ListaPasillos);
    static void ModificarProducto(ListaDoble* Lista, ListaSimple* ListaPasillos);

    static void InsertarProductoAVL(ArbolAVL* Arbol);
    static void BuscarProductoAVL(ArbolAVL* Arbol);
    static void ModificarProductoAVL(ArbolAVL* Arbol);
#pragma endregion

#pragma region Inventario
    static void InsertarInventario(ListaDoble* ListaInventario, ListaSimple* ListaPasillos, ListaDoble* ListaProds,
                                   ListaDobleCircular* ListaMarcas);
    static void EliminarInventario(ListaDoble* ListaInventario);
    static void BuscarInventario(ListaDoble* ListaInventario);
    static void ModificarInventario(ListaDoble* ListaInventario);

    static void InsertarInventarioAA(ArbolAA* Arbol);
    static void EncontrarInventarioAA(ArbolAA* Arbol);
    static void ModificarInventarioAA(ArbolAA* Arbol);
#pragma endregion
    
#pragma region Administrador
    static void InsertarAdministrador(TablaHash* TablaAdmins, ListaCircular* ListaCiudades);
    static void EliminarAdministrador(TablaHash* TablaAdmins, ListaCircular* ListaCiudades);
    static void EncontrarAdministrador(TablaHash* TablaAdmins, ListaCircular* ListaCiudades);
    static void ModificarAdministrador(TablaHash* TablaAdmins, ListaCircular* ListaCiudades);

    static void InsertarAdministradorB(ArbolB* Arbol, ListaCircular* ListaCiudades);
    static void EncontrarAdministradorB(ArbolB* Arbol, ListaCircular* ListaCiudades);
    static void ModificarAdministradorB(ArbolB* Arbol, ListaCircular* ListaCiudades);
#pragma endregion 

#pragma region Marca
    static void InsertarMarcaProducto(ListaDobleCircular* Lista, ListaSimple* ListaPasillos);
    static void EliminarMarcaProducto(ListaDobleCircular* Lista);
    static void EncontrarMarcaProducto(ListaDobleCircular* Lista);
    static void ModificarMarcaProducto(ListaDobleCircular* Lista);

    static void InsertarMarcaRN(ArbolRN* Arbol);
    static void EncontrarMarcaRN(ArbolRN* Arbol);
    static void ModificarMarcaRN(ArbolRN* Arbol);
#pragma endregion

#pragma region Ciudades
    static void InsertarCiudad(ListaCircular* ListaCiudades);
    static void EliminarCiudad(ListaCircular* ListaCiudades);
    static void EncontrarCiudad(ListaCircular* ListaCiudades);
    static void ModificarCiudad(ListaCircular* ListaCiudades);

    static void InsertarCiudadABB(ArbolBinario* Arbol);
    static void EncontrarCiudadABB(ArbolBinario* Arbol);
    static void ModificarCiudadABB(ArbolBinario* Arbol);
#pragma endregion

#pragma region Clientes
    static void InsertarClientes(TablaHash* TablaClientes, ListaCircular* ListaCiudades,int totalClientes);
    static void EliminarClientes(TablaHash* TablaClientes, ListaCircular* ListaCiudades);
    static void EncontrarClientes(TablaHash* TablaClientes, ListaCircular* ListaCiudades);
    static void ModificarClientes(TablaHash* TablaClientes, ListaCircular* ListaCiudades);

    static void InsertarClienteB(ArbolB* Arbol);
    static void EncontrarClienteB(ArbolB* Arbol, ListaCircular* ListaCiudades);
    static void ModificarClienteB(ArbolB* Arbol, ListaCircular* ListaCiudades);
#pragma endregion 
};
