#include <stdio.h>
#define in 1
#define out 0

int sumarray(int array[], int lim);
main(){
        loop:;          
       int c, s[200], i, d, n,j;
       for(i=0; i<=200; ++i){
                s[i]=0;
                }
       for(i=0; i<=200 && (c=getchar())!='\n' ; ++i){
                s[i]=c-96;
                }
       
                d=sumarray(s, 200);
                printf("\n%d\n", d);
                for(n=0; n<=100; ++n){
                         int t, state;
                         t = n*(n+1)/2;
                         if(d == t){
                              printf("Yes!");
                              }
                         
                              
                         }
       getch();
       goto loop;
       }

int sumarray(int a[], int l){
    int s, i;
    s=0;
    for(i=0; i<=l; ++i){
             s = s + a[i];
             }
    return s;
}
             

