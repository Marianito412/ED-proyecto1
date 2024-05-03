#include "BibliotecaReportesArboles.h"
#include "../Estructuras/Nodos/NodoBase.h"
#include "../Estructuras/Nodos/NodosDerivados/Pasillo/NodoPasillo.h"
#include "../Estructuras/Nodos/NodosDerivados/Inventario/NodoInventario.h"
#include <fstream>
#include <string>

#include "../Estructuras/Nodos/NodosDerivados/Clientes/NodoCliente.h"
#include "../Estructuras/Nodos/NodosDerivados/Marca/NodoMarca.h"
#include "../Estructuras/Nodos/NodosDerivados/Producto/NodoProducto.h"

void BibliotecaReportesArboles::ReportarPasilloMasVisitado(ArbolBinario* Arbol)
{
    std::ofstream Reporte("../Reportes/ReportePasilloMasVisitado.csv");

    NodoPasillo* MasBuscado = nullptr;
    
    Arbol->IterarNodos([&Reporte, &MasBuscado](NodoBase* Nodo)
    {
        if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(Nodo))
        {
            if (!MasBuscado)
            {
                MasBuscado = Pasillo;
                return;
            }

            if (Pasillo->Busquedas>=MasBuscado->Busquedas)
            {
                MasBuscado = Pasillo;
                return;
            }
            Reporte<<std::to_string(Pasillo->Codigo)+","+Pasillo->Nombre+"\n";
        }
    });
    Reporte<<std::to_string(MasBuscado->Codigo)+","+MasBuscado->Nombre+"\n";
    Reporte.close();
}

void BibliotecaReportesArboles::ReportarPasilloMenosVisitado(ArbolBinario* Arbol)
{
    std::ofstream Reporte("../Reportes/ReportePasilloMenosVisitado.csv");

    NodoPasillo* MasBuscado = nullptr;
    
    Arbol->IterarNodos([&Reporte, &MasBuscado](NodoBase* Nodo)
    {
        if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(Nodo))
        {
            if (!MasBuscado)
            {
                MasBuscado = Pasillo;
                return;
            }

            if (Pasillo->Busquedas<=MasBuscado->Busquedas)
            {
                MasBuscado = Pasillo;
                return;
            }
            Reporte<<std::to_string(Pasillo->Codigo)+","+Pasillo->Nombre+"\n";
        }
    });
    Reporte<<std::to_string(MasBuscado->Codigo)+","+MasBuscado->Nombre+"\n";
    Reporte.close();
}

void BibliotecaReportesArboles::ReportarPasillos(ArbolBinario* Arbol)
{
    std::ofstream Reporte("../Reportes/ReportePasillos.csv");

    Reporte<<"Codigo,Nombre\n";
    // Itera sobre los nodos del árbol de pasillos
    Arbol->IterarNodos([&](NodoBase* Nodo)
        {
            // Verifica si el nodo es un NodoPasillo
            if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(Nodo))
            {
                // Escribe los datos del pasillo en el reporte
                Reporte << Pasillo->Codigo << "," << Pasillo->Nombre << "\n";
            }
        });

    Reporte.close();
}

void BibliotecaReportesArboles::ReportarMarcasPorProducto(ArbolRN* Marcas)
{
    int Pasillo, Producto;

    std::ofstream Reporte("../Reportes/ReporteMarcasPorProducto.csv");
    
    cout<<"Ingrese el pasillo: ";
    cin>>Pasillo;

    cout<<"Ingrese el producto: ";
    cin>>Producto;

    Reporte<<"Marca,Nombre,Cantidad,Precio\n";
    Marcas->IterarNodos([&Reporte](NodoBase* Nodo)
    {
        if (NodoMarca* Marca = dynamic_cast<NodoMarca*>(Nodo))
        {
            Reporte<<Marca->CodMarca<<","<<Marca->Nombre<<","<<Marca->CantidadGondola<<","<<Marca->Precio<<"\n";
        }
    });
    cout<<"Reporte generado!";
    Reporte.close();
}

void BibliotecaReportesArboles::ReportarProductosDePasillo(ArbolBinario* Pasillos, ArbolAVL* Productos)
{
    int Pasillo;

    std::ofstream Reporte("../Reportes/ReporteProductoPorPasillo.csv");
    
    cout<<"Ingrese el pasillo: ";
    cin>>Pasillo;
    Reporte<<"Pasillo,Producto,Nombre\n";
    Productos->IterarNodos([&Reporte, Pasillo](NodoBase* Nodo)
    {
        if (NodoProducto* Producto = dynamic_cast<NodoProducto*>(Nodo))
        {
            if (Producto->Pasillo != Pasillo) return;
            
            Reporte<<Producto->Pasillo<<","<<Producto->Producto<<","<<Producto->Nombre<<"\n";
        }
    });
    cout<<"Reporte generado!";
    Reporte.close();
}

void BibliotecaReportesArboles::ReportarClientes(TablaHash* Clientes)
{
    std::ofstream Reporte("../Reportes/ReporteClientes.csv");
    Reporte<<"Cedula,Nombre\n";
    Clientes->IterarNodos([&Reporte](NodoBase* Nodo)
    {
        if (NodoCliente* Cliente = dynamic_cast<NodoCliente*>(Nodo))
        {
            Reporte<<Cliente->Cedula<<","<<Cliente->Nombre<<"\n";
        }
    });
    cout<<"Reporte generado!";
    Reporte.close();
}

void BibliotecaReportesArboles::ReportarInventario(ArbolAA* Arbol)
{
    std::ofstream Reporte("../Reportes/ReporteInventario.csv");

    // Encabezado del reporte
    Reporte << "Codigo Pasillo,Codigo Producto,Codigo Marca,Codigo Inventario,Nombre,Cantidad,Precio\n";

    // Función lambda para iterar sobre los nodos del árbol y escribir los datos del inventario en el reporte
    Arbol->IterarNodos([&](NodoBase* Nodo)
        {
            if (NodoInventario* Inventario = dynamic_cast<NodoInventario*>(Nodo))
            {
                // Escribe los datos del inventario en el reporte
                Reporte << Inventario->Pasillo << "," << Inventario->Producto << ","
                    << Inventario->Marca << "," << Inventario->Inventario << ","
                    << Inventario->Nombre << "," << Inventario->Cantidad << "\n";
            }
        });

    cout<<"Reporte generado!";
    Reporte.close();
}

void BibliotecaReportesArboles::ReportarProductoMasVendido(ArbolAA* Inventario)
{
    std::ofstream Reporte("../Reportes/ReporteProductoMasVendido.csv");

    // Encabezado del reporte
    NodoInventario* MasVendido = nullptr;
    Reporte << "Codigo Pasillo,Codigo Producto,Nombre\n";
    Inventario->IterarNodos([&MasVendido](NodoBase* Nodo)
    {
        if (NodoInventario* Inventario = dynamic_cast<NodoInventario*>(Nodo))
        {
            if (!MasVendido) MasVendido = Inventario;

            if (Inventario->Ventas>=MasVendido->Ventas)
            {
                MasVendido = Inventario;
            }
        }
    });
    cout<<"Reporte generado!";
    Reporte<<MasVendido->Pasillo<<MasVendido->Producto<<MasVendido->Nombre<<"\n";
    Reporte.close();
}
