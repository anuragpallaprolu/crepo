#include <stdio.h>
#define N 10080

int sum(int array[]);
main(){
       
       int n, j, ar[N]; 
       n= N;
       ar[0] = 0;
       for(j=1; j<=N; ++j){
                if(N % j == 0){
                      ar[j] = j;
                      }
                      else{
                           ar[j] = 0;
                           }
                           }
       for(j=0; j<=N; ++j){
                 if(ar[j] != 0){
                 printf(",%d", ar[j]);
                 }
                 }
       int s;
       s=0;
       for(j=0; j<=N; ++j){
                s = s + ar[j];
                }
                printf("\n\n%d", s);
                getch();
                
                 }
          
    
                 
                                               
