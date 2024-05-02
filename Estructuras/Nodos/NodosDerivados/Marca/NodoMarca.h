#pragma once
#include <string>
#include "../../NodoBase.h"

class NodoMarca : public NodoBase
{
public:
    int CodPasillo;
    int CodProducto;
    int CodMarca;
    std::string Nombre;
    int CantidadGondola;
    double Precio;

    NodoMarca(const std::string& linea);

    NodoMarca(int codPasillo, int codProducto, int codMarca, const std::string& nombre, int cantidad, double precio)
        : CodPasillo(codPasillo),
          CodProducto(codProducto),
          CodMarca(codMarca),
          Nombre(nombre),
          CantidadGondola(cantidad),
          Precio(precio)
    {
    }
    void Mostrar() override;
    int GetLlave() override;
};
