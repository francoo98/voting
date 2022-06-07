/*
 * Nodo.cpp
 *
 *  Created on: 12 dic. 2017
 *      Author: franco
 */

#include "NodoPartido.h"

NodoPartido::NodoPartido(){
	nAnt = NULL;
}

NodoPartido::NodoPartido(Partido _dato){
	dato = _dato;
	nAnt = NULL;
}

Partido NodoPartido::getValor(){
	return dato;
}

void NodoPartido::setValor(Partido _dato){
	dato = _dato;
}

NodoPartido* NodoPartido::getAnt(){
	return nAnt;
}

void NodoPartido::setAnt(NodoPartido* ant){
	nAnt = ant;
}
