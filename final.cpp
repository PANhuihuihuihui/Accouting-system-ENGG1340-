#include<iostream>
#include<time.h>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include"gobal.h"
using namespace std;

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

void Delet()
{
  int realpos = 0;
  //print the record
  if(!print_record(realpos))
    return;
  int userchoice;
  cout << " Please input the number of record you want to delet (delet other records input -1)"<<endl;
  cin>> userchoice;
  while( userchoice > 30 || userchoice <= -2){
    cout<<"invide input"<<endl;
    cin>> userchoice;
  }
  if(userchoice == -1 )
  {
    int* list_index = new int[MAX];
    if(search(list_index) == false)
    {
      cout << "There is no relevent reord."<<endl;
      return;
    }
    cout << " Please input the number of record you want to delet "<<endl;
    cin >> userchoice;
    realpos = list_index[userchoice-1];
    delete [] list_index;
  }
  else
  {
    realpos = realpos+ userchoice;
  }
  cout << " Are you sure you want to delet this record(Y/N) "<<endl;
  cout << store[realpos]<<endl;
  char userinput;
  cin>>userinput;
  while (userinput =='Y'||userinput == 'N')
  {
    if(userinput == 'N')
    {
      //****************************************************************************
    }
    if (userinput == 'Y')
    {
      for(int i = realpos; i < numberOfRecord-1 ; i++)
      {
        store[i] = store[i+1];
      }
       --numberOfRecord;
      cout<<"Record sucefully delet"<<endl;

      break;

    }
  }

}




//*********************************************** report *****************************************************
//check the whether it is another moth.
//what it does: check the whether it is another moth.
void upDateFileName()
{
  string tempTime = current_time();
  tempTime = tempTime.substr(0,6);
  fileName = "report_data_"+tempTime+".txt";
  ifstream fin;
}

int Maximum_number(int list[]){
  int max=list[0];
  for(int i=0;i<8;i++){
    if (list[i]>=max){
      max=list[i];
    }
  }
  return max;
}

//what it does:Give a report of different expenses ,monthly income, monthly expense.
//input:No input
//output:No output
void report(){

  ifstream fin;
  fin.open(fileName);
    string x1,x3,x5,x7,x9,x11,x13,x15,x17;
    double x2,x4,x6,x8,x10,x12,x14,x16,x18;
    double monthly_expenditure=0;
    fin>>x1>>x2>>x3>>x4>>x5>>x6>>x7>>x8>>x9>>x10>>x11>>x12>>x13>>x14>>x15>>x16>>x17>>x18;
    monthly_expenditure=x2+x4+x6+x8+x10+x12+x14+x16;
    cout<<"***********Report***********"<<endl;
    cout<<endl;
    cout<<"------";
    cout<<"Monthly income"<<" :"<<x18;
    cout<<"------"<<endl;
    cout<<endl;
    cout<<"Total expenditure"<<endl;
    cout<<monthly_expenditure<<endl;
    cout<<left<<setw(16)<<"Type"<<"Expenditure"<<right<<setw(18)<<"Percentage"<<endl;
    cout<<endl;
    cout<<fixed<<setprecision(2)<<left<<setw(20)<<"Food"<<x2<<right<<setw(20)<<fixed<<setprecision(2)<<(x2/monthly_expenditure)*100<<"%"<<endl;
    cout<<fixed<<setprecision(2)<<left<<setw(20)<<"Transportation"<<x4<<right<<setw(20)<<fixed<<setprecision(2)<<(x4/monthly_expenditure)*100<<"%"<<endl;
    cout<<fixed<<setprecision(2)<<left<<setw(20)<<"Daily"<<x6<<right<<setw(20)<<fixed<<setprecision(2)<<(x6/monthly_expenditure)*100<<"%"<<endl;
    cout<<fixed<<setprecision(2)<<left<<setw(20)<<"Education"<<x8<<right<<setw(20)<<fixed<<setprecision(2)<<(x8/monthly_expenditure)*100<<"%"<<endl;
    cout<<fixed<<setprecision(2)<<left<<setw(20)<<"Entertainment"<<x10<<right<<setw(20)<<fixed<<setprecision(2)<<(x10/monthly_expenditure)*100<<"%"<<endl;
    cout<<fixed<<setprecision(2)<<left<<setw(20)<<"Shopping"<<x12<<right<<setw(20)<<fixed<<setprecision(2)<<(x12/monthly_expenditure)*100<<"%"<<endl;
    cout<<fixed<<setprecision(2)<<left<<setw(20)<<"Load"<<x14<<right<<setw(20)<<fixed<<setprecision(2)<<(x14/monthly_expenditure)*100<<"%"<<endl;
    cout<<fixed<<setprecision(2)<<left<<setw(20)<<"Others"<<x16<<right<<setw(20)<<fixed<<setprecision(2)<<(x16/monthly_expenditure)*100<<"%"<<endl;
    int Food=(x2/monthly_expenditure)*100,Transportation=(x4/monthly_expenditure)*100,Daily=(x6/monthly_expenditure)*100,Education=(x8/monthly_expenditure)*100;
    int Entertainment=(x10/monthly_expenditure)*100,Shopping=(x12/monthly_expenditure)*100,Load=(x14/monthly_expenditure)*100,Others=(x16/monthly_expenditure)*100;

    int list[8] = {Food,Transportation,Daily,Education,Entertainment,Shopping,Load,Others};

    int max = Maximum_number(list);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<" Financial bar chart :"<<endl;
    cout<<endl;

    cout<<"Expenditure "<<endl;
    cout<<"  "<<endl;
    for(int i=0;i<34;i++){

      if(i==8)
      cout<<"75%";
      else if(i==17)
      cout<<"50%";
      else if(i==26)
      cout<<"25%";
      else
      cout<<"  |";

      string star="      ***      ";
      string noting="               ";

      if (Food<100){
        cout<<noting;
        Food+=3;
      }
      else{
        cout<<star;
      }


      if (Transportation<100){
        cout<<noting;
        Transportation+=3;
      }

      else{
        cout<<star;
      }

      if (Daily<100){
        cout<<noting;
        Daily+=3;
      }

      else{
        cout<<star;
      }

      if (Education<100){
        cout<<noting;
        Education+=3;
      }

      else{
        cout<<star;
      }

      if (Entertainment<100){
        cout<<noting;
        Entertainment+=3;
      }

      else{
        cout<<star;
      }

      if (Shopping<100){
        cout<<noting;
        Shopping+=3;
      }
      else{
        cout<<star;
      }

      if (Load<100){
        cout<<noting;
        Load+=3;
      }
      else{
        cout<<star;
      }

      if (Others<100){
        cout<<noting;
        Others+=3;
      }
      else{
        cout<<star;
      }
      cout<<endl;

    fin.close();
}
cout<<"   __________________________________________________________________________________________________________________________________"<<endl;
cout<<endl;
cout<<"      Food     "<<" "<<"Transportation"<<" "<<"    Daily    "<<" "<<"  Education  "<<" "<<" Entertainment "<<" "<<"   Shopping   "<<" "<<"     Load     "<<" "<<"    Others    "<<endl;
}

//*********************************************budget setting***********************************************

//what it does:initialize the budget by inputting the value
//input:the values of the budget
//output:No output
void initial_budget(double &budget){
  ofstream fout;
  fout.open("Budget.txt");
  fout<<budget;
  fout.close();
}



//what it does:use a variable to store the value of the budget
//input:a variable money
//output:No output
void Get_budget(double &money){
  ifstream fin;
  fin.open("Budget.txt");
  fin>>money;
  fin.close();
}



//what it does:get the current total expenditure
//input:No output
//output:No output
double total_expenditure(){
  ifstream fin;
  fin.open(fileName);
  string x1,x3,x5,x7,x9,x11,x13,x15;
  double x2,x4,x6,x8,x10,x12,x14,x16;
  double monthly_expenditure=0;
  fin>>x1>>x2>>x3>>x4>>x5>>x6>>x7>>x8>>x9>>x10>>x11>>x12>>x13>>x14>>x15>>x16;
  monthly_expenditure=x2+x4+x6+x8+x10+x12+x14+x16;
  return monthly_expenditure;
}

//****************************************************************main***************************
//what it does:The main menu of the system (with the ability to showout "budget over" when monthly_expenditure  is larger than budget )
//input:1:the budget of expenditure 2: the monthly expenditure of the user
//output:No output
void Main_Mune(double budget,double monthly_expenditure)
{
  if (budget!=-1){
    if (monthly_expenditure>budget){
      cout<<"Budget is over               "<<"Records:"<<numberOfRecord<<endl;
    }
    else{
      cout<<"Budget left:   "<<budget-monthly_expenditure<<"        Records:"<<numberOfRecord<<endl;
    }
  }
  else
  {
    cout<<"No budget setting"<<"        Records:"<<numberOfRecord<<endl;
  }
  cout << "*************************************" << endl;
  cout << "----------   WELCOME TO   -----------"<<endl;
  cout << "*************************************" << endl;
  cout << " 1. Add bills." << endl;
  cout << " 2. Add income." <<endl;
  cout << " 3. Delete or Edit records." << endl;
  cout << " 4. Print records." << endl;
  cout << " 5. Search the records by partial match of the bill." << endl;
  cout << " 6. Giving report.(fullscreen condition)" << endl;
  cout << " 7. Budget setting." << endl;
  cout << " 0. Quit. " << endl;
  cout << " Please enter your choice: ";

}

int main()
{
  ofstream fout( "bill_record.txt",ios::app );
  fout.close();
  ofstream ffout( "budget.txt",ios::app );
  ffout.close();
  double budget=-1;
  ifstream fin;
  fin.open("Budget.txt",ios::in);
  int ch;
  ch=fin.get();
  if(fin.eof()){
    initial_budget(budget);
  }
  else{
    Get_budget(budget);
  }
  //welcome
  upDateFileName();
  bool flage = getTheRecord();
  double expense=0;
  expense=total_expenditure();
  Get_budget(budget);
  Main_Mune(budget,expense);
  // buget left
  if(flage)
  {
    double current= 1;

    int first_time=0;
    char Main_userinput;
    cin >> Main_userinput;
    while(Main_userinput != '0')
    {
      if (first_time!=0)
      {
        Get_budget(budget);
        expense=total_expenditure();
        Main_Mune(budget,expense);
        cin >> Main_userinput;
      }
      first_time+=1;

      switch(Main_userinput)
      {
        case '1':{
          if (numberOfRecord > MAX)
            grow_record_size(store,MAX);
        Main_page_add(current,current_type);
        outputRecord();
        break;
      }
        case '2':{
        long double temp_income;
        cout<<"Please input the income"<<endl;
        cin>>temp_income;
        bills[8].expenditure_report+=temp_income;
        initialize_report();
        break;
        }

        case '3':
        cout<<"Please choice to Delete or Edit(D/E)"<<endl;
        char choice;
        cin>>choice;

        if (choice=='D')
        {
          Delet();
        }
        if (choice=='E')
        {
          Edit();
        }
        outputRecord();
        break;

      case '4':{
        int realpos = 0;
        print_record(realpos);
        break;
        }
      case '5':{
        if (numberOfRecord==0)
        {
          cout << "There is no record to search"<<endl;
          break;
        }
        else{
          int* list_index=new int[MAX];
          if(search(list_index) == false)
          {
            cout << "There is no relevent reord."<<endl;
            break;
          }
          delete [] list_index;
          break;
        }

       }
      case '6':{
        if (numberOfRecord == 0 )
          cout<<"No record, no report."<<endl;
        else
          report();
        break;
      }
      case '7':{
        cout<<"Please add your monthy budget !"<<endl;
        cin>>budget;
        initial_budget(budget);
        break;
      }
      case '0':
      exit(-1);

      }
    cout << endl<<endl<<endl;
    }
   cout<<"SEE YOU NEXT TIME"<<endl;
  }
  outputRecord();
}
