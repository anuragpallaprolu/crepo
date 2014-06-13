#include <stdio.h>

//Graphics toolkit

struct point{
       int x;
       int y;
       };

struct rectangle{
       struct point p1;
       struct point p2;
       };

main()
{
      int t;
      struct point i = {0,0};
      struct point j = {7,7};
      struct rectangle r = {i, j};
      struct rectangle *rpt;
      rpt = &r;
      t = rpt->p1.x;
      printf("%d", t);
      getch();
      }
      
