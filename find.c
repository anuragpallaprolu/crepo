#include <stdio.h>
#include <string.h>
#define MAXSIZE 100000
#define FOUND 1
#define NOT_FOUND 0
//find.c
//authentic_find_program
void sf(char searchstr[], char inpstr[], int lim);
main()
{
      char *line, input[MAXSIZE], search[MAXSIZE];
      int i;
      int c;
      for(i=0; i<=MAXSIZE && (c=getchar())!=EOF; ++i)
      {
               input[i] = c;
               }
      printf("Enter Search String");
      for(i=0; i<=MAXSIZE && (c=getchar())!=EOF; ++i)
      {
               search[i] = c;
               }
      sf(search, input, MAXSIZE);
      getch();
      }

void sf(char search[], char inp[], int l)
{
     int i,j,c,state;
     i=0;
     c=0;
     for(i=0; i<=strlen(inp); ++i)
     {
              if(inp[i]==search[0])
              {
                                   for(j=1; j<=strlen(search); ++j)
                                   {
                                            if(inp[i+j] == search[j])
                                            {
                                                        c=i;
                                                        state = FOUND;
                                                        }
                                            else{
                                                 state = NOT_FOUND;
                                                 }
                                                 
                                            }
                                            
              }
     }
     if(state == FOUND)
     {
              printf("Yes");
              printf("%d", c);
              }
              
     
}
      
      
