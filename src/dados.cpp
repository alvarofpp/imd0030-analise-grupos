#include "dados.h"

Dados::Dados() {}
Dados::~Dados() {}

istream & operator>>(istream & in, Dados & dados) {
	string linha, aux;
	getline(in, linha);
	istringstream buffer(linha);
	while(getline(buffer, aux, ',')) {
		dados.informacoes.push_back(stod(aux));
	}
	return in;
}

ostream & operator<<(ostream & out, const Dados & dados) {
	for(size_t i = 0; i < dados.tamanho(); i++) {
		out << dados.informacoes[i];
		if(i+1 == dados.tamanho()) {
			out << "";
		} else {
			out << ",";
		}
	}
	out << endl;
	return out;
}

size_t Dados::tamanho() const {
	return informacoes.size();
}

