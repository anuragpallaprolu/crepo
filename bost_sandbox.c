#include <stdio.h>

main(){
       int numofcases,i,j,k;
       scanf("%d", &numofcases);
       int input[numofcases][4];
       for(i=1; i<=numofcases; ++i){
                scanf("%d %d %d", &input[i][1], &input[i][2], &input[i][3]);
                }
       /*         
       for(i=1; i<=numofcases; ++i){
                printf("%d %d %d\n", input[i][1], input[i][2], input[i][3]);
                }
       */
       
       int tplayed[numofcases], pos[numofcases];
       for(i=1; i<=numofcases; ++i){
                int q = input[i][2] * input[i][1];
                int r = (q / input[i][3]) + 1;
                if(r >= input[i][1]) input[i][4] = 1;
                else input[i][4] = 0;
                
                         }
       for(i=1; i<=numofcases; ++i){
                if(input[i][4] == 0){
                               printf("#%d:Broken\n", i);
                               }
                else printf("#%d:Possible\n", i);
                }
       
       getch();
                }
           
