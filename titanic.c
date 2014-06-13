#include <stdio.h>
#define MAX 1000


int pow(int b, int e);
int numsplit(int num, int store[]);
int numsize(int num);



main(){
       int numstore[MAX];
       int i=0,c;
       while((c=getchar())!='0'){
                                 scanf("%d", &numstore[i]);
                                 ++i;
                                 }
                printf("%d", numstore[1]+numstore[0]);
                getch();
                             }

int pow(int b, int e){
             if (e == 0) return 1;
             else return(b * pow(b, e-1));
             
}

int numsize(int num){
    int i;
    for(i=1; i<=100; ++i) printf("%d\n", pow(10,i));
    return 0;
}


int numsplit(int num, int store[]){
    int i;
    int powr[100];
    for(i=1; i<=100; ++i) powr[i] = pow(10,i);
    store[0] = num%powr[1];

}
