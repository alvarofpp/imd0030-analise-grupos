#ifndef DADOS_H
#define DADOS_H

#include <vector>
using std::vector;

#include <iostream>
using std::istream;
using std::ostream;
using std::endl;
using std::cout;

#include <string>
using std::string;

#include <sstream>
using std::istringstream;

class Dados {
private:
	vector<double> informacoes;
public:
	Dados();
	~Dados();

	friend istream & operator>>(istream &, Dados &);
	friend ostream & operator<<(ostream &, const Dados &);
	size_t tamanho() const;
	
};

#endif