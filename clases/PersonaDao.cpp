#include "PersonaDao.h"

PersonaDao::PersonaDao()
{

}

Persona PersonaDao::leerDatos(string sdni)
{
	Persona p;
	sql::ResultSet* res = MyConnection::instance()->query("SELECT * FROM persona WHERE dni = "+sdni);
	p.setDni(0);
	if(res->next())
	{
		p.setNombre(res->getString(2));
		p.setApellido(res->getString(3));
		p.setFecha(res->getString(4));
		p.setDireccion(res->getString(5));
		p.setLugar(res->getString(6));
		p.setDni(res->getInt(1));
	}
	return p;
}

int PersonaDao::checkVoto(string eleccion, string dni)
{
	sql::ResultSet* res = MyConnection::instance()->query("SELECT * FROM votos WHERE dni_persona="+dni+" AND id_eleccion="+eleccion);
	if(res->next())
		return 1;
	return 0;
}

void PersonaDao::votar(string dni, string eleccion)
{
		MyConnection::instance()->execute("INSERT INTO votos (dni_persona, id_eleccion) VALUES ("+dni+","+eleccion+")");
}
