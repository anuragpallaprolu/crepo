#include <stdio.h>
//NO OF ZEROES IN N!
//Copyright 2012 Anurag Pallaprolu

int pow(int b, int e);       //Exponentiaton operator
int primepow(int n, int p);  //Maximum power of a prime p in n!

main(){                // Main Function
       int inp; // User Input
       printf("Please enter number whose number of zeros is sought after:\n"); // Prompt
       scanf("%d", &inp); //Scan Input and store
       int i,j; //define two comparing operators
       i = primepow(inp, 2); //i is the maximum exponent of 2 in inp
       j = primepow(inp, 5); // j is the maximum exponent of 5 in inp
       if(i<j){
               printf("The no of zeros are\n%d", i); //Here the main comparison of which exponent s greater and why takes place.
                          }                          //If 5s are greater then answer is no of 5s and et cetera
       else if(i>j){
            printf("The no of zeroes are\n%d", j);
            }
            getch();
            
              }
       
int pow(int b, int e){
             if (e == 0) return 1;
             else return(b * pow(b, e-1)); // POWER RECURSION 
             
}

int primepow(int n, int p){
    int j,i,s; // j is the while counter, i is the integer part of the exponential ratio and s is the sum counter.
    j=0;//INITIALIZING...
    s=0;
    while(j>=0)
    {
                ++j;//Counter for while loop
                i  = n/(pow(p,j)) ;//every ratio is counted for
                s = s + i;//the integer part/ floor of i is taken and added to the sum counter
                
                if(i==0){
                         break;
                           }
    }
    return s;
}
             
                                       
            
