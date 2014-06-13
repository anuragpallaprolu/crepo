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

int main(){
    cout << "FIND FILE PATCH V4 UNSTABLE" <<endl;
    char search[256]; // search pattern
    char fname[256];
    int offset;
    string line;
    ifstream Myfile;
    cout << "Please enter file name:" <<endl;
    gets(fname);
    cout << "Please enter string to search:" <<endl;
    gets(search);
    Myfile.open (fname);
    
    if(Myfile.is_open())
    {
    while(!Myfile.eof())
    {
    getline(Myfile,line);
    if ((offset = line.find(search, 0)) != string::npos) {
    cout << "found '" << search << endl;
    system("PAUSE");
    }
    
    Myfile.close();
                   }
    return 0;
    }
    }
