#include "PersonaViewer.h"
PersonaViewer::PersonaViewer()
{

}

void PersonaViewer::ingresarDniHtml()
{
	map<string, string> Get;
	initializeGet(Get);
	cout << "Content-type: text/html" <<endl<<endl;
	cout << "<!DOCTYPE html>" << endl;
	cout << "<html>" << endl;
	cout << "<head>" << endl;
	//cout << "	<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.3/css/bootstrap.min.css' integrity='sha384-Zug+QiDoJOrZ5t4lssLdxGhVrurbmBWopoEl+M6BdEfwnCJZtKxi1KgxUyJq13dy' crossorigin='anonymous'>" << endl;
	cout << "	<link rel='stylesheet' href='/estilos/style.css'>" << endl;
	cout << "	<link rel='stylesheet' href='/estilos/bootstrap.css'>" << endl;
	cout << "	<title>Voto electronico</title>" << endl;
	cout << "</head>" << endl;
	cout << "<body>" << endl;
	cout << "	<div class='container-fluid' id='head'>" << endl;
	cout << "		<div class='row'>" << endl;
	cout << "			<div class='col-md-11'>" << endl;
	cout << "				<h2 id='titulo'>Voto electronico argentino</h2>" << endl;
	cout << "			</div>" << endl;
	cout << "			<div class='col-md-1' style='text-align:center;'>" << endl;
	cout << "				<img src='/estilos/sol.png' id='sol'>" << endl;
	cout << "			</div>" << endl;
	cout << "		</div>" << endl;
	cout << "	</div>" << endl;
	if(Get.find("dni") == Get.end())
	{
		cout << "	<div id='cuadro' class='container'>" << endl;
		cout << "		<form method='get'>" << endl;
		cout << "			<div class='row'>" << endl;
		cout << "				<div class='col-md-12'>" << endl;
		cout << "					<p><b>Ingrese su DNI</b></p>" << endl;
		cout << "					<input type='number' name='dni' required>" << endl;
		cout << "					<br>" << endl;
		cout << "				</div>" << endl;
		cout << "			</div>" << endl;
		cout << "			<br>" << endl;
		cout << "			<button type='submit' onClick='document.location.reload()' class='btn btn-primary'>Enviar</button>" << endl;
		cout << "		</form>" << endl;
		cout << "	</div>" << endl;
		cout << "</body>" << endl;
		cout << "</html>" << endl;
	}
	else
	{
		if(Get["dni"] == "1")
			adminHtml();
		else
			datosHtml(Get["dni"]);
	}
}

void PersonaViewer::datosHtml(string dni)
{
	Persona p;
	p = PersonaDao::leerDatos(dni);
	cout << "	<div class='container-fluid' id='datos'>" << endl;
	cout << "		<div class='row'>" << endl;
	if(p.getDni() != 0)
	{
		cout << "			<div class='col-md-2'>" << endl;
		cout << "				<p><b>Nombre</b><br>"<< p.getNombre() << "</p>" << endl;
		cout << "			</div>" << endl;
		cout << "			<div class='col-md-2'>" << endl;
		cout << "				<p><b>Apellido</b><br>" << p.getApellido() << "</p>" << endl;
		cout << "			</div>" << endl;
		cout << "			<div class='col-md-2'>" << endl;
		cout << "				<p><b>Fecha de nacimiento</b><br>"<< p.getFecha() << "</p>" << endl;
		cout << "			</div>" << endl;
		cout << "			<div class='col-md-2'>" << endl;
		cout << "				<p><b>Lugar de nacimiento</b><br>" << p.getLugar() << "</p>" << endl;
		cout << "			</div>" << endl;
		cout << "			<div class='col-md-2'>" << endl;
		cout << "				<p><b>Domicilio</b><br>" << p.getDireccion()<< "</p>" << endl;
		cout << "			</div>" << endl;
		cout << "			<div class='col-md-2'>" << endl;
		cout << "				<p><b>DNI</b><br>" << p.getDni() <<"</p>" << endl;
		cout << "			</div>" << endl;
		TipoEleccionesController::listarElecciones();
	}
	else
	{
		cout << "<div class='col-md-12' style='text-align:center'>" << endl;
		cout << "<h4 style='align:center';>>El DNI que ingreso no existe<</h2>" << endl;
		cout << "</div>" << endl;
	}
	cout << "		</div>" << endl;
	cout << "	</div>" << endl;
}

void PersonaViewer::adminHtml() //admin 1
{
	map<string, string> Get;
	initializeGet(Get);
	cout << "	<div class='container-fluid' id='datos'>" << endl;
	cout << "		<div class='row'>" << endl;
	cout << "			<div class='col-md-12'>" << endl;
	cout << "				<br><h5><b> >Panel administrable< </h5><br>" << endl;
	cout << "			</div>" << endl;
	cout << "		</div>" << endl;
	cout << "	</div>" << endl;
	cout << "<form method='get'>" << endl;
	cout << "<div class='container' id='cuadro'>" << endl;
	cout << "<div class='row'>" << endl;
	cout << "	" << endl;
	cout << "	<div class='col-md-6'>" << endl;
	cout << "		<button class='btn btn-primary' type='submit' onClick='document.location.reload()' name='op' value='1'>Administrar tipos de elecciones</button>" << endl;
	cout << "	</div>" << endl;
	cout << "	<div class='col-md-6'>" << endl;
	cout << "		<button class='btn btn-primary' type='submit' onClick='document.location.reload()' name='op' value='2'>Administrar partidos politicos</button>" << endl;
	cout << "	</div>" << endl;
	cout << "</div>" << endl;
	cout << "</div>" << endl;
	cout << "<input type='hidden' name='dni' value='1'>" << endl;
	cout << "</form>" << endl;
	if(Get.find("op") != Get.end())
	{
		if(Get["op"] == "1")
		{
			TipoEleccionesController::panel();
		}
		if(Get["op"] == "2")
		{
			PartidoController::panel();
		}
	}

}

