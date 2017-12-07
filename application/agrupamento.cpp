#include <fstream>

#include <iostream>
using std::cin;

#include "dataframe.h"

using std::ifstream;

int main(int argc, char const *argv[]) {

	Dataframe dataframe;

	string arquivo = "input/a.csv";
	dataframe.abrirArquivo(arquivo, dataframe);
	cout << dataframe;

	dataframe.persistencia("output", dataframe);

	

	/*string file;
	ifstream in;
	Conjuntos conjuntoA;
	Conjuntos conjuntoB;


	file = "input/a.csv";
	in.open(file);
	if(!in.is_open()) {
		cout << "Arquivo de entrada não pode ser aberto!" << endl;
	} else {
		cout << "--- Lendo arquivo de entrada \"" << file << "\" ---" << endl;
		in >> conjuntoA;
	}
	
	cout << conjuntoA;
	in.close();

	file = "input/b.csv";
	in.open(file);
	if(!in.is_open()) {
		cout << "Arquivo de entrada não pode ser aberto!" << endl;
	} else {
		cout << "--- Lendo arquivo de entrada \"" << file << "\" ---" << endl;
		in >> conjuntoB;
	}

	cout << conjuntoB;
	in.close();


	
	cout << "--- União dos conjuntos ---" << endl;
	Conjuntos conjuntoC = conjuntoA.uniao(conjuntoB);
	cout << conjuntoC;


	Dados d = {1.4};
	cout << "--- Pertinencia dos conjuntos ---" << endl;
	Conjuntos conjuntoD = conjuntoC.uniao(conjuntoA);
	cout << conjuntoD;*/


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
