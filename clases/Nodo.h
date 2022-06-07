/*
 * Nodo.h
 *
 *  Created on: 12 dic. 2017
 *      Author: franco
 */

#ifndef NODO_H_
#define NODO_H_

#include <string>
#include <iostream>

using namespace std;

class Nodo {
public:
	Nodo();
	Nodo(string);
	string getValor();
	void setValor(string);
	Nodo* getAnt();
	void setAnt(Nodo*);
private:
	string dato;
	Nodo* nAnt;
};

#endif /* NODO_H_ */
