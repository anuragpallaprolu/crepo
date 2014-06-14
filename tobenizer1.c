//TOBENIZER 1
//LYNCH COMPUTER CORP 2014
//ON LEASE TO BHARAT DYNAMICS LIMITED

//THIS DESIGN IS INSPIRED FROM THE LYNCH COLORSEARCH TAKE 12 EDITION
//COLORER TAKE 7 IS NO LONGER A PART OF THE COLORSEARCH DEV TEAM

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define RED FOREGROUND_RED
#define GREEN FOREGROUND_GREEN
#define BLUE FOREGROUND_BLUE
#define BUFSIZE 1000
/*

LYNCH_COLORSEARCH_TAKE 12

USING BUFSIZ PARAM IT SEARCH BUFFERS EACH SENTENCE AND LOCATES THE REQUIRED SEARCH STRING
ALPHA TESTING

!!NOT FOR PRO USE!!

(C) LYNCH-ENVY COMPUTER CORP. 2013
*/
//void colorer (char str[], int co); COLORER IS NOT INCLUDED IN THE TOBENIZER RELEASES HENCEFORTH
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
                printf("Please enter search string");
                
                char search[100];
                scanf("%s", search);
                int c;
                c=0;
                //system("dir");
                while(fgets(bufsiz,1000,fp)!=NULL)
                                                  {
                                                  char *result, delims[] = " ";
                                                  result = NULL;
                                                  result = strtok(bufsiz, delims);
                                                  while(result!=NULL){
                                                                      
                                                  if(strcmp(search, result)!=0){
                                                                    printf("%s", result);
                                                                    }
                                                  else{
                                                       //colorer(result, RED);
                                                       int j;
                                                       while(bufsiz[j]
                                                       ++c;
                                                       }
                                                  result = strtok(NULL, delims);
                                                  //printf("%s", bufsiz);
                                                  }
                
                     }
                     printf("Found given case %d times", c);
                     }
                     else
                     {
                         printf("FILEMAN : No such file found. exiting.....\n");
                         goto end;
                         }
                     

getch();

getch();
               
end:
    getch();
       
}
