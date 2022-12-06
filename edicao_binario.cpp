  #include "cstring"
#include "iostream"
#include "fstream"

using namespace std;

//função para ler o arquivo binário

void imprimir(){
    ifstream arquivo ("saida.bin", ios::binary| ios::in|ios::out);
    
    char* aux;
    aux = new char[arquivo.tellg()];
    
    bool fim = arquivo.eof();

    if (arquivo){
        while (fim == false){
            arquivo.read(aux, sizeof(aux));
            if (strcmp(aux, ";")){
                cout << aux << " ";
            }else{
                cout << endl;
            }
            fim = arquivo.eof();
        }
    }
};

//função responsável pelo menu do programa

void Menu() {
    int option = 0;
    while (option != 6) {
	    cout << "Digite um Número de 1 a 6."<< endl;
	    cout << "Opção 1: Adicionar um elemento."<< endl;
	    cout << "Opção 2: Ver registros entre x e y."<< endl;
	    cout << "Opção 3: Alterar dados de um Registro."<< endl;
	    cout << "Opção 4: Trocar dois registros de posição."<< endl;
	    cout << "Opção 5: Imprimir todos os registros ."<< endl;
        cout << "Opção 6: Sair do programa ." << endl;
        
        cin>>option;
        
        switch(option){
            case 1:
            //adicionarElemento();  
            break;
	        
            case 2:
            //verEntre();  
            break;
        
            case 3:
            //alterarDados();  
            break;
        
            case 4:
            //trocarReg();  
            break;
        
            case 5:
            imprimir();  
            break; 
        }
    }
}


int main(){
    Menu();
    return 0;
}

