#include <stdio.h>
#define YES 1
#define NO 0

int primetester(int i);
main(){
       int num,i, j,prime;
       j=2;
       prime = YES;
       scanf("%d", &num);
       for(i=2; i<=num; ++i){
               primetester(i);
               }
               
       
                         
       getch();
       }
       
int primetester(int i){
     int j,prime,c;
     
     prime = YES;
      for(j=2; j<i && prime == YES; ++j){
                         if((i%j == 0) && (i%2 != 0) &&  (i % 4 == 3)){
                                  prime = NO;
                                  printf("%d\t", i);
                                  
                           }
                             else if((i%j == 0) && (i%2 != 0) &&  (i % 4 == 1)){
                                  prime = NO;
                                  printf("%d\t", i);
                       
                       }
    
                    }
       if(prime == YES){
                
                ++c;       
                }
       
}
     
