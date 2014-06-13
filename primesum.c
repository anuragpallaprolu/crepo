#include <stdio.h>
#define YES 1
#define NO 0

int primetester(int i);
main(){
       int num,i, j,k,prime;
       j=2;
       prime = YES;
       scanf("%d", &num);
       int storage[num];
       for(i=2; i<=num; ++i){
               primetester(i);
               k = primetester(i);
               storage[i] = k;
                        
               }
       for(i=2; i<=num; ++i){
                printf("%d\n", storage[i]);
                }
                
                        
               
               
       
                         
       getch();
       }
       
int primetester(int i){
     int j,prime,c,r;
     
     prime = YES;
      for(j=2; j<i && prime == YES; ++j){
                         if(i%j == 0){
                                  prime = NO;
                                  
                           }
                         
    
                    }
       if(prime == YES){
                i = r;
                ++c;
                return i;       
                }
                
}      
     
