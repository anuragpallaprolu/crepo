#include <stdio.h>

void clfunct(char inp[], int c);
int inpline(char in[], int l);
main(){
       int c,d;
       char in[1000], inp[1000], out[1000];
       inpline(in, 1000);
       clfunct(in, 'd');
       printf("%s", in);
       getch();
                    }
       
int inpline(char in[], int len){
     int c;
     int j, i;
     j=0;
     for(i=0; i<=1000; ++i){
              in[i] = 0;
              }
              
     while((c=getchar())!='\n' && j<1000){
                  
                   in[j] = c;
                   ++j;
                   }
                             
                            
                   
     return j;
     }
     
void clfunct(char inp[], int c){
     int i;
     for(i=0; i<=1000; ++i){
              if(inp[i] == 'd'){
                        inp[i] = ' ';
                        }
                   
                   }
                   
                   }
                       

                                
