#include <stdio.h>
#include <conio.h>
#include <windows.h>
//CLOSE_COLOR TAKE 1
//close_take2


main()
{
      
char str[1000000];
int i,c;
 for(i=0; i<=1000000 && (c=getchar())!=EOF; ++i)
      {
               str[i] = c;
               }

//colorer
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
  SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );
   
  printf ( "This is a test\n" );
 
  /*
   * Restore the original colors
   */
  SetConsoleTextAttribute ( h, wOldColorAttrs);
  
  getch();

//tokenizer ver 2
char delims[] = " ";
char *result = NULL;
result = strtok( str, delims );
while( result != NULL ) {
    printf( "%s\n", result );
    result = strtok( NULL, delims );
}
getch();
}
