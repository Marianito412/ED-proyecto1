#pragma once
#include <functional>

#include "../ListaSimple/ListaSimple.h"

class TablaHash
{
    const static int TAMANNO = 13;
public:
    ListaSimple* Tabla[TAMANNO];

    TablaHash();

    int ConseguirHash(int Llave);

    void InsertarNodo(NodoBase* Nodo, int Llave);

    NodoBase* BuscarNodo(int Llave, function<bool(NodoBase*)> func);

    void EliminarNodo(int Llave, function<bool(NodoBase*)> func);

    void IterarNodos(function<void(NodoBase*)> func);

    void Mostrar();
};
