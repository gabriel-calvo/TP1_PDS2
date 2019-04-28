#include <iostream>

using std::string;

struct compromissos_t {
  string hora;
  string compromisso;
  compromissos_t *proximo;
};

struct Compromissos {
  compromissos_t *inicio;
  compromissos_t *fim;
  int compromissos_num;
  Compromissos();
  ~Compromissos();
  void insere(string hora, string compromisso);
  bool busca(string hora, bool remover=false);
  void imprime();
};
