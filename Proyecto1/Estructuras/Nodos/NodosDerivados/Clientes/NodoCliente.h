#pragma once
#include <string>

#include "../../NodoBase.h"

class NodoCliente : public NodoBase
{
public:
    int Cedula;
    std::string Nombre;
    int CodCiudad;
    int Telefono;
    std::string Correo;
    int Facturas;
    float Compra;

    NodoCliente(std::string& Linea);

    NodoCliente(int cedula, const std::string& nombre, int cod_ciudad, int telefono, const std::string& correo)
        : Cedula(cedula),
          Nombre(nombre),
          CodCiudad(cod_ciudad),
          Telefono(telefono),
          Correo(correo)
    {
    }

    void Mostrar() override;

    int GetLlave() override;
};
