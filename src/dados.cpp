/**
 *	@file		dados.cpp	
 *	@brief	Implementãção das funções auxiliares
 *	@author	Jessiely Oliveira (jessiely@imd.ufrn.br)
 *      @author Anne Moraes (ilarymoraes@hotmail.com) 
 *	@author	Isaac Kennedy (isaac_kennedy@hotmail.com)
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

/*
 * @brief Insere o elemento 
 */

void Dados::inserir(vector<double> & elemento) {
	informacoes.insert(elemento);
}

/*
 * @brief Remove o elemento 
 */

void Dados::remover(vector<double> & elemento) {
	informacoes.erase(elemento);
}

/*
 * @brief Faz a união dos conjuntos
 * @details Insere no conjuntoB os elementos do conjuntoA 
 */

Dados Dados::uniao(const Dados & conjuntoA) const {
	Dados conjuntoB;
	conjuntoB.informacoes.insert(conjuntoA.elementos.begin(), conjuntoA.elementos.end());
	conjuntoB.informacoes.insert(elementos.begin(), elementos.end());
	return conjuntoB;
}

/*
 * @brief Verifica se determinado elemento está no conjunto 
 */

bool Dados::pertinencia (const vector<double> & elemento) const {
    return informacoes.find(elemento) != elementos.end();
}

/*
 * @brief Verifica os elementos diferentes entre o conbjuntoA e conjuntoB 
 * @details Elimina essas diferenças do conjuntoB 
 */
Dados Dados::diferenca(const Dados & conjuntoA) const {
    Dados conjuntoB;
    conjuntoB.informacoes.insert(informacoes.begin(), informacoes.end());
    for (auto i = conjuntoA.informacoes.begin(); i != conjuntoA.informacoes.end(); i++) {
        conjuntoB.informacoes.erase(*i); 
    }
    return conjuntoB;
}

/*
 * @brief Verifica os elementos em comum dos conjuntos
 * @details 
 */

Dados Dados::intersecao(const Dados & conjuntoA) const {
    Dados conjuntoB;
    for (auto i = conjuntoA.informacoes.begin(); i != conjuntoA.informacoes.end(); i++)
        if (conjuntoA.pertinencia(*i)) {
        	conjuntoB.informacoes.insert(*i); 
        }
    return conjuntoB;
}

/*
 * @brief  
 * @details 
 */

bool Dados::comparar(const Dados & conjunto) {
  for(auto i = conjunto.informacoes.begin(); i != conjunto.informacoes.end(); i++) {
    if (informacoes.find(*i) == informacoes.end()) {
    	return false;
    }
  }
  return true;
}

set<int>::iterator Dados::begin() {
	return informacoes.begin();
}

set<int>::iterator Dados::end() {
	return informacoes.end();
}
