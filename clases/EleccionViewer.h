/*
 * EleccionViewer.h
 *
 *  Created on: 23 feb. 2018
 *      Author: franco
 */

#ifndef CLASES_ELECCIONVIEWER_H_
#define CLASES_ELECCIONVIEWER_H_
#include <iostream>
#include <string>
#include "getpost.h"
#include "EleccionesDao.h"
#include "ColaElecciones.h"
#include "PartidoController.h"
#include "CandidatosController.h"
using namespace std;
class EleccionViewer {
public:
	EleccionViewer();
	static void listarEleccionesHtml();
	static void panelHtml();
	static void estadisticasHtml();
	static void estadisticas();
};

#endif /* CLASES_ELECCIONVIEWER_H_ */
