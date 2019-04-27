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

//what it does: pass the past data into structure (for initializing the structure of first use)
//what are the inputs:No inputs
//what are the outputs:No outputs
void initialize_structure_data(){
  ifstream fin;
  fin.open(fileName);
  string x1,x3,x5,x7,x9,x11,x13,x15,x17;
  double x2=0,x4=0,x6=0,x8=0,x10=0,x12=0,x14=0,x16=0,x18=0;
  fin>>x1>>x2>>x3>>x4>>x5>>x6>>x7>>x8>>x9>>x10>>x11>>x12>>x13>>x14>>x15>>x16>>x17>>x18;
  bills[0].expenditure_report=x2;
  bills[1].expenditure_report=x4;
  bills[2].expenditure_report=x6;
  bills[3].expenditure_report=x8;
  bills[4].expenditure_report=x10;
  bills[5].expenditure_report=x12;
  bills[6].expenditure_report=x14;
  bills[7].expenditure_report=x16;
  if (!fin.eof())
  {
    bills[8].expenditure_report=x18;
  }
  
  
  fin.close();
}

//what it does: expand the size of the dynamic array by a constant number
//input: dynamic record arry & max length of arry
//output: a new danamic arry with 50 more max records.
void grow_record_size(string* & store,int& MAX){
  string* new_store = new string[MAX+50];

  for(int i = 0;i<MAX;i++ )
    new_store[i] = store[i];

  delete [] store;
  store = new_store;
  MAX+=50;
}


#endif 