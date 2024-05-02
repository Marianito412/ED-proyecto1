#include "NodoInventario.h"

#include <iostream>
#include <sstream>

NodoInventario::NodoInventario(const std::string& Linea)
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
            Marca = std::stoi(Atributo);
            break;
        case 3:
            Inventario = std::stoi(Atributo);
            break;
        case 4:
            Nombre = Atributo;
            break;
        case 5:
            Cantidad = std::stoi(Atributo);
            break;
        case 6:
            CanastaBasica = std::stoi(Atributo);
            break;
        default: ;
        }
        Indice++;
    }
}

void NodoInventario::Mostrar()
{
    std::cout<<Pasillo<<" "<<Producto<<" "<<Marca<<" "<<Inventario<<" "<<Nombre<<" "<<Cantidad<<" "<<CanastaBasica<<std::endl;
}

int NodoInventario::GetLlave()
{
    return Inventario;
}
