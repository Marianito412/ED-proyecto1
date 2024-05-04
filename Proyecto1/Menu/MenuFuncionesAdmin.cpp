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

void MenuFuncionesAdmin::Facturar(ListaSimple* ListaCompras, ListaSimple* HistorialCompras)
{
    if (!ListaCompras->GetPrimero())
    {
        cout<<"No existen carritos en la cola"<<endl;
        return;
    }
    NodoCarrito* Carrito = dynamic_cast<NodoCarrito*>(ListaCompras->GetPrimero());
    NodoCarrito* Historial = new NodoCarrito(Carrito->Cedula);

    bool ArchivoExiste = true;
    int Cuenta = 0;
    while (ArchivoExiste)
    {
        ifstream f("../Reportes/"+to_string(Carrito->Cedula)+"#"+to_string(Cuenta).c_str()+".txt");
        ArchivoExiste = f.good();
        if (ArchivoExiste)
        {
            Cuenta++;    
        }
    }

    float Total = 0;
    string NombreReporte = to_string(Carrito->Cedula)+"#"+to_string(Cuenta);
    ofstream Reporte("../Reportes/"+NombreReporte+".txt");

    cout<<NombreReporte<<endl;
    
    Reporte<<"Consecutivo factura: #"+to_string(Cuenta)+"\n";
    Reporte<<"Cedula: "+to_string(Carrito->Cedula)+"\n";
    Reporte<<"Producto\tMarca\tCantidad\tPrecio\tTotal por producto\n";
    
    Carrito->Compras->IterarNodos([&Reporte, Cuenta, Carrito, &Total, &Historial](NodoBase* Nodo)
    {
        if (NodoCompra* Compra = dynamic_cast<NodoCompra*>(Nodo))
        {
            float TotalProd = Compra->Precio*Compra->Cantidad;
            Total += TotalProd;
            Historial->Compras->InsertarFinal(new NodoCompra(Compra->Pasillo, Compra->Producto, Compra->Marca, Compra->Cantidad, Compra->Inventario, Compra->Precio, Compra->RefInventario));
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
    Reporte<<"Total a pagar: "+to_string((1-Descuento)*Total)+"\n";
    
    HistorialCompras->InsertarFinal(Historial);
    ListaCompras->BorrarPosicion(0);
}

void MenuFuncionesAdmin::RevisarGondolas(ListaSimple* ListaVentas, ArbolAA* ArbolInventario)
{
    // Iterar sobre la lista de ventas
    ListaVentas->IterarNodos([&](NodoBase* Nodo)
        {
            // Verificar si el nodo es un NodoCompra
            if (NodoCompra* Venta = dynamic_cast<NodoCompra*>(Nodo))
            {
                // Verificar si la cantidad vendida es menor o igual a 2
                if (Venta->Cantidad <= 2)
                {
                    // Obtener el nodo de inventario correspondiente
                    NodoInventario* Inventario = Venta->RefInventario;

                    // Verificar si hay suficiente stock en inventario
                    if (Inventario->Inventario >= 20)
                    {
                        // Ajustar la cantidad en inventario y mostrar mensaje
                        Inventario->Inventario -= 20;
                        std::cout << "Se han ajustado las g�ndolas para el producto: " << Inventario->Nombre << std::endl;
                    }
                    else
                    {
                        std::cout << "No hay suficiente stock en inventario para ajustar las g�ndolas del producto: " << Inventario->Nombre << std::endl;
                    }
                }
            }
        });
}

