/*
 * TipoEleccionesDao.cpp
 *
 *  Created on: 22 feb. 2018
 *      Author: franco
 */

#include "TipoEleccionesDao.h"

TipoEleccionesDao::TipoEleccionesDao() {
	// TODO Auto-generated constructor stub

}

ColaTipoElecciones TipoEleccionesDao::leerTipoElecciones()
{
	ColaTipoElecciones c;
	sql::ResultSet* res = MyConnection::instance()->query("SELECT * FROM tipo_eleccion");
	TipoElecciones t;
	while(res->next())
	{
		t.setId(res->getInt(1));
		t.setNombre(res->getString(2));
		c.push(t);
	}
	delete res;
	return c;
}

void TipoEleccionesDao::agregarTipoEleccion(string s)
{
	MyConnection::instance()->execute("INSERT INTO tipo_eleccion (nombre) VALUE (\"" + s + "\")");
}

void TipoEleccionesDao::eliminarTipoEleccion(string s)
{
	MyConnection::instance()->execute("DELETE FROM tipo_eleccion WHERE id="+s);
	MyConnection::instance()->execute("DELETE FROM elecciones WHERE id_tipo="+s);
}

void TipoEleccionesDao::cambiarNombre(string nombre, string id)
{
	MyConnection::instance()->execute("UPDATE tipo_eleccion SET nombre=\""+nombre+"\" WHERE id="+id);
}
