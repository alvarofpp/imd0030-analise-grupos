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

#include <cmath>

class Dados {

	private:
		vector<double> informacoes;
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

		double DistEuclidiana( const Dados & ) const; 

};

namespace std {

	template <>
	struct hash< vector<double> > {
		size_t operator()(const vector<double> & d) const {
			if (!d.size()) {
				return EXIT_FAILURE;
			}
			size_t h = hash<double>()(d[0]);
			for (size_t i = 1; i < d.size(); i++)
					h ^= hash<double>()(d[i]); 
			return h;
		}
	};
}

#endif
