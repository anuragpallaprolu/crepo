#include <stdio.h>

main()
{
      int c, i;
      char arr[1000];
      for(i=0; i<=1000 && (c=getchar())!=' '; ++i)
      {
               arr[i] = c;
               }
      printf("%s", arr);
      for(i=1; i<=strlen(arr); ++i)
      {
               printf("\\");
               }
      getch();
}
      
