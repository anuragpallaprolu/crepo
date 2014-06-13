#include <stdio.h>
#include <stdlib.h>
#define yes 1
#define no 0
//gamedevel t_t_1

void map(int order_r, int order_c, char mapped[]);
void edit(int order_r, int order_c, char mapf[]);
void map_print(int order_r, int order_c, char mapf[]);
void move_r(int order_r, int order_c,int cursor, char mapf[]);
void move_l(int order_r, int order_c,int cursor, char mapf[]);
void move_u(int order_r, int order_c,int cursor, char mapf[]);
void move_d(int order_r, int order_c,int cursor, char mapf[]);
int battle(int myscore, int opponent, char name[], char battle[]);
main()
{
 int order_r, order_c;
 order_r=10;
 order_c=10;
 int p;
 p = (order_r*order_c)-1;
 char matrix[p];
 printf("\nMONSTER WARS\n");
 printf("Welcome To NewFound Town");
 char name[1000];
 printf("\nWhat's Your Name?");
 scanf("%s", name);
 getch();
 map(10, 10, matrix);
 printf("\nStart Game?\n");
 system("cls");
 edit(order_r, order_c, matrix);
 map_print(order_r, order_c, matrix);
 getch();
 int c,i;
 i=0;
 while(i>=0){
                           
                           if((c=getch())=='d'){
                                                   system("cls"); 
                                                   move_r(order_r, order_c, i, matrix);
                                 
                                                   map_print(order_r, order_c, matrix);
                                                   ++i;
                                                   
                           }
                           else if((c=getch())=='s'){
                                                     system("cls");
                                                   move_d(order_r, order_c, i, matrix);
                                 
                                                   map_print(order_r, order_c, matrix);
                                                   ++i;
                                                   }
                           
}
 char opp[] = "Pika";
 int mystat = 10;
 int pikastat = 10;                           
 battle(mystat, pikastat, name, opp);
 getch();
     
      
}

void map(int order_r, int order_c,char matrix[])
{
      int p;
      p = (order_r*order_c)-1;
      int i;
      int j;
      for(i=0; i<=p; ++i){
               matrix[i] = ' ';
               }
      for(i=0; i<=order_r-1; ++i){
               printf("\n");
               for(j=(i*order_c); j<=((order_c)*(i+1))-1; ++j){
                                printf("%c", matrix[j]);
                                }
               }
      getch();
}

void edit(int order_r, int order_c, char matrix[])
{
     int i, j;
     matrix[0] = '*';
     printf("Here you start at the rightmost corner.\n");
     printf("Which direction would you like to go next?\n");
     int k;
     
}

void map_print(int order_r, int order_c, char matrix[])
{
     int i,j;
     for(i=0; i<=order_r-1; ++i){
               printf("\n");
               for(j=(i*order_c); j<=((order_c)*(i+1))-1; ++j){
                                printf("%c", matrix[j]);
                                }
               }
     getch();
     
}

     
void move_r(int order_r, int order_c, int c_point, char matrix[])
{
     if(c_point <= (order_r*order_c)-1)
     {
                matrix[c_point] = ' ';
                matrix[c_point + 1] = '*';
                system("cls");
}
                else
                { 
                    printf("error");
                }
                
} 
              
              
              
int battle(int myscore, int oppscore, char name[], char opp[])
{
    int my_stat=myscore;
    int opp_stat=oppscore;
    int i=0;
    printf("\n%s\n", name);
    for(i=0; i<=my_stat; ++i)
    {
             
             printf("|");
             }
    printf("\n%s\n", opp);
    for(i=0; i<=opp_stat; ++i)
    {
             
             printf("|");
             }
    
}
     
                           
void move_d(int order_r, int order_c, int c_point, char matrix[])
{
     if(c_point <= (order_r*order_c)-1)
     {
                matrix[c_point] = ' ';
                matrix[c_point + order_c] = '*';
                system("cls");
}
                else
                { 
                    printf("error");
                }
                
} 
                                   
                             
