#pragma once
#include "NodoBase.h"

class NodoArbolB
{
public:
    NodoBase** keys; // An array of keys
    int t; // Minimum degree (defines the range for number
    // of keys)
    NodoArbolB** C; // An array of child pointers
    int n; // Current number of keys
    bool leaf; // Is true when node is leaf. Otherwise false

    NodoArbolB(int t, bool leaf)
        : t(t),
          leaf(leaf)
    {
        keys = new NodoBase*[2*t-1];
        C = new NodoArbolB*[2*t];
        n = 0;
    }

    // A utility function to insert a new key in the subtree rooted with
    // this node. The assumption is, the node must be non-full when this
    // function is called
    void insertNonFull(NodoBase* k);

    // A utility function to split the child y of this node. i is index of y in
    // child array C[].  The Child y must be full when this function is called
    void splitChild(int i, NodoArbolB* y);

    // A function to traverse all nodes in a subtree rooted with this node
    void traverse();

    // A function to search a key in the subtree rooted with this node.
    NodoArbolB* search(int k, NodoBase*& Nodo);   // returns NULL if k is not present.
};
