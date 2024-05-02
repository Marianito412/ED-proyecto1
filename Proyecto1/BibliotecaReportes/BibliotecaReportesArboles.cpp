#include "BibliotecaReportesArboles.h"
#include "../Estructuras/Nodos/NodoBase.h"
#include "../Estructuras/Nodos/NodosDerivados/Pasillo/NodoPasillo.h"
#include "../Estructuras/Nodos/NodosDerivados/Inventario/NodoInventario.h"
#include <fstream>
#include <string>

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

    Reporte.close();
}
