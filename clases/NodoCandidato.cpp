/*
 * NodoCandidato.cpp
 *
 *  Created on: 24 feb. 2018
 *      Author: franco
 */

#include "NodoCandidato.h"

NodoCandidato::NodoCandidato() {
	nAnt = NULL;
}

NodoCandidato::NodoCandidato(Candidato _dato){
	nAnt = NULL;
}

Candidato NodoCandidato::getValor(){
	return dato;
}

void NodoCandidato::setValor(Candidato _dato){
	dato = _dato;
}

NodoCandidato* NodoCandidato::getAnt(){
	return nAnt;
}

void NodoCandidato::setAnt(NodoCandidato* ant){
	nAnt = ant;
}
