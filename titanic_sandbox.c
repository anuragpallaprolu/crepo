#include <stdio.h>
#define MAX 1000


int pow(int b, int e);
int numsplit(int num, int store[]);
int recombine(int inpa[]);
int numsize(int num);



main(){
       int num,n_siz,i;
       scanf("%d", &num);
       n_siz = numsize(num);
       int store[MAX];
       numsplit(num, store);
       for(i=1; i<=n_siz; ++i) printf("%d\n", store[i]);
       getch();
                             }

int pow(int b, int e){
             if (e == 0) return 1;
             else return(b * pow(b, e-1));
             
}

int numsize(int n){
    int j;
    for(j=1; j<=100; ++j){
                int q;
                q = pow(10, j);
                if(n<q){
                        printf("The Number of Digits is %d\n", j);
                        return j;
                        }
                        }
}


int numsplit(int num, int store[]){
    int i;
    for(i=1; i<=numsize(num); ++i) store[i] = 0;
    for(i=1; i<=numsize(num); ++i){
              store[i]=((num%pow(10, i))-store[i-1])/pow(10, i-1);
              }
              
}
