#include "auxiliar.hpp"
#include <cstring>
#include <string>

using namespace std;

void print_message(string message){
  cout << message << endl;
}

void print_message(int message){
  cout << message << endl;
}

void imprimir(binary_data_aux *aux){
  print_message(aux->Series_reference);
  print_message(aux->Period);
  print_message(aux->Data_value);
  print_message(aux->Status);
  print_message(aux->Units);
  print_message(aux->Magnitude);
  print_message(aux->Subject);
  print_message(aux->Periodicity);
  print_message(aux->Group);
  print_message(aux->Series_title_1);
  print_message(aux->Series_title_2);
  print_message(aux->Series_title_3);
  print_message(aux->Series_title_4);
  print_message(aux->Series_title_5);
}

void criar_dados(string *binary_data_list, binary_data_aux &aux){
  strcpy(aux.Series_reference, binary_data_list[1].c_str());
  strcpy(aux.Period, binary_data_list[2].c_str());
  aux.Data_value = stoi(binary_data_list[3]);
  strcpy(aux.Status, binary_data_list[4].c_str());
  strcpy(aux.Units, binary_data_list[5].c_str());
  aux.Magnitude = stoi(binary_data_list[6]);
  strcpy(aux.Subject, binary_data_list[7].c_str());
  strcpy(aux.Periodicity, binary_data_list[8].c_str());
  strcpy(aux.Group, binary_data_list[9].c_str());
  strcpy(aux.Series_title_1, binary_data_list[10].c_str());
  strcpy(aux.Series_title_2, binary_data_list[11].c_str());
  strcpy(aux.Series_title_3, binary_data_list[12].c_str());
  strcpy(aux.Series_title_4, binary_data_list[13].c_str());
  strcpy(aux.Series_title_5, binary_data_list[14].c_str());
}

