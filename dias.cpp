#include "dias.hpp"
#include <iostream>

using namespace std;

Dias::Dias(int n){
  compromissos_d = new Compromissos*[n];
  for(int i=0; i<n; i++){
    compromissos_d[i] = nullptr; //como solicitado na especificação do exercicio.....
  }
  tamanho=n;
  compromissos=0;
}

Dias::~Dias(){
  for(int i=0; i<tamanho; i++){
    delete compromissos_d[i];
  }
  delete []compromissos_d;
}

void Dias::insere_compromisso(int dia, string hora, string compromisso){
  dia--;
  if(dia<0 || dia>30) return;
  if(compromissos_d[dia]==nullptr)  //é o primeiro compromisso dessa data
    compromissos_d[dia] = new Compromissos;
  compromissos_d[dia]->insere(hora, compromisso);
  compromissos++;
}

bool Dias::busca_compromisso(int dia, string hora, bool remover){
  dia--;
  if(dia<0 || dia>30) return false; //como o usuario nunca conseguira inserir dias<0 ou >31,
                                    /// assumimos que uma busca por esses intervalos nao existe
  if(compromissos_d[dia]==nullptr) return false; //nao ha nenhum compromisso nesse dia

  if(remover && compromissos_d[dia]->compromissos_num==1){
    // -> para manter a solicitacao do enunciado do exercicio
    // ("No conjunto de dias, se nao houver compromisso, na entrada deve ser armazenado o apontador nulo")
    // entao caso seja solicitado para remover um compromisso
    // e so haver apenas 1 compromisso no dia especifico, deletamos a tad compromisso e setamos nullptr
    // assumimos tambem que o usuario sempre tentara remover o horario correto do unico elemento!
    delete compromissos_d[dia];
    compromissos_d[dia] = nullptr;
    compromissos--;
    cout << "O compromisso FOI REMOVIDO com sucesso!" << endl;
    return true;
  }

  return compromissos_d[dia]->busca(hora, remover);
}


void Dias::imprime(){
  for(int i=0; i<tamanho; i++){
    if(compromissos_d[i]!=nullptr && compromissos_d[i]->inicio!=nullptr){
      cout << "Dia " << i+1 << endl;
      compromissos_d[i]->imprime();
      cout << endl;
    }
  }
}
