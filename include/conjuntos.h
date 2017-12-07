/**
 *	@file		conjuntos.h	
 *	@brief	Definição das funções relacionadas ao conjunto
 *	@author	Jessiely Oliveira (jessiely@imd.ufrn.br)
 *	@since	23.11.2017
 *	@data		07.12.2017
 */

#ifndef CONJUNTOS_H
#define CONJUNTOS_H

#include <unordered_set>
using std::unordered_set;

#include "dados.h"

class Conjuntos /* : private unordered_set<Dados>*/ {
	
	private:
		unordered_set< vector<double> > elementos;
	public:
		/*		using unordered_set<Dados>::insert;
		using unordered_set<Dados>::erase;
		using unordered_set<Dados>::find;
		using unordered_set<Dados>::empty;
		using unordered_set<Dados>::begin;
		using unordered_set<Dados>::end;*/


		bool pertinencia (const vector<double> &) const;
		void inserir(vector<double> &);
		void remover(vector<double> &);
		Conjuntos uniao(const Conjuntos &) const;
		Conjuntos diferenca(const Conjuntos &) const;
		Conjuntos intercessao(const Conjuntos &) const;
		bool comparar(const Conjuntos &);

};

#endif