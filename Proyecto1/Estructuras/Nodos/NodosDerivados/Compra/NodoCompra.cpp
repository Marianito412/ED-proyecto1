#include "NodoCompra.h"

#include <iostream>

#include "../Producto/NodoProducto.h"

void NodoCompra::Mostrar()
{
    std::cout<<"Producto: "<<RefInventario->Nombre<<", Cantidad: "<<Cantidad<<std::endl;
    NodoBase::Mostrar();
}
