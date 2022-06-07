/*
 * tipoEleccionesViewer.cpp
 *
 *  Created on: 22 feb. 2018
 *      Author: franco
 */

#include "TipoEleccionesViewer.h"

TipoEleccionesViewer::TipoEleccionesViewer()
{

}

void TipoEleccionesViewer::listarTipoEleccionesHtml()
{
	map <string, string> Get;
	initializeGet (Get);
	if (Get.find("tipo") == Get.end())
	{
		ColaTipoElecciones c;
		c = TipoEleccionesDao::leerTipoElecciones();
		cout << "<form method='get'>" << endl;
		while (c.getFirst())
		{
			cout << "	<div id='cuadro_partido' class='container'>" << endl;
			cout << "		<div class='row'>" << endl;
			cout << "			<div class='col-md-12'>" << endl;
			cout << "				<h4>" << c.getFirst()->getValor().getNombre() << "</h4>" << endl;
			cout << "				<button class='btn btn-primary' name='tipo' value='" << c.getFirst()->getValor().getId() << "' onClick='document.location.reload()'>Entrar a votar</button>" << endl;
			cout << "			</div>" << endl;
			cout << "		</div>" << endl;
			cout << "	</div>" << endl;
			c.pop();
		}
		cout << "<input type='hidden' name='dni' value='" << Get["dni"] << "'</input>" << endl;
		cout << "</form>" << endl;
		cout << "</body>" << endl;
		cout << "</html>" << endl;
	} else {
		EleccionController::listarElecciones();
	}
}
void TipoEleccionesViewer::panelHtml()
{
	map<string, string> Get;
	initializeGet(Get);
	cout << "<form method='get'>" << endl;
	cout << "<div class='container' id='cuadro'>" << endl;
	cout << "<div class='row'>" << endl;
	cout << "	<div class='col-md-6'>" << endl;
	cout << "		<button class='btn btn-primary' type='submit' onClick='document.location.reload()' name='op2' value='1'>Agregar tipo de eleccion</button>" << endl;
	cout << "	</div>" << endl;
	cout << "	<div class='col-md-3'>" << endl;
	cout << "		<button class='btn btn-primary' type='submit' onClick='document.location.reload()' name='op2' value='2'>Modificar/Eliminar tipo de eleccion</button>" << endl;
	cout << "	</div>" << endl;
	cout << "</div>" << endl;
	cout << "</div>" << endl;
	cout << "<input type='hidden' name='dni' value='1'>" << endl;
	cout << "<input type='hidden' name='op' value='1'>" << endl;
	cout << "</form>" << endl;
	if(Get["op2"] == "1") //agregar tipo de eleccion
	{
		TipoEleccionesController::agregar();
	}
	else
	{
		if(Get["op2"] == "2") // modificar/eliminar tipos de elecciones
		{
			TipoEleccionesController::modificar_eliminar();
		}
	}
}
void TipoEleccionesViewer::agregarTipoEleccionHtml()
{
	map<string, string> Get;
	initializeGet(Get);
	cout << "<br>" << endl;
	cout << "<form method='get'>" << endl;
	cout << "<div class='container' style='text-align:center'>"<< endl;
	cout << "Ingrese el nombre: <input type='text' name='nombre'>" << endl;
	cout << "<button class='btn btn-success btn-sm'> Agregar </button>" << endl;
	cout << "</div>" << endl;
	cout << "<input type='hidden' name='dni' value='1'>" << endl;
	cout << "<input type='hidden' name='op' value='1'>" << endl;
	cout << "<input type='hidden' name='op2' value='1'>" << endl;
	cout << "</form>" << endl;
	if(Get.find("nombre") != Get.end())
		TipoEleccionesDao::agregarTipoEleccion(Get["nombre"]);
}
void TipoEleccionesViewer::modificar_eliminarHtml()
{
	map<string, string> Get;
	initializeGet(Get);
	cout << "<div class='container' style='text-align: center'>" << endl;
	cout << "<br>" << endl;
	cout << "<br>" << endl;
	if(Get.find("op3") == Get.end())
	{
		ColaTipoElecciones c = TipoEleccionesDao::leerTipoElecciones();
		cout << "<h3>Tipos de elecciones existentes</h3>" << endl;
		while(c.getFirst())
		{
			cout << "<div class='row'>" << endl;
			cout << "<div class='col-md-12'>" << endl;
			cout << "<form method='get'>" << endl;
			cout << "<input type='hidden' name='dni' value='1'>" << endl;
			cout << "<input type='hidden' name='op' value='1'>" << endl;
			cout << "<input type='hidden' name='op2' value='2'>" << endl;
			cout << c.getFirst()->getValor().getNombre() << "<button class='btn btn-success btn-sm' name='op3' value='1' onClick='document.location.reload()'>Modificar</button> <button class='btn btn-danger btn-sm' name='op3' value='2' onClick='document.location.reload()'>Eliminar</button>" << endl;
			cout << "<input type='hidden' name='eleccion' value='" << c.getFirst()->getValor().getId() << "'>" << endl;
			cout << "</form>" << endl;
			cout << "</div>" << endl;
			cout << "</div>" << endl;
			cout << "<br>" << endl;
			c.pop();
		}
	}
	else
	{
		if(Get["op3"] == "2")
		{
			TipoEleccionesDao::eliminarTipoEleccion(Get["eleccion"]);
			cout << "<p>Tipo de eleccion eliminada</p>" << endl;
		}
		else
		{
			if(Get["op3"] == "1")
				modificarHtml();
		}
	}
	cout << "</div>" << endl;
}
void TipoEleccionesViewer::modificarHtml()
{
	map<string,string> Get;
	initializeGet(Get);
	cout << "<div class='container' style='text-align: center'" << endl;
	cout << "<div class='row'>" << endl;
	cout << "<div class='col-md-12'>" << endl;
	cout << "<h3>Modificar tipo de eleccion</h3>" << endl;
	cout << "</div>" << endl;
	cout << "</div>" << endl;
	cout << "<div class='row'>" << endl;
	cout << "<div class='col-md-12'>" << endl;
	cout << "<form method='get'>" << endl;
	cout << "Cambiar nombre: <input type='text' name='nombreTipo'> <button class='btn btn-success btn-sm' type='submit' onClick='document.location.reload()'>Enviar</button>" << endl;
	cout << "<input type='hidden' name='dni' value='1'>" << endl;
	cout << "<input type='hidden' name='op' value='1'>" << endl;
	cout << "<input type='hidden' name='op2' value='2'>" << endl;
	cout << "<input type='hidden' name='op3' value='" << Get["op3"] << "'</input>" << endl;
	cout << "<input type='hidden' name='eleccion' value='" << Get["eleccion"] << "'>" << endl;
	cout << "</form>" << endl;
	cout << "</div>" << endl;
	cout << "</div>" << endl;
	if(Get.find("nombreTipo") != Get.end())
	{
		TipoEleccionesDao::cambiarNombre(Get["nombreTipo"], Get["eleccion"]);
	}
	cout << "<div class='row'>" << endl;
	cout << "<div class='col-md-12'>" << endl;
	cout << "<h5><b>Elecciones: </b></h5>" << endl;
	 EleccionController::panel();
	cout << "</div>" << endl;
	cout << "</div>" << endl;
	cout << "</div>" << endl;
}
