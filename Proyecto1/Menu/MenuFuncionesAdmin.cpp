#include "MenuFuncionesAdmin.h"

#include <fstream>

#include "../Estructuras/Nodos/NodosDerivados/Compra/NodoCarrito.h"
#include "../Estructuras/Nodos/NodosDerivados/Compra/NodoCompra.h"
#include "../Estructuras/Nodos/NodosDerivados/Inventario/NodoInventario.h"

int MenuFuncionesAdmin::ConseguirCantidadInventario(int CodInventario, ListaSimple* ListaCarritos)
{
    int Cantidad = 0;
    ListaCarritos->IterarNodos([&Cantidad](NodoBase* Nodo)
    {
        if (NodoCarrito* Carrito = dynamic_cast<NodoCarrito*>(Nodo))
        {
            Carrito->Compras->IterarNodos([&Cantidad](NodoBase* Nodo)
            {
                if (NodoCompra* Compra = dynamic_cast<NodoCompra*>(Nodo))
                {
                    Cantidad = Cantidad + Compra->Cantidad;
                }
            });
        }
    });
    return Cantidad;
}

void MenuFuncionesAdmin::VerificarIventario(ArbolAA* ArbolInventario, ListaSimple* ListaCarritos)
{
    ArbolInventario->IterarNodos([ListaCarritos](NodoBase* Nodo)
    {
        if (NodoInventario* Inventario = dynamic_cast<NodoInventario*>(Nodo))
        {
            if (Inventario->Cantidad<20)
            {
                Inventario->Cantidad = Inventario->Cantidad + ConseguirCantidadInventario(Inventario->Inventario, ListaCarritos);
                cout<<Inventario->Nombre + " rellenado\n";
            }
        }
    });
}

void MenuFuncionesAdmin::Facturar(ListaSimple* ListaCompras)
{
    NodoCarrito* Carrito = dynamic_cast<NodoCarrito*>(ListaCompras->GetPrimero());

    bool ArchivoExiste = true;
    int Cuenta = 0;
    while (ArchivoExiste)
    {
        ifstream f(to_string(Carrito->Cedula)+"#"+to_string(Cuenta).c_str());
        ArchivoExiste = f.good();
        if (ArchivoExiste)
        {
            Cuenta++;    
        }
    }

    float Total = 0;
    string NombreReporte = to_string(Carrito->Cedula)+"#"+to_string(Cuenta);
    ofstream Reporte("../Reportes/"+NombreReporte+".txt");
    
    Reporte<<"Consecutivo factura: #"+to_string(Cuenta)+"\n";
    Reporte<<"Cedula: "+to_string(Carrito->Cedula)+"\n";
    Reporte<<"Producto\tMarca\tCantidad\tPrecio\tTotal por producto\n";
    
    Carrito->Compras->IterarNodos([&Reporte, Cuenta, Carrito, &Total](NodoBase* Nodo)
    {
        if (NodoCompra* Compra = dynamic_cast<NodoCompra*>(Nodo))
        {
            float TotalProd = Compra->Precio*Compra->Cantidad;
            Total += TotalProd;
            string Linea = to_string(Compra->Producto)+"\t"+to_string(Compra->Marca)+"\t"+to_string(Compra->Cantidad)+"\t"+to_string(Compra->Precio)+"\t"+to_string(TotalProd)+"\n";
            Reporte<<Linea;
        }
    });
    Reporte<<"Total: "+to_string(Total)+"\n";
    float Descuento = 0;
    if (Cuenta<=3)
    {
        Descuento = 0;
    }else
    {
        Descuento = 0.05f;
    }
    Reporte<<"Descuento: "+to_string(Descuento)+"\n";
    Reporte<<"Total a pagar: "+to_string(Descuento*Total)+"\n";
    ListaCompras->BorrarInicio();
}


