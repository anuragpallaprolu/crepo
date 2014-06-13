/* Presented by www.ncooltips.com
 * Drawing a line
 */
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
 
void main()
{
int gdriver=DETECT,gmode=0;
/* Open graphic mode
Detect grahic driver and supporting mode
 automatically*/
initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
 
/* draw  line */
line(0,0,getmaxx(),getmaxy());
 
getch();
 
/*Close graphic mode */
closegraph();
 
}
