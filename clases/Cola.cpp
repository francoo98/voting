/*
 * Cola.cpp
 *
 *  Created on: 12 dic. 2017
 *      Author: franco
 */

#include "Cola.h"

Cola::Cola()
{
	first = NULL;
	last = NULL;
}

void Cola::push(string dato)
{
	Nodo* nodo = new Nodo();
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

void Cola::pop()
{
	first = first->getAnt();
}

Nodo* Cola::getFirst()
{
	return first;
}
