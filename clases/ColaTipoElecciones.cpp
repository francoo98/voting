/*
 * ColaTipoElecciones.cpp
 *
 *  Created on: 23 feb. 2018
 *      Author: franco
 */

#include "ColaTipoElecciones.h"

ColaTipoElecciones::ColaTipoElecciones()
{
	first = NULL;
	last = NULL;
}

void ColaTipoElecciones::push(TipoElecciones dato)
{
	NodoTipoElecciones* nodo = new NodoTipoElecciones();
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
void ColaTipoElecciones::pop()
{
	first = first->getAnt();
}
NodoTipoElecciones* ColaTipoElecciones::getFirst()
{
	return first;
}
