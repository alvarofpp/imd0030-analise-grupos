/**
 *	@file		conjuntos.cpp	
 *	@brief	Implementação das funções relacionadas ao conjunto
 *	@author	Jessiely Oliveira (jessiely@imd.ufrn.br)
 *	@since	23.11.2017
 *	@data		07.12.2017
 */

#include "conjuntos.h"

void Conjuntos::inserir(vector<double> & elemento) {
	elementos.insert(elemento);
}

void Conjuntos::remover(vector<double> & elemento) {
	elementos.erase(elemento);
}

Conjuntos Conjuntos::uniao(const Conjuntos & conjuntoA) const {
	Conjuntos conjuntoB;
	conjuntoB.elementos.insert(conjuntoA.elementos.begin(), conjuntoA.elementos.end());
	conjuntoB.elementos.insert(elementos.begin(), elementos.end());
	return conjuntoB;
}

bool Conjuntos::pertinencia (const vector<double> & elemento) const {
    return elementos.find(elemento) != elementos.end();
}

Conjuntos Conjuntos::diferenca(const Conjuntos & conjuntoA) const {
    Conjuntos conjuntoB;
    for (auto i = conjuntoB.elementos.begin(); i != conjuntoB.elementos.end(); i++)
        if (!conjuntoA.pertinencia(*i)) {
        	conjuntoB.elementos.erase(*i); 
        }
    return conjuntoB;
}

Conjuntos Conjuntos::intercessao(const Conjuntos & conjuntoA) const {
    Conjuntos conjuntoB;
    for (auto i = conjuntoB.elementos.begin(); i != conjuntoB.elementos.end(); i++)
        if (conjuntoA.pertinencia(*i)) {
        	conjuntoB.elementos.insert(*i); 
        }
    return conjuntoB;
}

bool Conjuntos::comparar(const Conjuntos & conjunto) {
  for(auto i = conjunto.elementos.begin(); i != conjunto.elementos.end(); i++) {
    if (elementos.find(*i) == elementos.end()) {
    	return false;
    }
  }
  return true;
}
