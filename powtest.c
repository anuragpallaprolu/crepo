#include <stdio.h>
int pow(int b, int e);

main(){
       printf("%d", pow(2, 15));
       getch();
       }
int pow(int b, int e){
             if (e == 0) return 1;
             else return(b * pow(b, e-1));
             
} 
