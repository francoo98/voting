/*
 * ColaCandidatos.cpp
 *
 *  Created on: 24 feb. 2018
 *      Author: franco
 */

#include "ColaCandidatos.h"

ColaCandidatos::ColaCandidatos()
{
	first = NULL;
	last = NULL;
}

void ColaCandidatos::push(Candidato dato)
{
	NodoCandidato* nodo = new NodoCandidato();
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

void ColaCandidatos::pop()
{
	first = first->getAnt();
}

NodoCandidato* ColaCandidatos::getFirst()
{
	return first;
}


