/*
 * Eleccion.h
 *
 *  Created on: 23 feb. 2018
 *      Author: franco
 */

#ifndef ELECCION_H_
#define ELECCION_H_
#include <iostream>
#include <string>
using namespace std;
class Eleccion {
public:
	Eleccion();
	void setNombre(string);
	void setId_eleccion(int);
	string getNombre();
	int getId_eleccion();
private:
	string nombre;
	int id_eleccion;
};

#endif /* ELECCION_H_ */
