#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;


void dd_csv2bin(){
    string aux;
    ifstream arquivoLeitura("preparatorio2.csv");
    if (arquivoLeitura){
        while (getline(arquivoLeitura >> ws, aux)){
        }
    }
}

int main(){
    dd_csv2bin();
    return 0;
};
