#include <stdio.h>

void clfunct(char inp[], int c);
int inpline(char in[], int l);
main(){
       int c,d,q;
       char in[1000], inp[1000], out[1000];
       loop: ;
       inpline(in, 1000);
       clfunct(in, 1000);
       printf("%s", in);
       goto loop;
                    }
       
int inpline(char in[], int len){
     int c;
     int j, i;
     j=0;
     for(i=0; i<=1000; ++i){
              in[i] = 0;
              }
              
     while((c=getchar())!=EOF && j<1000){
                  
                   in[j] = c;
                   ++j;
                   
                   }
     for(i=j; i<=1000; ++i){
              
              in[i] = -i;
              }                        
                            
                   
     return j;
     }
     
void clfunct(char inp[], int c){
     int i;
     for(i=0; i<=c; ++i){
              if(inp[i] != EOF){
                        inp[i] = inp[i]+i;
                        
                        }
                   
                   }
                   
                   }
                       

                                
