#ifndef PARTIDODAO_H_
#define PARTIDODAO_H_
#include <iostream>
#include <string>
#include "ColaPartidos.h"
#include "myconnection.h"
#include "Partido.h"

using namespace std;

class PartidoDao 
{
	public:
		PartidoDao();
		static ColaPartidos leerPartidos();
		static void agregarPartido(string);
		static void eliminarPartido(string);
		static void cambiarNombre(string,string);
		static int checkVoto(string, int);
	private:
		
};

#endif
