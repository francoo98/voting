/*
 * NodoTipoElecciones.h
 *
 *  Created on: 23 feb. 2018
 *      Author: franco
 */

#ifndef CLASES_NODOTIPOELECCIONES_H_
#define CLASES_NODOTIPOELECCIONES_H_
#include <iostream>
#include <string>
#include "TipoElecciones.h"
using namespace std;
class NodoTipoElecciones {
public:
	NodoTipoElecciones();
	NodoTipoElecciones(TipoElecciones);
	TipoElecciones getValor();
	void setValor(TipoElecciones);
	NodoTipoElecciones* getAnt();
	void setAnt(NodoTipoElecciones*);
private:
	TipoElecciones dato;
	NodoTipoElecciones* ant;
};

#endif /* CLASES_NODOTIPOELECCIONES_H_ */
