#pragma once
#include "../../NodoBase.h"
#include "../Inventario/NodoInventario.h"

class NodoCompra: public NodoBase
{
public:
    NodoInventario* RefInventario;
    int Pasillo;
    int Producto;
    int Marca;
    int Cantidad;
    int Inventario;

    NodoCompra(int pasillo, int producto, int marca, int cantidad, int inventario, NodoInventario* refinventario)
        : Pasillo(pasillo),
          Producto(producto),
          Marca(marca),
          Cantidad(cantidad),
          Inventario(inventario),
          RefInventario(refinventario)
    {
    }

    void Mostrar() override;
};
