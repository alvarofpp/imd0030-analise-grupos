#include "algoritmo_hierarquico.h"

#include <iomanip>
using std::left;
using std::setw;
using std::setfill;

#include <iostream>
using std::cout;
using std::endl;

/*
* @func
*  Imprime o estado atual do objeto.
*/
void clt::AlgoritmoHierarquico::current_state ()
{
	cout << "---------------------------------------------------" << endl;
	cout << "Data: ";
	print_data();
	cout << " - " << mData.size() << " values." << endl;
	cout << "Matrix: " << endl;
	print_distance();
	cout << "---------------------------------------------------" << endl;
}

/*
* @func
*  Imprime os pontos envolvidos.
*/
void clt::AlgoritmoHierarquico::print_data ()
{
	cout << "[ ";
	for (size_t i = 0; i < mSize; i++) {
		cout << mData[i] << " ";
	}
	cout << "]";
}

/*
* @func
*  Imprime a matriz de distância.
*/
void clt::AlgoritmoHierarquico::print_distance ()
{
	const char separator = ' ';
	const int numWidth = 6;

	for (size_t i = 0; i < mSize; i++) {
		cout << "[ ";
		for (size_t j = 0; j <= i; j++) {
			cout << left << setw(numWidth) << setfill(separator) << mDistance[i][j];
		}
		cout << "]" << endl;
	}
}