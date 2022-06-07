/*
 * CandidatosDao.cpp
 *
 *  Created on: 24 feb. 2018
 *      Author: franco
 */

#include "CandidatosDao.h"

CandidatosDao::CandidatosDao() {
	// TODO Auto-generated constructor stub

}

ColaCandidatos CandidatosDao::leerCandidatos(string id_eleccion)
{
	ColaCandidatos c;
	Candidato k;
	sql::ResultSet* res = MyConnection::instance()->query("SELECT candidatos.dni, persona.nombre, persona.apellido, partidos_politicos.nombre, elecciones.nombre, candidatos.cantidad_votos FROM candidatos INNER JOIN persona ON candidatos.dni=persona.dni INNER JOIN partidos_politicos ON candidatos.id_partido=partidos_politicos.id_partido INNER JOIN elecciones ON elecciones.id_eleccion=candidatos.id_eleccion WHERE candidatos.id_eleccion="+id_eleccion);
	while(res->next())
	{
		k.setDni(res->getInt(1));
		k.setNombre(res->getString(2));
		k.setApellido(res->getString(3));
		k.setPartido(res->getString(4));
		k.setEleccion(res->getString(5));
		k.setVotos(res->getInt(6));
		c.push(k);
	}
	return c;
}

ColaCandidatos CandidatosDao::leerCandidatosPanel(string partidoid)
{
	ColaCandidatos c;
	Candidato k;
	sql::ResultSet* res = MyConnection::instance()->query("SELECT candidatos.dni, persona.nombre, persona.apellido FROM candidatos INNER JOIN persona ON persona.dni = candidatos.dni WHERE id_partido="+partidoid);
	while(res->next())
	{
		k.setDni(res->getInt(1));
		k.setNombre(res->getString(2));
		k.setApellido(res->getString(3));
		c.push(k);
	}
	return c;
}

void CandidatosDao::votar(string dni)
{
	MyConnection::instance()->execute("UPDATE candidatos SET cantidad_votos=cantidad_votos+1 WHERE dni="+dni);
}

void CandidatosDao::cambiarDatos(string dni, string nombre, string apellido)
{
	if(!nombre.empty())
		MyConnection::instance()->execute("UPDATE persona SET nombre='"+nombre+"' WHERE dni="+dni);
	if(!apellido.empty())
		MyConnection::instance()->execute("UPDATE persona SET apellido='"+apellido+"' WHERE dni="+dni);
}

void CandidatosDao::eliminarCandidato(string dni)
{
	MyConnection::instance()->execute("DELETE FROM candidatos WHERE dni="+dni);
}

void CandidatosDao::agregarCandidato(string dni, string eleccionid, string partidoid)
{
	MyConnection::instance()->execute("INSERT INTO candidatos (dni, id_eleccion, id_partido, id_candidatura) VALUES ("+dni+","+eleccionid+","+partidoid+",1)");
}

