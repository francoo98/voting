#include "Partido.h"

Partido::Partido()
{
	nombre = "";
	id = 0;
}

void Partido::setNombre(string s)
{
	nombre = s;
}

void Partido::setId(int a)
{
	id = a;
}

string Partido::getNombre()
{
	return nombre;
}

int Partido::getId()
{
	return id;
}
