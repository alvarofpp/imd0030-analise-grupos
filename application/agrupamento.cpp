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
  vector<double> in1 = {0.8,5.2,3.5,7.5,5.9};
  vector<double> in2 = {1.3,2.3,3.3,42.1,5.9};
  vector<double> in3 = {6.3,7.3,7.5,24.1,9.9};

	string arquivo = "input/a.csv";
	dataframe.abrirArquivo(arquivo, dataframe);
	cout << dataframe;

	dataframe.persistencia("output", dataframe);

	cout << "----  Testando Inserção no conjunto ----" << endl;
	A.inserir(in1);
  B.inserir(in1);
  assert(A.comparar(B) == true);
  A.inserir(in2);
  B.inserir(in3);
  assert(A.comparar(B) == false);
  A.inserir(in3);
  B.inserir(in2);
  assert(A.comparar(B) == true);
  
  cout << "---  Testando Remoção no conjunto ---" << endl;
  A.remover(in1);
  B.remover(in1);
  assert(A.comparar(B) == true);
  A.remover(in2);
  B.remover(in3);
  assert(A.comparar(B) == false);
  A.remover(in3);
  B.remover(in2);
  assert(A.comparar(B) == true);

	cout << "---  Testando Pertinência no conjunto ---" << endl;
  A.remover(in2);
  A.remover(in3);
  A.inserir(in1);
  assert(A.pertinencia(in1) == true);
  assert(A.pertinencia(in2) == false);
  assert(A.pertinencia(in3) == false);
  A.inserir(in2);
  assert(A.pertinencia(in1) == true);
  assert(A.pertinencia(in2) == true);
  assert(A.pertinencia(in3) == false);
  A.inserir(in3);
  assert(A.pertinencia(in1) == true);
  assert(A.pertinencia(in2) == true);
  assert(A.pertinencia(in3) == true);

  cout << "---  Testando União de conjuntos ---" << endl;
  A.remover(in1);
  A.remover(in2);
  A.remover(in3);
  A.inserir(in1);
  A.inserir(in2);
  B.inserir(in1);
  B.inserir(in3);
  C.inserir(in1);
  C.inserir(in2);
  C.inserir(in3);
  Conjuntos D = A.uniao(B);
  assert(D.comparar(C) == true);
  D.remover(in3);
  assert(D.comparar(C) == false);
  C.remover(in3);
  assert(D.comparar(C) == true);
  
  cout << "---  Testando Diferença de conjuntos ---" << endl;
  A.inserir(in3);
  B.remover(in1);
  Conjuntos E = A.diferenca(B);
  assert(E.comparar(C) == true);
  E.remover(in1);
  assert(E.comparar(C) == false);
  C.remover(in1);
  assert(E.comparar(C) == true);

  cout << "---  Testando Intersecção de conjuntos ---" << endl;
  C.remover(in2);
  C.inserir(in3);
  Conjuntos F = A.intersecao(B);
  assert(F.comparar(C) == true);

	return EXIT_SUCCESS;
}
