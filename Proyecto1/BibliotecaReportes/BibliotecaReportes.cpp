#include "BibliotecaReportes.h"

#include <fstream>

#include "../Estructuras/Nodos/NodosDerivados/Administrador/NodoAdmin.h"
#include "../Estructuras/Nodos/NodosDerivados/Pasillo/NodoPasillo.h"
#include "../Estructuras/Nodos/NodosDerivados/Producto/NodoProducto.h"
#include "../Estructuras/Nodos/NodosDerivados/Ciudad/NodoCiudad.h"
#include "../Estructuras/Nodos/NodosDerivados/Clientes/NodoCliente.h"
#include "../Estructuras/Nodos/NodosDerivados/Marca/NodoMarca.h"

void BibliotecaReportes::ReportarPasillos(ListaSimple* ListaPasillos)
{
    ofstream Reporte("../Reportes/ReportePasillos.csv");

    ListaPasillos->IterarNodos([&Reporte](NodoBase* Nodo)
    {
        if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(Nodo))
        {
            Reporte<<std::to_string(Pasillo->Codigo)+","+Pasillo->Nombre+"\n";
        }
    });

    Reporte.close();
}

void BibliotecaReportes::ReportarPasilloMasVisto(ListaSimple* ListaPasillos)
{
    ofstream Reporte("../Reportes/ReportePasilloMasVisto.csv");

    NodoPasillo* PasilloMasVisto = nullptr;
    ListaPasillos->IterarNodos([&Reporte, &PasilloMasVisto](NodoBase* Nodo)
    {
        if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(Nodo))
        {
            int MaximasBusquedas = PasilloMasVisto ? PasilloMasVisto->Vistas : 0; 
            if (Pasillo->Vistas >= MaximasBusquedas)
            {
                PasilloMasVisto = Pasillo;
            }
        }
    });

    if (PasilloMasVisto)
    {
        Reporte<<std::to_string(PasilloMasVisto->Codigo)+","+PasilloMasVisto->Nombre+"\n";    
    }

    Reporte.close();
}

void BibliotecaReportes::ReportarPasilloMenosVisto(ListaSimple* ListaPasillos)
{
    ofstream Reporte("../Reportes/ReportePasilloMenosVisto.csv");

    NodoPasillo* PasilloMenosVisto = nullptr;
    ListaPasillos->IterarNodos([&Reporte, &PasilloMenosVisto](NodoBase* Nodo)
    {
        if (NodoPasillo* Pasillo = dynamic_cast<NodoPasillo*>(Nodo))
        {
            int MinimasBusquedas = PasilloMenosVisto ? PasilloMenosVisto->Vistas : INT_MAX; 
            if (Pasillo->Vistas <= MinimasBusquedas)
            {
                PasilloMenosVisto = Pasillo;
            }
        }
    });

    if (PasilloMenosVisto)
    {
        Reporte<<std::to_string(PasilloMenosVisto->Codigo)+","+PasilloMenosVisto->Nombre+"\n";    
    }
    
    Reporte.close();
}

void BibliotecaReportes::ReportarProductosPasillo(ListaDoble* ListaProds)
{
    int NumPasillo = 0;
    cout<<"Ingrese el numero de pasillo: ";
    cin>>NumPasillo;
    
    ofstream Reporte("../Reportes/ReporteProdsPasillo.csv");

    ListaProds->IterarNodos([&Reporte, NumPasillo](NodoBase* Nodo)
    {
        if (NodoProducto* Producto = dynamic_cast<NodoProducto*>(Nodo))
        {
            if (NumPasillo != Producto->Pasillo) return;
            
            Reporte<<std::to_string(Producto->Pasillo)+"," + std::to_string(Producto->Producto) + "," + Producto->Nombre+"\n";
        }
    });
    Reporte.close();
}

void BibliotecaReportes::ReportarProductosMasBuscados(ListaDoble* ListaProds)
{
    int NumPasillo = 0;
    cout<<"Ingrese el numero de pasillo: ";
    cin>>NumPasillo;
    
    ofstream Reporte("../Reportes/ReporteProductosMasBuscados.csv");

    NodoProducto* ProductoMasVisto = nullptr;
    ListaProds->IterarNodos([&ProductoMasVisto, NumPasillo](NodoBase* Nodo)
    {
        if (NodoProducto* Producto = dynamic_cast<NodoProducto*>(Nodo))
        {
            int MaximasBusquedas = ProductoMasVisto ? ProductoMasVisto->Busquedas : 0; 
            if (NumPasillo == Producto->Pasillo && Producto->Busquedas >= MaximasBusquedas)
            {
                ProductoMasVisto = Producto;
            }
        }
    });

    if (ProductoMasVisto)
    {
        Reporte<<std::to_string(ProductoMasVisto->Pasillo)+"," + std::to_string(ProductoMasVisto->Producto) + "," + ProductoMasVisto->Nombre+"\n";
    }

    Reporte.close();
}
/*
void BibliotecaReportes::ReportarProductosMenosBuscados(ListaDoble* ListaProds)
{
    ofstream Reporte("../Reportes/ReporteProductosMenosBuscados.csv");

    NodoProducto* ProductoMenosVisto = nullptr;
    ListaProds->IterarNodos([&Reporte, &ProductoMenosVisto](NodoBase* Nodo)
    {
        if (NodoProducto* Producto = dynamic_cast<NodoProducto*>(Nodo))
        {
            int MaximasBusquedas = ProductoMenosVisto ? ProductoMenosVisto->Busquedas : 0; 
            if (Producto->Busquedas <= MaximasBusquedas)
            {
                ProductoMenosVisto = Producto;
            }
        }
    });

    if (ProductoMenosVisto)
    {
        Reporte<<std::to_string(ProductoMenosVisto->Pasillo)+"," + std::to_string(ProductoMenosVisto->Producto) + "," + ProductoMenosVisto->Nombre+"\n";
    }

    Reporte.close();
}
*/
void BibliotecaReportes::ReportarAdministradores(TablaHash* TablaAdmins)
{
    ofstream Reporte("../Reportes/ReporteAdmins.csv");

    TablaAdmins->IterarNodos([&Reporte](NodoBase* Nodo)
    {
        if (NodoAdmin* Admin = dynamic_cast<NodoAdmin*>(Nodo))
        {
            Reporte<<std::to_string(Admin->CodAministrador)+"," + Admin->Nombre + "," + std::to_string(Admin->CodCiudad) + ","+ std::to_string(Admin->Telefono)+ "," +Admin->Correo+"\n";
        }
    });
    Reporte.close();
}

void BibliotecaReportes::ReportarCiudades(ListaCircular* ListaCiudades)
{
    ofstream Reporte("../Reportes/ReporteCiudades.csv");

    ListaCiudades->IterarNodos([&Reporte](NodoBase* Nodo) {
        if (NodoCiudad* Ciudad = dynamic_cast<NodoCiudad*>(Nodo)) {
            Reporte << std::to_string(Ciudad->CodCiudad) + ";" + Ciudad->Nombre + "\n";
        }
    });

    Reporte.close();
}

void BibliotecaReportes::ReportarClientes(TablaHash* TablaClientes) {
    ofstream Reporte("../Reportes/ReporteClientes.csv");

    TablaClientes->IterarNodos([&Reporte](NodoBase* Nodo) {
        if (NodoCliente* Cliente = dynamic_cast<NodoCliente*>(Nodo)) {
            Reporte << std::to_string(Cliente->Cedula) + ";" + Cliente->Nombre + ";" + std::to_string(Cliente->CodCiudad) + ";" + std::to_string(Cliente->Telefono) + ";" + Cliente->Correo + "\n";
        }
    });

    Reporte.close();
}

void BibliotecaReportes::ReportarMarcasProducto(ListaDobleCircular* ListaMarcas)
{
    int CodPasillo, CodProducto;
    cout << "Ingrese el código del pasillo: ";
    cin >> CodPasillo;
    cout << "Ingrese el código del producto: ";
    cin >> CodProducto;

    ofstream Reporte("../Reportes/ReporteMarcasProducto.csv");

    ListaMarcas->IterarNodos([&Reporte, CodPasillo, CodProducto](NodoBase* Nodo) {
        if (NodoMarca* Marca = dynamic_cast<NodoMarca*>(Nodo)) {
            if (Marca->CodPasillo == CodPasillo && Marca->CodProducto == CodProducto) {
                Reporte << Marca->CodPasillo << ";" << Marca->CodProducto << ";" << Marca->CodMarca << ";" << Marca->Nombre << ";" << Marca->CantidadGondola << ";" << Marca->Precio << "\n";
            }
        }
    });

    Reporte.close();
}

void BibliotecaReportes::ReportarMarcasMasBuscadas(ListaDobleCircular* ListaMarcas)
{
    int CodPasillo, CodProducto;
    cout << "Ingrese el código del pasillo: ";
    cin >> CodPasillo;
    cout << "Ingrese el código del producto: ";
    cin >> CodProducto;
    
    ofstream Reporte("../Reportes/ReporteMarcasMasBuscadas.csv");

    NodoProducto* ProductoMasVisto = nullptr;
    ListaMarcas->IterarNodos([&ProductoMasVisto, CodPasillo, CodProducto](NodoBase* Nodo)
    {
        if (NodoProducto* Producto = dynamic_cast<NodoProducto*>(Nodo))
        {
            int MaximasBusquedas = ProductoMasVisto ? ProductoMasVisto->Busquedas : 0; 
            if (CodPasillo == Producto->Pasillo && CodProducto == Producto->Producto && Producto->Busquedas >= MaximasBusquedas)
            {
                ProductoMasVisto = Producto;
            }
        }
    });

    if (ProductoMasVisto)
    {
        Reporte<<std::to_string(ProductoMasVisto->Pasillo)+"," + std::to_string(ProductoMasVisto->Producto) + "," + ProductoMasVisto->Nombre+"\n";
    }

    Reporte.close();
}
