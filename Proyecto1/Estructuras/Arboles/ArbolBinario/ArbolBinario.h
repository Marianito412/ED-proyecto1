#pragma once
#include "../../../Estructuras/Nodos/NodoBase.h"

class ArbolBinario
{
public:
    NodoBase* Raiz = nullptr;
    
    void InsertarNodo(NodoBase* Nodo);

    NodoBase* BuscarNodo(NodoBase* NodoRaiz, int Llave);
    void Infijo(NodoBase* Nodo);

private:
    void Insertar(NodoBase*& NodoRaiz, NodoBase* Nodo);
};