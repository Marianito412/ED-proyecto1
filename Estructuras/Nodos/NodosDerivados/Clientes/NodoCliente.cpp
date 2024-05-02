#include "NodoCliente.h"
#include <iostream>
#include <sstream>

NodoCliente::NodoCliente(std::string& Linea) {
    std::string Atributo;
    std::istringstream StreamLinea(Linea);
    int Indice = 0;
    while (std::getline(StreamLinea, Atributo, ';')) {
        switch (Indice) {
            case 0:
                Cedula = std::stoi(Atributo);
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

void NodoCliente::Mostrar() {
    std::cout << "Cedula: " << Cedula << ", Nombre: " << Nombre << ", CodCiudad: " << CodCiudad << ", Telefono: " << Telefono << ", Correo: " << Correo << std::endl;
    NodoBase::Mostrar();
}
