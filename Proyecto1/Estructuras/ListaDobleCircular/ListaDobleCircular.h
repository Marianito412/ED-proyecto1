#pragma once
#include <functional>

#include "../Nodos/NodoBase.h"

class ListaDobleCircular
{
public:
    ListaDobleCircular() { primero = nullptr; }
    ~ListaDobleCircular();

    void InsertarInicio(NodoBase* NuevoNodo);
    void InsertarFinal(NodoBase* NuevoNodo);
    void InsertarPos(NodoBase* NuevoNodo, int pos);
    bool ListaVacia() { return primero == nullptr; }
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    NodoBase* EncontrarPorPredicado(std::function<bool(NodoBase*)> func);
    void Mostrar();
    int largoLista();
    void IterarNodos(std::function<void(NodoBase*)> func);
    NodoBase* GetPrimero() const
    {
        return primero;
    }

private:
    NodoBase* primero;
};