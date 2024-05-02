#include "ArbolRN.h"

void ArbolRN::IterarNodosAux(NodoBase* Nodo, std::function<void(NodoBase*)> func)
{
    if (!Nodo) return;
    IterarNodosAux(Nodo->Izquierda, func);
    func(Nodo);
    IterarNodosAux(Nodo->Derecha, func);
}

void ArbolRN::IterarNodos(std::function<void(NodoBase*)> func)
{
    IterarNodosAux(Raiz, func);
}
