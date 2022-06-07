/*
 * ColaTipoElecciones.h
 *
 *  Created on: 23 feb. 2018
 *      Author: franco
 */

#ifndef CLASES_COLATIPOELECCIONES_H_
#define CLASES_COLATIPOELECCIONES_H_
#include <iostream>
#include <string>
#include "TipoElecciones.h"
#include "NodoTipoElecciones.h"
class ColaTipoElecciones {
public:
	ColaTipoElecciones();
	void push(TipoElecciones);
	void pop();
	NodoTipoElecciones* getFirst();
private:
	NodoTipoElecciones* first;
	NodoTipoElecciones* last;
};

#endif /* CLASES_COLATIPOELECCIONES_H_ */
