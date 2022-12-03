#include "cstring"
#include "iostream"
#include "fstream"

using namespace std;

void imprimir(string aux){
    ofstream arquivoSaida("saida.txt", ios::in| ios::out| ios::binary | ios::app);
    if (arquivoSaida){
        arquivoSaida.read((aux.c_str()),sizeof(aux));
        
    }
    arquivoSaida.close();
}

void Menu() {
  int option = 0;
  while (option != 5) {
	  cout << "Digite um Número de 1 a 5."<< endl;
	  cout << "Opção 1: Adicionar um elemento."<< endl;
	  cout << "Opção 2: Ver registros entre x e y."<< endl;
	  cout << "Opção 3: Alterar dados de um Registro."<< endl;
	  cout << "Opção 4: Trocar dois registros de posição."<< endl;
	  cout << "Opção 5: Imprimir todos os registros ."<< endl;
  
  cin>>option;
  switch(option){
	  case 1

}
}
int main(){
    
    
    
    return 0;
}

