// Arthur Augusto Magalhaes - 202110830
// Wildes Augusto de Sousa  - 202020602
// Aaron Martins Leão Ferreira - 202120496

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

// Criamos uma estrutura utilizando orientação a objetos para servir de fila dos dados a serem escritos

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

bool isNumber(char aux){
    if (aux >= '0' and aux <= '9'){
        return true;
    }
    return false;
};

bool isLetter(char aux){
    if ((aux >= 'A' and aux <= 'Z') or ((aux >= 'a') and (aux <= 'z'))){
        return true;
    }
    return false;
};

string auxTreatment(string aux){
    int tamAux = aux.size();
    
    if (aux[tamAux] == ' '){
        aux[tamAux] = ';';
    }

    if (isNumber(aux[tamAux])){
        aux[(tamAux + 1)] = ';';
    }

    return aux;
}

void dd_csv2bin(class Fila ppufla){

    // Declaramos o arquivo de leitura como preparatorio2.csv e caso o programa identifique que o arquivo existe ele começa a ler linha a linha do arquivo e o enfileira na nossa estrutura "FILA"

    ifstream arquivoLeitura("preparatorio2.csv");
 
    string aux;

    if (arquivoLeitura){
        while(arquivoLeitura >> aux){
            aux = auxTreatment(aux);
            ppufla.enfileira(aux);
        }
    }
    arquivoLeitura.close();
 
    // Após fechar o arquivo de leitura e ter enfileirado todas as linhas, abrimos um arquivo de escrita que será escrito de forma binária

    ofstream arquivoEscrita("saida.bin",ios::in|ios::out|ios::binary|ios::app);

    if (arquivoEscrita){
        
        // Se o arquivo estiver aberto
        
        // Enquanto a fila não estiver vazia desenfileiramos o arquivo em uma strnig auxilar e capturamos seu tamanho. Em seguida geramos um vetor de mesmo tamanho da string e copiamos o valor da string para o vetor de char.
        
        // Completando isso escrevemos o vetor de char no arquivo binário 

        while (!ppufla.isEmpty()){
            aux = ppufla.desenfileira();

            int tamAux = aux.size();
            
            char auxW[tamAux];

            strcpy(auxW, aux.c_str());
            arquivoEscrita.write(auxW, sizeof(auxW));
        }
    }
    
    // Após terminar o arquivo de escrita é fechado com sucesso
    arquivoEscrita.close();
}

int main(){
    Fila ppufla;
    dd_csv2bin(ppufla);
    return 0;
}
