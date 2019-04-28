#include "dias.hpp"

struct mes_t {
  string nome;
  Dias* dias_mes;
  mes_t* proximo;
};

struct Mes {
  mes_t *inicio;
  mes_t *fim;
  Mes();
  ~Mes();
  void insere(string mes_name); //insere o elemento no fim da lista
  bool insere_compromisso(string mes_name, int dia, string hora, string compromisso);

  // como para encontrar um compromisso e para remove-lo
  // precisamos das mesmas funcoes e algoritimos (para percorrer as diferentes tad's)
  // optamos por colocar um parametro de remoção ja na funcao de busca
  // para evitar duplicação de código
  bool busca_compromisso(string mes_name, int dia, string hora, bool remover=false);
  void imprime();
};
