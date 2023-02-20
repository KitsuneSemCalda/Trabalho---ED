#include "iostream"
#include "fstream"
#include "auxiliar.hpp"
#include "cstring"
#include "sstream"
#include <string>

using namespace std;

int main(){
  data_auxiliar aux;
  fstream arq_in, arq_out;
  int i;
  string linha, str_list[14], column;

  arq_in.open("property-transfer-statistics-march-2022-quarter-csv.csv", ios::in);
  
  if (!arq_in){
    cout << "Não foi possivel abrir o arquivo de entrada" << endl;
    return 1;
  }

  arq_out.open("saida.bin", ios::in | ios::out | ios::trunc | ios::binary);
  
  if (!arq_out){
    cout << "Não foi possível abrir o arquivo de said" << endl;
    return 1;
  }
  
  getline(arq_in, linha);
  
  // Gerando uma stream a partir da segunda linha do arquivo csv, enquanto o arquivo não chegar ao fim
  // em seguida geramos uma stringstream onde dividimos o s da stream em colunas onde geramos uma str_list[i] 
  // em seguida usamos rw_dados para converter corretamente os dados de aux para poder ser escrito no arquivo binário
  
  while (getline(arq_in, linha) && !arq_in.eof()){
    i = 0;
    stringstream s(linha);
    while (getline(s, column, ',')){
      str_list[i] = column;
      i++;
    }
    rw_dados(str_list, aux);
    arq_out.write(reinterpret_cast<char*>(&aux), sizeof(aux));
  }

  arq_in.close();
  arq_out.close();

  cout << "Arquivo criado com sucesso" << endl;
  return 0;
}
