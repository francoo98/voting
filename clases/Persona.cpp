#include "Persona.h"

Persona::Persona(){}

void Persona::setDni(int _dni)
{
	dni = _dni;
}

void Persona::setNombre(string _nombre)
{
	nombre = _nombre;
}

void Persona::setApellido(string _a)
{
	apellido = _a;
}

void Persona::setFecha(string a)
{
	fecha = a;
}

void Persona::setDireccion(string a)
{
	direccion = a;
}

void Persona::setLugar(string a)
{
	lugar = a;
}

void Persona::setVoto(int a)
{
	voto = a;
}

void Persona::setId(int a)
{
	id = a;
}

int Persona::getDni()
{
	return dni;
}

string Persona::getNombre()
{
	return nombre;
}

string Persona::getApellido()
{
	return apellido;
}

string Persona::getFecha()
{
	return fecha;
}

string Persona::getDireccion()
{
	return direccion;
}

string Persona::getLugar()
{
	return lugar;
}

int Persona::getVoto()
{
	return voto;
}

int Persona::getId()
{
	return id;
}
