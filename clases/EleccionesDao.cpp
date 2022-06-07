/*
 * EleccionesDao.cpp
 *
 *  Created on: 24 feb. 2018
 *      Author: franco
 */

#include "EleccionesDao.h"

EleccionesDao::EleccionesDao() {
	// TODO Auto-generated constructor stub

}

ColaElecciones EleccionesDao::leerEleccionesT()
{
	ColaElecciones c;
	Eleccion e;
	sql::ResultSet* res = MyConnection::instance()->query("select id_eleccion, nombre from elecciones");
	while(res->next())
	{
		e.setId_eleccion(res->getInt(1));
		e.setNombre(res->getString(2));
		c.push(e);
	}
	return c;
}

ColaElecciones EleccionesDao::leerElecciones(string tipo)
{
	ColaElecciones c;
	Eleccion e;
	sql::ResultSet* res = MyConnection::instance()->query("select id_eleccion, nombre from elecciones where id_tipo="+tipo);
	while(res->next())
	{
		e.setId_eleccion(res->getInt(1));
		e.setNombre(res->getString(2));
		c.push(e);
	}
	return c;
}

void EleccionesDao::cambiarNombreEleccion(string nombre, string id)
{
	MyConnection::instance()->execute("UPDATE elecciones SET nombre=\""+nombre+"\" WHERE id_eleccion="+id);
}

void EleccionesDao::eliminarEleccion(string id)
{
	MyConnection::instance()->execute("DELETE FROM elecciones WHERE id_eleccion="+id);
	MyConnection::instance()->execute("DELETE FROM candidatos WHERE id_eleccion="+id);
}

void EleccionesDao::agregarEleccion(string s, string id)
{
	MyConnection::instance()->execute("INSERT INTO elecciones (id_tipo, nombre) VALUES ("+id+",\""+s+"\")");
}

