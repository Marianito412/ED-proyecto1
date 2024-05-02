#include "NodoMarca.h"
#include <iostream>
#include <sstream>

NodoMarca::NodoMarca(const std::string& linea)
{
    std::string token;
    std::istringstream iss(linea);
    int indice = 0;

    while (std::getline(iss, token, ';'))
    {
        switch (indice)
        {
        case 0:
            CodPasillo = std::stoi(token);
            break;
        case 1:
            CodProducto = std::stoi(token);
            break;
        case 2:
            CodMarca = std::stoi(token);
            break;
        case 3:
            Nombre = token;
            break;
        case 4:
            CantidadGondola = std::stoi(token);
            break;
        case 5:
            Precio = std::stod(token);
            break;
        default:
            std::cerr << "Error: Demasiados tokens en la línea." << std::endl;
            break;
        }
        indice++;
    }
}

void NodoMarca::Mostrar()
{
    std::cout << CodPasillo << CodProducto << CodMarca
              <<  Nombre << CantidadGondola << Precio << std::endl;
}

int NodoMarca::GetLlave()
{
    return CodMarca;
}
