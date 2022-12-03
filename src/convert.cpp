#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

bool Numero(char aux){
    if (aux >= '0' and aux <= '9'){
        return true;
    }
    return false;
}

bool Maisculo(char aux){
    if (aux >= 'A' and aux <= 'Z'){
        return true;
    }
    return false;
}

string auxTreatment(string aux){
    unsigned long tamAux = aux.size();
    
    unsigned long counter = tamAux * 2;
    unsigned long i = 0;
    do{
               
        if (aux[i] == ';' and aux[(i + 1)] == Maisculo(aux[(i + 1)])){
            aux[i] = '\n';
        }

        if (aux[i] == ','){
            aux[i] = ';';
        }

        if ((aux[i] == ' ') and (aux[(i + 1)] == ' ')){
            aux[i] = aux[(i - 1)];
        }

        if ((aux[i] == ' ') and (aux[(i + 1)]) == ' ' and (aux[(i + 2)]) == ' '){
            aux[i] = aux[(i + 1)];
            aux[(i + 1)] = aux[(i + 2)];
        }

        if ((aux[i]) == Numero(aux[i]) and aux[(i + 1)] == ' '){
            aux[(i + 1)] = '\n';
        }

        i++;
        counter --;

        if ( i == tamAux){
            i = 0;
        }

    }while(counter > 0);
    
    aux = (aux + '\n');
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
