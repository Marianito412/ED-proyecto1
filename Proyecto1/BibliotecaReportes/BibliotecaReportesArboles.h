#pragma once
#include "../Estructuras/Arboles/ArbolBinario/ArbolBinario.h"
#include "../Estructuras/Arboles/ArbolAVL/ArbolAVL.h"
#include "../Estructuras/Arboles/ArbolAA/ArbolAA.h"
#include "../Estructuras/Arboles/ArbolRN/ArbolRN.h"
#include "../Estructuras/TablaHash/TablaHash.h"

#include "../Estructuras/Arboles/ArbolB.h"
class BibliotecaReportesArboles
{
public:
    static void ReportarPasilloMasVisitado(ArbolBinario* Arbol);
    static void ReportarPasilloMenosVisitado(ArbolBinario* Arbol);
    static void ReportarPasillos(ArbolBinario* Arbol);
    static void ReportarMarcasPorProducto(ArbolRN* Marcas);
    static void ReportarProductosDePasillo(ArbolBinario* Pasillos, ArbolAVL* Productos);
    static void ReportarClientes(ArbolB* Clientes);
    static void ReportarInventario(ArbolAA* Arbol);
    static void ReportarMarcaMasVendida(ArbolRN* Marcas);
    static void ReportarProductoMasVendido(ArbolAA* Inventario);
    static void ReportarClienteMayorCompra(ListaSimple* ListaCarritos, ArbolB* Arbol);
    static void ReportarClienteMenorCompra(ListaSimple* ListaCarritos, ArbolB* Arbol);
    //static void ReportarProductoGondola(ArbolAA* Arbol);
    //static void ReportarClienteMasFacturo(ArbolB* Arbol);
    //static void ReportarMarcasProducto(ArbolRN* Arbol);
    //static void ReportarFacturaMayor(por determinar, no se );
    //static void ReportarProductos(ArbolAVL* Arbol);
    //static void ReportarClientes(ArbolB* Arbol);
    
};
