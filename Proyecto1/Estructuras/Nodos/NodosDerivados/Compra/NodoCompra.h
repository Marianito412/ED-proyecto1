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
    float Precio;
    int Inventario;

    NodoCompra(int pasillo, int producto, int marca, int cantidad, int inventario, float precio, NodoInventario* refinventario)
        :RefInventario(refinventario),
          Pasillo(pasillo),
          Producto(producto),
          Marca(marca),
          Cantidad(cantidad),
          Precio(precio),
          Inventario(inventario)
    {
    }

    void Mostrar() override;
};
