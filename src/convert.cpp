#include "cstring"
#include "iostream"
#include "fstream"

using namespace std;

void kitwrite(string aux){
    ofstream arquivoSaida("saida.bin", ios::in| ios::out| ios::binary | ios::app);
    if (arquivoSaida){
        arquivoSaida.write((aux.c_str()),sizeof(aux));
        
    }
    arquivoSaida.close();
}


void dd_csv2bin(){
    string aux;
    
    ifstream arquivoLeitura("preparatorio2.csv");

    if (arquivoLeitura){
        
        while (arquivoLeitura >> aux){
            kitwrite(aux);
        };
        
        arquivoLeitura.close();
    }
}

int main(){
    dd_csv2bin();
    return 0;
}
