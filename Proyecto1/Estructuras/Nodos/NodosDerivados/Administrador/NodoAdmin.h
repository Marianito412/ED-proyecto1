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

    NodoAdmin(int cod_aministrador, const std::string& nombre, int cod_ciudad, int telefono, const std::string& correo)
        : CodAministrador(cod_aministrador),
          Nombre(nombre),
          CodCiudad(cod_ciudad),
          Telefono(telefono),
          Correo(correo)
    {
    }

    NodoAdmin(std::string& Linea);

    void Mostrar() override;

    int GetLlave() override;
};
