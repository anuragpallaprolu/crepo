#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define RED FOREGROUND_RED
#define GREEN FOREGROUND_GREEN
#define BLUE FOREGROUND_BLUE
//CLOSE_COLOR TAKE 1
//close_take2
void colorer(char str[], int co);

main()
{
      
char str[1000000];
int i,c;
 for(i=0; i<=1000000 && (c=getchar())!=EOF; ++i)
      {
               str[i] = c;
               }



//tokenizer ver 2
char delims[] = " ";
char *result = NULL;
result = strtok( str, delims );
while( result != NULL ) {
       if(result==" int"){
    colorer(result, RED);
}
    printf( "%s\n", result );
    result = strtok( NULL, delims );
}



getch();
}

void colorer(char str[], int color)
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
   
  printf ("%s\n", str);
 
  /*
   * Restore the original colors
   */
  SetConsoleTextAttribute ( h, wOldColorAttrs);
  
  
}
