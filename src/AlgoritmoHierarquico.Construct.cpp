#include "algoritmo_hierarquico.h"

/*
* @func
*  Esse construct cria o objeto da classe 'AlgoritmoHierarquico' a partir de um vector<double>.
*/
clt::AlgoritmoHierarquico::AlgoritmoHierarquico( Dados & data ) {
	this->dataSet = data;
	// Tamanho do vetor usado para alimentar
	mSize = dataSet.tamanho();
	//Gera o vetor de coordenadas euclidianas unidimensionais
	mData = calculate_euclidian_vector();
	// Cria a matriz triangular inferior de distância entre os pontos
	distances_matrix();
}

/*
* @func
*  Função responsável por iterar sobre o dataset e gerar um vetor de coordenadas euclidianas, simulando um dataset unidimensional
*/
vector<double> clt::AlgoritmoHierarquico::calculate_euclidian_vector() {
	vector<double> vec;
	vec.resize(dataSet.tamanho());
	int pos = 0;
	for (auto it = dataSet.begin(); it != dataSet.end(); it++) {
		size_t dimensions = (*it).size();
		int sum = 0;
		for (size_t i = 0; i < dimensions; i++) {
			sum += (*it)[i];
		}
		vec[pos] = sqrt(sum);
	}
	
	return vec;
}
