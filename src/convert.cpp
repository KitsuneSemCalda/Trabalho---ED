// Nome: Arthur Augusto Magalhães - 202110830
// Nome: Aaron Martins Leão Ferreira - 202120496 
// Nome: Wildes Augusto de Sousa  - 202020602

#include "iostream"
#include "cstring"
#include "fstream"
#include <string>

using namespace std;

struct Aux {
  char nome[25];
  char graduacao[25];
  char dataentrada[25];
  char datasaida[25];
  float numeroMatricula;
  float quantidadeGasta;
};

void printSucessMessage(string message){
  cout << "[OK] " << message << endl; 
}

void printFailedMessage(string message){
  cout << "[Failed] " << message << endl;
}

void dd_csv2bin(){
  char letra;
  string result;
  
  Aux aux;
  printSucessMessage("estrutura auxiliar inicializada");

  bool nome_estado = true;
  bool graduacao_estado = false;
  bool dataent_estado = false;
  bool datasai_estado = false;
  bool numeroMat_estado = false;
  bool quantidadeGast_estado = false;

  ifstream arquivoTexto("preparatorio2.csv");
  if (arquivoTexto){
    printSucessMessage("arquivo encontrado");
    while (arquivoTexto >> letra){
      if (letra == ';'){
        if(nome_estado){
          nome_estado = false;
          strcpy(aux.nome, result.c_str()) ; 
          graduacao_estado = true;
          continue;
        }
        if (graduacao_estado){
          graduacao_estado = false;
          dataent_estado = true;
          continue;
        }

        if (dataent_estado){
          dataent_estado =  false;
          datasai_estado = true;
          continue;
        }
        
        if (datasai_estado){
          datasai_estado = false;
          numeroMat_estado = false;
          continue;
        }
        
        if (numeroMat_estado){
          numeroMat_estado = false;
          quantidadeGast_estado = true;
        }
        
        if (quantidadeGast_estado){
          quantidadeGast_estado = false;
          nome_estado = true;
        }
      }else{
        result += letra;
        if (result == "campo1" or result == "campo2" or (result == "campo3")) or (result == "campo4") or (result == "campo5)" or (result == "campo6")){
            continue;
          }
        
        if (graduacao_estado){
          strcpy(aux.graduacao, result.c_str());
        }
        if (dataent_estado){
          strcpy(aux.dataentrada, result.c_str());
        }
        if (datasai_estado){
          strcpy(aux.datasaida, result.c_str());
        }
        if (numeroMat_estado){
          aux.numeroMatricula = stof(result);
        }

        if (quantidadeGast_estado){
          aux.quantidadeGasta = stof(result);
        }
      }
    }
  }else{
    printFailedMessage("arquivo não encontrado");
  }
  printSucessMessage("dados populados com sucesso");
  
  ofstream arquivoSaida("saida.dat", ios::binary);

  if (arquivoSaida){
    printSucessMessage("arquivo de saída binaria criado com sucesso");
    arquivoSaida.write(aux.nome, sizeof(aux.nome));
    arquivoSaida.write(aux.graduacao, sizeof(aux.graduacao));
    arquivoSaida.write(aux.dataentrada, sizeof(aux.dataentrada));
    arquivoSaida.write(aux.datasaida, sizeof(aux.datasaida));
    arquivoSaida.write(std::to_string(aux.numeroMatricula).c_str(), sizeof(aux.numeroMatricula));
    arquivoSaida.write(std::to_string(aux.quantidadeGasta).c_str(), sizeof(aux.quantidadeGasta));
    printSucessMessage("Dados escritos com sucesso");
  }else{
    printFailedMessage("arquivo de saída binaria falhou em ser criada");
  }

}

int main(){
  dd_csv2bin();
}
