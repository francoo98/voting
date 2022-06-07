/*
 * EleccionController.cpp
 *
 *  Created on: 23 feb. 2018
 *      Author: franco
 */

#include "EleccionController.h"

EleccionController::EleccionController() {

}
void EleccionController::listarElecciones()
{
	EleccionViewer::listarEleccionesHtml();
}

void EleccionController::panel()
{
	EleccionViewer::panelHtml();
}
