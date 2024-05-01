#include "NodoAdmin.h"


#include <iostream>
#include <sstream>

NodoAdmin::NodoAdmin(std::string& Linea)
{
    std::string Atributo;
    std::istringstream StreamLinea(Linea);
    int Indice = 0;
    while (std::getline(StreamLinea, Atributo, ';'))
    {
        switch (Indice)
        {
        case 0:
            CodAministrador = std::stoi(Atributo);
            break;
        case 1:
            Nombre = Atributo;
            break;
        case 2:
            CodCiudad = std::stoi(Atributo);
            break;
        case 3:
            Telefono = std::stoi(Atributo);
            break;
        case 4:
            Correo = Atributo;
            break;
        default: ;
        }
        Indice++;
    }
}

void NodoAdmin::Mostrar()
{
    std::cout<<CodAministrador<<" "<<Nombre<<" "<<CodCiudad<<" "<<Telefono<<" "<<Correo<<std::endl;
    NodoBase::Mostrar();
}
