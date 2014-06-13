#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define RED FOREGROUND_RED
#define GREEN FOREGROUND_GREEN
#define BLUE FOREGROUND_BLUE
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
struct syntaxbox{
       char *wordptr;
       int color;
       }syntax[] = {
       "this", RED,
       "This", RED,
       "(char", RED,
       "(int", RED,
       "\n#define", BLUE,
       "#include", BLUE,
       };
       

       

main()
{
      char str[10000];
      int j,c;
      for(j=0; j<=10000 && (c=getchar())!=EOF; ++j)
      {
               str[j] =c;
               }
               system("cls");
      char delims[] = " ";
      char *result = NULL;
      result = strtok( str, delims );
      while( result != NULL ) {
             if (strcmp(syntax[0].wordptr, result)!=0 && strcmp(syntax[1].wordptr, result)!=0 && strcmp(syntax[2].wordptr, result)!=0 && strcmp(syntax[3].wordptr, result)!=0 && strcmp(syntax[4].wordptr, result)!=0 && strcmp(syntax[5].wordptr, result)!=0)
             {
                                          printf( "%s ", result );                             
                                          }
             
             else if(strcmp(syntax[0].wordptr, result)==0) {
                  colorer(result, RED);
                  }
             else if(strcmp(syntax[1].wordptr, result)==0) {
                  colorer(result, RED);
                  }
             else if(strcmp(syntax[2].wordptr, result)==0) {
                  colorer(result, RED);
                  }
             else if(strcmp(syntax[3].wordptr, result)==0) {
                  colorer(result, RED);
                  }
             else if(strcmp(syntax[4].wordptr, result)==0) {
                  colorer(result, BLUE);
                  }
             else if(strcmp(syntax[5].wordptr, result)==0) {
                  colorer(result, BLUE);
                  }
             
             
             
             result = strtok( NULL, delims );
             }
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
           
