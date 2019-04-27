#ifndef GOBAL_H_INCLUDED
#define GOBAL_H_INCLUDED

#include <iostream>
using namespace std;

int MAX = 0;
string fileName = "";
string* store = new string[MAX];//using the dynamic memory to store the record
int numberOfRecord = 0;//gobal variable
string current_type="HKD";

struct bill{
  string type_report;
  long double expenditure_report;
};
bill bills[9];

#endif 