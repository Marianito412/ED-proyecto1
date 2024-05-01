#pragma once
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

 /* // For balancing the tree after deletion
  void deleteFix(NodePtr x) {
    NodePtr s;
    while (x != root && x->color == 0) {
      if (x == x->parent->left) {
        s = x->parent->right;
        if (s->color == 1) {
          s->color = 0;
          x->parent->color = 1;
          leftRotate(x->parent);
          s = x->parent->right;
        }

        if (s->left->color == 0 && s->right->color == 0) {
          s->color = 1;
          x = x->parent;
        } else {
          if (s->right->color == 0) {
            s->left->color = 0;
            s->color = 1;
            rightRotate(s);
            s = x->parent->right;
          }

          s->color = x->parent->color;
          x->parent->color = 0;
          s->right->color = 0;
          leftRotate(x->parent);
          x = root;
        }
      } else {
        s = x->parent->left;
        if (s->color == 1) {
          s->color = 0;
          x->parent->color = 1;
          rightRotate(x->parent);
          s = x->parent->left;
        }

        if (s->right->color == 0 && s->right->color == 0) {
          s->color = 1;
          x = x->parent;
        } else {
          if (s->left->color == 0) {
            s->right->color = 0;
            s->color = 1;
            leftRotate(s);
            s = x->parent->left;
          }

          s->color = x->parent->color;
          x->parent->color = 0;
          s->left->color = 0;
          rightRotate(x->parent);
          x = root;
        }
      }
    }
    x->color = 0;
  }*/

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

  /*void deleteNodeHelper(NodePtr node, int key) {
    NodePtr z = TNULL;
    NodePtr x, y;
    while (node != TNULL) {
      if (node->data == key) {
        z = node;
      }

      if (node->data <= key) {
        node = node->right;
      } else {
        node = node->left;
      }
    }

    if (z == TNULL) {
      cout << "Key not found in the tree" << endl;
      return;
    }

    y = z;
    int y_original_color = y->color;
    if (z->left == TNULL) {
      x = z->right;
      rbTransplant(z, z->right);
    } else if (z->right == TNULL) {
      x = z->left;
      rbTransplant(z, z->left);
    } else {
      y = minimum(z->right);
      y_original_color = y->color;
      x = y->right;
      if (y->parent == z) {
        x->parent = y;
      } else {
        rbTransplant(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }

      rbTransplant(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }
    delete z;
    if (y_original_color == 0) {
      deleteFix(x);
    }
  }*/

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

   public:
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

/*  void deleteNode(int data) {
    deleteNodeHelper(this->root, data);
  }*/

  void MostrarRN() {
    if (Raiz) {
      MostrarRN(this->Raiz, "", true);
    }
  }
};