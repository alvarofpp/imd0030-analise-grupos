#include <fstream>

#include <iostream>
using std::cin;

#include "dados.h"
#include "conjuntos.h"

using std::ifstream;

int main(int argc, char const *argv[]) {

	vector <float> I1 = {1.0,2.2,3.5,4.1,5.9};
  vector <float> I2 = {1.3,2.3,3.3,42.1,5.9};
	Conjuntos conjuntoA, conjuntoB;

	/*if(argc != 2) {
		cout << "Insira arquivo .csv de entrada como argumento de linha de comando!" << endl;
		return EXIT_FAILURE;
	}

	string file = argv[1];
	ifstream in(file);
	if(!in.is_open()) {
		cout << "Arquivo de entrada não pode ser aberto!" << endl;
	} else {
		cout << "--- Lendo arquivo de entrada \"" << file << "\" ---" << endl;
		in >> conjuntoA;
	}

	cout << conjuntoA;*/





	
	return EXIT_SUCCESS;
}
