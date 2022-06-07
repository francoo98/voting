/*
 * TipoEleccionesController.cpp
 *
 *  Created on: 22 feb. 2018
 *      Author: franco
 */

#include "TipoEleccionesController.h"
#include "TipoEleccionesViewer.h"

TipoEleccionesController::TipoEleccionesController() {
	// TODO Auto-generated constructor stub

}

void TipoEleccionesController::listarElecciones()
{
	TipoEleccionesViewer::listarTipoEleccionesHtml();
}

void TipoEleccionesController::panel()
{
	TipoEleccionesViewer::panelHtml();
}
void TipoEleccionesController::agregar()
{
	TipoEleccionesViewer::agregarTipoEleccionHtml();
}
void TipoEleccionesController::modificar_eliminar()
{
	TipoEleccionesViewer::modificar_eliminarHtml();
}

