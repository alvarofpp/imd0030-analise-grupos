/**
 *  @file   dataframe.cpp 
 *  @brief  Implementação do dataframe
 *  @author Jessiely Oliveira (jessiely@imd.ufrn.br)
 *  @author Anne Moraes (ilarymoraes@hotmail.com)
 *  @author Isaac Kennedy (isaac_kennedy@hotmail.com)
 *  @since  05.12.2017
 *  @data   07.12.2017
 */

#include "dataframe.h"

istream & operator>> (istream & in, Dataframe &dataframe) {
  dataframe.ler(in, dataframe, dataframe.separador);
  return in;
}

ostream & operator<<(ostream & out, const Dataframe & dataframe) {
	dataframe.imprimir(out, dataframe, '	');
	return out;
}

void Dataframe::abrirArquivo(string & arquivo, Dataframe & dataframe) {
	ifstream in(arquivo);
	if(!in.is_open()) {
		cout << "Arquivo de entrada não pode ser aberto!" << endl;
	} else {
		cout << "--- Lendo arquivo de entrada \"" << arquivo << "\"  ---" << endl;
		in >> dataframe;
	}
}

void Dataframe::ler (istream & in, Dataframe & dataframe, const char & separador) const {
	string linhas, campos;
  vector<double> linha;
  size_t tamLinha = 0;

  while(getline (in, linhas)) {
    istringstream buffer(linhas);
    while(!buffer.eof()) {
      getline(buffer, campos, separador);
      linha.push_back(stod(campos));
    }

    if(dataframe.elementos.size() == 0) {
      tamLinha = linha.size();
      dataframe.elementos.push_back(linha);
      linha.clear();
      dataframe.status = true;
    } else if(tamLinha != linha.size()) {
        dataframe.status = false;
    } else {
      dataframe.elementos.push_back(linha);
     	linha.clear();
    }
  }
}

void Dataframe::imprimir(ostream & out, const Dataframe & dataframe, const char & separador) const {
	for(size_t i = 0; i < dataframe.elementos.size(); i++) {
		for(size_t j = 0; j <	dataframe.elementos[i].size(); j++) {
			if(j == dataframe.elementos[i].size() - 1) {
				out << dataframe.elementos[i][j];
			} else {
				out << dataframe.elementos[i][j] << separador;
			}
		}
		out << endl;
	}
}


void Dataframe::persistencia(const string & nomeArquivoSaida, const Dataframe & dataframe) const {
	ofstream arquivoSaida(nomeArquivoSaida + ".csv");
	if(!arquivoSaida.good()) {
		cout << "Arquivo não pôde ser criado!" << endl;
	} else {
		imprimir(arquivoSaida, dataframe, dataframe.separador);
	}
	cout << "Arquivo de saída gerado: " << nomeArquivoSaida << ".csv" << endl;
}

Dados Dataframe::geraDados(Dataframe dataset){
	Dados newDados;
	for (vector<vector<double>>::iterator i = dataset.elementos.end(); i < dataset.elementos.end(); i++){
			newDados.inserir(*i);
	}

	return newDados;
}

size_t Dataframe::tamanho() const {
	return elementos.size();
}