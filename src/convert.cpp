// Arthur Augusto Magalhaes - 202110830
// Wildes Augusto de Sousa  - 202020602
// Aaron Martins Leão Ferreira - 202120496

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

class Node{
    friend class Fila;
    private:
        string String2Write;
        Node* next;
    public:
        Node(string WriteString){
            String2Write = WriteString;
            next = NULL;
        }
};

class Fila{
    private:
        int tamanho;
        Node* inicio;
        Node* fim;

    public:
        Fila(){
            tamanho = 0;
            inicio = NULL;
            fim = NULL;
        }

        ~Fila(){
            while (tamanho > 0){
                desenfileira();
            }
        }
        
        bool isEmpty(){
            return (tamanho == 0);
        }

        void enfileira(string Valor){
            Node* novo = new Node(Valor);
            if (tamanho == 0){
                inicio = novo;
            }else{
                fim->next = novo;
            }
            novo->next = fim;
            fim = novo;
            tamanho++;
            
        }

        string desenfileira(){
            string valor = inicio->String2Write;
            Node* temp = inicio;
            inicio = inicio->next;
            delete temp;
            tamanho --;
            if (tamanho == 0){
                fim = NULL;
            }
            return valor;
        }
};

void dd_csv2bin(class Fila ppufla){
    ifstream arquivoLeitura("preparatorio2.csv");
 
    string aux;

    if (arquivoLeitura){
        while(getline(arquivoLeitura, aux)){
            cout << "enfileirando: " << aux << endl;
            ppufla.enfileira(aux);
        }
    }
    arquivoLeitura.close();
    
    ofstream arquivoEscrita("saida.bin",ios::in|ios::out|ios::binary|ios::app);

    if (arquivoEscrita){
        while (!ppufla.isEmpty()){
            aux = ppufla.desenfileira();

            int tamAux = aux.size();
            
            char auxW[tamAux];

            strcpy(auxW, aux.c_str());
            arquivoEscrita.write(auxW, sizeof(auxW));
        }
    }

    arquivoEscrita.close();
}

int main(){
    Fila ppufla;
    dd_csv2bin(ppufla);
}
