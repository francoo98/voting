/*
 * Nodo.h
 *
 *  Created on: 12 dic. 2017
 *      Author: franco
 */

#ifndef NODOPARTIDO_H_
#define NODOPARTIDO_H_

#include <string>
#include <iostream>
#include "Partido.h"

using namespace std;

class NodoPartido {
public:
	NodoPartido();
	NodoPartido(Partido);
	Partido getValor();
	void setValor(Partido);
	NodoPartido* getAnt();
	void setAnt(NodoPartido*);
private:
	Partido dato;
	NodoPartido* nAnt;
};

#endif /* NODO_H_ */
