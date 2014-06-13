#include <stdio.h>

int pow(int base, int exp);
main(){
       printf("Enter number = \n");
       int n;
       scanf("%d", &n);
       int i;
       int k;
       for(i=1; i<=n; ++i){
                int numarray[10];
                int j;
                for(j=0; j<=10; ++j){
                         numarray[j] = i % pow(10, j);
                         int k;
                         if(numarray[j] == 1){
                                        ++k;
                                        }
                                        }
                                        }
                                        printf("%d", k);
                                        getch();
                                        
                                        
                         
       }
       int pow(int b, int e){
             if (e == 0) return 1;
             else return(b * pow(b, e-1));
             
} 

 
             
    
