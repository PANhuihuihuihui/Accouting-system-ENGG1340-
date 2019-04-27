#include<iostream>
#include<time.h>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include"gobal.h"
#include"print.h"
using namespace std;

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


//what it does:initialize the past data into report_data.txt to store the value
//what are the inputs:No inputs
//what are the outputs:No outputs
void initialize_report(){
  ofstream fout;
  fout.open(fileName);
  if (fout.fail()){
    cout<<"Fail to open "<<fileName<<endl;
  }
  for(int i=0;i<9;i++){
    fout<<bills[i].type_report<<endl;
    fout<<bills[i].expenditure_report<<endl;
  }
  fout.close();
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

//*************************************add fuction******************************************************

//what it does: return the system time
//input: No input
//output: return the a string of year + month + day + hour + minutes + second
//1 get time
string current_time()
{
  // 基于当前系统的当前日期/时间
  time_t now = time(0);

 stringstream ss;

   tm *ltm = localtime(&now);
   string time2="";
   string time="";
   ss << 1900 + ltm->tm_year ;
   ss << "-"<< 1 + ltm->tm_mon;
   ss << "-"<< ltm->tm_mday;
   ss >> time;
   ss.clear();
   ss << ltm->tm_hour << ":";
   ss << ltm->tm_min << ":";
   ss << ltm->tm_sec << endl;
   ss >> time2;
   time=time+" "+time2;
  return time;
}



//what it does: printing the currency type that user have chosen
//input: currency_type (by address since the value of current_type should be updated)
//output: No output
void print_unit(string &current_type){
  cout<<"********************************************"<<endl;
  cout<<endl;
  cout<<"Currency unit"<<" : "<<current_type<<"(input -1 to change the unit)"<<endl;
}

//what it does: change the exchange rate according to the type of currency has been chosen.
//input: exchange_type (by address since the value of current_type should be updated);current_type(by address since the type can be changed )
//output: No output
void currency_type( double &exchange_rate,string &current_type){
  unit_mune();
  int number=0;
  cout<<"Please input currency type (1-8):"<<endl;
  cin>>number;
  while (number>8||number<1)
  {
    cout<<"Invid input, please input again."<<endl;
  }
  switch(number)
  {
  case 1:
      cout<<"You have chosen HKD"<<endl;
      exchange_rate=1;
      current_type="HKD";
      break;
  case 2:
      cout<<"You have chosen CNY"<<endl;
      exchange_rate =1.167;
      current_type="CNY";
      break;
  case 3:
      cout<<"You have chosen USD"<<endl;
      exchange_rate =7.8499;
      current_type="USD";
      break;
  case 4:
      cout<<"You have chosen EUR"<<endl;
      exchange_rate =8.7919;
      current_type="EUR";
      break;
  case 5:
      cout<<"You have chosen JPY"<<endl;
      exchange_rate =0.07051;
      current_type="JPY";
      break;
  case 6:
      cout<<"You have chosen KRW"<<endl;
      exchange_rate =0.006913;
      current_type="KRW";
      break;
  case 7:
      cout<<"You have chosen AUD"<<endl;
      exchange_rate =5.5514;
      current_type="AUD";
      break;
  case 8:
      cout<<"You have chosen GBP"<<endl;
      exchange_rate =10.2559;
      current_type="GBP";
      break;
  }
}




//what it does: update the value of the expenditure of different type of catagorizes within a structure.
//input: 1:the expenditure should be updated 2:the type of bills 3: the index number of the type of bills
//output: No output
void update_struct(string expenditure,string type,int index){
  bills[index].type_report=type;
  stringstream ss;
  int expenditure_int;
  ss<<expenditure;
  ss>>expenditure_int;
  bills[index].expenditure_report+=expenditure_int;
}

//what it does: let the user choose the type of account
//input: No input
//output: No output

string type_account(){
  cout<<"Please input the type of cash :"<<endl;
  string list_account[3]={"Cash", "Bank_card", "Credit_card"};
  cout<<"1:cash  2:bank card  3:credit card "<<endl;
  int number=0;
  cin>>number;
  while(number!=1 && number!=3 &&number!=2)
  {
    cout<< "Invid input, please input again"<<endl;
    cin>>number;
  }
  return list_account[number-1];

}

//what it does: get single bill information from the consumers
//input: 1: the type of currency 2:exchange rate 3:the number of choice
//output: a string of bills with the basic information as required.
string Get_bill(string &current_type,double &exchange_rate,int choice){
  string account="";
  string list[8]={"Food","Transportation","Daily","Education","Entertainment","Shopping","Load","Others",};
  string type=list[choice-1];
  account=type_account();
  cout<<"Please input the amount of doller used"<<endl;
  double expenditure_do=0;
  cin>>expenditure_do;
  double expenditure_double=expenditure_do*exchange_rate;
  stringstream ss;
  string expenditure;
  ss<<expenditure_double;
  ss>>expenditure;
  ss.clear();
  ss<<expenditure_do;
  string expenditure_temp;
  ss>>expenditure_temp;
  cout<<endl;
  cout<<"comment:";
  string comment="";
  cin.ignore();
  getline(cin,comment);
  cout<<endl;
  string time =current_time();
  string bill=time+" "+account+" "+type+" "+expenditure_temp+" "+current_type+" comment: "+comment;
  int index_report=choice-1;
  initialize_structure_data();
  update_struct(expenditure,type,index_report);
  initialize_report();
  return bill;
}

//what it does: the main function to add bills
//input: 1:exchange rate 2:the type of currency used
//output:No output
void Main_page_add( double &current,string &current_type)
{
  string list2[9]={"Food","Transportation","Daily","Education","Entertainment","Shopping","Load","Others","Income"};
  for (int w=0;w<9;w++){
    bills[w].type_report=list2[w];
  }

  char type;
  int number=0;

  do{
    print_unit(current_type);
    print_category();
    string bill="";
    cin>> number;
    while (number==-1){
      currency_type(current,current_type);
      print_unit(current_type);
      print_category();
      cin>>number;
      while (number<1 || number>8){
        if (number == -1)
          break;
        else
        {
          cout<<"Invaild number,please input again"<<endl;
          cin>>number;
        }
        
      }
      
    }
    while (number<1 || number>8){
      cout<<"Invaild number,please input again"<<endl;
      cin>>number;
    }
    bill=Get_bill(current_type,current,number);
    store[numberOfRecord]=bill;
    numberOfRecord++;
    cout<<"Add more bills (Y/N)"<<endl;
    cin>>type;
  }while(type=='Y'||type == 'y');
}
//**************************************search****************************************

//what it does: search the bills by part of the information
//input:a list with the location of the specific bills
//output: ture (if finded) else return false
bool search(int* list_index){
  cout<<"Please input the information to search"<<endl;
  cout << "For example, You can input" << endl;
  cout << "   Date   :    YYYY-MM-DD" <<endl<<endl;
  cout << "   Unit   :    HKD    CNY    USD    EUR"<<endl;
  cout << "               JPY    KRW    AUD    GBD"<< endl<<endl;
  cout << " Category :    Food        Transportation    Daily   Education"<<endl;
  cout<<"             Entertainment    Shopping        Load     Others " <<endl<<endl;
  cout << "  Comment : " << endl;
  string data;
  cin>>data;
  int index=0;
  string line;
  int n=0;
  bool falge = false;
  while(n < numberOfRecord ){
    line = store[n];
    if ( line.find(data)!= string::npos){
      list_index[index]=n;
      cout<< index+1 <<". "<<line<<endl;
      index++;
    }
    n++;
  }
  if (index >0)
    return true;
  else
    return false;
}

//********************************************print records*****************************************
//what it does: print the latest 20 bills
//input: real position in the store 
//output: false (if no bills ) else (return true)
bool print_record(int& realpos)
{
  if(numberOfRecord == 0)
  {
    cout<< "There is no record"<<endl;
    return false;
  }
  else if(numberOfRecord  < 21 &&  numberOfRecord > 0)
  {
    realpos =-1;
    for(int i = 1 ; i < numberOfRecord +1 ; i++)
    {
      if(i>9)
      {
        cout <<i<<". " <<store[i-1]<<endl;
      }
      else
      {
        cout <<i<<".  " <<store[i-1]<<endl;
      }
    }
    return true;
  }
  else
  {
    realpos = numberOfRecord - 21;
    for(int i = 1 ; i < 21 ; i++)
    {
       if(i>9)
      {
        cout << i <<". " << store[numberOfRecord - 21 + i ]<<endl;
      }
      else
      {
        cout << i <<".  " << store[numberOfRecord - 21 + i ]<<endl;
      }
    }
    return true;
  }

}

//what it does:
//input:
//output:
void outputRecord()
{
  ofstream output("bill_record.txt");
    for (int i = 0; i <numberOfRecord;i++)
    {
      output << store[i];
      if (i != numberOfRecord-1)
        output<<endl;
    }
  output.close();
}

bool getTheRecord()
{
  ifstream input("bill_record.txt");
  if (input.fail())
	{
	    cout << "There is no record" << endl;
      return false;
  }
  else{

    while(!input.eof())
    {
      if(numberOfRecord + 1 > MAX){
        grow_record_size(store,MAX);
      }
      getline(input,store[numberOfRecord]);
      if(store[numberOfRecord] != ""){
        numberOfRecord++;
      }
    }
    input.close();
    return true;
  }
}
