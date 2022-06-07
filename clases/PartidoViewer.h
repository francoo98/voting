#ifndef PARTIDOVIEWER_H_
#define PARTIDOVIEWER_H_
#include <iostream>
#include <string>
#include "CandidatosController.h"
#include "PartidoDao.h"
#include "PersonaDao.h"
#include "ColaPartidos.h"
#include "getpost.h"
using namespace std;

class PartidoViewer 
{
	public:
		PartidoViewer();
		static void partidosHtml();
		static void panelHtml();
		static void agregarPartidoHtml();
		static void modificarEliminarPartidoHtml();
		static void modificarHtml();
	private:
};

#endif
