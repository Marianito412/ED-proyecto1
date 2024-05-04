#pragma once
#include <functional>

#include "../Nodos/NodoArbolB.h"
#include "../Nodos/NodoBase.h"

class ArbolB
{
    NodoArbolB* Raiz = nullptr;
    int Grado = 5;
public:
    
    void Insertar(NodoBase* Nodo);

    void Recorrer();

    NodoArbolB* Buscar(int k, NodoBase*& Nodo);

    void IterarNodos(std::function<void(NodoBase*)> func);
};
