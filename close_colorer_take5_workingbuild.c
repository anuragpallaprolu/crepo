#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define RED FOREGROUND_RED
#define GREEN FOREGROUND_GREEN
#define BLUE FOREGROUND_BLUE
//CLOSE_COLOR TAKE 1
//close_take2
//closecolor_take4
void colorer(char str[], int co);

main()
{
      
char str[1000000];
int i,c;
 for(i=0; i<=1000000 && (c=getchar())!=EOF; ++i)
      {
               str[i] = c;
               }


system("cls");
//tokenizer ver 2
char delims[] = " ";
char inte[] = "int";
char chare[] = "char";
char *result = NULL;
result = strtok( str, delims ); //tokenise the input string with the delimiter and give the pointer to each token to return variable
while( result != NULL ) { //while result pointer is not null 
                         


         if(strcmp(result, inte)!=0 && strcmp(result, chare)!=0){                                  
             printf( "%s ", result );//print the token to which the pointer points to
             }
    
    
        //else 
        else
        {
            if(strcmp(result, chare)==0){
             colorer(result, BLUE);
             
             }
            else colorer(result, RED);
            } 
        
        
    result = strtok( NULL, delims );//set the pointer to the next delimiter position
}



getch();
}
//colorer using the windows api
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
   
  printf ("%s ", str);
 
  /*
   * Restore the original colors
   */
  SetConsoleTextAttribute ( h, wOldColorAttrs);
  
  
}
