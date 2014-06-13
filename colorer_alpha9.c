#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define MAX 1000000
main()
{
      int c, i;
      char inp[MAX];
      for(i=0; i<=MAX && (c=getchar())!=' '; ++i)
      {
                                       inp[i] = c; 
                                        }
      printf("%s", inp);
      getch();
                               
      }
