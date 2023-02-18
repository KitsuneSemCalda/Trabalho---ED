#include <cstring>
#define MAX_VALUE 150

#include "iostream"
#include "cstring"
#include "string"

using namespace std;

struct data_auxiliar{
  char Series_reference[MAX_VALUE];
  char Period[MAX_VALUE];
  float Data_value;
  char Status[MAX_VALUE];
  char Units[MAX_VALUE];
  int Magnitude;
  char Subject[MAX_VALUE]; 
  char Periodicity[MAX_VALUE]; 
  char Group[MAX_VALUE]; 
  char Series_title_1[MAX_VALUE]; 
  char Series_title_2[MAX_VALUE]; 
  char Series_title_3[MAX_VALUE]; 
  char Series_title_4[MAX_VALUE]; 
  char Series_title_5[MAX_VALUE]; 
};

void rw_dados(string str_list[], data_auxiliar &aux){
  strcpy(aux.Series_reference, str_list[0].c_str());
  strcpy(aux.Period, str_list[1].c_str());
  aux.Data_value = atof(str_list[2].c_str());
  strcpy(aux.Status, str_list[3].c_str());
  strcpy(aux.Units, str_list[4].c_str());
  aux.Magnitude = stoi(str_list[5]);
  strcpy(aux.Subject, str_list[6].c_str());
  strcpy(aux.Periodicity, str_list[7].c_str());
  strcpy(aux.Group, str_list[8].c_str());
  strcpy(aux.Series_title_1, str_list[9].c_str());
  strcpy(aux.Series_title_2, str_list[10].c_str());
  strcpy(aux.Series_title_3, str_list[11].c_str());
  strcpy(aux.Series_title_4, str_list[12].c_str());
  strcpy(aux.Series_title_5, str_list[13].c_str());
}
