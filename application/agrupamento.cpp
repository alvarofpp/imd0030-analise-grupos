#include <fstream>

#include "dados.h"
#include "conjuntos.h"

using std::ifstream;

int main(int argc, char const *argv[]) {

	Conjuntos conjunto;

	if(argc != 2) {
		cout << "Insira arquivo .csv de entrada como argumento de linha de comando!" << endl;
		return EXIT_FAILURE;
	}

	string file = argv[1];
	ifstream in(file);
	if(!in.is_open()) {
		cout << "Arquivo de entrada não pode ser aberto!" << endl;
	} else {
		cout << "--- Lendo arquivo de entrada \"" << file << "\" ---" << endl;
		in >> conjunto;
	}

	cout << conjunto;
	
	return EXIT_SUCCESS;
}
