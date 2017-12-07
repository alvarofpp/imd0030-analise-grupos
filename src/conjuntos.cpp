/**
 *	@file		conjuntos.cpp	
 *	@brief	Implementação das funções relacionadas ao conjunto
 *	@author	Jessiely Oliveira (jessiely@imd.ufrn.br)
 *	@since	23.11.2017
 *	@data		07.12.2017
 */

#include "conjuntos.h"

/*
 * @brief Insere o elemento 
 */

void Conjuntos::inserir(vector<double> & elemento) {
	elementos.insert(elemento);
}

/*
 * @brief Remove o elemento 
 */

void Conjuntos::remover(vector<double> & elemento) {
	elementos.erase(elemento);
}

/*
 * @brief Faz a união dos conjuntos
 * @details Insere no conjuntoB os elementos do conjuntoA 
 */

Conjuntos Conjuntos::uniao(const Conjuntos & conjuntoA) const {
	Conjuntos conjuntoB;
	conjuntoB.elementos.insert(conjuntoA.elementos.begin(), conjuntoA.elementos.end());
	conjuntoB.elementos.insert(elementos.begin(), elementos.end());
	return conjuntoB;
}

/*
 * @brief Verifica se determinado elemento está no conjunto 
 */

bool Conjuntos::pertinencia (const vector<double> & elemento) const {
    return elementos.find(elemento) != elementos.end();
}

/*
 * @brief Verifica os elementos diferentes entre o conbjuntoA e conjuntoB 
 * @details Elimina essas diferenças do conjuntoB 
 */
Conjuntos Conjuntos::diferenca(const Conjuntos & conjuntoA) const {
    Conjuntos conjuntoB;
    for (auto i = conjuntoB.elementos.begin(); i != conjuntoB.elementos.end(); i++)
        if (!conjuntoA.pertinencia(*i)) {
        	conjuntoB.elementos.erase(*i); 
        }
    return conjuntoB;
}

/*
 * @brief Verifica os elementos em comum dos conjuntos
 * @details 
 */

Conjuntos Conjuntos::intercessao(const Conjuntos & conjuntoA) const {
    Conjuntos conjuntoB;
    for (auto i = conjuntoB.elementos.begin(); i != conjuntoB.elementos.end(); i++)
        if (conjuntoA.pertinencia(*i)) {
        	conjuntoB.elementos.insert(*i); 
        }
    return conjuntoB;
}

/*
 * @brief  
 * @details 
 */

bool Conjuntos::comparar(const Conjuntos & conjunto) {
  for(auto i = conjunto.elementos.begin(); i != conjunto.elementos.end(); i++) {
    if (elementos.find(*i) == elementos.end()) {
    	return false;
    }
  }
  return true;
}
