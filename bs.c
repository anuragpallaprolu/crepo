#include <stdio.h>
#define in 1
#define out 0

//binsearch.c
int min(int inp[], int n);
int maxim(int inp[], int n);
main(){
       int low, high, mid, i,tosearch,num; // Lower Bound, Upper Bound, Midval, To Search, The number of entries
       scanf("%d", &num);
       int input[num]; //initialize array wrt no of entries
       for(i=0; i<=num; ++i){
                scanf("%d", &input[i]);
                }
       
       low = min(input, num);
       printf("%d", low);
       getch();
       
       
       scanf("What to search %d", &tosearch);
       
       while(low<=high){
                        mid = (low+high)/2;
                        if(tosearch<mid){
                                  high = mid - 1;
                                  }
                        else if(tosearch>mid){
                                       low = mid + 1;
                                       }
                        else{
                             printf("found");
                             getch();
                             }
                        }
       getch();
       }

int min(int inp[], int n){
    int i,j,state;
    j=0;
    state = out;
    for(i=0; i<=n && state == out ; ++i){
             state = in;
             for(j=i+1; j<=n && state == in; ++j){
                      if(inp[0]<inp[j]){
                                        state = out;
                                        return inp[0];
                                        }
                      else if(i>0){
                           int k;
                           k=1;
                           while(inp[i-k] > inp[i]){
                                          ++k;
                                          if(inp[i]<inp[j]){
                                                            state = out;
                                                            return inp[i];
                                                            }
                                          }
                           }
                      else{
                           state = in;
                           }
                      
                      }
             }
}
                      
    
