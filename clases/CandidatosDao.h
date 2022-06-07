/*
 * CandidatosDao.h
 *
 *  Created on: 24 feb. 2018
 *      Author: franco
 */

#ifndef CLASES_CANDIDATOSDAO_H_
#define CLASES_CANDIDATOSDAO_H_
#include <iostream>
#include <string>
#include "ColaCandidatos.h"
#include "Candidato.h"
#include "myconnection.h"
class CandidatosDao {
public:
	CandidatosDao();
	static ColaCandidatos leerCandidatos(string id_eleccion);
	static ColaCandidatos leerCandidatosPanel(string partidoid);
	static void votar(string dni); //aumenta cantidad de votos
	static void cambiarDatos(string, string, string);
	static void eliminarCandidato(string);
	static void agregarCandidato(string, string, string);
};

#endif /* CLASES_CANDIDATOSDAO_H_ */
