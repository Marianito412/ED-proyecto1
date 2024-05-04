#include "NodoCarrito.h"

#include "NodoCompra.h"

float NodoCarrito::GetTotal()
{
    float Total = 0;
    Compras->IterarNodos([&Total](NodoBase* Nodo)
    {
        if (NodoCompra* Compra = dynamic_cast<NodoCompra*>(Nodo))
        {
            Total = Total + Compra->Precio;
        }
    });
    return Total;
}
