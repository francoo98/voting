/*
 * CandidatosController.cpp
 *
 *  Created on: 24 feb. 2018
 *      Author: franco
 */

#include "CandidatosController.h"

CandidatosController::CandidatosController() {
	// TODO Auto-generated constructor stub

}

void CandidatosController::candidatos()
{
	CandidatosViewer::candidatosHtml();
}
void CandidatosController::panel()
{
	CandidatosViewer::panelHtml();
}

