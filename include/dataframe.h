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
    vector< vector<double> > elementos;
    char separador = ',';
    bool status;
public:
  friend istream & operator>>(istream &, Dataframe &);
  friend ostream & operator<<(ostream &, const Dataframe &);
  void abrirArquivo(string &, Dataframe &);
  void ler (istream &, Dataframe &, const char &) const;
  void imprimir(ostream &, const Dataframe &, const char &) const;
  void persistencia(const string &, const Dataframe &) const;

};

#endif
