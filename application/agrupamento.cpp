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

	cout << "Testando a função de inserção no conjunto..." << endl;
	A.inserir(I1);
  B.inserir(I1);
  assert(A.comparar(B) == true);
  A.inserir(I2);
  B.inserir(I3);
  assert(A.comparar(B) == false);
  A.inserir(I3);
  B.inserir(I2);
  assert(A.comparar(B) == true);
  cout << "Testando a função de remoção no conjunto..." << endl;
  A.remover(I1);
  B.remover(I1);
  assert(A.comparar(B) == true);
  A.remover(I2);
  B.remover(I3);
  assert(A.comparar(B) == false);
  A.remover(I3);
  B.remover(I2);
  assert(A.comparar(B) == true);
	cout << "Testando a função de pertinência no conjunto..." << endl;
  A.remover(I2);
  A.remover(I3);
  A.inserir(I1);
  assert(A.pertinencia(I1) == true);
  assert(A.pertinencia(I2) == false);
  assert(A.pertinencia(I3) == false);
  A.inserir(I2);
  assert(A.pertinencia(I1) == true);
  assert(A.pertinencia(I2) == true);
  assert(A.pertinencia(I3) == false);
  A.inserir(I3);
  assert(A.pertinencia(I1) == true);
  assert(A.pertinencia(I2) == true);
  assert(A.pertinencia(I3) == true);
  cout << "Testando a função de união de conjuntos..." << endl;
  A.remover(I1);
  A.remover(I2);
  A.remover(I3);
  A.inserir(I1);
  A.inserir(I2);
  B.inserir(I1);
  B.inserir(I3);
  C.inserir(I1);
  C.inserir(I2);
  C.inserir(I3);
  Conjuntos D = A.uniao(B);
  assert(D.comparar(C) == true);
  D.remover(I3);
  assert(D.comparar(C) == false);
  C.remover(I3);
  assert(D.comparar(C) == true);
  cout << "Testando a função de intersecção de conjuntos..." << endl;
  C.remover(I2);
  C.inserir(I3);
  Conjuntos F = A.intercessao(B);
  //Conferir daqui para baixo
  assert(F.comparar(C) == true);
  cout << "Testando a função de diferença de conjuntos..." << endl;
  A.inserir(I3);
  B.remover(I1);
  Conjuntos E = A.diferenca(B);
  assert(E.comparar(C) == true);
  E.remover(I1);
  assert(E.comparar(C) == false);
  C.remover(I1);
  assert(E.comparar(C) == true);


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
