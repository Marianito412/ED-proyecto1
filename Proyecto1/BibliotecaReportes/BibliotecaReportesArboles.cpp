#include "BibliotecaReportesArboles.h"
#include "../Estructuras/Nodos/NodoBase.h"
#include "../Estructuras/Nodos/NodosDerivados/Pasillo/NodoPasillo.h"
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
