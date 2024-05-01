#pragma once
#include <functional>

#include "../../../Estructuras/Nodos/NodoBase.h"

class ArbolBinario
{
public:
    NodoBase* Raiz = nullptr;
    
    void InsertarNodo(NodoBase* Nodo);

    NodoBase* BuscarNodo(NodoBase* NodoRaiz, int Llave);
    void Infijo(NodoBase* Nodo);

    void IterarNodos(std::function<void(NodoBase*)> func);

private:
    void Insertar(NodoBase*& NodoRaiz, NodoBase* Nodo);
    void IterarNodosAux(NodoBase* Nodo, std::function<void(NodoBase*)> func);
};