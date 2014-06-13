#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define RED FOREGROUND_RED
#define GREEN FOREGROUND_GREEN
#define BLUE FOREGROUND_BLUE
#define MAX 100000000
#define in 1
#define out 0
/*
LYNCH-ENVY INC.
EDITOR WITH COLORSEARCH FUNCTION
BUILD 1 TO TEST OPEN/CLOSE FILE
*/

/*

COLORER TAKE 7 PRE-ALPHA TESTING
THIS BUILD USES STRUCTURE POINTERS WHICH HAVE BEEN INTRODUCED
FOR THE FIRST TIME IN THE ARCHITECTURE OF CLOSE_COLORER

THERE ARE TWO FUNCTIONS, ONE WHICH BINARY SEARCHES FOR THE TOKEN AND THE OTHER WHICH
COLORS THE TOKEN

(C)LYNCH-ENVY COMPUTERS INC 2013.

*/

/*
ADDENDUM ON 10TH JAN 2013
THIS BUILD HAS BEEN DEEMED TO BE STABLE AND FREE FOR DISTRIB.
STRUCT_POINT VARS HAVE BEEN SUCEESFULLY IMPLEMENTED ON LIBRARY CATALOGING.

*/
void colorer (char str[], int co);
struct syntaxh{
       char *wordptr;
       int color;
       };
struct searchstr{
       char *inp;
       int tcolor;
       };
main()
{
      char *synbox;
      char *search;
      synbox = (char *)malloc(MAX * sizeof(char));
      search = (char *)malloc(MAX * sizeof(char));
      int i,c;
      if(synbox != NULL)
      
      {
                for(i=0; i<=MAX && (c = getchar())!=EOF; ++i){
                                *(synbox+i) = c;
               }
               }
      
      printf("Which String To be Search For?");
      if(search != NULL){
                
                for(i=0; i<=MAX && (c = getchar())!=EOF; ++i){
                                *(search+i) = c;
                                }
                                }
      char delims[] = " ";
      char *result = NULL;
      result = strtok(synbox, delims);
      while(result!=NULL)
      {
                         if(strcmp(search, result)!=0)
                         {
                                               printf("%s", synbox);
                                               }
                         else
                         {
                             colorer(result, RED);
                             }
      }
                                               
      //FILE *fp;
      //fp = fopen("edit.c", "r");
      //char *alloc;
      //int c;
      //alloc = (char *)malloc(MAX * sizeof(char));
      //if(NULL==alloc){
      //                printf("Error, No memory available!!");
      //                }
      //else{
           //int i, state;
           //state = out;
           //for(i=0; i<=MAX && (c=getchar())!='\n' && state == out; ++i)
           //{        
           //                                    
           //                                *(alloc+i) = c;
                                           
                    
           //         }
           //system("cls");
           //printf("%s", alloc);
           //free(alloc);
           //alloc = NULL;
           //printf("%s", alloc);
           //free(alloc);
           //alloc = NULL;
           //}
      getch();
      }

void colorer (char str[], int color)
{
     HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE ); //stdout handle
  WORD wOldColorAttrs; //->set back to old color once used
  CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
   
  /*
   * First save the current color information
   */
  GetConsoleScreenBufferInfo(h, &csbiInfo);
  wOldColorAttrs = csbiInfo.wAttributes; 
   
  /*
   * Set the new color information
   */
  SetConsoleTextAttribute ( h, color | FOREGROUND_INTENSITY );
   
  printf (" %s ", str);
 
  /*
   * Restore the original colors
   */
  SetConsoleTextAttribute ( h, wOldColorAttrs);
  
  
}
    
