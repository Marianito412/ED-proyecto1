#pragma once
#include <functional>

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

    void IterarNodos(std::function<void(NodoBase*)> func);

    NodoBase* BuscarNodo(NodoBase* NodoRaiz, int Llave);
private:
    void IterarNodosAux(NodoBase* Nodo, std::function<void(NodoBase*)> func);
};
