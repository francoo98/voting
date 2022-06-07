#ifndef PERSONAVIEWER_H_
#define PERSONAVIEWER_H_
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Persona.h"
#include "PartidoController.h"
#include "PersonaDao.h"
#include "PartidoViewer.h"
#include "getpost.h"
#include "TipoEleccionesController.h"
using namespace std;

class PersonaViewer 
{
	public:
		PersonaViewer();
		static void ingresarDniHtml();
		static void datosHtml(string);
		static void adminHtml();
		static void adminTiposDeElecciones();
	private:
};

#endif
