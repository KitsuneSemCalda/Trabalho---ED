// Nome: Arthur Augusto Magalhães - 202110830
// Nome: Aaron Martins Leão Ferreira - 202120496 
// Nome: Wildes Augusto de Sousa  - 202020602

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Campos{
  char nome[25];
  char graduacao[25];
  char dataEntrada[25];
	  char dataSaida[25];
  float numeroMatricula;
  float quantidadeGasta;
};


void dd_csv2binary(){
   string dados;
   bool nome_estado = true;
   bool graduacao_estado = false;
   bool dataEntrada_estado = false;
   bool dataSaida_estado = false;
   bool numeroMatricula_estado = false;
   bool quantidadeGasta_estado = false;
   ifstream InpArquivo("preparatorio.csv");
   if (InpArquivo){
	cout << "[OK] Arquivo Encontrado com Sucesso" << endl;
	ofstream OutArquivo("binaryFile.dat", ios::binary);
	if (OutArquivo){
	cout << "[OK] Arquivo binario criado com sucesso" << endl;
	}
//InpArquivo >> registro.int
//InpArquivo.ignore(256, ',')
//InpArquivo.getlibe(registr.txt, 50, ',')
	for (int k = 0; k < 6; k++){
		while (InpArquivo >> dados){
		    if (dados == ","){
		    	if (nome_estado){
			  nome_estado = false;
			  graduacao_estado = true;
			}else if (graduacao_estado){
			  graduacao_estado = false;
			  dataEntrada_estado = true;
			}else if (dataEntrada_estado){
			  dataEntrada_estado = false;
			  dataSaida_estado = true;
			}else if (dataSaida_estado){
			  dataSaida_estado = false;
			  numeroMatricula_estado = true;
			}else if (numeroMatricula_estado){
		          numeroMatricula_estado = false;
			  quantidadeGasta_estado = true;
			}else if (quantidadeGasta_estado){
			  quantidadeGasta_estado = false;
			  nome_estado = true;
			}
                    }else{
	            	if (nome_estado){
			   Campos.nome = dados;
                   	}else if (graduacao_estado){
			   Campos.graduacao = dados;
                    	}else if (dataEntrada_estado){
		    	   Campos.dataEntrada = dados;
                    	}else if (dataSaida_estado){
		           Campos.dataSaida = dados;
                    	}else if (numeroMatricula_estado){
		           Campos.numeroMatricula = dados;
                    	}else if (quantidadeGasta_estado){
		    	   Campos.quantidadeGasta = dados;
			}
					
		}
	    }
	    OutArquivo.write(Campos.nome);
	    OutArquivo.write(Campos.graduacao);
	    OutArquivo.write(Campos.dataEntrada);
	    OutArquivo.write(Campos.dataSaida);
	    OutArquivo.write(Campos.numeroMatricula);
	    OutArquivo.write(Campos.quantidadeGasta);
	}
	cout << "[OK] Campos Gravados com Sucesso" << endl;
	InpArquivo.close();
	cout << "[OK] Arquivo de leitura fechado com sucesso" << endl;
	OutArquivo.close();
	cout << "[OK] Arquivo de escrita fechado com sucesso" << endl;	
   }
 }

int main(){
  dd_csv2binary();
  return 0;
}
