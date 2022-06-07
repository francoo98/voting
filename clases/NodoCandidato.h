/*
 * NodoCandidato.h
 *
 *  Created on: 24 feb. 2018
 *      Author: franco
 */

#ifndef CLASES_NODOCANDIDATO_H_
#define CLASES_NODOCANDIDATO_H_
#include <iostream>
#include <string>
#include "Candidato.h"
class NodoCandidato {
public:
	NodoCandidato();
	NodoCandidato(Candidato);
	Candidato getValor();
	void setValor(Candidato);
	NodoCandidato* getAnt();
	void setAnt(NodoCandidato*);
private:
	Candidato dato;
	NodoCandidato* nAnt;
};

#endif /* CLASES_NODOCANDIDATO_H_ */
