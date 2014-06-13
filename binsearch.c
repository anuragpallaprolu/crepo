#include <stdio.h>

//BINARY SEARCH IN C
//V1

main(){
       //takes input to array
       //takes given token to be searched
       //implements the binsearch algorithm.
       int k, lim;
       printf("How many entries do you have?");
       scanf("%d", &lim);
       int input[lim];
       for(k=1; k<=lim-1; ++k){
                scanf("%d", &input[k]);
                }
       int low, high;
       low = input[0];
       high = input[lim];
       printf("Please enter the lower bound:");
       scanf("%d", &input[0]);
       printf("Please enter the upper bound:");
       scanf("%d", &input[lim]);
       int mid;
       int tofind;
       scanf("%d", &tofind);
       while(low<high){
                       mid = (low+high)/2
                       if(tofind > mid){
                                 
