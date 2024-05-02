#pragma once
#include <functional>
#include <iostream>

#include "../Nodos/NodoBase.h"
using namespace std;

class ListaSimple
{
public:
	ListaSimple() { Primero = NULL; }
	~ListaSimple();

	void InsertarInicio(NodoBase* Nodo);
	void InsertarFinal(NodoBase* Nodo);
	void InsertarPos(int v, int pos);
	bool ListaVacia() { return Primero == NULL; }
	void Mostrar();
	void BorrarFinal();
	void BorrarInicio();
	void BorrarPosicion(int pos);
	NodoBase* EncontrarPorPredicado(function<bool(NodoBase*)> func);
	int ConseguirPosicion(NodoBase* Nodo);
	int largoLista();

	void IterarNodos(function<void(NodoBase*)> func);

	NodoBase* GetPrimero() const
	{
		return Primero;
	}

private:
	NodoBase* Primero;
};