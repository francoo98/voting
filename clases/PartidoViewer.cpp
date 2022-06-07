#include "PartidoViewer.h"

PartidoViewer::PartidoViewer() {

}

/*void PartidoViewer::partidosHtml() {
	map<string, string> Get;
	initializeGet(Get);
	ColaPartidos c = PartidoDao::leerPartidos(Get["eleccionid"]);
	if(Get.find("candidatodni") == Get.end())
	{

	}
}*/

void PartidoViewer::panelHtml()
{
	map<string, string> Get;
	initializeGet(Get);
	cout << "<form method='get'>" << endl;
	cout << "<div class='container' id='cuadro'>" << endl;
	cout << "<div class='row'>" << endl;
	cout << "	<div class='col-md-6'>" << endl;
	cout << "		<button class='btn btn-primary' type='submit' onClick='document.location.reload()' name='op2' value='1'>Agregar partido</button>" << endl;
	cout << "	</div>" << endl;
	cout << "	<div class='col-md-3'>" << endl;
	cout << "		<button class='btn btn-primary' type='submit' onClick='document.location.reload()' name='op2' value='2'>Modificar/Eliminar partidos</button>" << endl;
	cout << "	</div>" << endl;
	cout << "</div>" << endl;
	cout << "</div>" << endl;
	cout << "<input type='hidden' name='dni' value='1'>" << endl;
	cout << "<input type='hidden' name='op' value='2'>" << endl;
	cout << "</form>" << endl;
	if(Get.find("op2") != Get.end())
	{
		if(Get["op2"] == "1")
			agregarPartidoHtml();
		if(Get["op2"] == "2")
			modificarEliminarPartidoHtml();
	}
}

void PartidoViewer::agregarPartidoHtml()
{
	map<string,string> Get;
	initializeGet(Get);
	cout << "<br>" << endl;
	cout << "<form method='get'>" << endl;
	cout << "<div class='container' style='text-align:center'>"<< endl;
	cout << "Ingrese el nombre: <input type='text' name='nombre'>" << endl;
	cout << "<button class='btn btn-success btn-sm'> Agregar </button>" << endl;
	cout << "</div>" << endl;
	cout << "<input type='hidden' name='dni' value='1'>" << endl;
	cout << "<input type='hidden' name='op' value='2'>" << endl;
	cout << "<input type='hidden' name='op2' value='1'>" << endl;
	cout << "</form>" << endl;
	if(Get.find("nombre") != Get.end())
		PartidoDao::agregarPartido(Get["nombre"]);
}

void PartidoViewer::modificarEliminarPartidoHtml()
{
	map<string, string> Get;
	initializeGet(Get);
	cout << "<div class='container' style='text-align: center'>" << endl;
	cout << "<br>" << endl;
	cout << "<br>" << endl;
	if(Get.find("op3") == Get.end())
	{
		cout << "<h3>Partidos politicos</h3>" << endl;
		ColaPartidos c = PartidoDao::leerPartidos();
		while(c.getFirst())
		{
			cout << "<div class='row'>" << endl;
			cout << "<div class='col-md-12'>" << endl;
			cout << "<form method='get'>" << endl;
			cout << "<input type='hidden' name='dni' value='1'>" << endl;
			cout << "<input type='hidden' name='op' value='2'>" << endl;
			cout << "<input type='hidden' name='op2' value='2'>" << endl;
			cout << c.getFirst()->getValor().getNombre() << "<button class='btn btn-success btn-sm' name='op3' value='1' onClick='document.location.reload()'>Modificar</button> <button class='btn btn-danger btn-sm' name='op3' value='2' onClick='document.location.reload()'>Eliminar</button>" << endl;
			cout << "<input type='hidden' name='partidoid' value='" << c.getFirst()->getValor().getId() << "'>" << endl;
			cout << "</form>" << endl;
			cout << "</div>" << endl;
			cout << "</div>" << endl;
			cout << "<br>" << endl;
			c.pop();
		}
	}
	{
		if(Get["op3"] == "2")
		{
			PartidoDao::eliminarPartido(Get["partidoid"]);
			cout << "<p>Partido eliminado</p>" << endl;
		}
		else
		{
			if(Get["op3"] == "1")
				modificarHtml();
		}
	}
	cout << "</div>" << endl;
}

void PartidoViewer::modificarHtml()
{
	map<string,string> Get;
	initializeGet(Get);
	cout << "<div class='container' style='text-align: center'" << endl;
	cout << "<div class='row'>" << endl;
	cout << "<div class='col-md-12'>" << endl;
	cout << "<h3>Modificar partido</h3>" << endl;
	cout << "</div>" << endl;
	cout << "</div>" << endl;
	cout << "<div class='row'>" << endl;
	cout << "<div class='col-md-12'>" << endl;
	cout << "<form method='get'>" << endl;
	cout << "Cambiar nombre: <input type='text' name='nombrePartido'> <button class='btn btn-success btn-sm' type='submit' onClick='document.location.reload()'>Enviar</button>" << endl;
	cout << "<input type='hidden' name='dni' value='1'>" << endl;
	cout << "<input type='hidden' name='op' value='2'>" << endl;
	cout << "<input type='hidden' name='op2' value='2'>" << endl;
	cout << "<input type='hidden' name='op3' value='" << Get["op3"] << "'</input>" << endl;
	cout << "<input type='hidden' name='partidoid' value='" << Get["partidoid"] << "'>" << endl;
	cout << "</form>" << endl;
	cout << "</div>" << endl;
	cout << "</div>" << endl;
	cout << "</div>" << endl;
	CandidatosController::panel();
	if(Get.find("nombrePartido") != Get.end())
	{
		PartidoDao::cambiarNombre(Get["nombrePartido"], Get["partidoid"]);
	}
}
