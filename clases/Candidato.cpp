/*
 * Candidato.cpp
 *
 *  Created on: 24 feb. 2018
 *      Author: franco
 */

#include "Candidato.h"

Candidato::Candidato() { // @suppress("Class members should be properly initialized")
	// TODO Auto-generated constructor stub

}
void Candidato::setNombre(string s)
{
	nombre = s;
}
void Candidato::setApellido(string s)
{
	apellido = s;
}
void Candidato::setPartido(string s)
{
	partido = s;
}
void Candidato::setDni(int i)
{
	dni = i;
}
void Candidato::setVotos(int i)
{
	votos = i;
}
void Candidato::setEleccion(string s)
{
	eleccion = s;
}
string Candidato::getNombre()
{
	return nombre;
}
string Candidato::getApellido()
{
	return apellido;
}
string Candidato::getPartido()
{
	return partido;
}
int Candidato::getDni()
{
	return dni;
}
int Candidato::getVotos()
{
	return votos;
}
string Candidato::getEleccion()
{
	return eleccion;
}
