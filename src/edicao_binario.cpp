#include "cstring"
#include "iostream"
#include "fstream"

using namespace std;



void Menu() {
  int option = 0;
  while (option != 6) {
	  cout << "Digite um Número de 1 a 5."<< endl;
	  cout << "Opção 1: Adicionar um elemento."<< endl;
	  cout << "Opção 2: Ver registros entre x e y."<< endl;
	  cout << "Opção 3: Alterar dados de um Registro."<< endl;
	  cout << "Opção 4: Trocar dois registros de posição."<< endl;
	  cout << "Opção 5: Imprimir todos os registros ."<< endl;
      cout << "Opção 6: Sair do programa ." << endl;
    cin>>option;
    switch(option){
        case 1:
            break;

        }
    }
}

int main(){
    Menu();
    return 0;
}

