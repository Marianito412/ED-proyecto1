#pragma once
#include <string>

#include "../../NodoBase.h"

class NodoProducto : public NodoBase
{
public:
    int Pasillo;
    int Producto;
    std::string Nombre;

    NodoProducto(const std::string& Linea);

    NodoProducto(int pasillo, int producto, const std::string& nombre)
        : Pasillo(pasillo),
          Producto(producto),
          Nombre(nombre)
    {
    }
    void Mostrar() override;
    int GetLlave() override;
};
