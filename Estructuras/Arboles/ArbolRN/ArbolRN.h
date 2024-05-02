#pragma once
#include <functional>
#include <iostream>

#include "../../Nodos/NodoBase.h"

class ArbolRN {
private:
  NodoBase* Raiz;
  NodoBase* TNULL;

  void initializeNULLNode(NodoBase* nodo, NodoBase* padre) {
    //nodo->valor = 0;
    nodo->padre = padre;
    nodo->Izquierda= nullptr;
    nodo->Derecha = nullptr;
    nodo->color = 0;
  }

  // Preorder
  void preOrden(NodoBase* nodo) {
    if (nodo != TNULL) {
      nodo->Mostrar();
      preOrden(nodo->Izquierda);
      preOrden(nodo->Derecha);
    }
  }

  // Inorder
  void inOrden(NodoBase* nodo) {
    if (nodo != TNULL) {
      inOrden(nodo->Izquierda);
      nodo->Mostrar();
      inOrden(nodo->Derecha);
    }
  }

  // Post order
  void postOrden(NodoBase* nodo) {
    if (nodo != TNULL) {
      postOrden(nodo->Izquierda);
      postOrden(nodo->Derecha);
      nodo->Mostrar();
    }
  }

  NodoBase* Busqueda(NodoBase* nodo, int numbuscado) {

    if (!nodo) return nullptr;
    if (/*nodo == TNULL ||*/ numbuscado == nodo->GetLlave()) {
      return nodo;
    }

    if (numbuscado < nodo->GetLlave()) {
      return Busqueda(nodo->Izquierda, numbuscado);
    }
    return Busqueda(nodo->Derecha, numbuscado);
  }
  
  void rbModificar(NodoBase* uRaiz, NodoBase* vValor) {
    if (Raiz->padre == nullptr) {
      Raiz = vValor;
    } else if (uRaiz == uRaiz->padre->Izquierda) {
      uRaiz->padre->Izquierda = vValor;
    } else {
      uRaiz->padre->Derecha = vValor;
    }
    vValor->padre = uRaiz->padre;
  }
  
  // Balanceo despues de inserción
  void insertarBalanceado(NodoBase* NodoEva) {
    NodoBase* uValor;
    while (NodoEva->padre->color == 1) {
      if (NodoEva->padre == NodoEva->padre->padre->Derecha) {
        uValor = NodoEva->padre->padre->Izquierda;
        if (uValor->color == 1) {
          uValor->color = 0;
          NodoEva->padre->color = 0;
          NodoEva->padre->padre->color = 1;
          NodoEva = NodoEva->padre->padre;
        } else {
          if (NodoEva == NodoEva->padre->Izquierda) {
            NodoEva = NodoEva->padre;
            RotacionDerecha(NodoEva);
          }
          NodoEva->padre->color = 0;
          NodoEva->padre->padre->color = 1;
          RotacionIzquierda(NodoEva->padre->padre);
        }
      } else {
        uValor = NodoEva->padre->padre->Derecha;

        if (uValor->color == 1) {
          uValor->color = 0;
          NodoEva->padre->color = 0;
          NodoEva->padre->padre->color = 1;
          NodoEva = NodoEva->padre->padre;
        } else {
          if (NodoEva == NodoEva->padre->Derecha) {
            NodoEva = NodoEva->padre;
            RotacionIzquierda(NodoEva);
          }
          NodoEva->padre->color = 0;
          NodoEva->padre->padre->color = 1;
          RotacionDerecha(NodoEva->padre->padre);
        }
      }
      if (NodoEva == Raiz) {
        break;
      }
    }
    Raiz->color = 0;
  }

  void MostrarRN(NodoBase* raiz, std::string indent, bool ultimo) {
    if (raiz != TNULL) {
      std::cout << indent;
      if (ultimo) {
        std::cout << "Derecha----";
        indent += "   ";
      } else {
        std::cout << "Izquierda----";
        indent += "|  ";
      }

      std::string sColor = raiz->color ? "Rojo" : "Negro";
      raiz->Mostrar();
      MostrarRN(raiz->Izquierda, indent, false);
      MostrarRN(raiz->Derecha, indent, true);
    }
  }
  void IterarNodosAux(NodoBase* Nodo, std::function<void(NodoBase*)> func);
   public:
  void IterarNodos(std::function<void(NodoBase*)> func);
    ArbolRN() {
    TNULL = new NodoBase();
    TNULL->color = 0;
    TNULL->Izquierda = nullptr;
    TNULL->Derecha = nullptr;
    Raiz = TNULL;
  }

  void preordenM() {
    preOrden(this->Raiz);
  }

  void inordenM() {
    inOrden(this->Raiz);
  }

  void postorderM() {
    postOrden(this->Raiz);
  }

  NodoBase* BusquedaM(int numbuscado) {
    return Busqueda(this->Raiz, numbuscado);
  }

  NodoBase* minimo(NodoBase* nodo) {
    while (nodo->Izquierda != TNULL) {
      nodo = nodo->Izquierda;
    }
    return nodo;
  }

  NodoBase* maximo(NodoBase* nodo) {
    while (nodo->Derecha != TNULL) {
      nodo = nodo->Derecha;
    }
    return nodo;
  }

  NodoBase* successor(NodoBase* nodo) {
    if (nodo->Derecha != TNULL) {
      return minimo(nodo->Derecha);
    }

    NodoBase* y = nodo->padre;
    while (y != TNULL && nodo == y->Derecha) {
      nodo = y;
      y = y->padre;
    }
    return y;
  }

  NodoBase* predecessor(NodoBase* nodo) { ////////////////////////////////AQUI
    if (nodo->Izquierda != TNULL) {
      return maximo(nodo->Izquierda);
    }

    NodoBase* y = nodo->padre;
    while (y != TNULL && nodo == y->Izquierda) {
      nodo = y;
      y = y->padre;
    }

    return y;
  }

  void RotacionIzquierda(NodoBase* nodo) {
    NodoBase* y = nodo->Derecha;
    nodo->Derecha = y->Izquierda;
    if (y->Izquierda != TNULL) {
      y->Izquierda->padre = nodo;
    }
    y->padre = nodo->padre;
    if (nodo->padre == nullptr) {
      this->Raiz = y;
    } else if (nodo == nodo->padre->Izquierda) {
      nodo->padre->Izquierda = y;
    } else {
      nodo->padre->Derecha = y;
    }
    y->Izquierda = nodo;
    nodo->padre = y;
  }

  void RotacionDerecha(NodoBase* nodo) {
    NodoBase* y = nodo->Izquierda;
    nodo->Izquierda = y->Derecha;
    if (y->Derecha != TNULL) {
      y->Derecha->padre= nodo;
    }
    y->padre = nodo->padre;
    if (nodo->padre == nullptr) {
      this->Raiz = y;
    } else if (nodo == nodo->padre->Derecha) {
      nodo->padre->Derecha = y;
    } else {
      nodo->padre->Izquierda= y;
    }
    y->Derecha = nodo;
    nodo->padre = y;
  }

  // Insercion
  void insertar(NodoBase* NodoNuevo) {
    
    NodoNuevo->padre = nullptr;
    NodoNuevo->Izquierda = TNULL;
    NodoNuevo->Derecha = TNULL;
    NodoNuevo->color = 1;

    NodoBase* y = nullptr;
    NodoBase* x = this->Raiz;

    while (x != TNULL) {
      y = x;
      if (NodoNuevo->GetLlave() < x->GetLlave()) {
        x = x->Izquierda;
      } else {
        x = x->Derecha;
      }
    }

    NodoNuevo->padre = y;
    if (y == nullptr) {
      Raiz = NodoNuevo;
    } else if (NodoNuevo->GetLlave()< y->GetLlave()) {
      y->Izquierda = NodoNuevo;
    } else {
      y->Derecha = NodoNuevo;
    }

    if (NodoNuevo->padre== nullptr) {
      NodoNuevo->color = 0;
      return;
    }

    if (NodoNuevo->padre->padre == nullptr) {
      return;
    }

    insertarBalanceado(NodoNuevo);
  }

  NodoBase* getRaiz() {
    return this->Raiz;
  }

  void MostrarRN() {
    if (Raiz) {
      MostrarRN(this->Raiz, "", true);
    }
  }
};