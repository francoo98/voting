/*
 * TipoEleccionesController.h
 *
 *  Created on: 22 feb. 2018
 *      Author: franco
 */

#ifndef CLASES_TIPOELECCIONESCONTROLLER_H_
#define CLASES_TIPOELECCIONESCONTROLLER_H_
#include "TipoEleccionesViewer.h"
#include <iostream>
using namespace std;
class TipoEleccionesController {
public:
	TipoEleccionesController();
	static void listarElecciones();
	static void panel();
	static void agregar();
	static void modificar_eliminar();
};

#endif /* CLASES_TIPOELECCIONESCONTROLLER_H_ */
