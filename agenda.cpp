#include <iostream>
#include "mes.hpp"

using namespace std;

int main(){

  /* Inicializa o objeto Meses inserindo os 12 meses do ano que
    serão armazenados na tad */
  Mes Meses;
  Meses.insere("Janeiro");
  Meses.insere("Fevereiro");
  Meses.insere("Março");
  Meses.insere("Abril");
  Meses.insere("Maio");
  Meses.insere("Junho");
  Meses.insere("Julho");
  Meses.insere("Agosto");
  Meses.insere("Setembro");
  Meses.insere("Outubro");
  Meses.insere("Novembro");
  Meses.insere("Dezembro");

  while(true){ // para o usuário não ter que abrir o pograma toda hora para
               // executar mais de uma opcao

    cout << "AGENDA DE COMPROMISSOS" << endl;
    cout << "Escolha uma opção:" << endl;
    cout << "1 - Inserir compromisso" << endl;
    cout << "2 - Remover compromisso" << endl;
    cout << "3 - Lista de compromissos" << endl;
    cout << "4 - Consultar por dia e hora" << endl;

    int opcao;
    cin >> opcao;
    cin.clear();

    //Valida a opcao inserida pelo usuario
    if(opcao<1 || opcao>4) {
      cout << endl << "Opção inválida!" << endl << endl;
      continue;
    }


    else if(opcao==1){
      cout << "[INSERIR NOVO COMPROMISSO]" << endl;
      string mes,hora,compromisso;
      int dia;

      cin.ignore(); //Ignora o \n do stream
      cout << "Insira o mês (com letra maiúscula na primeira letra apenas): ";
      getline(cin,mes);

      cout << "Insira o dia: ";
      cin >> dia;

      cin.ignore();
      cout << "Insira a hora [formato: hh:mm]: ";
      getline(cin,hora);


      cout << "Insira o compromisso: ";
      getline(cin,compromisso);

      cout << endl;

      //logica de curto-circuito....
      if((dia>=1 && dia<=31) && Meses.insere_compromisso(mes, dia, hora, compromisso)){
        cout << "Compromisso inserido com sucesso!!" << endl << endl;
      }
      else {
        cout << "O mês ou o dia inserido (é)são inválido(s)! O compromisso não foi inserido." << endl <<  endl;
      }
    }

    //remove um compromisso
    else if(opcao==2){
      cout << "[REMOVER COMPROMISSO]" << endl;
      string mes,hora;
      int dia;

      cin.ignore(); //Ignora o \n do stream
      cout << "Insira o mês (com letra maiúscula na primeira letra apenas): ";
      getline(cin,mes);

      cout << "Insira o dia: ";
      cin >> dia;

      cin.ignore();
      cout << "Insira a hora [formato: hh:mm]: ";
      getline(cin,hora);

      cout << endl;
      if(!Meses.busca_compromisso(mes, dia, hora, true)){
        cout << "Não há nenhum compromisso nessa data/horário! Portanto, nenhum compromisso foi removido! " << endl;
      }
      cout << endl;
    }

    //imprime os compromissos
    else if(opcao==3){
      cout << "[LISTA DE COMPROMISSOS]" << endl;
      Meses.imprime();
      cout << endl;
    }

    //faz a consulta por dia e hora
    else if(opcao==4){
      cout << "[BUSCAR COMPROMISSO]" << endl;
      string mes,hora;
      int dia;

      cin.ignore(); //Ignora o \n do stream
      cout << "Insira o mês (com letra maiúscula na primeira letra apenas): ";
      getline(cin,mes);

      cout << "Insira o dia: ";
      cin >> dia;

      cin.ignore();
      cout << "Insira a hora [formato: hh:mm]: ";
      getline(cin,hora);

      cout << endl;
      if(!Meses.busca_compromisso(mes, dia, hora)){
        cout << "Não há nenhum compromisso nessa data/horário! " << endl;
      }
      cout << endl;
    }

  }
  return 0;
}
