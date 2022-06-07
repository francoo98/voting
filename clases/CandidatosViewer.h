/*
 * CandidatosViewer.h
 *
 *  Created on: 24 feb. 2018
 *      Author: franco
 */

#ifndef CLASES_CANDIDATOSVIEWER_H_
#define CLASES_CANDIDATOSVIEWER_H_
#include <iostream>
#include <string>
#include "getpost.h"
#include "ColaCandidatos.h"
#include "CandidatosDao.h"
#include "PersonaDao.h"
#include "EleccionesDao.h"
#include "ColaElecciones.h"
using namespace std;
class CandidatosViewer {
public:
	CandidatosViewer();
	static void candidatosHtml();
	static void panelHtml();
};

#endif /* CLASES_CANDIDATOSVIEWER_H_ */
