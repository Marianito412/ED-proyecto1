#pragma once
#include "../../Nodos/NodoBase.h"

class ArbolAVL
{
public:
    NodoBase* Raiz;

    void RotacionSimpleIzquierda(NodoBase* N, NodoBase* N1);
    void RotacionSimpleDerecha(NodoBase* N, NodoBase* N1);

    void RotacionDobleIzquierda(NodoBase* N, NodoBase* N1);
    void RotacionDobleDerecha(NodoBase* N, NodoBase* N1);
    
    void InsertarNodo(NodoBase*& NodoRaiz, bool HH, NodoBase* Nodo);

    void Infijo(NodoBase* Nodo);

    NodoBase* BuscarNodo(NodoBase* NodoRaiz, int Llave);
};
