#include <stdio.h>

int factorial(int n);
int c(int i, int j);

int factorial(int n){
    if(n==0){
             return 1;
             }
    else{
         return(n*factorial(n-1));
         }
}

int c(int i, int j){
    int p;
    if(i>=j){
    p = factorial(i)/(factorial(j)*factorial(i-j)) ;
    }
    else{
         p=0;
         }
    return p;
}
    

main(){
       int i,j;
       for(i=1; i<=20; ++i){
                printf("\n1\t");
                for(j=1; j<=i; ++j){
                         
                         printf("%d\t", c(i,j));
                         }
                         }
                         
       getch();
       
       }
       
    
