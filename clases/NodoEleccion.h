/*
 * NodoEleccion.h
 *
 *  Created on: 23 feb. 2018
 *      Author: franco
 */

#ifndef CLASES_NODOELECCION_H_
#define CLASES_NODOELECCION_H_
#include <iostream>
#include <string>
#include "Eleccion.h"
using namespace std;
class NodoEleccion {
public:
	NodoEleccion();
	NodoEleccion(Eleccion);
	void setDato(Eleccion);
	void setAnt(NodoEleccion*);
	Eleccion getDato();
	NodoEleccion* getAnt();
private:
	Eleccion dato;
	NodoEleccion* ant;
};

#endif /* CLASES_NODOELECCION_H_ */
