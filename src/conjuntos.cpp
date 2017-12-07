/**
 *	@file		conjuntos.cpp	
 *	@brief	Implementação das funções relacionadas ao conjunto
 *	@author	Jessiely Oliveira (jessiely@imd.ufrn.br)
 *	@since	23.11.2017
 *	@data		07.12.2017
 */

#include "conjuntos.h"

/*
 * @brief	Sobrecarga do operador de inserção
 * @details	Realiza a leitura do arquivo .csv
 
istream & operator>>(istream & in, Conjuntos & conjunto) {
	while(!in.eof()) {
		Dados dados;
		in >> dados;
		conjunto.conteudo.insert(dados);
	}
	return in;
}*/

/*
 * @brief	Sobrecarga do operador de extração
 * @details	Realiza a escrita dos dados do arquivo .csv
 
ostream & operator<< (ostream & out, const Conjuntos & conjunto) {
	for(auto i = conjunto.conteudo.begin(); i != conjunto.conteudo.end(); i++) {
		out << *i;
	}
	return out;
}*/

void Conjuntos::inserir(Dados & elemento) {
	conteudo.insert(elemento);
}

void Conjuntos::remover(Dados & elemento) {
	conteudo.erase(elemento);
}

Conjuntos Conjuntos::uniao(const Conjuntos & conjuntoA) const {
	Conjuntos conjuntoB;
	conjuntoB.conteudo.insert(conjuntoA.conteudo.begin(), conjuntoA.conteudo.end());
	conjuntoB.conteudo.insert(conteudo.begin(), conteudo.end());
	return conjuntoB;
}

bool Conjuntos::pertinencia (const Dados & elemento) const {
    return conteudo.find(elemento) != conteudo.end();
}

Conjuntos Conjuntos::diferenca(const Conjuntos & conjuntoA) const {
    Conjuntos conjuntoB;
    for (auto i = conjuntoB.conteudo.begin(); i != conjuntoB.conteudo.end(); i++)
        if (!conjuntoA.pertinencia(*i)) {
        	conjuntoB.conteudo.erase(*i); 
        }
    return conjuntoB;
}

Conjuntos Conjuntos::intercessao(const Conjuntos & conjuntoA) const {
    Conjuntos conjuntoB;
    for (auto i = conjuntoB.conteudo.begin(); i != conjuntoB.conteudo.end(); i++)
        if (conjuntoA.pertinencia(*i)) {
        	conjuntoB.conteudo.insert(*i); 
        }
    return conjuntoB;
}