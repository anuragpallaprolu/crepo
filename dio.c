#include <stdio.h>

main(){
       int num, i, j, k, l,c;
       c=0;
       scanf("%d", &num);
       for(i=0; i<=num; ++i){
                j=num-i;
                for(k=0; k<=num; ++k){
                         l = j - k;
                         ++c;
                         printf("%d\t%d\t%d\n", i, k , l);
                         }
                                   
       
                }
                printf("\n\nThere are a total of %d solutions", c);
                
                getch();
       }
