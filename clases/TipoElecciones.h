/*
 * TipoElecciones.h
 *
 *  Created on: 23 feb. 2018
 *      Author: franco
 */

#ifndef CLASES_TIPOELECCIONES_H_
#define CLASES_TIPOELECCIONES_H_
#include <iostream>
#include <string>
using namespace std;
class TipoElecciones {
public:
	TipoElecciones();
	void setNombre(string);
	void setId(int);
	string getNombre();
	int getId();
private:
	string nombre;
	int id;
};

#endif /* CLASES_TIPOELECCIONES_H_ */
