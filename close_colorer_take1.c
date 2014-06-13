#include <stdio.h>

//CLOSE_COLOR TAKE 1



main()
{
      
char str[1000000];
int i,c;
 for(i=0; i<=1000000 && (c=getchar())!=EOF; ++i)
      {
               str[i] = c;
               }
char delims[] = " ";
char *result = NULL;
result = strtok( str, delims );
while( result != NULL ) {
    printf( "result is \"%s\"\n", result );
    result = strtok( NULL, delims );
}
getch();
}
