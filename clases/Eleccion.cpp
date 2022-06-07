/*
 * Eleccion.cpp
 *
 *  Created on: 23 feb. 2018
 *      Author: franco
 */

#include "Eleccion.h"

Eleccion::Eleccion() { // @suppress("Class members should be properly initialized")	// TODO Auto-generated constructor stub
}
void Eleccion::setNombre(string s)
{
	nombre = s;
}

void Eleccion::setId_eleccion(int i)
{
	id_eleccion = i;
}
string Eleccion::getNombre()
{
	return nombre;
}
int Eleccion::getId_eleccion()
{
	return id_eleccion;
}


