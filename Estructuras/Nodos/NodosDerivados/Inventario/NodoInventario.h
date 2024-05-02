#pragma once
#include <string>

#include "../../NodoBase.h"

class NodoInventario: public NodoBase
{
public:
    int Pasillo;
    int Producto;
    int Marca;
    int Inventario;
    std::string Nombre;
    int Cantidad;
    bool CanastaBasica;

    NodoInventario(const std::string& Linea);

    void Mostrar() override;

    int GetLlave() override;
};
