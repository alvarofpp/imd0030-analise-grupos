#include "conjuntos.h"

istream & operator>>(istream & in, Conjuntos & conjunto) {
	while(!in.eof()) {
		Dados dados;
		in >> dados;
		conjunto.insert(dados);
	}
	return in;
}
