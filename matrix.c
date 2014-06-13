#include <stdio.h>
#define in 1
#define out 0
#define MAX_ROW 5
#define MAX_COL 5
//Matrix printer

main()
{
      int col[MAX_ROW][MAX_COL],myptr;
      int order, state;
      printf("please enter the order of the matrix");
      scanf("%d", &order);
      getch();
      if ((order > MAX_ROW) || (order > MAX_COL)) {
                 printf("\too big to handle..");
                 goto abort_program;
                 }
      int i, j;
      for(i=0; i<=order-1; ++i){
               printf("\n");
               for(j=0; j<=order-1; ++j){
                        printf("Please enter the %dth row and %dth column", i, j);
                        scanf("%d", &col[i][j]);
                        }
               }
      myptr = &col;
       for(i=0; i<4 ;  ++i){
               printf("%d\t", *(myptr+i));
                                       }

abort_program:      getch();
      
}
      

