#ifndef PERSONA_H_
#define PERSONA_H_
#include <iostream>
#include <string>
using namespace std;

class Persona 
{
	public:
		Persona();
		void setNombre(string);		
		void setApellido(string);		
		void setFecha(string);		
		void setDireccion(string);		
		void setLugar(string);		
		void setDni(int);
		void setVoto(int);
		void setId(int);
		string getNombre();		
		string getApellido();		
		string getFecha();		
		string getDireccion();		
		string getLugar();		
		int getDni();
		int getVoto();
		int getId();		
	private:
		int id;
		int dni;
		int voto;
		string nombre;
		string apellido;
		string fecha;
		string direccion;
		string lugar;
};

#endif
