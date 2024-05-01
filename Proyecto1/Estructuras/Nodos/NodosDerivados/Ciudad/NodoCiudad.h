#pragma once
#include <string>

#include "../../NodoBase.h"

class NodoCiudad : public NodoBase
{
public:
    int CodCiudad;
    std::string Nombre;

    NodoCiudad(const std::string& Linea);

    NodoCiudad(int codCiudad, const std::string& nombre)
        : CodCiudad(codCiudad),
          Nombre(nombre)
    {
    }

    void Mostrar() override;

    int GetLlave() override;
};