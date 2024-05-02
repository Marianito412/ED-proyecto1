#pragma once
#include "../../NodoBase.h"
#include "../../../ListaSimple/ListaSimple.h"

class NodoCarrito: public NodoBase
{
public:
    int Cedula;
    ListaSimple* Compras;

    explicit NodoCarrito(int cedula)
        : Cedula(cedula)
    {
        Compras = new ListaSimple();
    }
};
