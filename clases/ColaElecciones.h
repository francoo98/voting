/*
 * ColaElecciones.h
 *
 *  Created on: 23 feb. 2018
 *      Author: franco
 */

#ifndef CLASES_COLAELECCIONES_H_
#define CLASES_COLAELECCIONES_H_
#include <iostream>
#include <string>
#include "NodoEleccion.h"
class ColaElecciones {
public:
	ColaElecciones();
	void push(Eleccion);
	void pop();
	NodoEleccion* getFirst();
private:
	NodoEleccion* first;
	NodoEleccion* last;
};

#endif /* CLASES_COLAELECCIONES_H_ */
