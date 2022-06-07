/*
 * NodoTipoElecciones.cpp
 *
 *  Created on: 23 feb. 2018
 *      Author: franco
 */

#include "NodoTipoElecciones.h"

NodoTipoElecciones::NodoTipoElecciones() {
	ant = NULL;
}

NodoTipoElecciones::NodoTipoElecciones(TipoElecciones dato)
{
	this->dato = dato;
	ant = NULL;
}
TipoElecciones NodoTipoElecciones::getValor()
{
	return dato;
}
void NodoTipoElecciones::setValor(TipoElecciones s)
{
	dato = s;
}
NodoTipoElecciones* NodoTipoElecciones::getAnt()
{
	return ant;
}
void NodoTipoElecciones::setAnt(NodoTipoElecciones* s)
{
	ant = s;
}
