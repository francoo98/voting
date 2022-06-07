/*
 * TipoElecciones.cpp
 *
 *  Created on: 23 feb. 2018
 *      Author: franco
 */

#include "TipoElecciones.h"

TipoElecciones::TipoElecciones() {} // @suppress("Class members should be properly initialized")

void TipoElecciones::setNombre(string s)
{
	nombre = s;
}
void TipoElecciones::setId(int i)
{
	id = i;
}
string TipoElecciones::getNombre()
{
	return nombre;
}
int TipoElecciones::getId()
{
	return id;
}

