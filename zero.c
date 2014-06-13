#include <stdio.h>

int pow(int b, int e);
int primepow(int n, int p);
int factorial(int n);
main(){
       int num;
       num = 60;
       int i,j;
       i = primepow(num, 2);
       j = primepow(num, 5);
       if(i<j){
               printf("The no of zeros are\n%d", i);
               }
       else if(i>j){
            printf("The no of zeroes are\n%d", j);
            }
            getch();
            
              }
       
int pow(int b, int e){
             if (e == 0) return 1;
             else return(b * pow(b, e-1));
             
}

int factorial(int n){
    if(n==0){
             return 1;
             }
    else{
         return(n*factorial(n-1));
         }
}
int primepow(int n, int p){
    int j,k[10000],s;
    j=0;
    s=0;
    while(j>=0)
    {
                ++j;
                k[j]  = n/(pow(p,j)) ;
                s = s + k[j];
                
                if(k[j]==0){
                         break;
                           }
    }
    return s;
}
             
                                       
            
