#include <fstream>
#include <string>
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int openfile();
int newfile();

    string   fileopen;
    string   createfile;
    string   text;
    ofstream outfile;
    ifstream infile;

int main()
{
    
    system("CLS");
    char date [9]; char time [9];
    _strdate(date); 
    _strtime(time); 
    cout<<"-----------------------------NEW FILE--------------------------"<<endl;
    cout<<"Date:"<<date<<"-----------------------------------Time:"<<time<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"Type In ~ to quit: ";
    getline(cin, text, '~');
    cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
    
            
         
    cout << "Please Enter File Name";
    getline(cin, createfile);
    outfile.open(createfile.c_str(), ios::out);
    outfile << text;
    outfile << endl;
    outfile << "\tEdited using C.L.O.S.E\t" <<endl;
    outfile << date << "                              "<<time<<endl;
    
    cout<<endl; 
    cout<<endl;
    
    system("pause");
    
}
