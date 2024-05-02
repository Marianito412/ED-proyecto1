#include "TablaHash.h"

TablaHash::TablaHash()
{
    for (int i = 0; i<TAMANNO;i++)
    {
        Tabla[i] = new ListaSimple();
    }
}

int TablaHash::ConseguirHash(int Llave)
{
    return Llave%TAMANNO;
}

void TablaHash::InsertarNodo(NodoBase* Nodo, int Llave)
{
    Tabla[ConseguirHash(Llave)]->InsertarFinal(Nodo);
}

NodoBase* TablaHash::BuscarNodo(int Llave, function<bool(NodoBase*)> func)
{
    return Tabla[ConseguirHash(Llave)]->EncontrarPorPredicado(func);
}

void TablaHash::EliminarNodo(int Llave, function<bool(NodoBase*)> func)
{
    ListaSimple* Lista = Tabla[ConseguirHash(Llave)]; 
    NodoBase* Nodo = Lista->EncontrarPorPredicado(func);

    if (!Nodo)
    {
        cout<<"El elemento no existe en la tabla hash"<<endl;
        return;
    }
    Lista->BorrarPosicion(Lista->ConseguirPosicion(Nodo));
}

void TablaHash::IterarNodos(function<void(NodoBase*)> func)
{
    for (int i = 0; i<TAMANNO;i++)
    {
        if (Tabla[i]->ListaVacia()) continue;
        Tabla[i]->IterarNodos(func);
        //cout<<"______________________________"<<endl;
    }
}

void TablaHash::Mostrar()
{
    for (int i = 0; i<TAMANNO;i++)
    {
        if (Tabla[i]->ListaVacia()) continue;
        Tabla[i]->Mostrar();
        cout<<"______________________________"<<endl;
    }
}
