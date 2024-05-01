#pragma once
#include "../Estructuras/ListaDoble/ListaDoble.h"
#include "../Estructuras/ListaSimple/ListaSimple.h"
#include "../Estructuras/TablaHash/TablaHash.h"
#include "../Estructuras/ListaCircular/ListaCircular.h"
#include "../Estructuras/ListaDobleCircular/ListaDobleCircular.h"

class BibliotecaReportes
{
public:
    static void ReportarPasillos(ListaSimple* ListaPasillos);
    static void ReportarPasilloMasVisto(ListaSimple* ListaPasillos);
    static void ReportarPasilloMenosVisto(ListaSimple* ListaPasillos);
    
    static void ReportarProductosPasillo(ListaDoble* ListaProds);
    static void ReportarProductosMasBuscados(ListaDoble* ListaProds);
    //static void ReportarProductosMenosBuscados(ListaDoble* ListaProds);
    
    static void ReportarAdministradores(TablaHash* TablaAdmins);
    
    static void ReportarCiudades(ListaCircular* ListaCiudades);
    
    static void ReportarClientes(TablaHash* TablaClientes);
    
    static void ReportarMarcasProducto(ListaDobleCircular* ListaMarcas);
    static void ReportarMarcasMasBuscadas(ListaDobleCircular* ListaMarcas);
};
