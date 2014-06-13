#include <stdio.h>

//Length Return Prog

main()
{
      int order_r, order_c,p;
      scanf("%d", &order_r);
      scanf("%d", &order_c);
      p = (order_r*order_c)-1;
      char matrix[p];
      int i;
      int j;
      for(i=0; i<=p; ++i){
               scanf("%c\n", &matrix[i]);
               }
      for(i=0; i<=order_r-1; ++i){
               printf("\n");
               for(j=(i*order_c); j<=((order_c)*(i+1))-1; ++j){
                                printf("%c\t", matrix[j]);
                                }
               }
      
      getch();
}
