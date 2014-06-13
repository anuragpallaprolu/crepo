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
  system("cls");
  string line;
  char fname[256];
  cout <<"\tOPENFILEPATCH STABLE V4\t"<<endl;
  cout << "\tPlease Enter File Name:\t"<<endl;
  gets(fname);
  ifstream myfile (fname);
  if (myfile.is_open())
  {
    while (! myfile.eof() )
    {
      getline (myfile,line);
      cout << line << endl;
    }
    myfile.close();
    system("PAUSE");
  }

  else cout << "Unable to open file"; 

  return 0;
    
}
