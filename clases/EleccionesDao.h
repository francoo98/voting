/*
 * EleccionesDao.h
 *
 *  Created on: 24 feb. 2018
 *      Author: franco
 */

#ifndef CLASES_ELECCIONESDAO_H_
#define CLASES_ELECCIONESDAO_H_
#include <iostream>
#include <string>
#include "Eleccion.h"
#include "ColaElecciones.h"
#include "myconnection.h"
class EleccionesDao {
public:
	EleccionesDao();
	static ColaElecciones leerElecciones(string);
	static ColaElecciones leerEleccionesT();
	static void cambiarNombreEleccion(string, string);
	static void eliminarEleccion(string);
	static void agregarEleccion(string, string);
};

#endif /* CLASES_ELECCIONESDAO_H_ */
