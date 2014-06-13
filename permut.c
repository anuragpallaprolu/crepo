#include <stdio.h>
#define max 101
//Permutator V1

void permutator(int arr[], int inl, int maxlen);
void follower(int arr[], int inl, int hol_el, int maxlen);
main()
{
      int perm[max];
      int n;
      scanf("%d", &n);
      //int pmain[2][6]; // In general pmain[no of entries][no. of rearrangements assuming distinct numbers, i.e fac[n]]
      int i;
      for(i=0; i<=n-1; ++i)
      {
               scanf("%d", &perm[i]);
               }
      int k;
      k= perm[1];
      permutator(perm, n, max);
      follower(perm, n, 0, max);     
      
      
      
      
      
      
      
      
      
      
      
      
      
      getch();
}
void permutator(int perm[], int inl, int maxlen)
{
      int i;
      for(i=0; i<=(maxlen-inl); ++i)
      {
               perm[i+inl] = perm[i];
               }
      int j;
      for(j=0; j<=inl-1; ++j){
               
      for(i=j; i<=inl+j-1; ++i)
      {
               printf("%d," ,perm[i]);
               }
      printf("\n");
      }
}

void follower(int perm[], int inl, int hold, int maxlen)
{
     int i;
      for(i=0; i<=(maxlen-inl); ++i)
      {
               perm[i+inl] = perm[i];
               }
      int j;
      for(j=0; j<=inl-1; ++j){
               
      for(i=j; i<=inl+j-1; ++i)
      {
               if(i!=hold)
               {
                          
                          printf("%d," ,perm[i]);
                          }
               }
               printf("\n");
               }
      
      
     
}
