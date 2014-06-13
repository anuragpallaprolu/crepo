#include <stdio.h>
#define maxlen 10000
#define in 1
#define out 0
#include <string.h>
#define FOUND 1
#define NOTFOUND 0
//string searcher
//version 2
 int locate(char inp[], char searchstr[], int lpos);
 
main()
{
       char inp[maxlen], searchstr[maxlen];
       int d, c, i;
       
       d=0;
       i=0;
       for(d=0; d<=maxlen && (c=getchar())!=EOF; ++d)
                inp[d] = c;
                
       printf("What would you like to search?");
       for(i=0; i<=maxlen && (c=getchar())!=EOF; ++i)
                searchstr[i] = c;
                
       for (i=0;i<strlen(inp);i++) 
           if(locate(inp,searchstr,i)) 
           {
             printf("\n%s", searchstr);
             getch();
             break;
           }
}
             

 int locate(char inp[], char searchstr[], int lpos)
{
     int i, j=NOTFOUND;
      if (lpos+strlen(searchstr) > strlen(inp)) 
      return NOTFOUND;
      
     i=0;
     while(i<=strlen(searchstr)){
                 if(inp[lpos+i] == searchstr[i]) 
                                j=FOUND;
                 else 
                      return NOTFOUND;
                 i++;
                 }
     return j;
}                 
