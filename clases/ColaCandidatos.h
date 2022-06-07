/*
 * ColaCandidatos.h
 *
 *  Created on: 24 feb. 2018
 *      Author: franco
 */

#ifndef CLASES_COLACANDIDATOS_H_
#define CLASES_COLACANDIDATOS_H_
#include <iostream>
#include <string>
#include "NodoCandidato.h"
#include "Candidato.h"
using namespace std;
class ColaCandidatos {
public:
	ColaCandidatos();
	void push(Candidato);
	void pop();
	NodoCandidato* getFirst();
private:
	NodoCandidato* first;
	NodoCandidato* last;
};

#endif /* CLASES_COLACANDIDATOS_H_ */
