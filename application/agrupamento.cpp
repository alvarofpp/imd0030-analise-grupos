#include <fstream>
using std::ifstream;

#include "dados.h"

int main(int argc, char const *argv[]) {

	Dados dados;

	ifstream in("input/iris.csv");
	cout << "--- Lendo arquivo de entrada ---" << endl;
	if(!in.is_open()) {
		cout << "Arquivo de entrada não pode ser aberto!" << endl;
	} else {
		in >> dados;
		cout << "Arquivo lido!" << endl;
	}

	cout << dados;
	
	return EXIT_SUCCESS;
}