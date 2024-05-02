#pragma once
#include <string>

#include "../../NodoBase.h"

class NodoCliente : public NodoBase {
    public:
        int Cedula;
        std::string Nombre;
        int CodCiudad;
        int Telefono;
        std::string Correo;

        NodoCliente(std::string& Linea);
        void Mostrar() override;
    };