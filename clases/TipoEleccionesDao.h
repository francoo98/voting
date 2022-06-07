/*
 * TipoEleccionesDao.h
 *
 *  Created on: 22 feb. 2018
 *      Author: franco
 */

#ifndef CLASES_TIPOELECCIONESDAO_H_
#define CLASES_TIPOELECCIONESDAO_H_
#include <iostream>
#include <string>
#include "myconnection.h"
#include "TipoElecciones.h"
#include "ColaTipoElecciones.h"
using namespace std;
class TipoEleccionesDao {
public:
	TipoEleccionesDao();
	static ColaTipoElecciones leerTipoElecciones();
	static void agregarTipoEleccion(string);
	static void eliminarTipoEleccion(string);
	static void cambiarNombre(string, string);
};

#endif /* CLASES_TIPOELECCIONESDAO_H_ */
