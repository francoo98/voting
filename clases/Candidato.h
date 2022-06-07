/*
 * Candidato.h
 *
 *  Created on: 24 feb. 2018
 *      Author: franco
 */

#ifndef CLASES_CANDIDATO_H_
#define CLASES_CANDIDATO_H_
#include <iostream>
#include <string>
using namespace std;
class Candidato {
public:
	Candidato();
	void setNombre(string);
	void setApellido(string);
	void setPartido(string);
	void setDni(int);
	void setVotos(int);
	void setEleccion(string);
	string getNombre();
	string getApellido();
	string getPartido();
	int getVotos();
	string getEleccion();
	int getDni();
private:
	string nombre;
	string apellido;
	string partido;
	string eleccion;
	int dni;
	int votos;
};

#endif /* CLASES_CANDIDATO_H_ */
