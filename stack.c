#include <stdio.h>
#define MAX 1000
//getline_pointer_version

int getline(char *inp);

main()
{
      int d;
      char input[MAX], *inputp;
      *inputp = input[0];
      d = getline(inputp);
      printf("%d", d);
      getch();
      
}       

int getline(char *inp)
{
    int i=0;
    int c;
    while((c=getchar())!='\n')
    {
                              ++i;
                              *(inp++) = c;
                              }
    return i;
}
