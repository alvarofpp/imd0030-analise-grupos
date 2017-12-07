/**
 *	@file		dados.cpp	
 *	@brief	Implementãção das funções auxiliares
 *	@author	Jessiely Oliveira (jessiely@imd.ufrn.br)
 *      @author Anne Moraes (ilarymoraes@hotmail.com) 
 *	@since	23.11.2017
 *	@data		01.12.2017
 */

#include "dados.h"

Dados::~Dados() {}

/*
 * @brief
 * @details
 */
istream & operator>>(istream & in, Dados & dados) {
	string linha, aux;
	getline(in, linha);
	istringstream buffer(linha);
	while(getline(buffer, aux, ',')) {
		dados.informacoes.push_back(stod(aux));
	}
	return in;
}

/*
 * @brief
 * @details
 */
ostream & operator<<(ostream & out, const Dados & dados) {
	for(size_t i = 0; i < dados.tamanho(); i++) {
		out << dados.informacoes[i];
		if(i+1 == dados.tamanho()) {
			out << "";
		} else {
			out << "	";
		}
	}
	out << endl;
	return out;
}

/*
 * @brief Retorna o tamanho do objeto da classe Dados
 */
size_t Dados::tamanho() const {
	return informacoes.size();
}

/*void Dados::redimensionar(size_t tamanho) {
	informacoes.resize(tamanho);
}*/

/*
 * @brief 
 * @details
 */
bool Dados::operator== (const Dados & dados) const {
	if(informacoes.size() != dados.informacoes.size()) {
		return EXIT_FAILURE;
	}
	for(size_t  i = 0; i < informacoes.size(); i++) {
		if(informacoes[i] == dados.informacoes[i]) {
			continue;
		}
		return informacoes[i] < dados.informacoes[i];
	}
	return false;
}

/*
 * @brief Sobrecarga de operador de acesso
 * @param Indíce do elemento
 * @details Acessa um elemento por meio de um índice
 */
double & Dados::operator[](int indice) {
	return informacoes[indice];
}

/*
 * @brief
 * @details
 */
const double & Dados::operator[](int indice) const {
	return informacoes[indice];
}


double Dados::DistEuclidiana( const Dados & dsd_) const{

	double Distancia = 0.0;

	for( size_t i = 0; i < tamanho(); i++ ){
		Distancia += pow( dsd_[i] - informacoes[i], 2);
	}

	return sqrt(Distancia);

} 
