#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "auxiliar.hpp"

using namespace std;

const int BUFFER_SIZE = 1000; // Tamanho do buffer em número de registros

// Define a função de comparação para a estrutura data_auxiliar
bool compare_data(const data_auxiliar &a, const data_auxiliar &b) {
    int cmp = strcmp(a.series_reference, b.series_reference);
    if (cmp == 0) {
        return strcmp(a.period, b.period) < 0;
    } else {
        return cmp < 0;
    }
}

// Merge Sort
void merge_sort(vector<data_auxiliar>& v, int start, int end, bool (*cmp)(const data_auxiliar& a, const data_auxiliar& b)) {
  if (start >= end) {
    return;
  }
  int mid = start + (end - start) / 2;
  merge_sort(v, start, mid, cmp);
  merge_sort(v, mid + 1, end, cmp);

  vector<data_auxiliar> aux;
  int i = start;
  int j = mid + 1;
  while (i <= mid && j <= end) {
    if (cmp(v[i], v[j])) {
      aux.push_back(v[i]);
      i++;
    } else {
      aux.push_back(v[j]);
      j++;
    }
  }
  while (i <= mid) {
    aux.push_back(v[i]);
    i++;
  }
  while (j <= end) {
    aux.push_back(v[j]);
    j++;
  }

  for (int k = start; k <= end; k++) {
    v[k] = aux[k - start];
  }
}

// Define a função de mergesort externo para arquivos binários
void merge_sort_external(const char *filename) {
    // Abre o arquivo binário de entrada
    fstream fin(filename, ios::in | ios::binary);
    if (!fin) {
        cerr << "Erro ao abrir arquivo " << filename << endl;
        return;
    }

    // Lê o tamanho do arquivo em bytes
    fin.seekg(0, ios::end);
    size_t size = fin.tellg();
    fin.seekg(0, ios::beg);

    // Calcula o número de registros no arquivo
    size_t count = size / sizeof(data_auxiliar);

    // Cria um arquivo temporário para armazenar os dados ordenados
    fstream tmp("tmp.bin", ios::out | ios::binary | ios::trunc);
    if (!tmp) {
        cerr << "Erro ao criar arquivo temporário" << endl;
        fin.close();
        return;
    }

    // Divide o arquivo em blocos ordenando-os internamente
    size_t num_blocks = count / BUFFER_SIZE + (count % BUFFER_SIZE != 0);
    for (size_t i = 0; i < num_blocks; i++) {
        // Lê um bloco do arquivo para a memória
        vector<data_auxiliar> buffer;
        size_t block_size = std::min<size_t>(BUFFER_SIZE, count - i * BUFFER_SIZE);
        buffer.resize(block_size);
        fin.read(reinterpret_cast<char*>(&buffer[0]), block_size * sizeof(data_auxiliar));

        // Ordena o bloco em memória
        merge_sort(buffer, 0, block_size - 1, compare_data);

        // Escreve o bloco ordenado no arquivo temporário
        tmp.write(reinterpret_cast<char*>(&buffer[0]), block_size * sizeof(data_auxiliar));
    }

    // Fecha os arquivos e remove o arquivo de entrada
    fin.close();
    tmp.close();
    remove(filename);

    // Renomeia o arquivo temporário para o nome do arquivo de entrada
    rename("tmp.bin", filename);

    cout << "Arquivo ordenado com sucesso." << endl;
}



// Função de comparação para o Merge Sort
bool cmp(const data_auxiliar& a, const data_auxiliar& b) {
  if (strcmp(a.series_reference, b.series_reference) < 0) {
    return true;
  } else if (strcmp(a.series_reference, b.series_reference) == 0 && strcmp(a.period, b.period) < 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  vector<data_auxiliar> data;
  ifstream input("saida.bin", ios::binary);
  data_auxiliar aux;
  while (input.read(reinterpret_cast<char*>(&aux), sizeof(aux))) {
    data.push_back(aux);
  }

  merge_sort(data, 0, data.size() - 1, cmp);

  ofstream output("saida_ordenada.bin", ios::binary);
  for (const auto& d : data) {
    output.write(reinterpret_cast<const char*>(&d), sizeof(d));
  }

  input.close();
  output.close();

  cout << "Arquivo ordenado com sucesso." << endl;
  return 0;
}
