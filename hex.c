#include <stdio.h>

main(){
       int i,j,k,t[10000], p[10000], h[10000];
       for(i=0; i<=10000; ++i){
                t[i] = h[i] = p[i] = 0;
                }
       
       for(i=0; i<=10000; ++i){
                t[i] = i*(i+1)/2;
                p[i] = i*(3*i - 1)/2;
                h[i] = i*(2*i - 1);
                }
       
       for(k=0; k<=1000; ++k){
                for(j=0; j<=1000; ++j){
                         if(h[k] == p[j]){
                                 for(i=0; i<=1000; ++i){
                                          if(t[i]==h[k]){
                                                         printf("%d\t%d\t%d\n", i, j, k);
                                                         }
                                                         }
                                                         
                                  }
                         }
                }
                
                
                getch();
                
}
