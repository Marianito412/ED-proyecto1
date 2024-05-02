#include "ListaDoble.h"

#include <iostream>

ListaDoble::~ListaDoble()
{
    NodoBase* Aux;

    while (primero)
    {
        Aux = primero;
        primero = primero->Siguiente;
        delete Aux;
    }
    primero = nullptr;
}

int ListaDoble::largoLista()
{
    int cont = 0;

    NodoBase* Aux;
    Aux = primero;
    if (ListaVacia())
    {
        return cont;
    }
    else
    {
        while (Aux != nullptr)
        {
            Aux = Aux->Siguiente;
            cont++;
        }
        return cont;
    }
}

void ListaDoble::InsertarInicio(NodoBase* NuevoNodo)
{
   if (ListaVacia())
   {
   
     primero = NuevoNodo;
     primero->Anterior=nullptr;     
   }
   else
   {
     primero=NuevoNodo;
     primero->Siguiente->Anterior=primero;
   }
}
 
void ListaDoble::InsertarFinal(NodoBase* NuevoNodo)
{
   if (ListaVacia())
   {
   
     primero = NuevoNodo;
     primero->Anterior=nullptr;     
   }
   else
     { NodoBase* Aux = primero;
        while ( Aux->Siguiente != nullptr)
          Aux= Aux->Siguiente;
        Aux->Siguiente=NuevoNodo;
        Aux->Siguiente->Anterior=Aux;       
      }    
}


void ListaDoble::InsertarPos(NodoBase* NuevoNodo, int pos)
{
    if (ListaVacia())
    {
        primero = NuevoNodo;
        primero->Anterior = nullptr;
    }
    else
    {
        if (pos <= 1)
            InsertarInicio(NuevoNodo);
        else
        {
            NodoBase* Aux = primero;
            int i = 2;
            while ((i != pos) && (Aux->Siguiente != nullptr))
            {
                i++;
                Aux = Aux->Siguiente;
            }
            NodoBase* nuevo = NuevoNodo;
            nuevo->Siguiente = Aux->Siguiente;
            Aux->Siguiente = nuevo;
            Aux->Siguiente->Anterior = Aux;
            nuevo->Siguiente->Anterior = nuevo;
        }
    }
}

void ListaDoble::BorrarFinal()
{
    if (ListaVacia())
    {
        std::cout << "No hay elementos en la lista:" << std::endl;
    }
    else
    {
        if (primero->Siguiente == nullptr) //solo un nodo
        {
            NodoBase* temp = primero;
            primero = nullptr;
            delete temp;
        }
        else
        {
            NodoBase* Aux = primero;
            while (Aux->Siguiente->Siguiente != nullptr)
            {
                Aux = Aux->Siguiente;
            }

            NodoBase* temp = Aux->Siguiente;
            Aux->Siguiente = nullptr;

            delete temp;
        }
    }
}

void ListaDoble::BorrarInicio()
{
    if (ListaVacia())
    {
        std::cout << "No hay elementos en la lista:" << std::endl;
    }
    else
    {
        if (primero->Siguiente == nullptr)
        {
            NodoBase* temp = primero;
            primero = nullptr;
            delete temp;
        }
        else
        {
            NodoBase* Aux = primero;
            primero = primero->Siguiente;
            primero->Anterior = nullptr;
            delete Aux;
        }
    }
}


void ListaDoble::BorrarPosicion(int pos)
{
    if (ListaVacia())
    {
        std::cout << "Lista vacia" << std::endl;
    }
    else
    {
        if ((pos > largoLista()) || (pos < 0)) //no validas
        {
            std::cout << "Error en posicion" << std::endl;
        }
        else
        {
            if (pos == 1)
                BorrarInicio();
            else
            {
                if (pos == largoLista())
                    BorrarFinal();
                else
                {
                    int cont = 2;
                    NodoBase* Aux = primero;
                    while (cont < pos)
                    {
                        Aux = Aux->Siguiente;
                        cont++;
                    }
                    NodoBase* temp = Aux->Siguiente;
                    Aux->Siguiente = Aux->Siguiente->Siguiente;
                    Aux->Siguiente->Anterior = Aux;
                    delete temp;
                } //else
            } //else
        } //else
    } //else
}

NodoBase* ListaDoble::EncontrarPorPredicado(std::function<bool(NodoBase*)> func)
{
    NodoBase* Aux = primero;

    while (Aux)
    {
        if (func(Aux))
        {
            return Aux;
        }
        Aux = Aux->Siguiente;
    }
    return nullptr;
}

int ListaDoble::ConseguirPosicion(NodoBase* Nodo)
{
    NodoBase* Aux = primero;

    int i = 1;
    while (Aux)
    {
        if (Aux == Nodo)
        {
            return i;
        }
        i++;
        Aux = Aux->Siguiente;
    }
    return -1;
}

void ListaDoble::IterarNodos(std::function<void(NodoBase*)> func)
{
    NodoBase* Aux = primero;
    while (Aux)
    {
        func(Aux);
        Aux = Aux->Siguiente;
    }
}

void ListaDoble::Mostrar()
{
    NodoBase* Aux;

    Aux = primero;
    while (Aux)
    {
        Aux->Mostrar();
        //std::cout << "-> ";
        Aux = Aux->Siguiente;
    }
    std::cout << std::endl;
}
