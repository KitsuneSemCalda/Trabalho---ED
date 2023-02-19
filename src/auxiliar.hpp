#ifndef auxiliar_hpp

#define auxiliar_hpp

#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>

#define max_value 150

using namespace std;

struct data_auxiliar{
  char series_reference[max_value];
  char period[max_value];
  float data_value;
  char status[max_value];
  char units[max_value];
  int magnitude;
  char subject[max_value]; 
  char periodicity[max_value]; 
  char group[max_value]; 
  char series_title_1[max_value]; 
  char series_title_2[max_value]; 
  char series_title_3[max_value]; 
  char series_title_4[max_value]; 
  char series_title_5[max_value]; 
};

bool rw_dados(string str_list[], data_auxiliar &aux) {
  if (str_list[0].size() >= sizeof(aux.series_reference)) {
    return false;
  }
  strncpy(aux.series_reference, str_list[0].c_str(), sizeof(aux.series_reference));

  if (str_list[1].size() >= sizeof(aux.period)) {
    return false;
  }
  strncpy(aux.period, str_list[1].c_str(), sizeof(aux.period));

  aux.data_value = atof(str_list[2].c_str());

  if (str_list[3].size() >= sizeof(aux.status)) {
    return false;
  }
  strncpy(aux.status, str_list[3].c_str(), sizeof(aux.status));

  if (str_list[4].size() >= sizeof(aux.units)) {
    return false;  
  }
  strncpy(aux.units, str_list[4].c_str(), sizeof(aux.units));

  aux.magnitude = stoi(str_list[5]);

  if (str_list[6].size() >= sizeof(aux.subject)) {
    return false;
  }
  strncpy(aux.subject, str_list[6].c_str(), sizeof(aux.subject));

  if (str_list[7].size() >= sizeof(aux.periodicity)) {
    return false;
  }
  strncpy(aux.periodicity, str_list[7].c_str(), sizeof(aux.periodicity));

  if (str_list[8].size() >= sizeof(aux.group)) {
    return false;
  }
  strncpy(aux.group, str_list[8].c_str(), sizeof(aux.group));

  if (str_list[9].size() >= sizeof(aux.series_title_1)) {
    return false;
  }
  strncpy(aux.series_title_1, str_list[9].c_str(), sizeof(aux.series_title_1));

  if (str_list[10].size() >= sizeof(aux.series_title_2)) {
    return false;  }
  strncpy(aux.series_title_2, str_list[10].c_str(), sizeof(aux.series_title_2));
  
  if (str_list[11].size() >= sizeof(aux.series_title_3)) {
    return false;
  }

  strncpy(aux.series_title_3, str_list[11].c_str(), sizeof(aux.series_title_3));

  if (str_list[12].size() >= sizeof(aux.series_title_4)) {
    return false;
  }
  strncpy(aux.series_title_4, str_list[12].c_str(), sizeof(aux.series_title_4));

  if (str_list[13].size() >= sizeof(aux.series_title_5)) {
    return false;
  }
  strncpy(aux.series_title_5, str_list[13].c_str(), sizeof(aux.series_title_5));

  return true;
}
#endif
