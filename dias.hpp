#include "compromissos.hpp"

struct Dias {
  Compromissos** compromissos_d; //array de ponteiros para compromissos
  int tamanho;
  int compromissos;
  Dias(int n);
  ~Dias();
  void insere_compromisso(int dia, string hora, string compromisso);
  bool busca_compromisso(int dia, string hora, bool remover);
  void imprime();
};
