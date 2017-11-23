#ifndef CONJUNTOS_H
#define CONJUNTOS_H

#include <set>
using std::set;

#include <unordered_set>
using std::unordered_set;

#include "dados.h"

class Conjuntos {
private:
	unordered_set<Dados> conteudo;
public:
	Conjuntos();
	~Conjuntos();

	friend istream & operator>>(istream &, Conjuntos &);
	
};

#endif