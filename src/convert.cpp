#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;
//estrutura que recebe os dados do arquivo
class Node{
    friend class Fila;
    //friend ostream& operator<<(ostream& out, const Node& dado);
    private:
        string allData;
        string Nome;
        string Graduacao;
        string DataEntrada;
        string DataSaida;
        float NumeroMatricula;
        float QuantiaGasta;
        Node* next;
    public:
        Node(){
            Nome = "";
            Graduacao = "";
            DataEntrada = "";
            DataSaida = "";
            NumeroMatricula = 0.0;
            QuantiaGasta = 0.0;

        }

        Node(string str){
            allData = str;
        }
        Node(string rNome, string rGraduacao, string rDataEntrada, string rDataSaida, float rNumeroMatricula, float rQuantiaGasta){
            Nome = rNome;
            Graduacao = rGraduacao;
            DataEntrada = rDataEntrada;
            DataSaida = rDataSaida;
            NumeroMatricula = rNumeroMatricula;
            QuantiaGasta = rQuantiaGasta;
            allData = "null";
        }
        void setNome(string nome){
            Nome = nome;
        }
        string getAllData(){
            return allData;
        }
        string getNome(){
            return Nome;
        }
        string getGraduacao(){
            return Graduacao;
        }
        string getDataEntrada(){
            return DataEntrada;
        }
        string getDataSaida(){
            return DataSaida;
        }
        float getNumeroMatricula(){
            return NumeroMatricula;
        }
        float getQuantidadeGasta(){
            return QuantiaGasta;
        }
};

//Sobrecarga de operador 
/*ostream& operator<<(ostream& out, const Node& dado){
    out << dado.Nome << "\n"
        << dado.Graduacao << "\n"
        << dado.DataEntrada << "\n"
        << dado.DataSaida<< "\n"
        << dado.NumeroMatricula << "\n"
        << dado.QuantiaGasta << endl;
    return out;
}*/

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

        void enfileira(string aData){
            cout<< "enfileira "<< endl;
            Node* novo = new Node(aData);

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
            //cout<< "desenfileira "<< endl;
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

        int size() {
            return Tamanho;
        }
};

string TratamentoAux(string aux){
    return aux;
}
/*
void dd_csv2bin(){
    string aux;
    unsigned qtdArq =0;
    
    ifstream Arquivoleitura("preparatorio2.csv");
    if (Arquivoleitura){
        while (getline(Arquivoleitura, aux)) {
            cout << "aux: " << aux << endl;
            cout <<"Tratamento :"<< TratamentoAux(aux) << endl;
            qtdArq++;
        }
    }
    cout<< "\n\nQuantidade de arquivos: " << qtdArq << endl;
}*/

//arquivo.read(reinterpret_cast<char *> (&variavel),
//  sizeof(tipo_dado_variavel));

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
//funcao que separa a string dados
void desmontaStr(string str)
{
    
    int tamanho = str.length();
    char fullCampo[tamanho];
    char campo[30];
    Node resul;
    int i = 0, j =0;
    while (tamanho > i)
    {
   
        if( fullCampo[i] )
        {
            campo[j++] = fullCampo[i++];
        }
        int t = strlen(campo);
        int x =0;
        while(t > x){

            cout << "Campo: " << campo[x++];
            tamanho=-1;
        }
    }
   

}

void read(){
    string aux;
    unsigned qtdArq =0;
    Fila ufla;

    ifstream Arquivoleitura("preparatorio2.csv");

    cout << "Tamanho da Fila: " << ufla.size() << endl;
  
    if (Arquivoleitura){
        char null = 'v';
        while (getline(Arquivoleitura, aux)) {
            int tam = aux.length();
              
            cout << "dados: " << aux << endl;
            qtdArq++;
            cout << aux << endl;
            ufla.enfileira(aux);
            
        }
        
       
    }
    cout << "\n\nQuantidade de arquivos: " << qtdArq << endl;
    cout << "Extraindo dados da fila"  << endl;
    Node dado;
    while (ufla.size() > 0)
    {
        dado = ufla.desenfileira();
        cout << dado.getAllData() << endl;
        cout<<"Tentativa de separacao: "<< endl;
        desmontaStr(dado.getAllData());
        
    }
    cout << "Tamanho da Fila: " << ufla.size() << endl;
    ufla.~Fila();
    
}


int main(){

    Fila teste, resul;
    string aux;
    Node dado;

    teste.enfileira("Aluno", "Administracao", "2022", "2027",20202025.0,5.0);

    /*while(teste.size() != 0){
        dado = teste.desenfileira();
        cout << "Nome: " << dado.getNome() << endl;
        cout << "Graduacao: " << dado.getGraduacao() << endl;
        cout << "DataEntrada: " << dado.getDataEntrada() << endl;
        cout << "DataSaida: " << dado.getDataSaida()<< endl;
        cout << "NumeroMatricula: " << dado.getNumeroMatricula() << endl;
        cout << "QuantiaGasta: " << dado.getQuantidadeGasta() << endl;
    }
*/
   

    cout <<  "cria aquivo binario..." << endl;
    //dd_csv2bin();
    
    //lerRegistros("saida.bin");
    read();

    

    return 0;
}
