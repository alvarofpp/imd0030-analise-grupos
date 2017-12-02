/**
 *	@file		conjuntos.cpp	
 *	@brief	Implementação das funções relacionadas ao conjunto
 *	@author	Jessiely Oliveira (jessiely@imd.ufrn.br)
 *	@since	23.11.2017
 *	@data		01.12.2017
 */

#include "conjuntos.h"

/*
 * @brief	Sobrecarga do operador de inserção
 * @details	Realiza a leitura do arquivo .csv
 */
istream & operator>>(istream & in, Conjuntos & conjunto) {
	while(!in.eof()) {
		Dados dados;
		in >> dados;
		conjunto.insert(dados);
	}
	return in;
}

/*
 * @brief	Sobrecarga do operador de extração
 * @details	Realiza a escrita dos dados do arquivo .csv
 */
ostream & operator<< (ostream & out, const Conjuntos & conjunto) {
	for(auto i = conjunto.begin(); i != conjunto.end(); i++) {
		out << *i;
	}
	return out;
}