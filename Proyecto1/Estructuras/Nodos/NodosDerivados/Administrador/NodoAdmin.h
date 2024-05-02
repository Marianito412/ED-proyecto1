#pragma once
#include <string>

#include "../../NodoBase.h"

class NodoAdmin: public NodoBase
{
public:
    int CodAministrador;
    std::string Nombre;
    int CodCiudad;
    int Telefono;
    std::string Correo;
    NodoAdmin(std::string& Linea);

    void Mostrar() override;
};
