#include "NodoProducto.h"

#include <iostream>
#include <sstream>

NodoProducto::NodoProducto(const std::string& Linea)
{
    std::string Atributo;
    std::istringstream StreamLinea(Linea);
    int Indice = 0;
    while (std::getline(StreamLinea, Atributo, ';'))
    {
        switch (Indice)
        {
        case 0:
            Pasillo = std::stoi(Atributo);
            break;
        case 1:
            Producto = std::stoi(Atributo);
            break;
        case 2:
            Nombre = Atributo;
            break;
        default: ;
        }
        Indice++;
    }
}

void NodoProducto::Mostrar()
{
    std::cout << Pasillo<<" "<<Producto<<" "<<Nombre<<std::endl;
}

int NodoProducto::GetLlave()
{
    return Producto;
    //std::string Test = std::to_string(Pasillo) + std::to_string(Producto);
    //return std::stoi(Test);
}
