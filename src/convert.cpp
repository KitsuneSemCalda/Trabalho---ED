#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

bool Maisculo(char aux){
    if (aux >= 'A' and aux <= 'Z'){
        return true;
    }
    return false;
}

string auxTreatment(string aux){
    unsigned long tamAux = aux.size();

    for (unsigned long i = 0; i < tamAux; i++){
        if (aux[i] == ','){
            aux[i] = ';';
        }

        if ((aux[i] == ' ') and (aux[(i + 1)] == ' ')){
            aux[i] = aux[(i - 1)];
        }
        
        if ((aux[i] == ' ') and (aux[(i + 1)]) == Maisculo(aux[(i + 1)])){
            aux[i] = '\n';
        }
    }
    
    aux = (aux + '\n');

    return aux;
}

void kitwrite(string aux){
   /* ofstream arquivoSaida("saida.bin", ios::in| ios::out| ios::binary | ios::app); */
    ofstream arquivoSaida("saida.txt", ios::in | ios::out | ios::app);
    if (arquivoSaida){
        //arquivoSaida.write((aux.c_str()),sizeof(aux));
        arquivoSaida << auxTreatment(aux);
    }
    arquivoSaida.close();
}


void dd_csv2bin(){
    string aux;
    
    ifstream arquivoLeitura("preparatorio2.csv");

    if (arquivoLeitura){
        while (getline(arquivoLeitura, aux)){
            if ((aux[0] >= 'A') and (aux[0] <= 'Z')){
                kitwrite(aux);
            }
        }
        arquivoLeitura.close();
    }
}

int main(){
    dd_csv2bin();
    return 0;
}
