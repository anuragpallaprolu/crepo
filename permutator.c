#include <stdio.h>

//Permutator

main()
{
      int perm[101];
      int n;
      scanf("%d", &n);
      int pmain[2][6]; // In general pmain[no of entries][no. of rearrangements assuming distinct numbers, i.e fac[n]]
      int i;
      for(i=0; i<=n-1; ++i)
      {
               scanf("%d", &perm[i]);
               }
      for(i=0; i<=(101-n); ++i)
      {
               perm[i+n] = perm[i];
               }
      int j;
      for(j=0; j<=n-1; ++j){
               
      for(i=j; i<=n+j-1; ++i)
      {
               printf("%d," ,perm[i]);
               }
      printf("\n");
      }
      int t;
      t= n-1;
      for(i=0; i<=t-1; ++i)
      {
               perm[i+1] = perm[i];
               }
      for(i=0; i<=(101-n); ++i)
      {
               perm[i+n] = perm[i];
               }
      int j;
      for(j=0; j<=n-1; ++j){
               
      for(i=j; i<=n+j-1; ++i)
      {
               printf("%d," ,perm[i]);
               }
      printf("\n");
      }
      
            
      getch();

}
