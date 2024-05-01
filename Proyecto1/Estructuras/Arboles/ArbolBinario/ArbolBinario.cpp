#include "ArbolBinario.h"

#include <iostream>
#include <regex>
#include <vcruntime.h>

void ArbolBinario::InsertarNodo(NodoBase* Nodo)
{
    if (!Raiz)
    {
        Raiz = Nodo;
        return;
    }
    Insertar(Raiz, Nodo);
}

NodoBase* ArbolBinario::BuscarNodo(NodoBase* NodoRaiz, int Llave)
{
    if (!NodoRaiz)
    {
        return nullptr;
    }

    if (NodoRaiz->GetLlave() == Llave)
    {
        return NodoRaiz;
    }

    if (Llave < NodoRaiz->GetLlave())
    {
        return BuscarNodo(NodoRaiz->Izquierda, Llave);
    }
    return BuscarNodo(NodoRaiz->Derecha, Llave);
    
}

void ArbolBinario::Infijo(NodoBase* Nodo)
{
    if (!Nodo) return;

    Infijo(Nodo->Izquierda);
    Nodo->Mostrar();
    Infijo(Nodo->Derecha);
}

void ArbolBinario::IterarNodos(std::function<void(NodoBase*)> func)
{
    IterarNodosAux(Raiz, func);
}

void ArbolBinario::IterarNodosAux(NodoBase* Nodo, std::function<void(NodoBase*)> func)
{
    IterarNodosAux(Nodo->Izquierda, func);
    func(Nodo);
    IterarNodosAux(Nodo->Derecha, func);
}

void ArbolBinario::Insertar(NodoBase*& NodoRaiz, NodoBase* Nodo)
{
    if (!NodoRaiz)
    {
        NodoRaiz = Nodo;
        return;
    }

    if (Nodo->GetLlave() == NodoRaiz->GetLlave())
    {
        std::cout << "Nodo ya existe\n";
        return;
    }
    
    if (Nodo->GetLlave() < NodoRaiz->GetLlave())
    {
        Insertar(NodoRaiz->Izquierda, Nodo);
    }
    else
    {
        Insertar(NodoRaiz->Derecha, Nodo);
    }
}
