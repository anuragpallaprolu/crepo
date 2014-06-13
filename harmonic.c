#include <stdio.h>
#include <time.h>
#define L 10000
//harmonic sums


main()
{
      clock_t INIT, FINAL;
      INIT = clock();
      double s=0;
      unsigned long i;
      for(i=1; i<=L; ++i)
      {
               double t;
               t = 1.0/i;
               s = s + t;
               }
      
      printf("%lf\n", s);
      FINAL = clock();
      double time;
      time = difftime(FINAL, INIT);
      printf("%lf", time);
      getch();
      
      
      }
      
