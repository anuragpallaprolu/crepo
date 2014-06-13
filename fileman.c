
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define RED FOREGROUND_RED
#define GREEN FOREGROUND_GREEN
#define BLUE FOREGROUND_BLUE

void colorer (char str[], int co);
main()
{
        FILE *fp;
        char fname[20];
        printf("WELCOME TO FILEMAN V 0.1\n");
        char bufsiz[1000];
        scanf("%s", fname);
        fp = fopen(fname, "r");
        if(fp!=NULL){
                printf("Succesfully  Read The File\n");
                //system("dir");
                while(fgets(bufsiz,1000,fp)!=NULL)
                                                  {
                                                  printf("%s", bufsiz);
                                                  }
                getch();
                     }
                     else
                     {
                         printf("FILEMAN : No such file found. exiting.....\n");
                         goto end;
                         }
                     

getch();

//////////////////////////////////

char *inp;
scanf("%s", inp);
//struct synbox{
//       char *wordptr;
//       int color;
//       }synt[] = {
//               inp, RED,
//               };
       
       while(fgets(bufsiz,1000,fp)!=NULL)
                                         {
                                              char delims[] = " ";
                                              char *result = NULL;
                                              result = strtok( bufsiz, delims );
                                               while( result != NULL ) {
                                                      if(strcmp(inp, result)!=0){
                                                                              printf("%s", bufsiz);
                                                                              }
                                                      else
                                                      {
                                                          colorer(result, RED);
                                                          }
                    
             
                                                result = strtok( NULL, delims );
             }
       }
getch();
               
end:
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
   
