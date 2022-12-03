#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;
/*
class Node{
    friend class Fila;
    private:
        string Nome;
        string Graduacao;
        string DataEntrada;
        string DataSaida;
        float NumeroMatricula;
        float QuantiaGasta;
        Node* next;
    public:
        Node(string rNome, string rGraduacao, string rDataEntrada, string rDataSaida, float rNumeroMatricula, float rQuantiaGasta){
        Nome = rNome;
        Graduacao = rGraduacao;
        DataEntrada = rDataEntrada;
        DataSaida = rDataSaida;
        NumeroMatricula = rNumeroMatricula;
        QuantiaGasta = rQuantiaGasta;
    }
};

class Fila{
    friend class Node;
    private:
        int Tamanho;
        Node* inicio;
        Node* fim;
    public:
        Fila(){
            Tamanho = 0;
            inicio = NULL;
            fim = NULL;
        };

        ~Fila(){
            while(Tamanho > 0){
                desenfileira();
            }
        }
        void enfileira(string Nome, string Graduacao, string DataEntrada, string DataSaida, float NumeroMatricula, float QuantiaGasta){
        Node* novo = new Node(Nome, Graduacao, DataEntrada, DataSaida, NumeroMatricula, QuantiaGasta);

        if (Tamanho == 0){
            inicio = novo;
        }else{
            fim->next = novo;
        }
        novo->next = fim;
        fim = novo;
        Tamanho ++;
        }

        Node desenfileira(){
            Node valor = *inicio;
            Node* temp = inicio;
            inicio = inicio->next;
            delete temp;
            Tamanho --;
            if (Tamanho == 0){
                fim = NULL;
            }
            return valor;
        }
};
*/
string TratamentoAux(string aux){
    return aux;
}

void dd_csv2bin(){
    string aux;
    
    ifstream Arquivoleitura("preparatorio2.csv");
    if (Arquivoleitura){
        while (getline(Arquivoleitura, aux)) {
            cout << aux << endl;
            cout << TratamentoAux(aux) << endl;
        }
    }
}

int main(){
    return 0;
}
