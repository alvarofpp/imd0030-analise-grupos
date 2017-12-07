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
		unordered_set<Dados> conteudo;
	public:
/*		using unordered_set<Dados>::insert;
		using unordered_set<Dados>::erase;
		using unordered_set<Dados>::find;
		using unordered_set<Dados>::empty;
		using unordered_set<Dados>::begin;
		using unordered_set<Dados>::end;*/

		//friend istream & operator>>(istream &, Conjuntos &);
		//friend ostream & operator<< (ostream &, const Conjuntos &);

		bool pertinencia (const Dados &) const;
		void inserir(Dados &);
		void remover(Dados &);
		Conjuntos uniao(const Conjuntos &) const;
		Conjuntos diferenca(const Conjuntos &) const;
		Conjuntos intercessao(const Conjuntos &) const;


};

#endif