/*
 * Cola.h
 *
 *  Created on: 12 dic. 2017
 *      Author: franco
 */

#ifndef COLA_H_
#define COLA_H_
#include <string>
#include <iostream>
#include "Nodo.h"

using namespace std;

class Cola {
public:
	Cola();
	void push(string);
	void pop();
	Nodo* getFirst();
private:
	Nodo* first;
	Nodo* last;
};
#endif /* COLA_H_ */
