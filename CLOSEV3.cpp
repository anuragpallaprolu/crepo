#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <windows.h>

using namespace std;
char input[256];

void cls(){
     system("cls");
     }

void pause(){
     system("PAUSE");
     }

void help(){
     cout << "\t _________________________\t" << endl;
     cout << "\t|         HELP INFO       |\t" << endl;
     cout << "\t---------------------------\t" << endl;
     cout << "\t| CLS - Clear Screen      |\t" << endl;
     cout << "\t| OPEN - Open File        |\t" << endl;
     cout << "\t| NEW - New File          |\t" << endl;
     cout << "\t| FIND - Find in file     |\t" << endl;
     cout << "\t| APP - Append To File    |\t" << endl;
     cout << "\t| HELP - Show this text   |\t" << endl;
     cout << "\t| QUIT - Quit the program |\t" << endl;
     cout << "\t| SHOWDATE - Displays Date|\t" << endl;
     cout << "\t| SHOWTIME - Displays Time|\t" << endl;
     cout << "\t---------------------------\t" << endl;
     }
void splash(){
     system("title C.L.O.S.E V3 Enhanced.");
    int i = 4; //replace to 6
    while (i > 0)
    {
          if (i == 0, 2, 4,6)
          {
                system("color 2A");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t        C.L.O.S.E\t\t";
                  cout << "\n\t\tThe Command Line Open Source Editor. VERSION 3 ALPHA\t\t";
    cout << "\n\t\t   Inanimate Studios 2010. (C)Envy Inc. 2010\t\t";
    Sleep(500);
    system("cls");
 i--; 
             }
             if (i == 1, 3, 5) {
                  system("color 1A");
                  cout << "\n\n\n\n\n\n\n\n\n\n\t\t        C.L.O.S.E\t\t";
                  cout << "\n\t\tThe Command Line Open Source Editor. VERSION 3 ALPHA\t\t";
    cout << "\n\t\t   Inanimate Studios 2010. (C)Envy Inc. 2010\t\t";
    Sleep(500);
    system("cls");
 i--; 
                  }  
        }
}

void cmdline(){
     cout << "\tC.L.O.S.E -- THE NEW COMMAND LINE INTERFACE\t" << endl;
     string inp;
     char date[20], time[20];
     _strdate(date);
     _strtime(time);
     do
     {
          cout << "|=>";
          cin >> inp;
          if(inp == "open"){
            system("open.exe");
            }
          if(inp == "new"){
            system("new.exe");
            }
          if(inp == "cls"){
            cls();
            }
          if(inp == "help"){
            help();
            }
          if(inp == "app"){
            system("append.exe");
            }
          if(inp == "find"){
            system("find.exe");
            }
          if(inp == "showdate"){
            cout << date << endl;
            }
          if(inp == "showtime"){
            cout << time << endl;
            }
          }while(inp != "quit");
     
     
     
          

}

int main(){
    splash();
    cmdline();
}
