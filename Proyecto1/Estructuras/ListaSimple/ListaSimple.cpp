#include "ListaSimple.h"


ListaSimple::~ListaSimple()
{
   NodoBase* aux;
   
   while(Primero) {
      aux = Primero;
      Primero = Primero->Siguiente;
      delete aux;
   }
   Primero= NULL;
}

int ListaSimple::largoLista(){
    int cont=0;

    NodoBase* aux= Primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->Siguiente;
        cont++;
    }
    return cont;
    }
    
}

void ListaSimple::InsertarInicio(NodoBase* Nodo)
{
	if (ListaVacia())
	{
		Primero = Nodo;
	}
	else
	{
		NodoBase* Nuevo = Nodo;
		Nuevo->Siguiente = Primero;
		Primero = Nuevo;
	}
}

void ListaSimple::InsertarFinal(NodoBase* Nodo)
{
	if (ListaVacia())
		Primero = Nodo;
	else
	{
		NodoBase* Aux = Primero;
		while (Aux->Siguiente != NULL)
			Aux = Aux->Siguiente;
		NodoBase* Nuevo = Nodo;
		Aux->Siguiente = Nuevo;
	}
}


void ListaSimple::InsertarPos(int v,int pos)
{
	return;
	/*
	if (ListaVacia())
		Primero = new nodo(v);
	else
	{
		if (pos <= 1)
		{
			//OPcion1
			NodoBase* nuevo = new nodo(v);
			nuevo->siguiente = Primero;
			Primero = nuevo;
			//OPcion 2
			//InsertarInicio(v);
		}
		else
		{
			nodo* aux = Primero;
			int i = 2;
			while ((i != pos) && (aux->siguiente != NULL))
			{
				i++;
				aux = aux->siguiente;
			}
			NodoBase* nuevo = new nodo(v);
			nuevo->siguiente = aux->siguiente;
			aux->siguiente = nuevo;
		}
	}
	*/
}
      
void ListaSimple::BorrarFinal()
{
	return;
	/*
	if (ListaVacia())
	{
		cout << "No hay elementos en la lista:" << endl;
	}
	else
	{
		if (Primero->siguiente == NULL)
		{
			NodoBase* temp = Primero;
			Primero = NULL;
			delete temp;;
		}
		else
		{
			NodoBase* aux = Primero;
			while (aux->siguiente->siguiente != NULL)
			{
				aux = aux->siguiente;
			}

			NodoBase* temp = aux->siguiente;
			aux->siguiente = NULL;


			delete temp;
		}
	}
	*/
}

void ListaSimple::BorrarInicio()
{
	return;
	/*
	if (ListaVacia())
	{
		cout << "No hay elementos en la lista:" << endl;
	}
	else
	{
		if (Primero->siguiente == NULL)
		{
			NodoBase* temp = Primero;
			Primero = NULL;
			delete temp;
		}
		else
		{
			NodoBase* aux = Primero;
			Primero = Primero->siguiente;
			delete aux;
		}
	}
	*/
}


void ListaSimple::BorrarPosicion(int pos)
{
	if (ListaVacia())
	{
		cout << "Lista vacia" << endl;
	}
	else
	{
		if ((pos > largoLista()) || (pos < 0))
		{
			cout << "Error en posicion" << endl;
		}
		else
		{
			if (pos == 1)
			{
				NodoBase* Temp = Primero;
				Primero = Primero->Siguiente;
				delete Temp;
			}
			else
			{
				int cont = 2;
				NodoBase* Aux = Primero;
				while (cont < pos)
				{
					Aux = Aux->Siguiente;
					cont++;
				}
				NodoBase* temp = Aux->Siguiente;
				Aux->Siguiente = Aux->Siguiente->Siguiente;
				delete temp;
			}
		}
	}
}

NodoBase* ListaSimple::EncontrarPorPredicado(function<bool(NodoBase*)> func)
{
	NodoBase* Aux = Primero;

	while (Aux)
	{
		if (func(Aux))
		{
			return Aux;
		}
		Aux = Aux->Siguiente;
	}
	return nullptr;
}

int ListaSimple::ConseguirPosicion(NodoBase* Nodo)
{
	int Contador = 1;

	NodoBase* Aux = Primero;
	while (Aux)
	{
		if (Nodo == Aux)
		{
			return Contador;
		}
		Contador++;
		Aux = Aux->Siguiente;
	}
	return -1;
}


void ListaSimple::Mostrar()
{
	NodoBase* Aux;
	if (Primero == nullptr)
		cout << "No hay elementos AQUI";
	else
	{
		Aux = Primero;
		while (Aux)
		{
			Aux->Mostrar();
			Aux = Aux->Siguiente;
		}
		cout << endl;
	}
}

void ListaSimple::IterarNodos(function<void(NodoBase*)> func)
{
	NodoBase* Aux = Primero;
	while (Aux)
	{
		func(Aux);
		Aux = Aux->Siguiente;
	}
}