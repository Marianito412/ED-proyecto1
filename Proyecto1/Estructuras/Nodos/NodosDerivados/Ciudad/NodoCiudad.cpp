#include "NodoCiudad.h"

#include <iostream>
#include <sstream>

NodoCiudad::NodoCiudad(const std::string& Linea)
{
    std::string Atributo;
    std::istringstream StreamLinea(Linea);
    int Indice = 0;
    while (std::getline(StreamLinea, Atributo, ';'))
    {
        switch (Indice)
        {
        case 0:
            CodCiudad = std::stoi(Atributo);
            break;
        case 1:
            Nombre = Atributo;
            break;
        default: ;
        }
        Indice++;
    }
}

void NodoCiudad::Mostrar()
{
    std::cout << CodCiudad << Nombre << std::endl;
}

int NodoCiudad::GetLlave()
{
    return CodCiudad;
}
