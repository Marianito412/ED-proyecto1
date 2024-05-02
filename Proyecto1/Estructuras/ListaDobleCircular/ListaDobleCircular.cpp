#include "ListaDobleCircular.h"
#include <iostream>

ListaDobleCircular::~ListaDobleCircular()
{
    if (ListaVacia())
    {
        return;
    }

    NodoBase* Aux = primero;
    while (Aux->Siguiente != primero)
    {
        NodoBase* temp = Aux;
        Aux = Aux->Siguiente;
        delete temp;
    }
    delete Aux;
    primero = nullptr;
}

void ListaDobleCircular::InsertarInicio(NodoBase* NuevoNodo)
{
    if (ListaVacia())
    {
        primero = NuevoNodo;
        primero->Siguiente = primero;
        primero->Anterior = primero;
    }
    else
    {
        NuevoNodo->Siguiente = primero;
        NuevoNodo->Anterior = primero->Anterior;
        primero->Anterior->Siguiente = NuevoNodo;
        primero->Anterior = NuevoNodo;
        primero = NuevoNodo;
    }
}

void ListaDobleCircular::InsertarFinal(NodoBase* NuevoNodo)
{
    if (ListaVacia())
    {
        primero = NuevoNodo;
        primero->Siguiente = primero;
        primero->Anterior = primero;
    }
    else
    {
        NuevoNodo->Siguiente = primero;
        NuevoNodo->Anterior = primero->Anterior;
        primero->Anterior->Siguiente = NuevoNodo;
        primero->Anterior = NuevoNodo;
    }
}

void ListaDobleCircular::InsertarPos(NodoBase* NuevoNodo, int pos)
{
    if (pos <= 1)
    {
        InsertarInicio(NuevoNodo);
    }
    else if (pos > largoLista())
    {
        InsertarFinal(NuevoNodo);
    }
    else
    {
        NodoBase* Aux = primero;
        for (int i = 2; i < pos; i++)
        {
            Aux = Aux->Siguiente;
        }
        NuevoNodo->Siguiente = Aux->Siguiente;
        NuevoNodo->Anterior = Aux;
        Aux->Siguiente->Anterior = NuevoNodo;
        Aux->Siguiente = NuevoNodo;
    }
}

void ListaDobleCircular::BorrarFinal()
{
    if (ListaVacia())
    {
        std::cout << "No hay elementos en la lista." << std::endl;
        return;
    }

    if (primero->Siguiente == primero) // Solo un nodo en la lista
    {
        delete primero;
        primero = nullptr;
        return;
    }

    NodoBase* Aux = primero->Anterior;
    Aux->Anterior->Siguiente = primero;
    primero->Anterior = Aux->Anterior;
    delete Aux;
}

void ListaDobleCircular::BorrarInicio()
{
    if (ListaVacia())
    {
        std::cout << "No hay elementos en la lista." << std::endl;
        return;
    }

    if (primero->Siguiente == primero) // Solo un nodo en la lista
    {
        delete primero;
        primero = nullptr;
        return;
    }

    NodoBase* Aux = primero;
    primero = primero->Siguiente;
    primero->Anterior = Aux->Anterior;
    Aux->Anterior->Siguiente = primero;
    delete Aux;
}

void ListaDobleCircular::BorrarPosicion(int pos)
{
    if (ListaVacia())
    {
        std::cout << "Lista vacía." << std::endl;
        return;
    }

    if (pos <= 0 || pos > largoLista())
    {
        std::cout << "Posición inválida." << std::endl;
        return;
    }

    if (pos == 1)
    {
        BorrarInicio();
        return;
    }

    NodoBase* Aux = primero;
    for (int i = 1; i < pos; i++)
    {
        Aux = Aux->Siguiente;
    }

    Aux->Anterior->Siguiente = Aux->Siguiente;
    Aux->Siguiente->Anterior = Aux->Anterior;
    delete Aux;
}

NodoBase* ListaDobleCircular::EncontrarPorPredicado(std::function<bool(NodoBase*)> func)
{
    NodoBase* Aux = primero;
    do
    {
        if (func(Aux))
        {
            return Aux;
        }
        Aux = Aux->Siguiente;
    } while (Aux != primero);
    return nullptr;
}

void ListaDobleCircular::Mostrar()
{
    if (ListaVacia())
    {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    NodoBase* Aux = primero;
    do
    {
        Aux->Mostrar();
        Aux = Aux->Siguiente;
    } while (Aux != primero);
    std::cout << std::endl;
}

int ListaDobleCircular::largoLista()
{
    if (ListaVacia())
    {
        return 0;
    }

    int cont = 0;
    NodoBase* Aux = primero;
    do
    {
        cont++;
        Aux = Aux->Siguiente;
    } while (Aux != primero);

    return cont;
}

void ListaDobleCircular::IterarNodos(std::function<void(NodoBase*)> func)
{
    if (ListaVacia())
    {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    NodoBase* Aux = primero;
    do
    {
        func(Aux);
        Aux = Aux->Siguiente;
    } while (Aux != primero);
}
