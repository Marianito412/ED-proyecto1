#include "MenuFuncionesCliente.h"

#include <fstream>
#include <iostream>
#include "../Estructuras/Arboles/ArbolAVL/ArbolAVL.h"
#include "../Estructuras/Nodos/NodosDerivados/Pasillo/NodoPasillo.h"
#include "../Estructuras/Nodos/NodosDerivados/Producto/NodoProducto.h"
#include "../Estructuras/Arboles/ArbolRN/ArbolRN.h"
#include "../Estructuras/Nodos/NodosDerivados/Compra/NodoCarrito.h"
#include "../Estructuras/Nodos/NodosDerivados/Compra/NodoCompra.h"
#include "../Estructuras/Nodos/NodosDerivados/Inventario/NodoInventario.h"
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
    int Cedula;
    cout<<"Ingrese su cedula: ";
    cin>>Cedula;

    bool ArchivoExiste = true;
    int Cuenta = 0;
    while (ArchivoExiste)
    {
        ifstream f(to_string(Cedula)+"#"+to_string(Cuenta).c_str());
        ArchivoExiste = f.good();
        if (ArchivoExiste)
        {
            Cuenta++;    
        }
    }

    if (Cuenta<=3)
    {
        cout<<"Usted no posee descuento\n";
        return;
    }
    if (Cuenta == 4)
    {
        cout<<"Su descuento es de 5%\n";
        return;
    }
    cout<<"Su descuento es de 5%\n";
}

void MenuFuncionesCliente::ConsultarProductos(ArbolAVL* ArbolProductos)
{
    int CodPasillo;
    
    std::cout<<"Ingrese el codigo de pasillo: ";
    std::cin>>CodPasillo;

    
    ArbolProductos->IterarNodos([CodPasillo](NodoBase* Nodo)
    {
        if (NodoProducto* Producto = dynamic_cast<NodoProducto*>(Nodo))
        {
            if (CodPasillo == Producto->Pasillo)
            {
                std::cout<<Producto->Nombre<<std::endl;
            }
        }
    });
}

void MenuFuncionesCliente::Comprar(ListaSimple*& ListaCarritos, ArbolBinario* Pasillos, ArbolAVL* Productos,
                                   ArbolRN* Marcas, ArbolAA* ArbolInventario, TablaHash* Clientes)
{
    int Cedula, Pasillo, Producto, Marca, Cantidad, CantidadDisponible, CodigoInventario;

    cout<<"Ingrese su cedula: ";
    cin>>Cedula;
    bool Continuar = false;
    do
    {
        EscogerProducto(Pasillos, Productos, Marcas, ArbolInventario, Pasillo, Producto, Marca, Cantidad, CodigoInventario, CantidadDisponible);
        Cantidad = ValidarCantidad(Cantidad, CantidadDisponible);

        NodoBase* Nodo = ListaCarritos->EncontrarPorPredicado([Cedula](NodoBase* Nodo)
        {
            if (NodoCarrito* Carrito = dynamic_cast<NodoCarrito*>(Nodo))
            {
                return Carrito->Cedula == Cedula;
            }
            return false;
        });

        if (!Nodo)
        {
            Nodo = new NodoCarrito(Cedula);
            ListaCarritos->InsertarFinal(Nodo);
        }else
        {
            cout<<"Carrito ya existe\n";
        }
        NodoCarrito* Carrito = dynamic_cast<NodoCarrito*>(Nodo);
        NodoInventario* RefInventario = dynamic_cast<NodoInventario*>(ArbolInventario->Encontrar(CodigoInventario));
        Carrito->Compras->InsertarFinal(new NodoCompra(Pasillo, Producto, Marca, Cantidad, CodigoInventario, RefInventario));
        
        int Continuacion;
        Carrito->Compras->Mostrar();

        
        
        cout<<"Desea comprar mas? (1: Si, 2:NO): ";
        cin>>Continuacion;
        Continuar = Continuacion==1;
    }
    while (Continuar);
}

int MenuFuncionesCliente::ValidarCantidad(int Cantidad, int CantidadDisponible)
{
    if (Cantidad>CantidadDisponible)
    {
        int TomarDisponible;
        cout<<"Solo hay "<<CantidadDisponible<<" disponible. Desea tomarlo? (1: Si, 2:NO)";
        cin>>TomarDisponible;

        if (TomarDisponible == 1)
        {
            return CantidadDisponible;
        }
        return 0;
    }
    return Cantidad;
}

void MenuFuncionesCliente::EscogerProducto(ArbolBinario* Pasillos, ArbolAVL* Productos, ArbolRN* Marcas,
    ArbolAA* ArbolInventario, int& Pasillo, int& Producto, int& Marca, int& Cantidad,
    int& CodigoInventario, int& CantidadDisponible)
{
    Pasillos->Infijo(Pasillos->Raiz);
    cout<<"Escoja un pasillo:";
    cin>>Pasillo;
    
    Productos->IterarNodos([Pasillo](NodoBase* Nodo)
    {
        if (NodoProducto* Prod = dynamic_cast<NodoProducto*>(Nodo))
        {
            if (Prod->Pasillo == Pasillo)
            {
                cout<<Prod->Producto<<" "<<Prod->Nombre<<endl;
            }
        }
    });
    cout<<"Escoja un producto:";
    cin>>Producto;

    Marcas->IterarNodos([Producto](NodoBase* Nodo)
    {
        if (NodoMarca* Marca = dynamic_cast<NodoMarca*>(Nodo))
        {
            if (Marca->CodProducto == Producto)
            {
                cout<<Marca->CodMarca<<" "<<Marca->Nombre<<endl;
            }
        }
    });
    cout<<"Escoja una marca:";
    cin>>Marca;
    
    ArbolInventario->IterarNodos([Pasillo, Producto, Marca, &CantidadDisponible, &CodigoInventario](NodoBase* Nodo)
    {
        if (NodoInventario* Inventario = dynamic_cast<NodoInventario*>(Nodo))
        {
            if (Inventario->Pasillo == Pasillo && Inventario->Producto == Producto && Inventario->Marca == Marca)
            {
                cout<<Inventario->Nombre<<" "<<Inventario->Cantidad<<endl;
                CantidadDisponible = Inventario->Cantidad;
                CodigoInventario = Inventario->Inventario;
            }
        }
    });
    cout<<"Ingrese una cantidad: ";
    cin>>Cantidad;
}
