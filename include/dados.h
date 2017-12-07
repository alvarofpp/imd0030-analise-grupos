	/**
 *	@file		dados.h	
 *	@brief	Definição das funções auxiliares
 *	@author	Jessiely Oliveira (jessiely@imd.ufrn.br)
 *      @author Anne Moraes (ilarymoraes@hotmail.com) 
 *	@since	23.11.2017
 *	@data		01.12.2017
 */

#ifndef DADOS_H
#define DADOS_H

#include <vector>
using std::vector;

#include <iostream>
using std::istream;
using std::ostream;
using std::endl;
using std::cout;

#include <string>
using std::string;

#include <sstream>
using std::istringstream;

#include <utility>
using std::pair;

#include <set>
using std::set;

#include <cmath>

class Dados {

	private:
		set< vector<double> > informacoes;
	public:
		Dados() = default;
		Dados(const vector< pair<double, double> > &);
		~Dados();

		friend istream & operator>>(istream &, Dados &);
		friend ostream & operator<<(ostream &, const Dados &);
		size_t tamanho() const;
	//	void redimensionar(size_t tamanho);
		bool operator== (const Dados &) const;
		double & operator[](int indice);
		const double & operator[](int indice) const;
		bool pertinencia (const vector<double> &) const;
		void inserir(vector<double> &);
		void remover(vector<double> &);
		Dados uniao(const Conjuntos &) const;
		Dados diferenca(const Conjuntos &) const;
		Dados intersecao(const Conjuntos &) const;
		bool comparar(const Conjuntos &);

};

/**namespace std {
*
*	template <>
*	struct set< vector<double> > {
*		size_t operator()(const vector<double> & d) const {
*			if (!d.size()) {
*				return EXIT_FAILURE;
*			}
*			size_t h = set<double>()(d[0]);
*			for (size_t i = 1; i < d.size(); i++)
*					h ^= hash<double>()(d[i]); 
*			return h;
*		}
*	};
*}
*/
#endif
