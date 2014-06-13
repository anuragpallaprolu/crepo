
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
    char fname[256];
    cout << "APPEND V4" << endl;
    cout << "Please Enter Name Of The File To Append." << endl;
    gets(fname);
    outfile.open(fname, ios::out|ios::app);
    string append;
    cout << "Enter Text To Append" <<endl;
    cout << "Type in ! when completed." << endl;
    getline(cin, append, '!');
    outfile << append<<endl;
    cout << endl;
    outfile << "Appended" << endl;
}
