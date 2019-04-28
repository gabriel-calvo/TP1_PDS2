#include "mes.hpp"
#include <iostream>

using namespace std;

Mes::Mes(){
  inicio = nullptr;
  fim = nullptr;
}

Mes::~Mes(){
  mes_t *anterior = nullptr;
  mes_t *proximo = inicio;
  while (proximo != nullptr) {
    anterior = proximo;
    proximo = proximo->proximo;
    delete anterior->dias_mes;
    delete anterior;
  }
}

void Mes::insere(string mes_name){
  mes_t* novo = new mes_t;
  novo->nome = mes_name;
  novo->dias_mes = new Dias(31);
  novo->proximo = nullptr;

  if(inicio==nullptr){ // é o primeiro elemento
    inicio = novo;
  }
  else {
    fim->proximo = novo;
  }
  fim = novo; //sempre sera o ultimo
}

bool Mes::insere_compromisso(string mes_name, int dia, string hora, string compromisso){
  mes_t *proximo = inicio;
  while (proximo != nullptr) { //percorre a lista
    if(proximo->nome==mes_name){ //encontra o mes a ser inserido
      proximo->dias_mes->insere_compromisso(dia, hora, compromisso);
      return true;
    }
    proximo = proximo->proximo;
  }
  return false;
}

bool Mes::busca_compromisso(string mes_name, int dia, string hora, bool remover){
  mes_t *proximo = inicio;
  while (proximo != nullptr) {
    if(proximo->nome==mes_name){
      return proximo->dias_mes->busca_compromisso(dia, hora, remover);
    }
    proximo = proximo->proximo;
  }
  return false; //nao ha nenhum mes com o nome solicitado
}

void Mes::imprime(){
  if(inicio==nullptr) return;
  mes_t *proximo = inicio;
  while (proximo != nullptr) { //percorre a lista
    if(proximo->dias_mes->compromissos>0){ //verifica se ha algum compromisso no mes
      cout << "[Mês " << proximo->nome << "]" << endl;
      proximo->dias_mes->imprime();
      cout << endl;
    }
    proximo = proximo->proximo;
  }
}
