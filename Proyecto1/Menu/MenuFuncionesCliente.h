#pragma once
#include "../Estructuras/Arboles/ArbolRN/ArbolRN.h"
#include "../Estructuras/Arboles/ArbolAVL/ArbolAVL.h"

class MenuFuncionesCliente
{
public:
    static void ConsultarPrecio(ArbolRN* ArbolProds);

    static void ConsultarDescuento();

    static void ConsultarProductos(ArbolAVL* ArbolProductos);

    static void Comprar();
};
