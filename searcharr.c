#include <stdio.h>
#define maxlen 10000
#define in 1
#define out 0
#include <string.h>
//string searcher

void search(char inp[], char searchstr[], int l);

main(){
       char input[maxlen], searchstr[maxlen];
       int d, c, i;
       
       d=0;
       i=0;
       for(d=0; d<=maxlen && (c=getchar())!=EOF; ++d){
                input[d] = c;
                }
       printf("What would you like to search?");
       for(i=0; i<=maxlen && (c=getchar())!=EOF; ++i){
                searchstr[i] = c;
                }
       search(input, searchstr ,maxlen);
       printf("\n%s", searchstr);
       getch();
       }
             

void search(char inp[], char searchstr[], int l){
     int i, j, state;
     i=0;
     while(i>=0 && i<=strlen(inp)){
                 ++i;
                 j=0;
                 while(inp[i-1] == searchstr[j]){
                                ++j;        
                                    printf("match");
                                    }
                          }
                 
                 
                      
}
                       
