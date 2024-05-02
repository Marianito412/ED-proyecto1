#pragma once
#include "../Estructuras/Arboles/ArbolAA/ArbolAA.h"
#include "../Estructuras/ListaSimple/ListaSimple.h"

class MenuFuncionesAdmin
{
    static int ConseguirCantidadInventario(int CodInventario, ListaSimple* ListaCarritos);
public:
    static void RevisarGondolas();

    static void Facturar(ListaSimple* ListaCompras);

    static void VerificarIventario(ArbolAA* ArbolInventario, ListaSimple* ListaCarritos);
};
