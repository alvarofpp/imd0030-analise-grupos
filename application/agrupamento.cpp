#include <fstream>

#include <iostream>
using std::cin;

#include <cassert>

#include "dataframe.h"
#include "conjuntos.h"

using std::ifstream;

int main(int argc, char const *argv[]) {

	Dataframe dataframe;
	Conjuntos A, B, C;
  vector<double> I1 = {1.0,2.2,3.5,4.1,5.9};
  vector<double> I2 = {1.3,2.3,3.3,42.1,5.9};
  vector<double> I3 = {4.3,7.3,8.3,24.1,9.9};

	string arquivo = "input/a.csv";
	dataframe.abrirArquivo(arquivo, dataframe);
	cout << dataframe;

	dataframe.persistencia("output", dataframe);

	std::cout << "Testando a função de inserção no conjunto..." << std::endl;
	A.inserir(I1);
  B.inserir(I1);
  assert(A.comparar(B) == 1);
  A.inserir(I2);
  B.inserir(I3);
  assert(A.comparar(B) == 0);
  A.inserir(I3);
  B.inserir(I2);
  assert(A.comparar(B) == 1);
  std::cout << "Testando a função de remoção no conjunto..." << std::endl;
  A.remover(I1);
  B.remover(I1);
  assert(A.comparar(B) == 1);
  A.remover(I2);
  B.remover(I3);
  assert(A.comparar(B) == 0);
  A.remover(I3);
  B.remover(I2);
  assert(A.comparar(B) == 1);



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
