/*
 * CandidatosViewer.cpp
 *
 *  Created on: 24 feb. 2018
 *      Author: franco
 */

#include "CandidatosViewer.h"

CandidatosViewer::CandidatosViewer() {
	// TODO Auto-generated constructor stub

}

void CandidatosViewer::candidatosHtml()
{
	map<string, string> Get;
	initializeGet(Get);
	ColaCandidatos c;
	c = CandidatosDao::leerCandidatos(Get["eleccionid"]);
	if (Get.find("candidatodni") == Get.end())
	{
		cout << "<form method='get'>" << endl;
		while (c.getFirst())
		{
			cout << "	<div id='cuadro_partido' class='container'>" << endl;
			cout << "		<div class='row'>" << endl;
			cout << "			<div class='col-md-12'>" << endl;
			cout << "				<h4>" << c.getFirst()->getValor().getPartido() << "</h4>" << endl;
			cout << "				<h5>" /*<< c->getFirst()->getValor().getCandidatura() <<": " */<< c.getFirst()->getValor().getNombre() << " " << c.getFirst()->getValor().getApellido() << "</h5>" << endl;
			cout << "				<button class='btn btn-primary' name='candidatodni' value='" << c.getFirst()->getValor().getDni() << "' action='document.location.reload()'>Votar</button>" << endl;
			cout << "			</div>" << endl;
			cout << "		</div>" << endl;
			cout << "	</div>" << endl;
			c.pop();
		}
		cout << "<input name='eleccionid' type='hidden' value='" << Get["eleccionid"] << "'</input>" << endl;
		cout << "<input name='dni' type='hidden' value='" << Get["dni"] << "'</input>" << endl;
		cout << "<input name='tipo' type='hidden' value='" << Get["tipo"] << "'</input>" << endl;
		cout << "</form>" << endl;
		cout << "</body>" << endl;
		cout << "</html>" << endl;
	}
	else
	{
		if(PersonaDao::checkVoto(Get["eleccionid"], Get["dni"]) == 0)
		{
			CandidatosDao::votar(Get["candidatodni"]);
			PersonaDao::votar(Get["dni"], Get["eleccionid"]);
			cout << "<h3>Gracias por votar</h3>" << endl;
		}
		else
		{
			cout << "<h3>Ya participo en la votacion</h3>" << endl;
		}

	}
}

void CandidatosViewer::panelHtml()
{
	map<string,string> Get;
	initializeGet(Get);
	if(Get.find("op4") != Get.end())
	{
		if(Get["op4"] == "1")
			CandidatosDao::cambiarDatos(Get["candidatodni"], Get["nombre"], Get["apellido"]);
		if(Get["op4"] == "2")
			CandidatosDao::eliminarCandidato(Get["candidatodni"]);
		if(Get["op4"] == "3")
			CandidatosDao::agregarCandidato(Get["dniNuevo"], Get["eleccionid"], Get["partidoid"]);
	}
	ColaCandidatos c = CandidatosDao::leerCandidatosPanel(Get["partidoid"]);
	cout << "<div class='container' style='text-align:center'>" << endl;
	cout << "<h5><b>Candidatos: </b></h5>" << endl;
	while(c.getFirst())
	{
		cout << "<div class='row'>" << endl;
		cout << "<div class='col-md-12'>" << endl;
		cout << "<form method='get'>" << endl;
		cout << "<input type='hidden' name='dni' value='1'>" << endl;
		cout << "<input type='hidden' name='op' value='2'>" << endl;
		cout << "<input type='hidden' name='op2' value='2'>" << endl;
		cout << "<input type='hidden' name='op3' value='1'>" << endl;
		cout << "<input type='hidden' name='partidoid' value='" << Get["partidoid"] << "'>" << endl;
		cout << "<input type='hidden' name='candidatodni' value='" << c.getFirst()->getValor().getDni() << "'</input>" << endl;
		cout << c.getFirst()->getValor().getEleccion() << endl;
		cout << "<input type='text' name='nombre' placeholder='" << c.getFirst()->getValor().getNombre() << "'>" << endl;
		cout << "<input type='text' name='apellido' placeholder='" << c.getFirst()->getValor().getApellido() << "'>" << endl;
		cout << "<button class='btn btn-success btn-sm' name='op4' value='1' onClick='document.location.reload()'>Modificar</button> <button class='btn btn-danger btn-sm' name='op4' value='2' onClick='document.location.reload()'>Eliminar</button>" << endl;
		cout << "</form>" << endl;
		cout << "</div>" << endl;
		cout << "</div>" << endl;
		cout << "<br>" << endl;
		c.pop();
	}
	cout << "Agregar candidato:" << endl;
	cout << "<form method='get'>" << endl;
	cout << "<input type='number' name='dniNuevo' placeholder='Numero de Documento'>" << endl;
	ColaElecciones d = EleccionesDao::leerEleccionesT();
	cout << "<select name='eleccionid'>" << endl;
	while(d.getFirst())
	{
		cout << "<option value='" << d.getFirst()->getDato().getId_eleccion() << "'>" << d.getFirst()->getDato().getNombre() << "</option>" << endl;
		d.pop();
	}
	cout << "</select>" << endl;
	cout << "<button class='btn btn-success btn-sm' name='op4' value='3' onClick='document.location.reload()'>Agregar</button>" << endl;
	cout << "<input type='hidden' name='dni' value='1'>" << endl;
	cout << "<input type='hidden' name='op' value='2'>" << endl;
	cout << "<input type='hidden' name='op2' value='2'>" << endl;
	cout << "<input type='hidden' name='op3' value='1'>" << endl;
	cout << "<input type='hidden' name='partidoid' value='" << Get["partidoid"] << "'>" << endl;
	cout << "</form>" << endl;
	cout << "</div>" << endl;
}

