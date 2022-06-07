/*
 * Cola.cpp
 *
 *  Created on: 12 dic. 2017
 *      Author: franco
 */

#include "ColaPartidos.h"

ColaPartidos::ColaPartidos()
{
	first = NULL;
	last = NULL;
}

void ColaPartidos::push(Partido dato)
{
	NodoPartido* nodo = new NodoPartido();
	nodo->setValor(dato);
	if(first == NULL)
	{
		first = nodo;
		last = nodo;
		return;
	}
	if(first != NULL)
	{
		last->setAnt(nodo);
		last = nodo;
		return;
	}
}

void ColaPartidos::pop()
{
	first = first->getAnt();
}

/*void ColaPartidos::mostrar()
{
	NodoPartido* aux = first;
	while(aux != NULL)
	{
		cout << aux->getValor() << endl;
		aux = aux->getAnt();
	}
}*/

NodoPartido* ColaPartidos::getFirst()
{
	return first;
}
