#include <stdio.h>
#include <string.h>
#define MAXSIZE 100000
#define FOUND 1
#define NOT_FOUND 0

//find advance
void sf(char searchstr[], char inpstr[], int lim);

main(int argc, char *argv[])
{
         if(argc!=2)
         {
                    printf("wrong input");
                    }
         else
         {
             sf(arg
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
