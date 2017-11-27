# Projeto 3 - Análise de Agrupamentos

**Instituição**: Universidade Federal do Rio Grande do Norte (UFRN)
**Disciplina**:  Linguagem De Programação I (IMD0029) - T04
**Professor**:  Leonardo Cesar Teonacio Bezerra
**Integrantes**:
* Anne -- 20150128135 
* Álvaro -- 2016039162 
* Ian -- 2015033389 
* Isaac -- 2016035065 
* Jessiely -- 2016038568 

# Classe "AlgoritmoHierarquico"
```cpp
std::vector<double> test = { 2, 4, 6.3, 9, 11.6 };
clt::AlgoritmoHierarquico cluster = clt::AlgoritmoHierarquico( test );
cluster.hierarchical_algorithm(3);
```
No exemplo acima, esperasse que os valores resultantes sejam: **7.475**, **4.65** e **10.3**, nessa mesma ordem.