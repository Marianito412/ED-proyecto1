#pragma once
#include "../Estructuras/Arboles/ArbolAA/ArbolAA.h"
#include "../Estructuras/Arboles/ArbolRN/ArbolRN.h"
#include "../Estructuras/Arboles/ArbolAVL/ArbolAVL.h"
#include "../Estructuras/Arboles/ArbolBinario/ArbolBinario.h"
#include "../Estructuras/ListaSimple/ListaSimple.h"
#include "../Estructuras/TablaHash/TablaHash.h"

class MenuFuncionesCliente
{
    static int ValidarCantidad(int Cantidad, int CantidadDisponible);

    static void EscogerProducto(ArbolBinario* Pasillos, ArbolAVL* Productos, ArbolRN* Marcas,
                                ArbolAA* ArbolInventario, int& Pasillo, int& Producto, int& Marca,
                                int& Cantidad, int& CodigoInventario, int& CantidadDisponible);
    
public:
    static void ConsultarPrecio(ArbolRN* ArbolProds);

    static void ConsultarDescuento();

    static void ConsultarProductos(ArbolAVL* ArbolProductos);

    static void Comprar(ListaSimple*& ListaCarritos, ArbolBinario* Pasillos, ArbolAVL* Productos, ArbolRN* Marcas,
                        ArbolAA* ArbolInventario, TablaHash* Clientes);
};
