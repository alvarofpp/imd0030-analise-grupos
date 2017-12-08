/**
 *  @file   dataframe.h 
 *  @brief  Definição do dataframe
 *  @author Jessiely Oliveira (jessiely@imd.ufrn.br)
 *  @author Anne Moraes (ilarymoraes@hotmail.com) 
 *  @since  05.12.2017
 *  @data   07.12.2017
 */

#ifndef DATAFRAME_H
#define DATAFRAME_H

#include <vector>
using std::vector;

#include <set>
using std::set;

#include <iterator>

#include <iostream>
using std::ostream;
using std::endl;
using std::istream;
using std::cout;

#include <string>
using std::string;

#include <sstream>
using std::istringstream;

#include <fstream>
using std::ifstream;
using std::ofstream;

class Dataframe {
private:
    char separador = ',';
    bool status;
public:
  vector< vector<double> > elementos;
  friend istream & operator>>(istream &, Dataframe &);
  friend ostream & operator<<(ostream &, const Dataframe &);
  void abrirArquivo(string &, Dataframe &);
  void ler (istream &, Dataframe &, const char &) const;
  void imprimir(ostream &, const Dataframe &, const char &) const;
  void persistencia(const string &, const Dataframe &) const;
  //Dados geraDados(Dataframe dataset);
  size_t tamanho() const;
  vector< vector<double> >::iterator begin();
  vector< vector<double> >::iterator end();
};

#endif
