// Nome: Arthur Augusto Magalhães - 202110830
// Nome: Aaron Martins Leão Ferreira - 202120496 
// Nome: Wildes Augusto de Sousa  - 202020602

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

// Define Function to readfile 

void read_csv(){
  ofstream readFile("preparatorio2.csv");

  if (readFile){
    cout << "[OK] Arquivo encontrado com sucesso" << endl;
  } else {
    cout << "[FAILED] Arquivo não encontrado" << endl;
  }

}

int main(){
  read_csv();
}
