#pragma once
#include <string>

#include "../../NodoBase.h"

class NodoPasillo: public NodoBase
{
public:
    std::string Nombre;
    int Codigo;

    NodoPasillo(std::string& Linea);

    NodoPasillo(const std::string& nombre, int codigo)
        : Nombre(nombre),
          Codigo(codigo)
    {
    }

    void Mostrar() override;

    int GetLlave() override;
};
