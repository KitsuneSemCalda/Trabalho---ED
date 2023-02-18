#ifndef AUXILIAR_HPP
  #include "iostream"
  #include "cstring"
  using namespace std;

  #define AUXILIAR_HPP
  
  #define MAX_SIZE_CHAR 150

  struct binary_data_aux{
    char Series_reference[MAX_SIZE_CHAR];
    char Period[MAX_SIZE_CHAR];
    int Data_value;
    char Status[MAX_SIZE_CHAR];
    char Units[MAX_SIZE_CHAR];
    int Magnitude; 
    char Subject[MAX_SIZE_CHAR];
    char Periodicity[MAX_SIZE_CHAR];
    char Group[MAX_SIZE_CHAR];
    char Series_title_1[MAX_SIZE_CHAR];
    char Series_title_2[MAX_SIZE_CHAR];
    char Series_title_3[MAX_SIZE_CHAR];
    char Series_title_4[MAX_SIZE_CHAR]; 
    char Series_title_5[MAX_SIZE_CHAR];
  };
  
  void imprimir(binary_data_aux* aux);
  void criar_dados(string binary_data_list[] ,binary_data_aux &aux);
#endif
