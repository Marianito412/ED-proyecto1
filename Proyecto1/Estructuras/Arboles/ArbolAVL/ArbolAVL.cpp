#include "ArbolAVL.h"

#include <vcruntime.h>

void ArbolAVL::RotacionSimpleIzquierda(NodoBase* N, NodoBase* N1)
{
    N->Izquierda = N1->Derecha;
    N1->Derecha = N;

    if (N1->FactorBalance ==-1)
    {
        N->FactorBalance = 0;
        N1->FactorBalance = 0;
    }
    else
    {
        N->FactorBalance = -1;
        N1->FactorBalance = -1;
        N = N1;
    }
    N = N1;
}

void ArbolAVL::RotacionSimpleDerecha(NodoBase* N, NodoBase* N1)
{
    N->Derecha = N1->Izquierda;
    N1->Izquierda = N;

    if (N1->FactorBalance ==1)
    {
        N->FactorBalance = 0;
        N1->FactorBalance = 0;
    }
    else
    {
        N->FactorBalance = 1;
        N1->FactorBalance = -1;
    }
    N = N1;
}

void ArbolAVL::RotacionDobleIzquierda(NodoBase* N, NodoBase* N1)
{
    NodoBase* N2;
    N2 = N1->Derecha;
    N->Izquierda = N2->Derecha;
    N2->Derecha = N;
    N1->Derecha = N2->Izquierda;
    N2->Izquierda = N1;

    if (N2->FactorBalance == 1)
    {
        N1->FactorBalance = -1;
    }
    else
    {
        N1->FactorBalance = 0;
    }
    
    if (N2->FactorBalance == -1)
    {
        N->FactorBalance = 1;
    }
    else
    {
        N->FactorBalance = 0;    
    }
    N2->FactorBalance = 0;
    N = N2;
}

void ArbolAVL::RotacionDobleDerecha(NodoBase* N, NodoBase* N1)
{
    NodoBase* N2;
    N2 = N1->Izquierda;
    N->Derecha = N2->Izquierda;
    N2->Izquierda = N;
    N1->Izquierda = N2->Derecha;
    N2->Derecha = N1;

    if (N2->FactorBalance == 1)
    {
        N1->FactorBalance = -1;
    }
    else
    {
        N1->FactorBalance = 0;
    }
    
    if (N2->FactorBalance == -1)
    {
        N1->FactorBalance = 1;
    }
    else
    {
        N1->FactorBalance = 0;    
    }
    N2->FactorBalance = 0;
    N = N2;
}

void ArbolAVL::InsertarNodo(NodoBase*& NodoRaiz, bool HH, NodoBase* Nodo)
{
    if (!NodoRaiz)
    {
        NodoRaiz = Nodo;
        HH = true;
        return;
    }
    if (Nodo->GetLlave()<=NodoRaiz->GetLlave())
    {
        InsertarNodo(NodoRaiz->Izquierda, HH, Nodo);
        if (HH)
        {
            switch (NodoRaiz->GetLlave())
            {
            case 1:
                Raiz->FactorBalance = 0;
                HH = false;
                break;
            case 0:
                Raiz->FactorBalance = -1;
                break;
            case -1:
                NodoBase* N1 = NodoRaiz->Izquierda;
                if (N1->FactorBalance == -1)
                {
                    RotacionSimpleIzquierda(NodoRaiz, N1);    
                }
                else
                {
                    RotacionDobleIzquierda(NodoRaiz, N1);
                }
            }
        }
    }
    else
    {
        InsertarNodo(NodoRaiz->Derecha, HH, Nodo);
        if (HH)
        {
            switch (NodoRaiz->GetLlave())
            {
            case -1:
                Raiz->FactorBalance = 0;
                HH = false;
                break;
            case 0:
                Raiz->FactorBalance = 1;
                break;
            case 1:
                NodoBase* N1 = NodoRaiz->Derecha;
                if (N1->FactorBalance == -1)
                {
                    RotacionSimpleDerecha(NodoRaiz, N1);    
                }
                else
                {
                    RotacionDobleDerecha(NodoRaiz, N1);
                }
            }
        }
    }
}

void ArbolAVL::Infijo(NodoBase* Nodo)
{
    if (!Nodo) return;

    Infijo(Nodo->Izquierda);
    Nodo->Mostrar();
    Infijo(Nodo->Derecha);
}

void ArbolAVL::IterarNodos(std::function<void(NodoBase*)> func)
{
    IterarNodosAux(Raiz, func);
}

void ArbolAVL::IterarNodosAux(NodoBase* Nodo, std::function<void(NodoBase*)> func)
{
    IterarNodosAux(Nodo->Izquierda, func);
    func(Nodo);
    IterarNodosAux(Nodo->Derecha, func);
}

NodoBase* ArbolAVL::BuscarNodo(NodoBase* NodoRaiz, int Llave)
{
    if (!NodoRaiz) return nullptr;
    
    if (NodoRaiz->GetLlave() == Llave)
    {
        return NodoRaiz;
    }

    if (Llave <= NodoRaiz->GetLlave())
    {
        
    }
    return BuscarNodo(NodoRaiz->Izquierda, Llave);
}

