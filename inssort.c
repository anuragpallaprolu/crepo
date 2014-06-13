#include <stdio.h>


//insertion sort
main(){

       int inp[8], i, k;
       k=0;
       for(i=0; i<=8 ;++i){
                scanf("%d\n", &inp[i]);
                }
       loop:;
       for(k=0; k<=7; ++k){
       i=k;         
       if(inp[i] > inp[i+1]){
                 int t,t1;
                 t=inp[i];
                 t1=inp[i+1];
                 inp[i] = t;
                 inp[i+1] = t1;
                 inp[i] = t1;
                 inp[i+1] = t;
                 }     
                 }
       for(i=0; i<=8 ; ++i){
                printf("%d,", inp[i]);
                
                }
                printf("\n");
        getch();        
       goto loop;          
       
                                     
       getch();
         
       }

