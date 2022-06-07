/*
 * ColaElecciones.cpp
 *
 *  Created on: 23 feb. 2018
 *      Author: franco
 */

#include "ColaElecciones.h"

ColaElecciones::ColaElecciones()
{
	first = NULL;
	last = NULL;
}

void ColaElecciones::push(Eleccion dato)
{
	NodoEleccion* nodo = new NodoEleccion();
	nodo->setDato(dato);
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

void ColaElecciones::pop()
{
	first = first->getAnt();
}

NodoEleccion* ColaElecciones::getFirst()
{
	return first;
}

