#include "compromissos.hpp"
#include <iostream>

using namespace std;

Compromissos::Compromissos(){
  inicio = nullptr;
  fim = nullptr;
  compromissos_num = 0;
}

Compromissos::~Compromissos(){
  compromissos_t *anterior = nullptr;
  compromissos_t *proximo = inicio;
  while (proximo != nullptr) {
    anterior = proximo; //para nao perder o endereco ao destruir
    proximo = proximo->proximo;
    delete anterior;
  }
}

void Compromissos::insere(string hora, string compromisso){
  compromissos_t* novo = new compromissos_t; //aloca o objeto
  novo->hora = hora; //inicializa os dados do objeto
  novo->compromisso = compromisso;
  novo->proximo = nullptr;

  if(inicio==nullptr){ //é o primeiro objeto da lista
    inicio = novo;
  }
  else {
    fim->proximo = novo;
  }
  compromissos_num++;
  fim = novo; //sempre sera o ultimo a ser inserido
}

bool Compromissos::busca(string hora, bool remover){
  if(inicio==nullptr) return false; //nao ha elementos na lista
  compromissos_t *proximo = inicio;
  compromissos_t *anterior = inicio;

  int i=0;
  while (proximo != nullptr) { //percorre ate o fim da lista
    if(proximo->hora==hora){
      if(!remover){ //apenas buscando o elemento, entao imprimimos ele
        cout << i << " (" << proximo->hora << ") " << proximo->compromisso << endl;
      }
      else { //solicitacao para remover o elemento

        // nao tratamos a situacao onde o compromisso é o unico da lista, pois
        // ela ja é tratada na implemetancao da entidade Dias

        if(proximo==inicio){ //primeiro elemento da lista
          inicio = proximo->proximo;
          delete proximo;
        }
        else { //nao é o primeiro elemetno da lista
          anterior->proximo = proximo->proximo;
          delete proximo;
        }
        cout << "O compromisso FOI REMOVIDO com sucesso!" << endl;

        compromissos_num--;
      }
      return true;
    }

    if(i>=1){ // o cursor do elemento anterior começa a ser incrementado
              // apos o cursor proximo ja ter iniciado, mantendo-se sempre no anterior
      anterior = anterior->proximo;
    }
    proximo = proximo->proximo;

    i++;
  }
  return false;
}

void Compromissos::imprime(){
  if(inicio==nullptr) return; //não há compromissos
  compromissos_t *proximo = inicio;
  int i=0;
  while (proximo != nullptr) { //percorre todos compromissos ate chegar ao fim da lista
    cout << "(" << proximo->hora << ") " << proximo->compromisso << endl;
    proximo = proximo->proximo;
    i++;
  }
}
