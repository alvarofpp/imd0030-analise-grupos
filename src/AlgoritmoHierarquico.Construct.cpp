#include "algoritmo_hierarquico.h"

/*
* @func
*  Esse construct cria o objeto da classe 'AlgoritmoHierarquico' a partir de um vector<double>.
*/
clt::AlgoritmoHierarquico::AlgoritmoHierarquico( vector<double> & vetor ) {
	// Tamanho o vetor usado para alimentar
	mSize = vetor.size();
	// Guarda os dados realizando cash
	mData.reserve( mSize );
	for (auto it = vetor.begin(); it < vetor.end(); it++)
		mData.push_back( *it );
	// Cria a matriz triangular inferior de distância entre os pontos
	distances_matrix();
}