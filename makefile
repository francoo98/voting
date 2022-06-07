DIR = -I/usr/include/cppconn -I./clases
OBJS = main.o clases/PersonaController.o clases/PersonaViewer.o clases/PartidoController.o clases/PartidoViewer.o clases/Cola.o clases/PersonaDao.o clases/Persona.o clases/PartidoDao.o clases/Nodo.o clases/myconnection.o clases/ColaPartidos.o clases/NodoPartido.o clases/Partido.o clases/TipoEleccionesController.o clases/TipoEleccionesViewer.o clases/TipoEleccionesDao.o clases/NodoTipoElecciones.o clases/ColaTipoElecciones.o clases/TipoElecciones.o clases/Eleccion.o clases/NodoEleccion.o clases/ColaElecciones.o clases/EleccionController.o clases/EleccionViewer.o clases/EleccionesDao.o clases/Candidato.o clases/CandidatosController.o clases/CandidatosViewer.o clases/CandidatosDao.o clases/ColaCandidatos.o clases/NodoCandidato.o
CXXFLAGS=-std=c++11
main: $(OBJS)
	g++ -g -Wall $(DIR) $(OBJS) -o /var/www/cgi-bin/main2 -L/usr/lib -lmysqlcppconn
clean:
	rm -f $(OBJS)
