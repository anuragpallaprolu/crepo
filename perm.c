#include <stdio.h>


// UNDER TESTING/////////////////WRONG CODE////////////////PL. IGNORE

int pow(int b, int e);
main(){
       int one,n,j,d,p;
       j=1;
       d=0;
       one=0;
       n = 45671;
       int place[10];
       place[0] = 0;
       for(j=1; j<=100; ++j){
                int q;
                q = pow(10, j);
                if(n<q){
                        printf("The Number of Digits is %d\n", j);
                        
                        break;
                        }
                        }
       
       for(d=1; d<=j; ++d){
                place[d]=0;
                }
           
       for(d=1; d<=j; ++d){
                place[d]=((n%pow(10, d))-place[d-1])/pow(10, d-1);
                }
       for(d=1; d<=j; ++d){
       printf("%d\n", place[d]);
       }
       getch();
       
       }
       
       
int pow(int b, int e){
             if (e == 0) return 1;
             else return(b * pow(b, e-1));
             
} 
