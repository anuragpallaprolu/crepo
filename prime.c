#include <stdio.h>
#define YES 1
#define NO 0

void primetester(int i);
main(){
       loop:;
       
       int num,i, j,prime;
       j=2;
       prime = YES;
       scanf("%d", &num);
                
                for(j=2; j<num && prime == YES; ++j){
                         if(num%j == 0){
                                  prime = NO;
                           }
                         
    
                    }
       if(prime == YES){
                printf("its a prime");
                }
       
                         
       getch();
       goto loop;
       }
       

