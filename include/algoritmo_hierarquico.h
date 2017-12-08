#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include <vector>
using std::vector;

#include <iostream>
using std::size_t;

#include <cmath>

namespace clt
{
	class AlgoritmoHierarquico
	{
		private:
			size_t mSize;
			vector<double> mData; 
			vector<double> cluster_limits;
			vector< vector<double> > mDistance;
			Dados dataSet;
		public:
			/*
			* Constructs and Destructs
			*/
			AlgoritmoHierarquico( Dados & data );
			~AlgoritmoHierarquico() = default;
			/*
			* Display
			*/
			// Imprime o estado atual do objeto
			void current_state();
			/*
			* Algorithm
			*/
			// Realiza o 'Algoritmo Hierárquico'
			void hierarchical_algorithm( size_t k );

		private:
			/*
			* Algorithm
			*/
			// Gera uma matriz de distâncias entre os pontos envolvidos
			void distances_matrix();
			// Encontrar a menor distância na matriz de distâncias
			void find_shorter_distance( size_t& r, size_t& c );
			//Calcula a emulação unidimensional da matriz de dados
			vector<bool> calculate_euclidian_vector();
			/*
			* Display
			*/
			// Imprime os pontos envolvidos
			void print_data();
			// Imprime a matriz de distância
			void print_distance();
	};
}

#endif /* __CLUSTER_H__ */
