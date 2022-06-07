/*
 * Nodo.cpp
 *
 *  Created on: 12 dic. 2017
 *      Author: franco
 */

#include "Nodo.h"

Nodo::Nodo(){
	dato = dato.empty();
	nAnt = NULL;
}

Nodo::Nodo(string _dato){
	dato = _dato;
	nAnt = NULL;
}

string Nodo::getValor(){
	return dato;
}

void Nodo::setValor(string _dato){
	dato = _dato;
}

Nodo* Nodo::getAnt(){
	return nAnt;
}

void Nodo::setAnt(Nodo* ant){
	nAnt = ant;
}
