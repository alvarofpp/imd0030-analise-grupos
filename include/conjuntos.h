/**
 *	@file		conjuntos.h	
 *	@brief	Definição das funções relacionadas ao conjunto
 *	@author Jessiely Oliveira (jessiely@imd.ufrn.br)
 *      @author Anne Moraes (ilarymoraes@hotmail.com) 
 *	@since	23.11.2017
 *	@data		07.12.2017
 */

#ifndef CONJUNTOS_H
#define CONJUNTOS_H

#include <unordered_set>
using std::unordered_set;

#include "dados.h"

class Conjuntos {
	
	private:
		unordered_set< vector<double> > elementos;
	public:


		bool pertinencia (const vector<double> &) const;
		void inserir(vector<double> &);
		void remover(vector<double> &);
		Conjuntos uniao(const Conjuntos &) const;
		Conjuntos diferenca(const Conjuntos &) const;
		Conjuntos intersecao(const Conjuntos &) const;
		bool comparar(const Conjuntos &);

};

#endif
