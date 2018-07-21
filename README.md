# Projeto 3 - Análise de Agrupamentos

**Instituição**: Universidade Federal do Rio Grande do Norte (UFRN)

**Disciplina**:  Linguagem De Programação I (IMD0030) - T04

**Professor**:  Leonardo Cesar Teonacio Bezerra

**Integrantes**:
- <a href="https://github.com/alvarofpp">Anne Ílary de Moraes Gomes</a>
  - Matrícula: 20150128135
  - E-mail: ilarymoraes@hotmail.com
- <a href="https://github.com/alvarofpp">Álvaro Ferreira Pires de Paiva</a>
  - Matrícula: 2016039162
  - E-mail: alvarofepipa@gmail.com
- <a href="https://github.com/alvarofpp">Ian Honorato Pereira</a>
  - Matrícula: 2015033389
  - E-mail: ian.0603@hotmail.com
- <a href="https://github.com/alvarofpp">Isaac Kennedy Diniz Gomes</a>
  - Matrícula: 2016035065
  - E-mail: isaac_kennedy@hotmail.com
- <a href="https://github.com/alvarofpp">Jessiely Oliveira Costa</a>
  - Matrícula: 2016038568
  - E-mail: jessiely@imd.ufrn.br

# Classe "AlgoritmoHierarquico"

```cpp
std::vector<double> test = { 2, 4, 6.3, 9, 11.6 };
clt::AlgoritmoHierarquico cluster = clt::AlgoritmoHierarquico( test );
cluster.hierarchical_algorithm(3);
```

No exemplo acima, esperasse que os valores resultantes sejam: **7.475**, **4.65** e **10.3**, nessa mesma ordem.
