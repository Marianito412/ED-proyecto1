#pragma once
#include "../Estructuras/Arboles/ArbolBinario/ArbolBinario.h"
#include "../Estructuras/Arboles/ArbolAVL/ArbolAVL.h"
#include "../Estructuras/Arboles/ArbolAA/ArbolAA.h"
#include "../Estructuras/Arboles/ArbolRN/ArbolRN.h"
//#include "../Estructuras/Arboles/ArbolB/ArbolB.h"
class BibliotecaReportesArboles
{
public:
    static void ReportarPasilloMasVisitado(ArbolBinario* Arbol);
    static void ReportarPasilloMenosVisitado(ArbolBinario* Arbol);
    static void ReportarPasillos(ArbolBinario* Arbol);

    //static void ReportarProductoMasVendido(ArbolAVL* Arbol);
    //static void ReportarMarcaMasVendido(ArbolRN* Arbol);
    //static void ReportarClienteMayorCompra(ArbolB* Arbol);
    //static void ReportarClienteMenorCompra(ArbolB* Arbol);
    //static void ReportarProductoGondola(ArbolAA* Arbol);
    //static void ReportarClienteMasFacturo(ArbolB* Arbol);
    //static void ReportarMarcasProducto(ArbolRN* Arbol);
    //static void ReportarFacturaMayor(por determinar, no se );
    //static void ReportarProductos(ArbolAVL* Arbol);
    //static void ReportarClientes(ArbolB* Arbol);
    //static void ReportarInventario(ArbolAA* Arbol);
};
