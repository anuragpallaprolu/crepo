#include <stdio.h>
//lychrel number //palindrome finder
main()
{
      char input[100], out[100];
      int c, i;
      int l;      
      for(i=0; i<=100 ; ++i){
               if((c=getchar())!=EOF){
                                      
               input[i]=c;
               }
               else{
                    l=i;
                    break;
                    }
               }
      char rev[l];
      printf("%d\n", l);
      for(i=0; i<=l; ++i)
      {
               printf("%c", input[l-i]);
               }
      printf("\n");
      int outp[l];
      for(i=0; i<=l; ++i){
               outp[i] = input[i] + input[l-i];
               }
      for(i=0; i<=l; ++i)
      {
               printf("%d", outp[i]);
               }
      
      getch();
}
      
      
      
