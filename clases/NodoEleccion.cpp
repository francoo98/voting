/*
 * NodoEleccion.cpp
 *
 *  Created on: 23 feb. 2018
 *      Author: franco
 */

#include "NodoEleccion.h"

NodoEleccion::NodoEleccion() {
	ant = NULL;
}

NodoEleccion::NodoEleccion(Eleccion dato)
{
	this->dato = dato;
	ant = NULL;
}

Eleccion NodoEleccion::getDato(){
	return dato;
}

void NodoEleccion::setDato(Eleccion _dato){
	dato = _dato;
}

NodoEleccion* NodoEleccion::getAnt(){
	return ant;
}

void NodoEleccion::setAnt(NodoEleccion* a){
	ant= a;
}
