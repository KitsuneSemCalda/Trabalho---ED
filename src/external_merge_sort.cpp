#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define INT_MAX 1024

void intercala(int a[], int inicio, int meio, int fim){
  int i = inicio, j = meio + 1, tamanho = fim - inicio + 1;
  int aux[tamanho];

  for (int k = 0; k < tamanho; k++){
    if ((i <= meio ) and (j <= fim)){
      if (a[i] <= a[j]){
        aux[k] = a[i];
        i++;
      }else{
        aux[k] = a[j];
        j++;
      }
    }else if (i > meio){
      aux[k] = a[j];
      j++;
    }else{
      aux[k] = a[i];
      i++;
    }
  }
  
  for (int k = 0; k < tamanho; k++){
    a[inicio + k] = aux[k];
  }
}

void mergesort(int a[], int inicio, int fim){
  int meio;

  if (inicio < fim){
    meio = (inicio + fim) / 2;
    mergesort(a, inicio, meio);
    mergesort(a, meio + 1, fim);
    intercala(a, inicio, meio, fim);
  }
}
