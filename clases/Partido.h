#ifndef PARTIDO_H_
#define PARTIDO_H_
#include <iostream>
#include <string>
#include "Candidato.h"
using namespace std;

class Partido 
{
	public:
		Partido();
		void setNombre(string);
		void setId(int);
		string getNombre();
		int getId();
		
	private:
		string nombre;
		int id;
};

#endif
