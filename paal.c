#include <stdio.h>
#include <ctype.h>
main(){
       char arr[5000],ar1[2500],ar2[2500], arr1[2500], arr2[5000];
       int i,c,j,q,n;
       for(i=0; i<=5000 && (c=getchar())!='\n'; ++i){
                arr[i] = c;
                }
       n = i-1;
       i = 0;
       while(isdigit(arr[i])!=0){
                  ar1[i]= arr[i];
                  arr1[i] = atoi(ar1[i]);
                  printf("%c", arr[i]);
                  ++i;
                  }
       q = i-1;
       while(arr[i-1]!='\0'){
                           ar2[i] = arr[i+1];
                           arr2[i] = atoi(ar2[i]);
                           printf("%c", ar2[i]);
                           ++i;
                           }
       
       
       getch();
       
       
       
                }
