#include "NodoPasillo.h"

#include <iostream>
#include <sstream>

NodoPasillo::NodoPasillo(std::string& Linea)
{
    std::string Atributo;
    std::istringstream StreamLinea(Linea);
    int Indice = 0;
    while (std::getline(StreamLinea, Atributo, ';'))
    {
        switch (Indice)
        {
        case 0:
            Codigo = std::stoi(Atributo);
            break;
        case 1:
            Nombre = Atributo;
            break;
        default: ;
        }
        Indice++;
    }
}

void NodoPasillo::Mostrar()
{
    std::cout << Codigo << Nombre << std::endl;
}

int NodoPasillo::GetLlave()
{
    return Codigo;
}
