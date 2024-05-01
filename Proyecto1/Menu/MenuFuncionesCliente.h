#pragma once
#include "../Estructuras/Arboles/ArbolRN/ArbolRN.h"
#include "../Estructuras/Arboles/ArbolBinario/ArbolBinario.h"

class MenuFuncionesCliente
{
public:
    static void ConsultarPrecio(ArbolRN* ArbolProds);

    static void ConsultarDescuento();

    static void ConsultarProductos(ArbolBinario* ArbolPasillos);

    static void Comprar();
};
