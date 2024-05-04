#include "ArbolB.h"

void ArbolB::Insertar(NodoBase* Nodo)
{
    // If tree is empty
    if (Raiz == nullptr)
    {
        // Allocate memory for Raiz
        Raiz = new NodoArbolB(Grado, true);
        Raiz->keys[0] = Nodo;  // Insert key
        Raiz->n = 1;  // Update number of keys in Raiz
    }
    else // If tree is not empty
    {
        // If Raiz is full, then tree grows in height
        if (Raiz->n == 2*Grado-1)
        {
            // Allocate memory for new Raiz
            NodoArbolB *s = new NodoArbolB(Grado, false);

            // Make old Raiz as child of new Raiz
            s->C[0] = Raiz;

            // Split the old Raiz and move 1 key to the new Raiz
            s->splitChild(0, Raiz);

            // New Raiz has two children now.  Decide which of the
            // two children is going to have new key
            int i = 0;
            if (s->keys[0]->GetLlave() < Nodo->GetLlave())
                i++;
            s->C[i]->insertNonFull(Nodo);

            // Change Raiz
            Raiz = s;
        }
        else  // If Raiz is not full, call insertNonFull for Raiz
            Raiz->insertNonFull(Nodo);
    }
}

void ArbolB::Recorrer()
{
    if (Raiz != nullptr) Raiz->traverse();
}

NodoArbolB* ArbolB::Buscar(int k, NodoBase*& Nodo)
{
    return (Raiz == nullptr)? nullptr : Raiz->search(k, Nodo);
}
