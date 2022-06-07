/*
 * EleccionViewer.cpp
 *
 *  Created on: 23 feb. 2018
 *      Author: franco
 */

#include "EleccionViewer.h"

EleccionViewer::EleccionViewer() {
	// TODO Auto-generated constructor stub
}

void EleccionViewer::listarEleccionesHtml()
{
	map<string, string> Get;
	initializeGet(Get);
	if (Get.find("eleccionid") == Get.end())
	{
		ColaElecciones c = EleccionesDao::leerElecciones(Get["tipo"]);
		cout << "<form method='get'>" << endl;
		while (c.getFirst())
		{
			cout << "	<div id='cuadro_partido' class='container'>" << endl;
			cout << "		<div class='row'>" << endl;
			cout << "			<div class='col-md-12'>" << endl;
			cout << "				<h4>" << c.getFirst()->getDato().getNombre() << "</h3>" << endl;
			cout << "				<button class='btn btn-primary' name='eleccionid' value='" << c.getFirst()->getDato().getId_eleccion() << "' action='document.location.reload()'>Votar</button>" << endl;
			cout << "			</div>" << endl;
			cout << "		</div>" << endl;
			cout << "	</div>" << endl;
			c.pop();
		}
		cout << "<input name='tipo' type='hidden' value='" << Get["tipo"] << "'</input>" << endl;
		cout << "<input name='dni' type='hidden' value='" << Get["dni"] << "'</input>" << endl;
		cout << "</form>" << endl;
		cout << "</body>" << endl;
		cout << "</html>" << endl;
	}
	else
	{
		CandidatosController::candidatos();
	}
}

void EleccionViewer::panelHtml()
{
	map<string,string> Get;
	initializeGet(Get);
	//EleccionesDao ed;
	if(Get["op4"] == "1")
		EleccionesDao::cambiarNombreEleccion(Get["nombre"], Get["eleccionid"]);
	if(Get["op4"] == "2")
		EleccionesDao::eliminarEleccion(Get["eleccionid"]);
	if(Get["op4"] == "3")
		EleccionesDao::agregarEleccion(Get["nombre_nueva"], Get["eleccion"]);
	if(Get["op4"] == "4")
		estadisticas();
	ColaElecciones c;
	c = EleccionesDao::leerElecciones(Get["eleccion"]);
	while(c.getFirst())
	{
		cout << "<div class='row'>" << endl;
		cout << "<div class='col-md-12'>" << endl;
		cout << "<form method='get'>" << endl;
		cout << "<input type='hidden' name='dni' value='1'>" << endl;
		cout << "<input type='hidden' name='op' value='1'>" << endl;
		cout << "<input type='hidden' name='op2' value='2'>" << endl;
		cout << "<input type='hidden' name='op3' value='1'>" << endl;
		cout << "<input type='hidden' name='eleccion' value='" << Get["eleccion"] << "'>" << endl; //eleccion = id_tipo
		cout << "<input type='hidden' name='eleccionid' value='" << c.getFirst()->getDato().getId_eleccion() << "'</input>" << endl;
		cout << "<input type='text' name='nombre' placeholder='" << c.getFirst()->getDato().getNombre() << "'>" << endl;
		cout << "<button class='btn btn-success btn-sm' name='op4' value='1' onClick='document.location.reload()'>Cambiar nombre</button> <button class='btn btn-danger btn-sm' name='op4' value='2' onClick='document.location.reload()'>Eliminar</button> <button class='btn btn-info btn-sm' name='op4' value='4' onClick='document.location.reload()'>Estadisticas</button>" << endl;
		cout << "</form>" << endl;
		cout << "</div>" << endl;
		cout << "</div>" << endl;
		cout << "<br>" << endl;
		c.pop();
	}
	cout << "<form method='get'>" << endl;
	cout << "<input type='text' name='nombre_nueva'>" << endl;
	cout << "<button class='btn btn-success btn-sm' name='op4' value='3'>Agregar eleccion</button>" << endl;
	cout << "<br>" << endl; cout << "<br>" << endl; cout << "<br>" << endl;
	cout << "<input type='hidden' name='dni' value='1'>" << endl;
	cout << "<input type='hidden' name='op' value='1'>" << endl;
	cout << "<input type='hidden' name='op2' value='2'>" << endl;
	cout << "<input type='hidden' name='op3' value='1'>" << endl;
	cout << "<input type='hidden' name='eleccion' value='" << Get["eleccion"] << "'>" << endl; //eleccion = id_tipo
	cout << "<input type='hidden' name='eleccionid' value='" << c.getFirst()->getDato().getId_eleccion() << "'</input>" << endl;
	cout << "</form>" << endl;
}

void EleccionViewer::estadisticas()
{
	map<string,string> Get;
	initializeGet(Get);
	//CandidatosDao* cd = new CandidatosDao();
	ColaCandidatos c;
	c = CandidatosDao::leerCandidatos(Get["eleccionid"]);
	int total = 0;
	while(c.getFirst())
	{
		total = total + c.getFirst()->getValor().getVotos();
		c.pop();
	}
	ColaCandidatos d = CandidatosDao::leerCandidatos(Get["eleccionid"]);
	float a = 0;
	while(d.getFirst())
	{
		a = d.getFirst()->getValor().getVotos();
		cout << d.getFirst()->getValor().getPartido() << ": %" << a/total*100 << endl;
		d.pop();
	}
}

