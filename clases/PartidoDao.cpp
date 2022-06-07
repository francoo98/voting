#include "PartidoDao.h"

PartidoDao::PartidoDao()
{

}

ColaPartidos PartidoDao::leerPartidos()
{
	ColaPartidos cola;
	sql::ResultSet* res = MyConnection::instance()->query("SELECT * FROM partidos_politicos");
	Partido p;
	while(res->next())
	{
		p.setId(res->getInt(1));
		p.setNombre(res->getString(2));
		cola.push(p);
	}
	return cola;
}

void PartidoDao::agregarPartido(string s)
{
	MyConnection::instance()->execute("INSERT INTO partidos_politicos (nombre) VALUES (\""+s+"\")");
}

void PartidoDao::eliminarPartido(string id)
{
	MyConnection::instance()->execute("DELETE FROM partidos_politicos WHERE id_partido="+id);
	MyConnection::instance()->execute("DELETE FROM candidatos WHERE id_partido="+id);
}

void PartidoDao::cambiarNombre(string nombre, string id)
{
	MyConnection::instance()->execute("UPDATE partidos_politicos SET nombre=\""+nombre+"\" WHERE id_partido="+id);
}


