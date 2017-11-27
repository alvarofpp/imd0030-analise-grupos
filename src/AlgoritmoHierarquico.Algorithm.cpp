#include "algoritmo_hierarquico.h"

#include <math.h>
// fabs

#include <stack>
using std::stack;

#include <iostream>
using std::cout;
using std::endl;

/*
* @func
*  Essa função realiza o 'Algoritmo de Hierárquico'.
* @param
*  size_t k : Quantidade de valores que servirão para dividir o conjunto em k grupos/subconjuntos.
*/
void clt::AlgoritmoHierarquico::hierarchical_algorithm( size_t k ) {
	stack<double> distances; // Pilha de distâncias que dividirão o conjunto
	vector<double> newVetor; // Variável que servirá para armazenar o novo vetor de valores usados
	size_t r, c;             // Indices dos valores que será cálculado a média
	double media;            // Variável que armazenará a média entre dois valores ('r' e 'c')
	bool troca = false;      // Variáveis que informará se já ouve troca de valores ou não

	// Quando mSize == 1, então a matriz de distâncias chegará a uma matriz nula de dimensão 1
	while (mSize > 1) {
		// Encontro a menor distância e pego a média entre os valores envolvidos
		find_shorter_distance(r, c);
		media = (mData[r] + mData[c])/2;
		// Limpo o vetor de novos valores e adiciono os novos valores, substituindo 'r' e 'c' por 'media'
		newVetor.clear();
		for (size_t i = 0; i < mSize; i++) {
			if ((i != r) && (i != c)) {
				newVetor.push_back(mData[i]);
			} else if (!troca) {
				distances.push(media);
				newVetor.push_back(media);
				troca = true;
			}
		}
		// Atualizo os valores envolvidos no processo
		troca = false;
		mData = newVetor;
		mSize = newVetor.size();
		distances_matrix();
	}

	// Imprimo os valores que servirão para dividir o conjunto, respeitar a ordem que são mostrados
	size_t size = distances.size()-1;
	cout << "(" << distances.size() << ") Stack: " << endl;
	for (size_t i = size; i > (size-k); i--) {
		cout << distances.top() << endl;
		distances.pop();
	}
}

/*
* @func
*  Essa função cálcula a distância entre os pontos envolvidos, gerando uma matriz triângular inferior
*  de diagonal principal nula.
*/
void clt::AlgoritmoHierarquico::distances_matrix () {
	vector< vector<double> > newDistance(mSize); // Matriz usada para armazenar os novos valores 

	size_t diagonal = 0; // Variável que dirá o tamanho da linha
	for (size_t i = 0; i < mSize; i++) {
		// Atualiza o tamanho da linha
		newDistance[i].resize( ++diagonal );

		for (size_t j = 0; j <= i; j++) {
			// Verifica se está analisando a distância do valor com ele mesmo
			if (j == i) {
				// Diagonal principal
				newDistance[i][j] = 0.0;
			} else {
				// Valor absoluto |mData[j] - mData[i]|
				newDistance[i][j] = fabs(mData[j] - mData[i]);
			}
		}
	}
	// Atualiza a matriz de distância
	mDistance = newDistance;
}

/*
* @func
*  Encontrar a menor distância na matriz de distâncias entre os pontos.
* @param
*  size_t& r : Indices dos valores que possuem a menor distância entre eles.
*  size_t& c : Indices dos valores que possuem a menor distância entre eles.
*/
void clt::AlgoritmoHierarquico::find_shorter_distance ( size_t& r, size_t& c ) {
	size_t row = 0, col = 0;

	for (size_t i = 0; i < mSize; i++) {
		for (size_t j = 0; j < i; j++) {
			if ((mDistance[row][col] == 0.0) || (mDistance[row][col] > mDistance[i][j])) {
				row = i;
				col = j;
			}
		}
	}
	// Atualiza os indices da menor distância
	r = row;
	c = col;
}