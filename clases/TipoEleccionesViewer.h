/*
 * tipoEleccionesViewer.h
 *
 *  Created on: 22 feb. 2018
 *      Author: franco
 */

#ifndef CLASES_TIPOELECCIONESVIEWER_H_
#define CLASES_TIPOELECCIONESVIEWER_H_
#include <iostream>
#include "getpost.h"
#include "TipoEleccionesDao.h"
#include "EleccionController.h"
#include "TipoEleccionesController.h"
#include "Cola.h"
using namespace std;
class TipoEleccionesViewer {
public:
	TipoEleccionesViewer();
	static void listarTipoEleccionesHtml();
	static void panelHtml();
	static void agregarTipoEleccionHtml();
	static void modificar_eliminarHtml();
	static void modificarHtml();
};

#endif /* CLASES_TIPOELECCIONESVIEWER_H_ */
