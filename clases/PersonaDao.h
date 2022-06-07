#ifndef PERSONADAO_H_
#define PERSONADAO_H_
#include <iostream>
#include <string>
#include "Persona.h"
#include "myconnection.h"

using namespace std;

class PersonaDao 
{
	public:
		PersonaDao();
		static Persona leerDatos(string);
		static int checkVoto(string, string);
		static void votar(string dni, string eleccion);
	private:
};

#endif
