/*
 * Cola.h
 *
 *  Created on: 12 dic. 2017
 *      Author: franco
 */

#ifndef COLAPARTIDOS_H_
#define COLAPARTIDOS_H_
#include <string>
#include <iostream>
#include "NodoPartido.h"
#include "Partido.h"

using namespace std;

class ColaPartidos {
public:
	ColaPartidos();
	void push(Partido);
	void pop();
	//void mostrar();
	NodoPartido* getFirst();
private:
	NodoPartido* first;
	NodoPartido* last;
};
#endif
