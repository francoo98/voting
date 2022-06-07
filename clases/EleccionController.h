/*
 * EleccionController.h
 *
 *  Created on: 23 feb. 2018
 *      Author: franco
 */

#ifndef CLASES_ELECCIONCONTROLLER_H_
#define CLASES_ELECCIONCONTROLLER_H_
#include "EleccionViewer.h"
#include <string>
class EleccionController {
public:
	EleccionController();
	static void listarElecciones();
	static void panel();
};

#endif /* CLASES_ELECCIONCONTROLLER_H_ */
