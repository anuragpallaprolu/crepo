#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx =0, midy = 0;
   int stagex=10,stagey=400, stageh=60;
   int legsize=30;
   int left = 0;
   int entered = 0;
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");
   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   /* set the fill style */
   setfillstyle(6,GREEN) ;
   /* draw the stage */
   bar3d(stagex, stagey, 600,400+stageh,25, 1);
   while(1)     {
   /*body*/
   setcolor(RED);
   line(midx-30,midy-40,midx+30,midy+40);
   setcolor(RED) ;
   line(midx-30,midy+40,midx+30,midy-40);
   /*neck & waist*/
   setcolor(YELLOW);
   line(midx-30,midy-40,midx+30,midy-40);
   setcolor(YELLOW);
   line(midx-30,midy+40,midx+30,midy+40);
   setfillstyle(7,MAGENTA) ;
   bar(midx-30,midy+42,midx+30,midy+80);
   /*legs*/
   setfillstyle(2,YELLOW);
   bar(midx-30,midy+80,midx-20,midy+80+legsize);
   bar(midx+20,midy+80,midx+30,midy+80+legsize);

   /* throat */
   setfillstyle(2,YELLOW);
   bar(midx-5,midy-50,midx+5,midy-40);
   /* head */
   setfillstyle(1,CYAN);
   fillellipse(midx,midy-60,10,10);
   setfillstyle(1,BLACK);
   fillellipse(midx-4,midy-60,2,2);
   fillellipse(midx+4,midy-60,2,2);

   int choice = rand()%3;
   int t = rand()%20;

   for(int i=0;i<t;i++) {
   if(choice == 0){
   /* hands */
   setcolor(YELLOW);
   line(midx-30,midy-40,midx-40-i,midy+15-i);
   line(midx+30,midy-40,midx+40+i,midy+15-i);
   line(midx-40-i,midy+15-i,midx-80-i,midy+10-i);
   line(midx+40+i,midy+15-i,midx+80+i,midy+10-i);
   delay(20);
   setcolor(BLACK);
   line(midx-30,midy-40,midx-40-i,midy+15-i);
   line(midx+30,midy-40,midx+40+i,midy+15-i);
   line(midx-40-i,midy+15-i,midx-80-i,midy+10-i);
   line(midx+40+i,midy+15-i,midx+80+i,midy+10-i);
   }
   else if( choice == 1){
   /* hands */
   setcolor(YELLOW);
   line(midx-30,midy-40,midx-60-i,midy+15-i);
   line(midx+30,midy-40,midx+40+i,midy+15-i);
   line(midx-60-i,midy+15-i,midx-60-i,midy+50-i);
   line(midx+40+i,midy+15-i,midx+60-i,midy+50-i);
   delay(20);
   setcolor(BLACK);
   line(midx-30,midy-40,midx-60-i,midy+15-i);
   line(midx+30,midy-40,midx+40+i,midy+15-i);
   line(midx-60-i,midy+15-i,midx-60-i,midy+50-i);
   line(midx+40+i,midy+15-i,midx+60-i,midy+50-i);
   }
   else if( choice == 2){
   /* hands */
   setcolor(YELLOW);
   line(midx-30,midy-40,midx-60-i,midy+15-i);
   line(midx+30,midy-40,midx+40+i,midy+15-i);
   line(midx-60-i,midy+15-i,midx-60-i,midy-50-i*i/8);
   line(midx+40+i,midy+15-i,midx+60-i,midy-50-i*i/8);
   delay(20);
   setcolor(BLACK);
   line(midx-30,midy-40,midx-60-i,midy+15-i);
   line(midx+30,midy-40,midx+40+i,midy+15-i);
   line(midx-60-i,midy+15-i,midx-60-i,midy-50-i*i/8);
   line(midx+40+i,midy+15-i,midx+60-i,midy-50-i*i/8);
   }

   }
   if(entered==1)
            delay(rand()%100);
   else
            delay(rand()%20);

    /* rewritting the system */
    setcolor(BLACK);
    setfillstyle(1,BLACK);
    /*body*/
   line(midx-30,midy-40,midx+30,midy+40);
   line(midx-30,midy+40,midx+30,midy-40);
   /*neck & waist*/
   line(midx-30,midy-40,midx+30,midy-40);
   line(midx-30,midy+40,midx+30,midy+40);
   bar(midx-30,midy+42,midx+30,midy+80);
   /*legs*/
   bar(midx-30,midy+80,midx-20,midy+80+legsize);
   bar(midx+20,midy+80,midx+30,midy+80+legsize);
   /* throat */
   bar(midx-5,midy-50,midx+5,midy-40);
   /* head */
   fillellipse(midx,midy-60,10,10);
   fillellipse(midx-4,midy-60,2,2);
   fillellipse(midx+4,midy-60,2,2);
   /* hands */
   line(midx-30,midy-40,midx-40,midy-70);

   if(midx>=500)
             left =1;
   else if (midx <=50)
            left = 0;
   if(entered==1)           {
   if(left == 1)
   midx-=10;
   else if(left == 0)
   midx +=10;
   }

   if(entered == 0){
   midx+=10;
   midy+=15;
   if(midy >= 270) entered =1;
   }
 }
   getch();

   closegraph();
   return 0;
}                      
