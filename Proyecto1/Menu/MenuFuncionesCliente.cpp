#include "MenuFuncionesCliente.h"

#include <iostream>

#include "../Estructuras/Nodos/NodosDerivados/Pasillo/NodoPasillo.h"
#include "../Estructuras/Nodos/NodosDerivados/Producto/NodoProducto.h"
#include "../Estructuras/Arboles/ArbolRN/ArbolRN.h"
#include "../Estructuras/Nodos/NodosDerivados/Marca/NodoMarca.h"

void MenuFuncionesCliente::ConsultarPrecio(ArbolRN* ArbolProds)
{
    int CodPasillo, CodProd, CodMarca;
    std::cout<<"Ingrese el codigo de pasillo: ";
    std::cin>>CodPasillo;

    std::cout<<"Ingrese el codigo de producto: ";
    std::cin>>CodProd;

    std::cout<<"Ingrese el codigo de marca: ";
    std::cin>>CodMarca;

    NodoMarca* Encontrado = nullptr;
    ArbolProds->IterarNodos([&Encontrado, CodPasillo, CodProd, CodMarca](NodoBase* Nodo)
    {
        if (NodoMarca* Prod = dynamic_cast<NodoMarca*>(Nodo))
        {
            if (CodPasillo == Prod->CodPasillo && CodProd == Prod->CodProducto && CodMarca == Prod->CodMarca)
            {
                Encontrado = Prod;
            }
        }
    });

    std::cout<<Encontrado->Nombre<<": "<<Encontrado->Precio<<std::endl;
}

void MenuFuncionesCliente::ConsultarDescuento()
{
}

void MenuFuncionesCliente::ConsultarProductos(ArbolBinario* ArbolPasillos)
{
}

void MenuFuncionesCliente::Comprar()
{
}
